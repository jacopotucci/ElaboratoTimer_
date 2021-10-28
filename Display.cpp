//
// Created by jaxo on 30/09/21.
//

#include "Display.h"

Display::Display(Timer *tm) : subject(tm) {
    min = sec = ore = 0;
    data = Data();
    ora = Ora();
    info = fine = false;
    Display::attach();
}
Display::~Display() {
    Display::detach();
}

void Display::inizio() {
    initscr();

    keypad(stdscr, true);
    nodelay(stdscr, true);

    do{
        aggiornaDisplay();
    } while (!fine);

    endwin();
}

void Display::aggiornaDisplay() {
    prendiTasto();
    erase();
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



