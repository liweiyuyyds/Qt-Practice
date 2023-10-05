#ifndef PACKUNPACK_H
#define PACKUNPACK_H
#include <QList>

//liweiyu
class PackUnpack
{
public:
    PackUnpack();
    virtual ~PackUnpack();

    bool pack_data(QList<uchar> &listPack);
    bool unpackData(uchar data);
    QList<uchar> getUnpackRslt();

public:
    const int MAX_PACK_LEN = 10;

    //定义m_listBuf
    //m_listBuf[0]  : 对应packId
    //m_listBuf[1-8]: 对应arrData
    //m_listBuf[9]  : 对应checkSum
    QList<uchar> mListBuf;
    QList<int> mListPackLen;

private:
     void packWithCheckSum(QList<uchar> &pack);
     bool unpackWithCheckSum(QList<uchar> &pack);

private:
    int  mPackLen;       //数据包长度
    bool mGotPackId;     //获取到ID的标志，获得正确的ID即为TRUE，否则为FALSE
    int  mRestByteNum;   //剩余字节数

};

#endif // PACKUNPACK_H
