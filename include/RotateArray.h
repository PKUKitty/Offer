//
// Created by zhangmiao on 2018/8/22.
//

#ifndef OFFER_ROTATEARRAY_H
#define OFFER_ROTATEARRAY_H

#include <vector>

/**
 * rotate array find the lowest value;
 */

template<class T>
class RotateArray {
public:

    explicit RotateArray(const std::vector<T> &arrays) : m_arrays(arrays) {

    }

    /**
     * get min value
     * @return
     */
    T getMinValue() {
        if (m_arrays.empty()) {
            return T();
        }

        auto beginPtr = m_arrays.begin();
        auto endPtr = m_arrays.end();
        auto midPtr = beginPtr;

        while (*beginPtr >= *endPtr) {
            if (endPtr - beginPtr == 1) {
                midPtr = endPtr;
                break;
            }

            //midPtr = (beginPtr + endPtr) / 2;
            midPtr = beginPtr + ((endPtr - m_arrays.begin()) + (beginPtr - m_arrays.begin())) / 2;

            if(*beginPtr == *endPtr && *beginPtr == *midPtr && *midPtr == *endPtr)
            {
                return minInOrder(m_arrays, (beginPtr-m_arrays.begin()), (endPtr - m_arrays.begin()));
            }

            if(*midPtr >= *beginPtr)
            {
                beginPtr = midPtr;
            }

            if(*midPtr <= *endPtr)
            {
                endPtr = midPtr;
            }
        }

        return *midPtr;
    }

private:

    T minInOrder(const std::vector<T>& numbers, int index1, int index2) {
        T result = numbers[index1];
        for (int i = index1 + 1; i <= index2; ++i) {
            if (result > numbers[i])
                result = numbers[i];
        }
        return result;
    }

private:
    std::vector<T> m_arrays;
};

#endif //OFFER_ROTATEARRAY_H
