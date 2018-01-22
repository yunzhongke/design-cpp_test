/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：prototype.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月20日22时
*   描    述：原型模式实现
*
================================================================*/

#include <iostream>
#include <cstring>
#include "prototype.h"

Man::Man(const char* name , int age , const char* clothes_color)
{
    name_ = new char(strlen(name) + 1);
    strcpy(name_ , name);

    age_ = age;

    clothes_color_ = new char(strlen(clothes_color) + 1);
    strcpy(clothes_color_ , clothes_color);
}

Person* Man::clone()
{
    return new Man(*this);
}

void Man::setName(const char *name)
{
    if (name_){
        delete name_;
    }

    name_ = new char(strlen(name) + 1);
    strcpy(name_ , name);
}

void Man::setAge(int age)
{
    age_ = age;
}

void Man::setClothesColor(const char *clothes_color)
{
    if (clothes_color_){
        delete clothes_color_;
    }

    clothes_color_ = new char(strlen(clothes_color) + 1);
    strcpy(clothes_color_ , clothes_color); 
}

void Man::show_info()
{
    std::cout << "\t" << name_ << " " << age_ << " " << clothes_color_ << "\n";
}

Man::~Man()
{
    if (name_){
        delete name_;
        name_ = nullptr;
    }
    if (clothes_color_){
        delete clothes_color_;
        clothes_color_ = nullptr;
    }
}

Woman::Woman(const char *name , int age , const char *clothes_color)
{
    name_ = new char(strlen(name) + 1);
    strcpy(name_ , name);

    age_ = age;

    clothes_color_ = new char(strlen(clothes_color) + 1);
    strcpy(clothes_color_ , clothes_color);
}

Person* Woman::clone()
{
    return new Woman(*this);
}

Woman::~Woman()
{
    if (name_){
        delete name_;
        name_ = nullptr;
    }
    if (clothes_color_){
        delete clothes_color_;
        clothes_color_ = nullptr;
    }
}

void Woman::setName(const char *name)
{
    if (name_){
        delete name_;
    }

    name_ = new char(strlen(name) + 1);
    strcpy(name_ , name);
}

void Woman::setAge(int age)
{
    age_ = age;
}

void Woman::setClothesColor(const char *clothes_color)
{
    if (clothes_color_){
        delete clothes_color_;
    }

    clothes_color_ = new char(strlen(clothes_color) + 1);
    strcpy(clothes_color_ , clothes_color); 
}

void Woman::show_info()
{
    std::cout << "\t" << name_ << " " << age_ << " " << clothes_color_ << "\n";
}

Map::Map()
{
    std::cout << "地图:\n";
}

void Map::set_scene(Person *p)
{
    member_.push_back(p);
}

void Map::show()
{
    for (auto &v : member_)
        v->show_info();
}

Map::~Map()
{
    for (auto &v : member_){
        if (v){
            delete v;
            v = nullptr;
        }
    }
}
