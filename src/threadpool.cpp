//
// Created by Yu Jun on 12/03/16.
//

#include "../include/threadpool.h"
#include <string.h>

namespace utils {

    ThreadJob::ThreadJob() {
        m_jobName = NULL;
        m_jobNo = 0;
        m_workThread = NULL;
    }

    ThreadJob::~ThreadJob() {
        if(NULL != m_jobName){
            free(m_jobName);
        }
    }

    void ThreadJob::setJobName(char *jobName) {
        if(NULL != m_jobName){
            free(m_jobName);
            m_jobName = NULL;
        }

        if(NULL != jobName){
            m_jobName = (char*) malloc(strlen(jobName) + 1);
            strcpy(m_jobName,jobName);
        }
    }
}

