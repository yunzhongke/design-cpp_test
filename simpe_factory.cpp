/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：simpe_factory.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月18日22时
*   描    述：simpe_factory.h中类的具体实现
*
================================================================*/

#include <iostream>
#include <cstring>
#include "simpe_factory.h"

Benz::Benz()
{
    std::cout << "create Benz!" << "\n";
}

void Benz::drive()
{
    std::cout << "now drive Benz!" << "\n";
}

Audi::Audi()
{
    std::cout << "create Audi!\n";
}

void Audi::drive()
{
    std::cout << "now drive Audi!\n";
}

Bmw::Bmw()
{
    std::cout << "create Bmw!\n";
}

void Bmw::drive()
{
    std::cout << "now drive Bmw!\n";
}

Factory::Factory()
{
    std::cout << "create Factory!\n";
}


Car* Factory::production_Car(const char* car_name)
{
    if (!strcmp(car_name , "Audi"))
        return new Audi();
    else if (!strcmp(car_name , "Benz"))
        return new Benz();
    else if (!strcmp(car_name , "Bmw"))
        return new Bmw();
    else 
        return NULL;
}
