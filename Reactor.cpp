/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reactor.cpp
 * Author: nicolo
 * 
 * Created on January 9, 2019, 6:34 PM
 */

#include "Reactor.h"

using namespace std;

void doNothing(){}

void Reactor::run(){
    while(!quit.load()){
        tasks.get()();
    }
}

void Reactor::addTask(function<void() > f) {
    tasks.push(f);
}


Reactor::~Reactor() {
    quit.store(true);
    tasks.push(doNothing);
    t.join();
}

