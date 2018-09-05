//
// Created by Yu Jun on 01/04/16.
//

#ifndef UTILIS_SIMPLETHREAD_H
#define UTILIS_SIMPLETHREAD_H

#include <string>
#include <iostream>

namespace utilis
{
    class SimpleThread
    {
    public:
        SimpleThread(std::string& name) : m_name(name)
        {

        }

        void start();

    private:
        std::string m_name;

    };


    void SimpleThread::start()
    {
        std::cout<<"Start Thread"<<std::endl;

    }
}


#endif //UTILIS_SIMPLETHREAD_H
