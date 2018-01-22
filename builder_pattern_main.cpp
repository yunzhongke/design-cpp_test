/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：builder_pattern_main.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月20日10时
*   描    述：建造者模式测试
*
================================================================*/

#include "builder_pattern.h"

int main()
{
    boss *s = new boss();
    builder *wk = new worker();
    s->set_builder(wk);
    s->assignment();
    car* c = wk->getCar();
    c->Show();

    delete s;
    return 0;
}
