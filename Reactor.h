/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reactor.h
 * Author: nicolo
 *
 * Created on January 9, 2019, 6:34 PM
 */

#ifndef REACTOR_H
#define REACTOR_H

#include "SyncronizedQueue.h"
#include "ActiveObject.h"
#include <functional>

class Reactor : public ActiveObject {
public:
    Reactor(){};
    void addTask(std::function<void ()> f);
    virtual ~Reactor();
private:
    void run();
    Reactor(const Reactor& orig) = delete;
    Reactor& operator=(const Reactor& orig) = delete;
    SynchronizedQueue<function<void ()>> tasks;
};

#endif /* REACTOR_H */

