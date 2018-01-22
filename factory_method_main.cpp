/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：factory_method_main.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月20日13时
*   描    述：工厂方法测试
*
================================================================*/

#include <iostream>
#include "factory_method.h"

int main()
{
    /*
     * @name test 
     * @{ */ 
     Factory *f = new FileLog_Factory();
     Log *l = f->create_log();
     l->write_log();
     delete f;
     delete l;
    /*  @} */

     std::cout << "\n -------------------- change -----------------------\n";

    /*
      * @name 
      * @{ */ 
     f = new DatabaseLog_Factory();
     l = f->create_log();
     l->write_log();
     delete f;
     delete l;
     /*  @} */
}
