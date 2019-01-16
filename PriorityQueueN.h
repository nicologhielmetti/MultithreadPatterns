/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PriorityQueueN.h
 * Author: nicolo
 *
 * Created on January 16, 2019, 2:18 AM
 */

#ifndef PRIORITYQUEUEN_H
#define PRIORITYQUEUEN_H

#include <list>
#include <functional>
#include <condition_variable>
#include "Task.h"

class PriorityQueueN {
public:
    PriorityQueueN(){};
    void pushTask(const Task& t);
    Task getMaxPriorityTask();
    size_t getSize(){std::lock_guard<std::mutex> l(m);return tasks.size();}
    virtual ~PriorityQueueN(){};
private:
    PriorityQueueN(const PriorityQueueN& orig) = delete;
    PriorityQueueN& operator=(const PriorityQueueN& pq) = delete;
    std::condition_variable cv;
    std::mutex m;
    std::list<Task> tasks;
};

#endif /* PRIORITYQUEUEN_H */

