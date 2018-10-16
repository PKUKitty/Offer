//
// Created by Yu Jun on 01/04/16.
//

#include "simplethread.h"
#include "ThreadPool.h"
#include <gtest/gtest.h>

class SetAv
{
 public:
    void setAv(int& idx)
    {
      ++idx;
      std::cout <<"pid"<<getpid()<< "set av: " << idx << std::endl;
    }
};


TEST(test, thread_pool_test)
{
    //threadPool.append(std::bind(&HostAvsTestCase::setSegmentAV, this, ref(seg)));
    SetAv sa;
    int idx=0;
    ThreadPool threadPool(4);
    threadPool.start();
    threadPool.append(std::bind(&SetAv::setAv, sa, std::ref(idx))); // bind the task function
    threadPool.waitAll();
    threadPool.stop();
    //waitAll() and stop() functions also are called by destructor
    EXPECT_EQ(idx, 5);
}

TEST(test, test_tuple)
{
    std::tuple<int, int, const char*> tp = std::make_tuple(1, 2, "123");
    int a = 0;
    int b = 0;
    const char* c = nullptr;
    std::tie(a, b, c) = tp;
    EXPECT_EQ(1, a);
    EXPECT_EQ(2, b);
    EXPECT_EQ("123", c);
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
