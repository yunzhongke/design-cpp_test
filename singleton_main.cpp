/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：singleton_main.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月20日17时
*   描    述：单例测试
*
================================================================*/

#include <iostream>
#include <thread>
#include "singleton.h"

void fun()
{
    Singleton<int> *s = Singleton<int>::getSingleton();
    s->setP(10);
    std::cout << std::this_thread::get_id() << " : " << s->getValue() << "\n";
    //Singleton<int>::release();
    s->release();
}

int main()
{
    /*
     * @name test
     * @{ */
     std::thread *t1 = new std::thread(fun); 
     std::thread *t2 = new std::thread(fun); 
     t1->join();
     t2->join();

     delete t1;
     delete t2;
    /*  @} */
    
    return 0;
}
