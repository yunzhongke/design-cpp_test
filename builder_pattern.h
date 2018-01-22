/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：builder_pattern.h
*   创 建 者：yunzhongke
*   创建日期：2018年01月20日09时
*   描    述：建造者模式
*
================================================================*/

#ifndef __BUILDER_PATTERN_H__
#define __BUILDER_PATTERN_H__

#include <vector>
#include <string>

class builder;
class car;
/*
 * @brief 老板是指挥者
 */
class boss
{
    public:
        boss();
        void set_builder(builder*&);
        void assignment();
        ~boss();
    private:
        builder* w;
};

/*
 * @brief 建造者抽象类
 */
class builder
{
    public:
       virtual void build_carwheel() = 0;
       virtual void build_cardoor() = 0;
       virtual void build_carengine() = 0;
       virtual void build_carsteerwheel() = 0;
       virtual car* getCar() = 0;
       virtual ~builder(){}
};

/*
 * @brief 工人是具体的建造者
 */
class worker : public builder
{
    public:
        worker();
        void build_carwheel(); // 车轮
        void build_cardoor(); //车门
        void build_carengine(); //发动机
        void build_carsteerwheel(); //方向盘
        car* getCar();//组装完成
        ~worker();
    private:
        car *c;
};

/*
 * @brief 产品类汽车
 */
class car
{
    public:
        car();
        void Add(std::string part);
        void Show();
        ~car();
    private:
        std::vector<std::string> *parts;
};

#endif //__BUILDER_PATTERN_H__
