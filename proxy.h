/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：proxy.h
*   创 建 者：yunzhongke
*   创建日期：2018年01月21日09时
*   描    述：代理模式
*
================================================================*/

#ifndef __PROXY_H__
#define __PROXY_H__

#include <iostream>

/*
 * 实例：我想浏览youtobe的视频，但是国内访问不了，只能通过代理访问(VPN)
 */

/*
 * @brief 互联网 抽象类
 */
class Internet
{
    public:
        virtual void browse_youtobe() = 0;
        virtual ~Internet(){};
};

/*
 * @brief 国内网
 */
class Domestic_Network : public Internet
{
    public:
        void browse_youtobe();
        ~Domestic_Network(){}
};

/*
 * @brief VPN
 */
class Vpn : public Internet
{
    private:
        Domestic_Network* dn_;
    public:
        Vpn();
        Vpn(Domestic_Network *);
        void browse_youtobe();
        ~Vpn();
};

#endif //__PROXY_H__
