//
// Created by jaxo on 29/09/21.
//

#ifndef ELABORATOTIMER__TIMER_H
#define ELABORATOTIMER__TIMER_H

#include "Subject.h"
#include "Ora.h"
#include <thread>
#include <chrono>

class Timer : public Subject{
public:
    explicit Timer(int s = 5) : o(s) {}

    ~Timer() = default;

    void startTimer();

    void notify() override;

    void subscribeObserver(Observer* o) override;

    void unsubscribeObserver(Observer* o) override;

private:
    Ora o;
};


#endif //ELABORATOTIMER__TIMER_H
