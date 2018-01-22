/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：abstract_factory_main.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月19日20时
*   描    述：抽象工厂测试
*
================================================================*/

#include <iostream>
#include "abstract_factory.h"


int main()
{
    /*
     * @test1
     * @{ */ 
    abstract_factory* f = new vertv();
    abstract_tv*  t = f->create_product_tv();
    abstract_fridge* fr = f->create_product_fridge();
    t->show();
    fr->show();
    delete f;
    delete t; 
    delete fr;
    /*  @
        } */
    std::cout << "\n-------------- change ----------------\n";
    /*
     * @name 
     * @{ */ 
    f = new baoan();
    t = f->create_product_tv();
    fr = f->create_product_fridge();
    t->show();
    fr->show();
    delete f;
    delete t;
    delete fr;
    /*  @} */
    return 0;
}
