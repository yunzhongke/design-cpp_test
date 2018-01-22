/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：simpe_factory.h
*   创 建 者：yunzhongke
*   创建日期：2018年01月18日22时
*   描    述：简单工厂类
*
================================================================*/

#ifndef _SIMPE_FACTORY_H__
#define __SIMPE_FACTORY_H__


/*
 * @class 汽车抽象类
 */
class Car
{
    public:
        virtual void drive() = 0;
        virtual ~Car(){};
};

/*
 * @class Car的具体类
 */
class Benz : public Car
{
    public:
        Benz();
        void drive();
        ~Benz(){};
};

/*
 * @class Car的具体类
 */
class Audi : public Car
{
    public:
        Audi();
        void drive();
        ~Audi(){};
};

/*
 * @class Car的具体类
 */
class Bmw : public Car
{
    public:
        Bmw();
        void drive();
        ~Bmw(){};
};

/*
 * @class 生产Car的工厂
 */
class Factory
{
    public:
        Factory();
        Car* production_Car(const char* car_name);
        ~Factory(){};
};

#endif //__SIMPE_FACTORY_H__
