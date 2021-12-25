//
// Created by jaxo on 29/09/21.
//

#include "Timer.h"

void Timer::setTimer(int o, int m, int s) {
    ora.setOre(o);
    ora.setMinuti(m);
    ora.setSecondi(s);
}

void Timer::setStop(bool s) {
    Timer::stop = s;
}

void Timer::startTimer() {
    while (ora.getSecondi() > 0 && !stop){
        sleep(1);
        notify();
        ora.setSecondi(ora.getSecondi() - 1);
        if (ora.getSecondi() == 0){
            sleep(1);
            notify();
        }
        else if (ora.getSecondi() == 0 && ora.getMinuti() != 0){
            ora.setSecondi(59);
            ora.setMinuti(ora.getMinuti() - 1);
        }
        else if(ora.getMinuti() == 0 && ora.getSecondi() == 0 && ora.getOre() != 0){
            ora.setMinuti(59);
            ora.setSecondi(59);
            ora.setOre(ora.getOre() - 1);
        }
    }
}

int Timer::getOraTimer() {
    return ora.getOre();
}

int Timer::getMinutoTimer() {
    return ora.getMinuti();
}

int Timer::getSecondiTimer() {
    return ora.getSecondi();
}

void Timer::subscribeObserver(Observer *o) {
    observers.push_back(o);
}

void Timer::unsubscribeObserver(Observer *o) {
    observers.remove(o);
}

void Timer::notify() {
    for (auto& elem : observers)
        elem->update();
}
