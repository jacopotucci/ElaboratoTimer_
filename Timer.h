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
    explicit Timer(int s = 5);

    ~Timer() override;

    void startTimer();

    std::string getStringTimer() const;

    const Ora &getO() const { return o; }

    void notify() override;

    void subscribeObserver(Observer* newObserver) override;

    void unsubscribeObserver(Observer* oldObserver) override;

private:
    Ora o;
    Observer* observer;
};


#endif //ELABORATOTIMER__TIMER_H
