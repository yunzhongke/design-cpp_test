/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：prototype_main.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月20日22时
*   描    述：原型模式测试
*
================================================================*/

#include <iostream>
#include "prototype.h"

int main()
{
    /*
     * @name test
     * @{ */ 
    Map *m = new Map();
    Person *p1 = new Man("yunzhongke" , 11 , "red");
    Person *p2 = p1->clone();
    Person *p3 = p1->clone();
    p2->setName("yun");
    p3->setName("lian");

    Person *p4 = new Woman("hong" , 22 , "blue");
    Person *p5 = p4->clone();
    Person *p6 = p4->clone();
    p5->setName("yel");
    p6->setName("huang");

    m->set_scene(p1);
    m->set_scene(p2);
    m->set_scene(p3);
    m->set_scene(p4);
    m->set_scene(p5);
    m->set_scene(p6);
    m->show();
    delete m;
    /*  @} */

    return 0;
}
