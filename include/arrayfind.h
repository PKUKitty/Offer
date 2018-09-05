//
// Created by Yu Jun on 29/08/2018.
//

#ifndef UTILI_ARRAYFIND_H
#define UTILI_ARRAYFIND_H

#include <vector>
#include <iostream>

class ArrayFind {

public:

    static bool find(const std::vector<std::vector<int>> &matrix, int number) {
        if (matrix.empty()) {
            return false;
        }

        size_t row = matrix.size();
        size_t column = matrix[0].size();

        size_t beginRow = 0;
        size_t beginColumn = column - 1;

        while (beginRow >= 0 && beginRow < row && beginColumn >= 0 && beginColumn < column) {
            if (matrix[beginRow][beginColumn] == number) {
                return true;
            } else if (matrix[beginRow][beginColumn] > number) {
                beginColumn--;
            } else {
                beginRow++;
            }
        }
        return false;
    }
};

#endif //UTILI_ARRAYFIND_H
