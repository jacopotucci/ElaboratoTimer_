//
// Created by jaxo on 29/09/21.
//

#ifndef ELABORATOTIMER__THREADCLASS_H
#define ELABORATOTIMER__THREADCLASS_H

#include "Timer.h"
#include <thread>

class ThreadClass{
public:
    explicit ThreadClass(Timer* t);

    ~ThreadClass();

    void startTimer();

    void stopTimer();

private:
    Timer* timer;
    std::thread timerThread;

};

#endif //ELABORATOTIMER__THREADCLASS_H
