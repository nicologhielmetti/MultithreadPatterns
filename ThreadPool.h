/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ThreadPool.h
 * Author: nicolo
 *
 * Created on January 10, 2019, 11:51 AM
 */

#ifndef THREADPOOL_H
#define THREADPOOL_H

#include "PriorityQueueN.h"
#include <functional>
#include <atomic>
#include <vector>
#include <thread>


class ThreadPool {
public:
    ThreadPool(unsigned int);
    void pushTask(std::function<void ()>, unsigned int);
    virtual ~ThreadPool();
private:
    PriorityQueueN tasks;
    std::vector<std::thread> threads;
    std::atomic<bool> quit;
    virtual void run();
    unsigned int thread_count;
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool& tp) = delete;
};

#endif /* THREADPOOL_H */

