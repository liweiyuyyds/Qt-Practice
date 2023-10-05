#ifndef UTILS_H
#define UTILS_H

#include <QString>

//将0~f或0~F转换为十进制数
static short convertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
    {
        return ch - 0x30;
    }
    else if((ch >= 'A') && (ch <= 'F'))
    {
        return ch - 'A' + 10;
    }
    else if((ch >= 'a') && (ch <= 'f'))
    {
        return ch - 'a' + 10;
    }
    else
    {
        return (-1);
    }
}

//将十六进制字符串转换为字符数组
static QByteArray convertHexStrToByteArray(QString hexStr)
{
    QByteArray sendData;
    char lStr, hStr;
    int hexData, lowHexData;
    int hexDataLen = 0;
    int len = hexStr.length();
    sendData.resize(len / 2);

    for(int i = 0; i < len;)
    {
        hStr = hexStr.at(i).toLatin1();

        if(hStr == ' ')
        {
            i++;
            continue;
        }

        i++;

        if(i >= len)
        {
            break;
        }

        lStr = hexStr.at(i).toLatin1();
        hexData = convertHexChar(hStr);
        lowHexData = convertHexChar(lStr);

        if((hexData == 16) || (lowHexData == 16))
        {
            break;
        }
        else
        {
            hexData = hexData * 16 + lowHexData;
        }

        i++;
        sendData[hexDataLen] = (char)hexData;
        hexDataLen++;
    }

    sendData.resize(hexDataLen);

    return sendData;
}


#endif // UTILS_H
