/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PriorityQueueN.cpp
 * Author: nicolo
 * 
 * Created on January 16, 2019, 2:18 AM
 */

#include "PriorityQueueN.h"

void PriorityQueueN::pushTask(const Task& t){
    std::lock_guard<std::mutex> l(m);
    if(tasks.empty()) {
        tasks.push_back(t);
        cv.notify_one();
        return;
    }
    for(auto it = tasks.begin(); it != tasks.end(); it++)
        if(*it >= t){
            tasks.insert(it, t);
            cv.notify_one();
            return;
        }
    tasks.push_back(t);
    cv.notify_one();

}

Task PriorityQueueN::getMaxPriorityTask(){
    std::unique_lock<std::mutex> l(m);
    while(tasks.empty()) cv.wait(l);
    Task t = tasks.front();
    tasks.pop_front();
    return t;
}

