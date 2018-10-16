/**
 * Copyright (c) 2018, yujun R&D Department
 * All rights reserved
 * 
 * @file ThreadPool.h
 * @brief 
 * @author yujun@
 * @version 1.0
 * @date 8/23/18 
 **/
#ifndef OFFER_THREADPOOL_H
#define OFFER_THREADPOOL_H

#include <functional>
#include <mutex>
#include <condition_variable>
#include <list>
#include <vector>
#include <thread>

/**
 * @brief thread pool base on C++11 thread
 * usage: ThreadPool threadPool(4);
 *        threadPool.start();
 *        threadPool.append(std::bind(***)); // bind the task function
 *        threadPool.waitAll();
 *        threadPool.stop();
 *        //waitAll() and stop() functions also are called by destructor
 */
class ThreadPool {
 public:
  //task function
  // using ref(**) in std::bind() function if need modify para.
  //eg. threadPool.append(std::bind(&HostAvsTestCase::setSegmentAV, this, ref(seg)));
  using Task = std::function<void(void)>;

  /**
   * @brief initial thread nums.
   *        default is MIN_THREAD_NUMS(4), if input < min or > max, set MIN_THREAD_NUMS
   * @param nThreadNums input nums. [4,16]
   */
  explicit ThreadPool(unsigned nThreadNums = ThreadPool::MIN_THREAD_NUMS);

  /**
   * @brief destructor. wait all threads and stop it.
   */
  ~ThreadPool();

  ThreadPool(const ThreadPool &) = delete;

  ThreadPool &operator=(const ThreadPool &rhs) = delete;

  /**
   * @brief append one task. task is a function like std::function<void(void)>
   *        using std::bind() function to bind a function.
   * @param task eg.***.append(std::bind(&FltAncillary::setCatalog, this, ref(routing)));
   */
  void append(const Task &task);

  /**
   * @brief append one task by std::move.
   * @param task task is a function
   */
  void append(Task &&task);

  /**
   * @brief start m_nThreadNum threads
   * if have task. someone thread get the front task and do work
   * if no task. wait condition signal
   */
  void start();

  /**
   * @brief wait all threads finish worker
   */
  void waitAll();

  /**
   * @brief stop all threads.
   * 1.condition notify all threads
   * 2.join all threads
   */
  void stop();

 private:

  /**
   * @brief thread worker function;
   * if receive the condition, someone thread will get the front task and do it
   */
  void work();

 private:
  static const unsigned MIN_THREAD_NUMS = 4;
  static const unsigned MAX_THREAD_NUMS = 16;
  //thread pool running status
  bool m_bIsRunning;
  //thread pool thread num
  unsigned m_nThreadNum;
  // thread mutex
  std::mutex m_mutex;
  //task control condition
  std::condition_variable m_taskCond;
  //finish status control condition
  std::condition_variable m_finishCond;
  //task number
  unsigned m_nTaskNum;
  //tasks list
  std::list<Task> m_tasks;
  //all threads vector
  std::vector<std::shared_ptr<std::thread>> m_vThreads;
};

#endif //OFFER_THREADPOOL_H
