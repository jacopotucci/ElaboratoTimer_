//
// Created by jaxo on 29/09/21.
//

#ifndef ELABORATOTIMER__TIMEROBSERVER_H
#define ELABORATOTIMER__TIMEROBSERVER_H

#include "Observer.h"
#include <string>
#include "Timer.h"

class TimerObserver : public Observer{
public:
    TimerObserver();

    ~TimerObserver() override;

    void update() override;

    const std::string &getOraStringTimer() const { return oraStringTimer; }

private:
    Timer* subject;
    Ora oraTimer;
    std::string oraStringTimer;

};


#endif //ELABORATOTIMER__TIMEROBSERVER_H
