//
// Created by Yu Jun on 12/03/16.
//

#ifndef UTILIS_THREADPOOL_H
#define UTILIS_THREADPOOL_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

namespace utils {

    class Thread {
    private:
        int m_errorCode;
        //Semaphore m_threadSemaphore;

    };

    /**
     * Thread Job
     */
    class ThreadJob {
    private:
        int m_jobNo;
        char *m_jobName;
        Thread *m_workThread;
    public:
        ThreadJob();

        virtual ~ThreadJob();

        int getJobNo() const {
            return m_jobNo;
        }

        void setJobNo(int m_jobNo) {
            ThreadJob::m_jobNo = m_jobNo;
        }

        char *getJobName() const {
            return m_jobName;
        }

        void setJobName(char *jobName);

        Thread *getWorkThread() const {
            return m_workThread;
        }

        void setWorkThread(Thread *m_workThread) {
            ThreadJob::m_workThread = m_workThread;
        }

        virtual void run(void* ptr) = 0;

    };


    /**
     * Thread Pool
     */

    class ThreadPool {

    };

}

#endif //UTILIS_THREADPOOL_H
