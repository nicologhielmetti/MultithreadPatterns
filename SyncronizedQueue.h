/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SyncronizedQueue.h
 * Author: nicolo
 *
 * Created on January 9, 2019, 6:37 PM
 */

#ifndef SYNCRONIZEDQUEUE_H
#define SYNCRONIZEDQUEUE_H
#include <mutex>
#include <condition_variable>
#include <list>
using namespace std;

template<typename T>
class SynchronizedQueue {
public:
    SynchronizedQueue(){};
    T get()
    {
        unique_lock<mutex> lck(m);
        while(queue.empty()) cv.wait(lck);
        T result = queue.front();
        queue.pop_front();
        return result;
    }
    
    void push(const T& t)
    {
        lock_guard<mutex> lck(m);
        queue.push_back(t);
        cv.notify_one();
    }
    
    size_t getSize()
    {
        lock_guard<mutex> lck(m);
        return queue.size();
    }
    
    virtual ~SynchronizedQueue(){};
private:
    SynchronizedQueue(const SynchronizedQueue& orig) = delete;
    SynchronizedQueue& operator=(const SynchronizedQueue& sq) = delete;
protected:
    list<T> queue;
    mutex m;
    condition_variable cv;
};

#endif /* SYNCHRONIZEDQUEUE_H */



