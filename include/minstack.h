//
// Created by SuperMiao on 2018/9/15.
//

#ifndef OFFER_MINSTACK_H
#define OFFER_MINSTACK_H

#include <stack>

template <typename T>
class MinStack{
public:

    MinStack() = default;

    T pop()
    {
        if(m_elements.empty())
        {
            return T();
        }

        m_minData.pop();
        T t = m_elements.top();
        m_elements.pop();
        return t;
    }

    void push(const T& t)
    {
        if(!t)
        {
            return ;
        }

        if(m_elements.empty())
        {
            m_elements.push(t);
            m_minData.push(t);
        }
        else
        {
            T curMinValue = m_minData.top();
            m_elements.push(t);

            if(t < curMinValue)
            {
                m_minData.push(t);
            }
            else
            {
                m_minData.push(curMinValue);
            }
        }
    }

    T min()
    {
        if(m_minData.empty())
        {
            return T();
        }

        return m_minData.top();
    }

private:
    std::stack<T> m_elements;
    std::stack<T> m_minData;
};
#endif //OFFER_MINSTACK_H
