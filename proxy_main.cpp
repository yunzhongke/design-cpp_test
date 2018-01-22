/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：proxy_main.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月21日09时
*   描    述：代理模式测试
*
================================================================*/


#include <iostream>
#include "proxy.h"

int main()
{
    /*
     * @name test
     * @{ */ 
    Internet *i = new Domestic_Network();
    i->browse_youtobe();
    std::cout << "连接失败..\n";

    std::cout << "\n-------------------------\n\n";

    std::cout << "切换代理设置!\n";
    i = new Vpn(dynamic_cast<Domestic_Network*>(i));
    i->browse_youtobe();
    delete i;
    /*  @} */

    return 0;
}
