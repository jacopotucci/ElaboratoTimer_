//
// Created by jaxo on 29/09/21.
//

#include "TimerObserver.h"

TimerObserver::TimerObserver() {
    subject->subscribeObserver(this);
}

TimerObserver::~TimerObserver() {
    subject->unsubscribeObserver(this);
}

void TimerObserver::update() {
    oraTimer = subject->getO();
    oraStringTimer = oraTimer.oraToString();
}

