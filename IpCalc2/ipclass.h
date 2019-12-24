#ifndef IPCLASS_H
#define IPCLASS_H
#include <QHostAddress>
#include <math.h>


using namespace std;

class IpAdr{
private:
    QHostAddress IP;
    int CIDR_Mask_bits;
    QHostAddress minIp; // minimal ip adress for network
    QHostAddress maxIp; // maximal ip adress for network
    int BC_Mask; // broadcast mask bits
    QHostAddress BCIP; // broadcast adress
public:
    IpAdr();
    bool setIpAdr(QString str);
    void setCIDR_Mask_Bits(int n);
    void calcMinIp();
    void calcMaxIp();
    void calcBC_Mask_Bits();
    void calcBCIP();
    QString getIpNum();
    void updateIpInfo();
    QStringList displayIpInfo();
};

#endif // IPCLASS_H
