//
// Created by SuperMiao on 2018/10/10.
//

#ifndef OFFER_C0XDEFAULT_H
#define OFFER_C0XDEFAULT_H

class OagAvsQuery
{
public:
    OagAvsQuery() = default;

    int m_value = 1;
};

class OagAvsMode
{
public:
    OagAvsMode();

    OagAvsMode(int a)
    {
        std::cout << "[OagAvsMode] a constructor" << std::endl;
        m_query = new OagAvsQuery();
    }


    ~OagAvsMode()
    {
        delete m_query;
    }

    int getValue() const
    {
        return m_query->m_value;
    }

private:

    OagAvsQuery* m_query;
};

OagAvsMode::OagAvsMode()
{
    std::cout << "[OagAvsMode] constructor" << std::endl;
    m_query = new OagAvsQuery();
}

class OagAvs
{
public:
    OagAvs() = default;

    int value() const
    {
        return m_mode.getValue();
    }
private:
    OagAvsMode m_mode;
};

#endif //OFFER_C0XDEFAULT_H
