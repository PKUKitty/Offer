//
// Created by zhangmiao on 2018/9/3.
//

#ifndef OFFER_FABONACCI_H
#define OFFER_FABONACCI_H

class Fabonacci
{
public:

    static long fibonacci(int n)
    {
        if(n <= 0)
        {
            return 0;
        }

        if(n == 1 || n == 2)
        {
            return 1;
        }

        //n-2
        long prepre = 1l;
        //n-1
        long pre = 1l;
        //current fibonacci
        long current = 2l;

        for(int i = 3; i <= n; ++i)
        {
            current = pre + prepre;
            prepre = pre;
            pre = current;
        }
        return current;
    }



    static long fibonacci2(int n)
    {
        if(n <= 0)
        {
            return 0;
        }

        if(n == 1 || n == 2)
        {
            return 1;
        }

        return fibonacci2(n - 1) + fibonacci2(n - 2);
    }

    static long frogStep(int n)
    {
        if(n == 1)
        {
            return 1;
        }

        if(n == 2 )
        {
            return 2;
        }

        return frogStep(n-1) + frogStep(n-2);
    }

};


#endif //OFFER_FABONACCI_H
