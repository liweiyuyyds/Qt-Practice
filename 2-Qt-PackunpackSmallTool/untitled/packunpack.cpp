#include "packunpack.h"

PackUnpack::PackUnpack()
{
    for(int i = 0; i < MAX_PACK_LEN; i++)
    {
        mListBuf.insert(i, 0);  //ID、数据头、数据及校验和均清零
    }

    mPackLen      = 0;      //数据包的长度默认为0
    mGotPackId    = false;  //获取到数据包ID标志默认为false，即尚未获取到ID
    mRestByteNum  = 0;      //剩余的字节数默认为0
}

PackUnpack::~PackUnpack()
{

}

bool PackUnpack::pack_data(QList<uchar>& listPack)
{
    if (listPack[0] < 0x80)                 //包ID必须在0x00-0x7F之间, listPack[0]为包ID
    {
      packWithCheckSum(listPack);
      return true;
    }
    return false;
}

void PackUnpack::packWithCheckSum(QList<uchar> &pack)
{
    int i;
    uchar dataHead;          //数据头，在数据包的第2个位置，即ID之后
    uchar checkSum;          //数据校验和，在数据包的最后一个位置

    //对于包长小于2的数据，不需要打包，因此直接跳出此方法，注意，最短的包只有包头和校验和，即系统复位
    if (10 != pack.length())
    {
        return;
    }

    checkSum = pack[0];     //取出ID，加到校验和

    dataHead = 0;         //数据头清零

    for(i = 8; i > 1; i--)
    {
        //数据头左移，后面数据的最高位位于dataHead的靠左
        dataHead <<= 1;

        //对数据进行最高位置1操作，并将数据右移一位（数据头插入原因）
        pack.replace(i, (uchar)((pack[i - 1]) | 0x80));

        //数据加到校验和
        checkSum += pack.at(i);

        //取出原始数据的最高位，与dataHead相或
        dataHead |= (uchar)(((pack[i - 1]) & 0x80) >> 7);
    }

    //数据头在数据包的第二个位置，仅次于包头，数据头的最高位也要置为1
    pack.replace(1, (uchar)(dataHead | (0x80)));

    //将数据头加到校验和
    checkSum += pack[1];

    //校验和的最高位也要置为1
    pack.replace(9, (uchar)(checkSum | 0x80));
}

bool PackUnpack::unpackData(uchar data)
{
    bool findPack = false;

    if(mGotPackId)                          //已经接收到包ID
    {
        if(0x80 <= data)                       //包数据（非包ID）必须大于或等于0X80
        {
            //数据包中的数据从第二个字节开始存储，因为第一个字节是包ID
            mListBuf[mPackLen] = data;
            mPackLen++;                         //包长自增
            mRestByteNum--;                     //剩余字节数自减

            //已经接收到完整的数据包
            if((0 >= mRestByteNum) && (10 == mPackLen))
            {
                findPack = unpackWithCheckSum(mListBuf);   //接收到完整数据包后尝试解包
                mGotPackId = false;               //清除获取到包ID标志，即重新判断下一个数据包
            }
        }
        else
        {
            mGotPackId = false;                 //表示出错
        }
    }
    else if(data < 0x80)                     //当前的数据为包ID
    {
            mRestByteNum = 9;   //剩余的包长，即打包好的包长减去1
            mPackLen = 1;                       //尚未接收到包ID即表示包长为1
            mListBuf[0] = data;                  //数据包的ID
            mGotPackId = true;                  //表示已经接收到包ID
    }

    return findPack;    //如果获取到完整的数据包，并解包成功，findPack为TRUE，否则为FALSE
}

//带校验和的数据解包
//返回值0-解包不成功，1-解包成功
bool PackUnpack::unpackWithCheckSum(QList<uchar> &listPack)
{
    int i;
    uchar dataHead;
    uchar checkSum;


    if(10 != listPack.count())         //len不等于10，返回0
    {
        return false;
    }

    checkSum = listPack[0];   //取出ID，加到校验和
    dataHead = listPack[1];   //取出数据包的数据头，赋给dataHead
    checkSum += dataHead;     //将数据头加到校验和

    for(i = 1; i < 8; i++)
    {
      checkSum += listPack[i + 1];    //将数据依次加到校验和

      //还原有效的8位数据
      listPack[i] = (uchar)((listPack[i + 1] & 0x7f) | ((dataHead & 0x1) << 7));
      dataHead >>= 1;                 //数据头右移一位
    }

    //判断ID、数据头和数据求和的结果（低七位）是否与校验和的低七位相等，如果不等返回0
    if((checkSum & 0x7f) != ((listPack[9]) & 0x7f))
    {
       return false;
    }

      return true;
}


QList<uchar>  PackUnpack::getUnpackRslt()
{
    return(mListBuf);
}
