//
// Created by jaxo on 29/09/21.
//

#ifndef ELABORATOTIMER__OBSERVER_H
#define ELABORATOTIMER__OBSERVER_H

#include "Subject"

class Observer {
public:
    virtual void update() = 0;
};


#endif //ELABORATOTIMER__OBSERVER_H
