//
// Created by jaxo on 29/09/21.
//

#include "TimerObserver.h"

TimerObserver::TimerObserver(Timer* t) {
    subject = t;
    subject->subscribeObserver(this);
}

TimerObserver::~TimerObserver() {
    subject->unsubscribeObserver(this);
    delete subject;
}

void TimerObserver::update() {
    oraTimer = subject->getO();
    oraStringTimer = oraTimer.oraToString();
}


