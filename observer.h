/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：observer.h
*   创 建 者：yunzhongke
*   创建日期：2018年01月21日16时
*   描    述：观察者模式
*
================================================================*/

#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <vector>
#include <string>

/*
 * 多个买家观察古董价格的变动
 */

class Antique;
/*
 * @brief 买家 观察者抽象类
 */
class Buyer
{
    public:
        virtual void update(Antique *) = 0;
        virtual ~Buyer(){}
};

/*
 * @brief 具体的买家
 */
class Mayun : public Buyer
{
    private:
        std::string* name_;
    public:
        Mayun();
        void update(Antique *);
        ~Mayun();
};

/*
 * @brief 具体买家
 */
class WangS : public Buyer
{
    private:
        std::string* name_;
    public:
        WangS();
        void update(Antique *);
        ~WangS();
};

/*
 * @brief 古董 目标抽象类
 */
class Antique
{
    protected:
        std::vector<Buyer*> *list_;
        float price_;
    public:
        virtual void attach(Buyer *) = 0;
        virtual void detach(Buyer *) = 0;
        virtual void notify() = 0;
        virtual ~Antique(){}
        virtual float getPrice() = 0 ;
        virtual std::string getName() = 0;
        virtual void setPrice(float value) = 0;
};

/*
 * @brief 青花瓷
 */
class Minium_Blue : public Antique
{
    private:
        float price_;
        std::string name_;
    public:
        Minium_Blue();
        void attach(Buyer *);
        void detach(Buyer *);
        void notify();
        float getPrice() ;
        std::string getName() ;
        void setPrice(float value);
        ~Minium_Blue();
};

#endif // __OBSERVER_H__
