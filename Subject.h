//
// Created by jaxo on 29/09/21.
//

#ifndef ELABORATOTIMER__SUBJECT_H
#define ELABORATOTIMER__SUBJECT_H

#include "Observer.h"

class Subject {
public:
    void subscribeObserver(Observer* o) = 0;

    void unsubscribeObserver(Observer* o) = 0;

    void notify() = 0;
};


#endif //ELABORATOTIMER__SUBJECT_H
