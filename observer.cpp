/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：observer.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月21日16时
*   描    述：观察者模式实现
*
================================================================*/

#include <iostream>
#include "observer.h"

Mayun::Mayun()
{
    name_ = new std::string("Mayun");
}

void Mayun::update(Antique *at)
{
    std::cout << *name_ << "收到" << at->getName() << at->getPrice() << "美元价格的消息!\n";
}

Mayun::~Mayun()
{
    if (name_){
        delete name_;
        name_ = nullptr;
    }
}

WangS::WangS()
{
    name_ = new std::string("WangS");
}

void WangS::update(Antique *at)
{
    std::cout << *name_ << "收到" << at->getName() << at->getPrice() << "美元的价格消息!\n";
}

WangS::~WangS()
{
    if (name_){
        delete name_;
        name_ = nullptr;
    }
}

Minium_Blue::Minium_Blue()
{
    list_ = new std::vector<Buyer*>();
    name_ = "Minium_Blue";
    price_ = 20000.00;
}

void Minium_Blue::attach(Buyer *by)
{
    list_->push_back(by);
}

void Minium_Blue::detach(Buyer *by)
{
    for(auto it = list_->begin(); it != list_->end(); ++it){
        if (*it == by){
            list_->erase(it);
            delete by;
            break;
        }

    }
}

void Minium_Blue::notify()
{
    for (auto &v : *list_){
        v->update(this);
    }
}

float Minium_Blue::getPrice() 
{
    return price_;
}  

std::string Minium_Blue::getName()
{
    return name_;
}

void Minium_Blue::setPrice(float value)
{
    price_ = value;
}

Minium_Blue::~Minium_Blue()
{
    for (auto &v : *list_){
        if (v){
            delete v;
            v = nullptr;
        }
    }

    if (list_){
        delete list_;
        list_ = nullptr;
    }
}

