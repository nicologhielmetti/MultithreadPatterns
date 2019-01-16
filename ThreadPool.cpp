/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ThreadPool.cpp
 * Author: nicolo
 * 
 * Created on January 10, 2019, 11:51 AM
 */

#include <thread>
#include <vector>

#include "ThreadPool.h"

using namespace std;

void nothing(){}

ThreadPool::ThreadPool(unsigned int num_threads): quit(false) {
    if(num_threads > 0)
        thread_count = num_threads;
    else
        thread_count = thread::hardware_concurrency();
    for(int i = 0; i < thread_count; ++i)
        threads.push_back(thread(&ThreadPool::run,this));
}

void ThreadPool::run(){
    while(!quit.load()){
        //this_thread::sleep_for(500ms);
        tasks.getMaxPriorityTask()();
    }
}

void ThreadPool::pushTask(std::function<void ()> t, unsigned int priority) {
    tasks.pushTask(Task(t,priority));
}


ThreadPool::~ThreadPool() {
    quit.store(true);
    for(int i = 0; i < thread_count; i++) pushTask(nothing,0);
    for(auto & t : threads)
        if(t.joinable())
            t.join();
}