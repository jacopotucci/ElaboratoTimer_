//
// Created by jaxo on 30/09/21.
//

#include "Display.h"

Display::Display(Timer *tm) : subject(tm) {
    min = sec = ore = 0;
    data = Data();
    ora = Ora();
    info = fine = false;
    altezza = larghezza = altezzaTerminale = larghezzaTerminale = 0;
    Display::attach();
}
Display::~Display() {
    Display::detach();
}

void Display::inizio() {
    initscr();
    curs_set(0);

    keypad(stdscr, true);
    nodelay(stdscr, true);

    altezzaTerminale = getmaxy(stdscr);
    larghezzaTerminale = getmaxx(stdscr);
    altezza = 10;
    larghezza = 27;

    timerWindow = newwin(altezza, larghezza, (altezzaTerminale-altezza*2)/2, (larghezzaTerminale - larghezza*3)/2 + 2*larghezza - altezza);
    oraWindow = newwin(altezza, larghezza, (altezzaTerminale-altezza*2)/2, (larghezzaTerminale- larghezza*3)/2 + 2);
    dataWindow = newwin(altezza, larghezza, (altezzaTerminale - altezza*2)/2 + altezza, (larghezzaTerminale- larghezza*3)/2 + 2);
    refresh();

    do{
        aggiornaDisplay();
    } while (!fine);

    endwin();
}

void Display::aggiornaDisplay() {
    prendiTasto();
    erase();

    werase(timerWindow);
    werase(oraWindow);
    werase(dataWindow);
    wborder(timerWindow, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(oraWindow, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(dataWindow, 0, 0, 0, 0, 0, 0, 0, 0);

    mvwprintw(timerWindow, 2, 10, "TIMER");
    mvwprintw(oraWindow, 2, 10, "ORA");
    mvwprintw(dataWindow, 2, 10, "DATA");

    ora.setOraAttuale();
    oraString = ora.oraToString();

    data.setDataAttuale();
    dataString = data.dataToString();

    napms(50);
}

void Display::prendiTasto() {
    int tasto = getch();

    switch (tasto) {
        case 27:
            fine = true;
            break;
        default:
            break;
    }
}

void Display::stampaInformazioni() {

}

void Display::attach() {
    subject->subscribeObserver(this);
}

void Display::detach() {
    subject->unsubscribeObserver(this);
}

void Display::update() {
    this->sec = subject->getSecondiTimer();
    this->min = subject->getMinutoTimer();
    this->ore = subject->getOraTimer();
}



