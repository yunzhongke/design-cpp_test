/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：simpe_factory_main.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月18日22时
*   描    述：简单工厂测试
*
================================================================*/

#include <iostream>
#include "simpe_factory.h"
int main()
{
    /*
     * @test1
     * @{ */ 
    Factory *f = new Factory();
    Car *car = f->production_Car("Audi");
    car->drive();
    delete car;
    delete f;
    /*  @} */

    std::cout << "\n----------------- now exchange car ------------------\n";

    /*
     * @test2 
     * @{ */ 
    car = f->production_Car("Bmw");
    car->drive();
    delete car;
    /*  @} */

    
    
} 
