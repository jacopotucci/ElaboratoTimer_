//
// Created by jaxo on 28/09/21.
//

#include "Data.h"

Data::Data(int g, int m, int a, int v) {
    visualizzazione = v;
    if(a < 0 || a > 9999)
        throw std::out_of_range("Anno non valido");
    else{
        anni = a;
        if (m < 0 || m > 12)
            throw std::out_of_range("Mese non disponibile");
        else{
            mesi = m;
            if (g < 0)
                throw std::out_of_range("Giorno non valido");
            else{
                controlloGiorno(g);
                giorni = g;
            }
        }
    }
}

void Data::controlloGiorno(int g) {
    switch (mesi) {
        case 2:
            if (g > 29 || ((anni % 400) != 0 && g > 28))
                throw std::out_of_range("Giorno non valido");
            else
                giorni = g;
        case 4:
        case 6:
        case 9:
        case 11:
            if (g > 30)
                throw std::out_of_range("Giorno non valido");
            else
                giorni = g;
        default:
            if (g > 31)
                throw std::out_of_range("Giorno non valido");
    }
}

int Data::getGiorni() const {
    return giorni;
}

int Data::getMesi() const {
    return mesi;
}

int Data::getAnni() const {
    return anni;
}

void Data::setGiorni(int g) {
    controlloGiorno(g);
}

void Data::setMesi(int m) {
    if (m > 12 || m < 0)
        throw std::out_of_range("Mese non valido");
    else
        mesi = m;
}

void Data::setAnni(int a) {
    if (a > 9999 || a < 0)
        throw std::out_of_range("Anno non valido");
    else
        anni = a;
}

void Data::setDataAttuale() {
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);
    setGiorni(now->tm_mday);
    setMesi(now->tm_mon);
    setAnni(now->tm_year + 1900);
}

std::string Data::dataToString() const{
    std::string controlloData, dataString;
        switch (visualizzazione) {
            case 1:
                // giorni settimana, mesi scritti
                break;
            case 2:
                dataString += " giorno: " + std::to_string(giorni);
                dataString += " mese: " + std::to_string(mesi);
                dataString += " anno: " + std::to_string(anni);
                break;
            default:
                controlloData = std::to_string(giorni);
                dataString += (controlloData.length() == 1) ? ('0'+controlloData) : controlloData;
                controlloData = " / " + std::to_string(mesi);
                dataString += (controlloData.length() == 1) ? ('0'+controlloData) : controlloData;
                dataString += " / " + std::to_string(anni);
                break;
        }
        return dataString;
}

