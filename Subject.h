//
// Created by jaxo on 29/09/21.
//

#ifndef ELABORATOTIMER__SUBJECT_H
#define ELABORATOTIMER__SUBJECT_H

class Observer;
#include "Observer.h"

class Subject {
public:
    virtual ~Subject() {}

    virtual void subscribeObserver(Observer* o) = 0;

    virtual void unsubscribeObserver(Observer* o) = 0;

    virtual void notify() = 0;
};


#endif //ELABORATOTIMER__SUBJECT_H
