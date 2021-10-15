//
// Created by jaxo on 29/09/21.
//

#ifndef ELABORATOTIMER__OBSERVER_H
#define ELABORATOTIMER__OBSERVER_H

#include "Subject.h"

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update() = 0;

    virtual void attach() = 0;

    virtual void detach() = 0;
};


#endif //ELABORATOTIMER__OBSERVER_H
