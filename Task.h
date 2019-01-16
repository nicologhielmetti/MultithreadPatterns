/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Task.h
 * Author: nicolo
 *
 * Created on January 16, 2019, 2:33 AM
 */

#ifndef TASK_H
#define TASK_H

#include <functional>


class Task{
public:
    //pass the function object calling bind() if the function requires parameters
    Task(const std::function<void ()>& task, const unsigned int& priority)
    {
        this->task = task;
        this->priority = priority;
    }
    Task(){}
    std::function<void ()> getTask(){return task;}
    unsigned int getPriority(){return priority;}
    
    friend bool operator>=(const Task& t0, const Task& t1){return t0.priority >= t1.priority;}
    void operator()(){task();}
    Task& operator=(const Task& t){return *this;}
    
private:
    std::function<void ()> task;
    unsigned int priority;
};

#endif /* TASK_H */

