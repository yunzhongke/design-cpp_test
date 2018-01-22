/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：singleton.h
*   创 建 者：yunzhongke
*   创建日期：2018年01月20日16时
*   描    述：单例模式
*
================================================================*/

#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <mutex>

/*
 * @brief 单例类
 *
 */
template<typename _DATA_TYPE>
class Singleton
{
    public:
        static Singleton* getSingleton();
        static void release();
        void setP(_DATA_TYPE value);
        _DATA_TYPE getValue() const;
        Singleton(Singleton<_DATA_TYPE> const &s) = delete;
        Singleton<_DATA_TYPE> &operator=(Singleton<_DATA_TYPE> const& s) = delete;
    private:
        Singleton();
        ~Singleton();
        static Singleton *sptr;
        _DATA_TYPE* pointer;
        static std::mutex mt;
};

template<typename _DATA_TYPE>
Singleton<_DATA_TYPE>  *Singleton<_DATA_TYPE>::sptr = NULL;


template<typename _DATA_TYPE>
std::mutex Singleton<_DATA_TYPE>::mt;

template<typename _DATA_TYPE>
Singleton<_DATA_TYPE>::Singleton()
{
    Singleton<_DATA_TYPE>::pointer = new _DATA_TYPE();
}

template<typename _DATA_TYPE>
Singleton<_DATA_TYPE>* Singleton<_DATA_TYPE>::getSingleton()
{
    if (!Singleton<_DATA_TYPE>::sptr){
        std::lock_guard<std::mutex> lock(Singleton<_DATA_TYPE>::mt);
        {
            if (!Singleton<_DATA_TYPE>::sptr){
                Singleton<_DATA_TYPE>::sptr = new Singleton<_DATA_TYPE>();
            }
        }
    }
    return Singleton<_DATA_TYPE>::sptr;
}

template<typename _DATA_TYPE>
void Singleton<_DATA_TYPE>::setP(_DATA_TYPE value)
{
    *Singleton<_DATA_TYPE>::pointer = value;
}

template<typename _DATA_TYPE>
_DATA_TYPE Singleton<_DATA_TYPE>::getValue() const{
    return *Singleton<_DATA_TYPE>::pointer;
}

template<typename _DATA_TYPE>
void Singleton<_DATA_TYPE>::release()
{
    if (Singleton<_DATA_TYPE>::sptr){
        std::lock_guard<std::mutex> lock(Singleton<_DATA_TYPE>::mt);
        {
            if (Singleton<_DATA_TYPE>::sptr){
                delete Singleton<_DATA_TYPE>::sptr;
                Singleton<_DATA_TYPE>::sptr = nullptr;
            }
        }
    }
}

template<typename _DATA_TYPE>
Singleton<_DATA_TYPE>::~Singleton()
{
    if (pointer){
        delete Singleton<_DATA_TYPE>::pointer;
        Singleton<_DATA_TYPE>::pointer = nullptr;
    }
}

#endif //__SINGLETON_H__
