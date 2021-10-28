//
// Created by jaxo on 30/09/21.
//

#ifndef ELABORATOTIMER__DISPLAY_H
#define ELABORATOTIMER__DISPLAY_H

#include "Timer.h"
#include "Data.h"
#include "Observer.h"
#include <ncurses.h>

class Display : public Observer{
public:
    explicit Display(Timer* tm);

    ~Display() override;

    void inizio();

    void aggiornaDisplay();

    void prendiTasto();

    void stampaInformazioni();

    void update() override;

    void attach() override;

    void detach() override;

private:
    Data data;
    Ora ora;
    Timer* subject;
    int sec, min, ore;
    bool info, fine;
    int altezza, larghezza, altezzaTerminale, larghezzaTerminale;

    WINDOW* timerWindow = nullptr;
    WINDOW* dataWindow = nullptr;
    WINDOW* oraWindow = nullptr;
    WINDOW* istruzioniWindow = nullptr;
};

#endif //ELABORATOTIMER__DISPLAY_H
