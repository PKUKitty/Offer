//
// Created by Yu Jun on 29/08/2018.
//

#ifndef UTILIS_SINGLETON_H
#define UTILIS_SINGLETON_H

#include <mutex>

class Singleton
{
public:

    static Singleton* getInstance()
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        if(m_instance == nullptr)
        {
            m_instance = new Singleton();
        }
        return m_instance;
    }

    int getCount() const
    {
        return m_count;
    }

    virtual ~Singleton()
    {
        if(nullptr != m_instance)
        {
            delete m_instance;
            m_instance = nullptr;
        }
    }

private:

    Singleton() = default;

private:
    static std::mutex m_mutex;

    int m_count = 0;
    static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;
std::mutex Singleton::m_mutex;

#endif //UTILIS_SINGLETON_H
