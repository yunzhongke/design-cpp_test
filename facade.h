/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：facade.h
*   创 建 者：yunzhongke
*   创建日期：2018年01月21日08时
*   描    述：外观模式
*
================================================================*/

/*
 * 案例：老人使用电器
 */

#ifndef __FACADE_H__
#define __FACADE_H__

#include <iostream>

/*
 * @brief 灯类
 */
class Light
{
    public:
        void on(){
            std::cout << "打开灯!\n";
        }
        void off(){
            std::cout << "关闭灯!\n";
        }
};

/*
 * @brief 电视类
 */
class Television
{
    public:
        void on(){
            std::cout << "打开电视!\n";
        }
        void off(){
            std::cout << "关闭电视!\n";
        }
};

/*
 * @brief 空调类
 */
class Aircondition
{
    public:
        void on(){
            std::cout << "打开空调!\n";
        }
        void off(){
            std::cout << "关闭空调!\n";
        }
};

/*
 * @brief 遥控器 外观类
 */
class Remote_Control
{
    private:
        Light* ligth_;
        Television* tv_;
        Aircondition* air_;
    public:
        Remote_Control();
        void on();
        void off();
        ~Remote_Control();
};

#endif //__FACADE_H__
