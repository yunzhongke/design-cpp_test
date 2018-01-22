/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：observer_main.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月21日17时
*   描    述：观察者模式测试
*
================================================================*/

#include <iostream>
#include "observer.h"

int main()
{
    /*
     * @name test
     * @{ */ 
    Antique *at = new Minium_Blue();
    Buyer *by1 = new Mayun();
    Buyer *by2 = new WangS();
    at->attach(by1);
    at->attach(by2);
    at->setPrice(40000);
    at->notify();

    std::cout << "\n------------------change------------------\n\n";
    at->detach(by2);
    at->setPrice(30000);
    at->notify();

    delete at;
    /*  @} */

    return 0;
}
