//
// Created by jaxo on 29/09/21.
//

#include "ThreadClass.h"


ThreadClass::ThreadClass(Timer* t)  {
    timer = t;
}

ThreadClass::~ThreadClass() {
    delete timer;
}

void ThreadClass::startTimer() {
    timerThread = std::thread(&Timer::startTimer, timer);
}

void::ThreadClass::stopTimer(){
    timer->setStop(true);
}
