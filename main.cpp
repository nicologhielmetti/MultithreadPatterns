/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nicolo
 *
 * Created on January 9, 2019, 5:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <string>

#include "ThreadPool.h"

using namespace std;

ThreadPool tp(0); //0 threads --> maximum you can get from your architecture;
mutex m;
                   
void writeToCout(const unsigned int& priority)
{
    lock_guard<mutex> l(m);
    cout << "Priority --> " << priority << " ==> tid --> " << this_thread::get_id() << endl;
}

int main() {
    
    tp.pushTask(bind(writeToCout,2),2);
    tp.pushTask(bind(writeToCout,1),1);
    tp.pushTask(bind(writeToCout,0),0);
    this_thread::sleep_for(5s);
      
    return 0;
}