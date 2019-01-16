/*
 * It does not work properly... Just a tentative! :)
 */

/* 
 * File:   PriorityQueue.h
 * Author: nicolo
 *
 * Created on January 14, 2019, 12:13 AM
 */

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "SyncronizedQueue.h"
#include <list>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <map>

using namespace std;

template<typename T>
class PriorityQueueK {
public:
    PriorityQueueK(unsigned int n_priorities)
    {    
        if(n_priorities > 0)
        {
            lock_guard<mutex> l(m);
            priority_levels = n_priorities;
        }
    };
    
    auto getPriorities()
    {
        lock_guard<mutex> l(m);
        return priority_levels;
    }
    
    auto getPriorityQueueSize(auto priority)
    {
        if(priority < 0 || priority >= getPriorities()) return -1;
        {
            lock_guard<mutex> l(m);
            return queue[priority].size();
        }
    }
    
    void pushAt(const T& t, auto priority){
        if(priority < 0 || priority >= getPriorities()) return;
        {
            queue[priority].push_back(t);
            cv.notify_one();
        }
    }
    
    T getMaxPriorityTask(){
        unique_lock<mutex> lck(m);
        while(queue.empty()) cv.wait(lck);
        list<T> l = (*queue.begin()).second;
        T t = l.front();
        l.pop_front();
        return t;
    }
    
    
    
private:
    map<unsigned int,list<T>> queue;
    unsigned int priority_levels;
    mutex m;
    condition_variable cv;
    PriorityQueueK(const PriorityQueueK& pq) = delete;
    PriorityQueueK& operator=(const PriorityQueueK& pq) = delete;
};

#endif /* PRIORITYQUEUE_H */

