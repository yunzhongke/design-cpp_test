/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：facade.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月21日09时
*   描    述：外观类的实现
*
================================================================*/

#include "facade.h"

Remote_Control::Remote_Control():ligth_(new Light()) , tv_(new Television()) , air_(new Aircondition())
{
    std::cout << "欢迎使用遥控器！\n";    
}

void Remote_Control::on()
{
    ligth_->on();
    tv_->on();
    air_->on();
}

void Remote_Control::off()
{
    ligth_->off();
    tv_->off();
    air_->off();
}

Remote_Control::~Remote_Control()
{
    if (ligth_){
        delete ligth_;
        ligth_ = nullptr;
    }
    if (tv_){
        delete tv_;
        tv_ = nullptr;
    }
    if (air_){
        delete air_;
        air_ = nullptr;
    }
}
