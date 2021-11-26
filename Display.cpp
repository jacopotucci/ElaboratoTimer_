//
// Created by jaxo on 30/09/21.
//

#include "Display.h"

Display::Display(Timer *tm) : subject(tm) {
    min = sec = ore = 0;
    data = Data();
    ora = Ora();
    thread = new ThreadClass(subject);
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
    istruzioniWindow = newwin(altezza, larghezza, (altezzaTerminale-altezza*2)/2 + altezza, (larghezzaTerminale - larghezza*3)/2 + 2*larghezza - altezza);
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

    update();
    oraTimerToString();

    mvwprintw(oraWindow, 5, (larghezza - oraString.length())/2 - 1, &oraString[0]);
    mvwprintw(dataWindow, 5, (larghezza - dataString.length())/2 - 1, &dataString[0]);
    mvwprintw(timerWindow, 5, (larghezza - timerString.length())/2 - 1, &timerString[0]);


    if(info){
        stampaInformazioni();
    }else
        mvwprintw(istruzioniWindow, 0, 1, "Premi per istruzioni");

    wrefresh(timerWindow);
    wrefresh(oraWindow);
    wrefresh(dataWindow);
    wrefresh(istruzioniWindow);

    napms(50);
}

void Display::prendiTasto() {
    int tasto = getch();

    switch (tasto) {
        case 27:
            fine = true;
            break;
        case 'i':
            if(!info)
                info = true;
            else
                info = false;
            break;
        case 'd':
            data.setVisualizzazione((data.getVisualizazzione()+1)%3);
            break;
        case 'o':
            ora.setVisualizzazione((ora.getVisualizzazione()+1)%3);
            break;
        case 't':
            thread->startTimer();
            break;
        case 's':
            thread->stopTimer();
            break;
        default:
            break;
    }
}

void Display::stampaInformazioni() {
    mvwprintw(istruzioniWindow, 0, 1, "Start");
}

void Display::oraTimerToString() {
    timerString = std::to_string(ore);
    timerString += ":" + std::to_string(min);
    timerString += ":" + std::to_string(sec);
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


