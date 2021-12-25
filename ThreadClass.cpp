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
    timer->setStop(false);
    timerThread = std::thread(&Timer::startTimer, timer);
}

void ThreadClass::stopTimer(){
    timer->setStop(true);
}

void ThreadClass::incrementaTimer(){
    timer->setTimer(0, 0, timer->getSecondiTimer()+1);
}

void ThreadClass::resetTimer(){
    timer->setTimer(0, 0, 10);
}