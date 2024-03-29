//
// Created by jaxo on 30/09/21.
//

#ifndef ELABORATOTIMER__DISPLAY_H
#define ELABORATOTIMER__DISPLAY_H

#include "ThreadClass.h"
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

    void oraTimerToString();

    void update() override;

    void attach() override;

    void detach() override;

private:
    Data data;
    Ora ora;
    Timer* subject;
    ThreadClass* thread{};
    int sec, min, ore;
    bool info, fine;
    int altezza, larghezza, altezzaTerminale, larghezzaTerminale;
    std::string oraString, dataString, timerString;

    WINDOW* timerWindow = nullptr;
    WINDOW* dataWindow = nullptr;
    WINDOW* oraWindow = nullptr;
    WINDOW* istruzioniWindow = nullptr;
};

#endif //ELABORATOTIMER__DISPLAY_H
