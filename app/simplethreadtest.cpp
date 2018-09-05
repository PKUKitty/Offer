//
// Created by Yu Jun on 01/04/16.
//

#include "simplethread.h"

using namespace utilis;

int main()
{
    std::string name ="Thread";
    SimpleThread st(name);
    st.start();
}

