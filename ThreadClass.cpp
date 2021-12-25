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
    if (timer->getSecondiTimer() != 59)
        timer->setSecondiTimer(timer->getSecondiTimer()+1);
    else if(timer->getSecondiTimer() == 59 && timer->getMinutoTimer() != 59) {
        timer->setSecondiTimer(0);
        timer->setMinutiTimer(timer->getMinutoTimer() + 1);
    }else{
        timer->setMinutiTimer(0);
        timer->setOreTimer(timer->getOraTimer()+1);
    }
}

void ThreadClass::resetTimer(){
    timer->setTimer(0, 0, 10);
}