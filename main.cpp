#include <iostream>
#include "Display.h"
#include "ThreadClass.h"

int main() {

    auto* tt = new Timer();
    auto* d = new Display(tt);

    d->inizio();

    return 0;
}
