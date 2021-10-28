//
// Created by jaxo on 29/09/21.
//

#ifndef ELABORATOTIMER__TIMER_H
#define ELABORATOTIMER__TIMER_H

#include <unistd.h>
#include "Ora.h"
#include "Observer.h"
#include "Subject.h"
#include <list>

class Timer : public Subject{
public:
    explicit Timer(): ora(10){}

    ~Timer() override = default;

    void setTimer(int o, int m, int s);

    void startTimer();

    int getOraTimer();

    int getMinutoTimer();

    int getSecondiTimer();

    void subscribeObserver(Observer* o) override;

    void unsubscribeObserver(Observer* o) override;

    void notify() override;

private:
   Ora ora;
   std::list<Observer*> observers;
};

#endif //ELABORATOTIMER__TIMER_H
