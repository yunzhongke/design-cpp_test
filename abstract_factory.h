/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：abstract_factory.h
*   创 建 者：yunzhongke
*   创建日期：2018年01月19日19时
*   描    述：抽象工厂模式
*
================================================================*/

#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__


/*
 * @class 前身声明抽象产品
 */
class abstract_fridge;
class abstract_tv;

/*
 * @class 抽象工厂类
 */
class abstract_factory
{
    public:
        virtual abstract_fridge* create_product_fridge() = 0;
        virtual abstract_tv* create_product_tv() = 0;
        virtual ~abstract_factory(){} 
};

class vertv : public abstract_factory
{
    public:
        vertv();
        abstract_fridge* create_product_fridge();
        abstract_tv* create_product_tv();
        ~vertv(){}
};

class baoan : public abstract_factory 
{
    public:
        baoan();
        abstract_fridge* create_product_fridge();
        abstract_tv* create_product_tv();
        ~baoan(){}
};

/*
 * @class 电视机抽象类
 */
class abstract_tv
{
    public:
        virtual void show() = 0;
        virtual ~abstract_tv(){}
};

/*
 * @class abstract_tv实现类
 */
class tcl : public abstract_tv
{
    public:
        tcl(){};
        void show();
        ~tcl(){}
};

/*
 * @class abstract_tv实现类
 */
class haier_tv : public abstract_tv
{
    public:
        haier_tv(){};
        void show();
        ~haier_tv(){}
};

/*
 * @class 电冰箱抽象类
 */
class abstract_fridge
{
    public:
        virtual void show() = 0;
        virtual ~abstract_fridge(){}
};

/*
 * @class abstract_fridge 实现类
 */
class hairer_fridge : public abstract_fridge
{
    public:
        hairer_fridge(){};
        void show();
        ~hairer_fridge(){}
}; 

/*
 * @class abstract_fridge 实现类
 */
class hairxin_fridge : public abstract_fridge
{
    public:
        hairxin_fridge(){};
        void show();
        ~hairxin_fridge(){}
};

#endif //__ABSTRACT_FACTORY_H__
