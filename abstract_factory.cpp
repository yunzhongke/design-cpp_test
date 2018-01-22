/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：abstract_factory.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月19日19时
*   描    述：抽象工厂实现
*
================================================================*/

#include <iostream>
#include "abstract_factory.h"

vertv::vertv()
{
    std::cout << "Vertv工厂\n";
}

abstract_fridge* vertv::create_product_fridge()
{
    return new hairer_fridge();
}

abstract_tv* vertv::create_product_tv()
{
    return new tcl();
}

baoan::baoan()
{
    std::cout << "baoan 工厂!\n";
}

abstract_fridge* baoan::create_product_fridge()
{
    return new hairxin_fridge();
}

abstract_tv* baoan::create_product_tv()
{
    return new haier_tv();
}

void tcl::show()
{
    std::cout << "tcl 品牌电视机\n";
}

void haier_tv::show()
{
    std::cout << "海尔 品牌电视机\n";
}


void hairer_fridge::show()
{
    std::cout << "海尔电冰箱\n"; 
}

void hairxin_fridge::show()
{
    std::cout << "海信电冰箱\n";
}
