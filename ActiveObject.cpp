/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ActiveObject.cpp
 * Author: nicolo
 * 
 * Created on January 9, 2019, 5:21 PM
 */

#include "ActiveObject.h"

#include<functional>

using namespace std;

ActiveObject::ActiveObject(): quit(false), t(&ActiveObject::run,this) {}

void ActiveObject::run(){
    while(quit.load())
    {
        
    }
}

ActiveObject::~ActiveObject() {
    if(quit.load()) return;
    quit.store(true);
    t.join();
}


