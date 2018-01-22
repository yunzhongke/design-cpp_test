/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：facade_main.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月21日09时
*   描    述：外观类测试
*
================================================================*/

#include <thread>
#include <chrono>
#include "facade.h"

int main()
{
    /*
     * @name test
     * @{ */ 
    Remote_Control *r = new Remote_Control();
    r->on();
    std::cout << "\n----------------------------------------\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    r->off();
    delete r; 
    /*  @} */

    return 0;
}
