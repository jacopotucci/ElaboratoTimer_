//
// Created by jaxo on 29/09/21.
//

#include "Timer.h"

Timer::Timer(int s) {
    o = Ora(s);
    observer = nullptr;
}
Timer::~Timer() {
    delete observer;
}

void Timer::decr() {
        if (o.getSecondi() != 0)
            o.setSecondi(o.getSecondi() - 1);
        else {
            if (o.getMinuti() != 0) {
                o.setMinuti(o.getMinuti() - 1);
                o.setSecondi(59);
            } else {
                if (o.getOre() != 0) {
                    o.setOre(o.getOre() - 1);
                    o.setMinuti(59);
                }
            }
        }
        notify();
}

void Timer::start(){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::thread t(&Timer::start, this);
    t.join();
}

void Timer::notify() {
    observer->update();
}

void Timer::subscribeObserver(Observer *newObserver) {
    observer = newObserver;
}

void Timer::unsubscribeObserver(Observer *oldObserver) {
    delete observer;
}

std::string Timer::getStringTimer() const {
    std::string stringTimer = o.oraToString();
    return stringTimer;
}



