//
// Created by Yu Jun on 30/08/2018.
//

#ifndef UTILI_REPLACESPACE_H
#define UTILI_REPLACESPACE_H

#include <string>
#include <vector>

class ReplaceSpace {
public:
    static void replaceSpace(std::string &str) {
        for(size_t i =0; i< str.size();++i)
        {
            if(str[i] == ' ')
            {
                str.replace(i, 1, "%20");
            }
        }
    }
};

#endif //UTILI_REPLACESPACE_H
