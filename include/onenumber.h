//
// Created by Yu Jun on 05/09/2018.
//

#ifndef UTILI_ONENUMBER_H
#define UTILI_ONENUMBER_H

class OneNumber
{
public:
    static unsigned numberOfOne(int n)
    {
        unsigned count = 0;

        while (n != 0)
        {
            count++;

            n = (n-1) & n;
        }

        return count;
    }

};

class Power
{
public:
    static double power(double base, long exponent)
    {
        if(base == 0 && 0 == exponent)
        {
            return 0;
        }


        if(exponent == 0)
        {
            return 1;
        }

        long exp = exponent;
        if(exp < 0)
        {
            exp = -exp;
        }

        double result = powerOfUnsigned(base, exp);

        if(exponent < 0)
        {
            result = 1/ result;
        }
        return result;
    }

    static double powerOfUnsigned(double base, long exponent)
    {
        if(exponent == 0)
        {
            return 1;
        }

        if(exponent == 1)
        {
            return base;
        }

        double result = powerOfUnsigned(base, exponent >> 1);

        result = result * result;

        if(exponent % 2 != 0)
        {
            result *= base;
        }

        return result;
    }
};


#endif //UTILI_ONENUMBER_H
