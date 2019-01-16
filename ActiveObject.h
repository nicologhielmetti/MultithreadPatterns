/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ActiveObject.h
 * Author: nicolo
 *
 * Created on January 9, 2019, 5:21 PM
 */

#ifndef ACTIVEOBJECT_H
#define ACTIVEOBJECT_H

#include <thread>
#include <atomic>

class ActiveObject {
public:
    ActiveObject();
    virtual ~ActiveObject();
private:
    virtual void run();
    ActiveObject& operator=(const ActiveObject& ao) = delete;
    ActiveObject(const ActiveObject& orig) = delete;
protected:
    std::thread t;
    std::atomic<bool> quit;
};

#endif /* ACTIVEOBJECT_H */

