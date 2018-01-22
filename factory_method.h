/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：Factory_method.h
*   创 建 者：yunzhongke
*   创建日期：2018年01月20日12时
*   描    述：工厂方法模式
*
================================================================*/

#ifndef __FACTORY_METHOD_H__
#define __FACTORY_METHOD_H__

/*
 * @brief 抽象的产品类
 */
class Log
{
    public:
        Log();
        virtual ~Log(){}
        virtual void write_log() = 0;
};

/*
 * @brief 文件日志
 */
class File_Log : public Log
{
    public:
        File_Log();
        void write_log();
        ~File_Log(){};
};

/*
 * @brief 数据库日志文件
 */
class Database_Log : public Log
{
    public:
        Database_Log();
        ~Database_Log(){};
        void write_log();
};
/*
 * @brief 抽象工厂类
 */
class Factory
{
    public:
        Factory();
        virtual Log* create_log() = 0;
        virtual ~Factory(){}
};

/*
 * @brief 生产文件日志的工厂
 */
class FileLog_Factory : public Factory
{
    public:
        FileLog_Factory();
        Log* create_log();
        ~FileLog_Factory(){};
};


/*
 * @brief 生产数据库日志的工厂
 */
class DatabaseLog_Factory : public Factory
{
    public:
        DatabaseLog_Factory();
        Database_Log* create_log();
        ~DatabaseLog_Factory(){};
};

#endif //__FACTORY_METHOD_H__
