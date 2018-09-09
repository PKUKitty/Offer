/**
 * Copyright (c) 2018, Travelsky R&D Department
 * All rights reserved
 * 
 * @file link.cpp
 * @brief 
 * @author yujun@
 * @version 1.0
 * @date 18-9-7 
 **/

#include <gtest/gtest.h>
#include "link.h"
#include <iostream>

using std::ostream;

TEST(link, link_function)
{
  auto node1 = new Node(1, nullptr);
  node1->next = new Node(2, nullptr);
  node1->next->next = new Node(3, nullptr);
  node1->next->next->next = new Node(4, nullptr);

  node1 = Link::deleteNode(node1, node1);
  Link::printLink(node1);
  EXPECT_EQ(2, node1->value);

  Node* head = Link::reverseList(node1);
  Link::printLink(head);
  EXPECT_EQ(4, head->value);

}

struct db_airline
{
    char AIRLINE[4];
    char HOST[4];
    char OTHER[4];

};

ostream& operator<<(ostream& out, const db_airline* airline)
{
    out << "[AIRLINE]:";
    out << airline->AIRLINE << ", ";
    out << airline->HOST << ", ";
    out << airline->OTHER;
    return out;
}

struct db_host
{
    char AIRLINE[4];
    char HOST[4];
    char OTHER[4];
};

ostream& operator<<(ostream& out, const db_host* host)
{
    out << "[HOST]:";
    out << host->AIRLINE << ", ";
    out << host->HOST << ", ";
    out << host->OTHER;
    return out;
}

#define PRINT(T) (std::cout << (T) << std::endl)

typedef std::uint64_t hash_t;

constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;

hash_t hash_(char const* str)
{
    hash_t ret{basis};

    while(*str)
    {
        ret ^= *str;
        ret *= prime;
        str++;
    }
    return ret;
}

constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis)
{
    return *str ? hash_compile_time(str+1, (*str ^ last_value) * prime) : last_value;
}

constexpr std::uint64_t operator "" _hash(char const* p, size_t)
{
    return hash_compile_time(p);
}

GTEST_API_ int main(int argc, char **argv)
{

    const std::string tableName = "HOST";
    switch(hash_(tableName.c_str()))
    {
        case "AIRLINE"_hash:
            std::cout << "AIRLINE"<< std::endl;
            break;
        case "HOST"_hash:
            std::cout << "HOST"<< std::endl;
            break;
        default:
            break;
    }




    db_airline* dbAirline = new db_airline();
    memset(dbAirline, 0, sizeof(*dbAirline));

    strncpy(dbAirline->AIRLINE, "CAA", sizeof(dbAirline->AIRLINE));
    strncpy(dbAirline->HOST, "1EE", sizeof(dbAirline->HOST));
    strncpy(dbAirline->OTHER, "CCC", sizeof(dbAirline->OTHER));

    PRINT(dbAirline);


    db_host* dbHost = new db_host();
    memset(dbHost, 0, sizeof(*dbHost));

    strncpy(dbHost->AIRLINE, "AA", sizeof(dbHost->AIRLINE));
    strncpy(dbHost->HOST, "1A", sizeof(dbHost->HOST));

    PRINT(dbHost);

    delete dbAirline;
    delete dbHost;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
