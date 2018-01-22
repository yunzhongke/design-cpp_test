/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：proxy.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月21日09时
*   描    述：代理模式实现
*
================================================================*/

#include "proxy.h"


void Domestic_Network::browse_youtobe()
{
    std::cout << "正在尝试访问youtubo...\n";
}

Vpn::Vpn():dn_(new Domestic_Network())
{
    std::cout << "欢迎使用VPN代理！\n";
}

Vpn::Vpn(Domestic_Network *dn)
{
    dn_ = dn;
}

void Vpn::browse_youtobe()
{
    std::cout << "成功连接到youtobe!\n";
}

Vpn::~Vpn()
{
    if (dn_){
        delete dn_;
        dn_ = nullptr;
    }
}
