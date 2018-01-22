/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：builder_pattern.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月20日09时
*   描    述：建造者模式实现
*
================================================================*/

#include <iostream>
#include "builder_pattern.h"

boss::boss()
{
    std::cout << "我是这里的大老板!\n";
}

/*
 * @brief 老板指定某个员工
 *
 * @param builder*
 */
void boss::set_builder(builder*& b)
{
    this->w = b;
}

/*
 * @brief 指派某员工任务
 */
void boss::assignment()
{
   this->w->build_cardoor(); 
   this->w->build_carwheel();
   this->w->build_carengine();
   this->w->build_carsteerwheel();
}

boss::~boss()
{
    if (w){
        delete w;
        w = NULL;
    }
}


worker::worker():c(new car())
{
    std::cout << "我是张大炮组装员\n";
}

void worker::build_cardoor()
{
    c->Add("组装车门");
}

void worker::build_carwheel()
{
    c->Add("组装车轮");
}

void worker::build_carengine()
{
    c->Add("组装发动机");
}

void worker::build_carsteerwheel()
{
    c->Add("组装方向盘");
}

car* worker::getCar()
{
    return c;
}

worker::~worker(){
    if (c){
        delete c;
        c = NULL;
    }
}


car::car():parts(new std::vector<std::string>())
{
    std::cout << "即将为您组装汽车\n";
}


void car::Add(std::string part)
{
    parts->emplace_back(part);
}

void car::Show()
{
    for(auto &part : *parts){
        std::cout << part << "\n";
    }
    std::cout << "汽车组装完成!\n";
}

car::~car()
{
    if (parts){
        delete parts;
        parts = NULL;
    }
}
