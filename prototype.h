/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：prototype.h
*   创 建 者：yunzhongke
*   创建日期：2018年01月20日21时
*   描    述：原型模式
*
================================================================*/

#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

#include <string>
#include <vector>

/*
 * @brief 抽象类
 */
class Person
{
    public:
        virtual Person* clone() = 0;
        virtual ~Person(){};
        virtual void setName(const char* name) = 0;
        virtual void setAge(int age) = 0;
        virtual void setClothesColor(const char* clothes_color) = 0;
        virtual void show_info() = 0;
};

/*
 * @brief 具体类 男人
 */
class Man : public Person
{
    private:
        char *name_;
        int age_;
        char *clothes_color_;
    public:
        Man() = default;
        Man(const char *name , int age , const char* clothes_color);
        Person* clone();
        ~Man();
        void setName(const char* name);
        void setAge(int age);
        void setClothesColor(const char* clothes_color);
        void show_info();
};

/*
 * @brief 具体类 女人
 */
class Woman : public Person
{
    private:
        char *name_;
        int age_;
        char *clothes_color_;
    public:
        Woman() = default;
        Woman(const char *name , int age , const char *clothes_color);
        Person* clone();
        ~Woman();
        void setName(const char* name);
        void setAge(int age);
        void setClothesColor(const char* clothes_color);
        void show_info();
};
/*
 * @brief 地图类
 */
class Map
{
    private:
        std::vector<Person*> member_;
    public:
        Map();
        void set_scene(Person*);
        void show();
        ~Map();
};

#endif //__PROTOTYPE_H__
