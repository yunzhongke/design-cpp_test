/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：factory_method.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年01月20日13时
*   描    述：工厂方法模式的实现
*
================================================================*/

#include <iostream>
#include "factory_method.h"

Log::Log()
{
    std::cout << "日志产品类!\n";
}

File_Log::File_Log()
{
    std::cout << "文件日志!\n";
}

void File_Log::write_log()
{
    std::cout << "正在将信息写入文件日志中..\n";
}

Database_Log::Database_Log()
{
    std::cout << "数据库日志文件!\n";
}

void Database_Log::write_log()
{
    std::cout << "正在将信息写入数据库日志文件中..\n";
}

Factory::Factory()
{
    std::cout << "生产日志的工厂!\n";
}

FileLog_Factory::FileLog_Factory()
{
    std::cout << "专门生产文件日志的工厂!\n";
}

Log* FileLog_Factory::create_log()
{
    return new File_Log();
}

DatabaseLog_Factory::DatabaseLog_Factory()
{
    std::cout << "专门生产数据库日志的工厂!\n";
}

Database_Log* DatabaseLog_Factory::create_log()
{
    return new Database_Log();
}
