#include "ipclass.h"
#include <QDebug>

IpAdr::IpAdr(){

}

bool IpAdr::setIpAdr(QString str){
    return IP.setAddress(str);
}

void IpAdr::setCIDR_Mask_Bits(int n){
    CIDR_Mask_bits = n;
}

void IpAdr::calcMinIp(){
    QString ipstr = getIpNum();
    QStringList strspl = ipstr.split('.');
    int OCTATE4_int = strspl[3].toInt()+1;
    minIp.setAddress(strspl[0]+"."+strspl[1]+"."+strspl[2]+"."+
            QString::number(OCTATE4_int));
}

void IpAdr::calcMaxIp(){ // 128.64.0.0/9 => max 128.127.255.254 bc+1
    if(CIDR_Mask_bits > 0 && CIDR_Mask_bits <= 8){
        int bi = pow(2, (8 - CIDR_Mask_bits))-1;
        // to 1st octate
        maxIp.setAddress(QString::number(bi)+".255.255.254");
    }
    else if(CIDR_Mask_bits > 8 && CIDR_Mask_bits <= 16){
        int bi = pow(2, (16 - CIDR_Mask_bits))-1;
        QStringList strspl = IP.toString().split('.');
        // to 2nd octate
        maxIp.setAddress(strspl[0]+"."+QString::number(bi)+".255.254");
    }
    else if(CIDR_Mask_bits > 16 && CIDR_Mask_bits <= 24){
        int bi = pow(2, (24 - CIDR_Mask_bits))-1;
        QStringList strspl = IP.toString().split('.');
        // to 3rd octate
        maxIp.setAddress(strspl[0]+"."+strspl[1]+"."+QString::number(bi)+".254");
    }
    else if(CIDR_Mask_bits > 24 && CIDR_Mask_bits < 32){
        int bi = pow(2, (32 - CIDR_Mask_bits))-1;
        QStringList strspl = IP.toString().split('.');
        // to 4th octate
        maxIp.setAddress(strspl[0]+"."+strspl[1]+"."+strspl[2]+"."+QString::number(bi));
    }
}

void IpAdr::calcBC_Mask_Bits(){
    BC_Mask = 32 - CIDR_Mask_bits;
}

void IpAdr::calcBCIP(){
    QStringList strspl = maxIp.toString().split('.');
    QString temp = QString::number(strspl[3].toInt()+1);
    QString str = strspl[0]+"."+strspl[1]+"."+strspl[2]+"."+temp;
    BCIP.setAddress(str);
    qDebug()<<"debug bcip:"<<str<<endl;
}

QString IpAdr::getIpNum(){
    return IP.toString();
}

void IpAdr::updateIpInfo(){
    calcMinIp();
    calcMaxIp();
    calcBCIP();
}

QStringList IpAdr::displayIpInfo(){
    updateIpInfo();
    QStringList qstrli;
    QString bufstr = "IP Adress: "+this->getIpNum()+"/"+QString::number(CIDR_Mask_bits);
    qstrli.append(bufstr);
    bufstr = "Minimal Host Adress: "+this->minIp.toString()+"/"+QString::number(CIDR_Mask_bits);
    qstrli.append(bufstr);
    bufstr = "Maximal Host Adress: "+this->maxIp.toString()+"/"+QString::number(CIDR_Mask_bits);
    qstrli.append(bufstr);
    bufstr = "Broadcast: "+this->BCIP.toString()+"/"+QString::number(CIDR_Mask_bits);
    qstrli.append(bufstr);

    return qstrli;
}
