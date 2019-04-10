/**
 * Copyright (c) 2018, yujun R&D Department
 * All rights reserved
 * 
 * @file ThreadPool.cpp
 * @brief 
 * @author yujun@
 * @version 1.0
 * @date 8/23/18 
 **/
#include <iostream>
#include "ThreadPool.h"

ThreadPool::ThreadPool(unsigned nThreadNums) : m_bIsRunning(false), m_mutex(), m_nTaskNum(0)
{
  // set thread num correctly. [MIN_THREAD_NUMS, MAX_THREAD_NUMS]
  unsigned cpuNums = std::thread::hardware_concurrency();
  if (nThreadNums < MIN_THREAD_NUMS || nThreadNums > cpuNums)
  {
    m_nThreadNum = MIN_THREAD_NUMS;
  }
  else
  {
    m_nThreadNum = nThreadNums;
  }
  start();
}

ThreadPool::~ThreadPool()
{
  if (m_bIsRunning)
  {
    waitAll();
    stop();
  }
}

void ThreadPool::append(const ThreadPool::Task& task)
{
  if (m_bIsRunning)
  {
    //lock -> push back the task -> notify someone thread.
    // if have waiting status thread, it will do the worker.
    // else do nothing, just push back.
    std::unique_lock<std::mutex> locker(m_mutex);
    if (m_nTaskNum > UINT32_MAX)
    {
      return;
    }
    ++m_nTaskNum;
    m_tasks.push_back(task);
    m_taskCond.notify_one();
  }
}

void ThreadPool::append(ThreadPool::Task&& task)
{
  if (m_bIsRunning)
  {
    //lock -> push back the task -> notify someone thread.
    // if have waiting status thread, it will do the worker.
    // else do nothing, just push back.
    std::unique_lock<std::mutex> locker(m_mutex);
    ++m_nTaskNum;
    m_tasks.push_back(std::move(task));
    m_taskCond.notify_one();
  }
}

void ThreadPool::start()
{
  if (m_bIsRunning)
  {
    return;
  }
  m_bIsRunning = true;
  m_vThreads.reserve(m_nThreadNum);

  for (int i = 0; i < m_nThreadNum; ++i)
  {
    //push back the thread and bind the work function
    m_vThreads.push_back(std::make_shared<std::thread>(&ThreadPool::work, this));
  }
}

void ThreadPool::waitAll()
{
  std::unique_lock<std::mutex> locker(m_mutex);
  while (m_nTaskNum > 0)
  {
    //wait all threads, util m_finishCond condition notify when m_nTaskNum is zero.
    m_finishCond.wait(locker);
  }
}

void ThreadPool::stop()
{
  {
    std::unique_lock<std::mutex> locker(m_mutex);
    m_bIsRunning = false;
    // MUST set m_bIsRunning = false,
    // when notify all threads, usually, all thread will exit as m_bIsRunning is false;
    m_taskCond.notify_all();
  }

  for (auto& t : m_vThreads)
  {
    if (t->joinable())
    {
      // block and wait for join
      // TODO block
      t->join();
    }
  }
}

void ThreadPool::work()
{
  while (m_bIsRunning)
  {
    // 1. lock
    // 2. wait condition
    // 3. get the front task
    // 4. do task
    // 5. finish status condition
    Task task;
    {
      std::unique_lock<std::mutex> locker(m_mutex);
      if (m_bIsRunning && m_tasks.empty())
      {
        m_taskCond.wait(locker);
      }

      if (!m_tasks.empty())
      {
        task = m_tasks.front();
        m_tasks.pop_front();
      }
    }

    if (task)
    {
      task();
      std::cout <<"[worker::worker] id: " << std::this_thread::get_id() << " do working!" << std::endl;
      //finish status
      {
        std::unique_lock<std::mutex> locker(m_mutex);
        --m_nTaskNum;
        if (m_nTaskNum == 0)
        {
          m_finishCond.notify_all();
        }
      }
    }
  }
}
