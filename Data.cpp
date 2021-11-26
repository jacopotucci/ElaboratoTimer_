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

int Data::getVisualizazzione() const{
    return visualizzazione;
}

void Data::setGiorni(int g) {
    controlloGiorno(g);
    giorni = g;
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

void Data::setVisualizzazione(int v) {
    Data::visualizzazione = v;
}

std::string Data::giornoEMeseAttualeToString() const{
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);
    std::string giornoEMese;
    switch (now->tm_wday) {
        case 1:
            giornoEMese += "Lunedi'";
            break;
        case 2:
            giornoEMese += "Martedi'";
            break;
        case 3:
            giornoEMese += "Mercoledi'";
            break;
        case 4:
            giornoEMese += "Giovedi''";
            break;
        case 5:
            giornoEMese += "Venerdi";
            break;
        case 6:
            giornoEMese += "Sabato";
            break;
        default:
            giornoEMese += "Domenica";
            break;
    }
    giornoEMese += " " + std::to_string(now->tm_mday);
    switch (now->tm_mon){
        case 0:
            giornoEMese += " Gennaio";
            break;
        case 1:
            giornoEMese += " Febbraio";
            break;
        case 2:
            giornoEMese += " Marzo";
            break;
        case 3:
            giornoEMese += " Aprile";
            break;
        case 4:
            giornoEMese += " Maggio";
            break;
        case 5:
            giornoEMese += " Giugno";
            break;
        case 6:
            giornoEMese += " Luglio";
            break;
        case 7:
            giornoEMese += " Agosto";
            break;
        case 8:
            giornoEMese += " Settembre";
            break;
        case 9:
            giornoEMese += " Ottobre";
            break;
        case 10:
            giornoEMese += " Novembre";
            break;
        case 11:
            giornoEMese += " Dicembre";
            break;
    }
    return giornoEMese;
}

std::string Data::dataToString() const{
    std::string controlloData , dataString;
        switch (visualizzazione) {
            case 1:
                dataString += giornoEMeseAttualeToString();
                dataString += " " + std::to_string(anni);
                break;
            case 2:
                dataString += std::to_string(mesi);
                dataString += "." + std::to_string(giorni);
                dataString += "." + std::to_string(anni);
                break;
            default:
                controlloData = std::to_string(giorni);
                dataString += (controlloData.length() == 1) ? ("0"+controlloData) : controlloData;
                controlloData = " / " + std::to_string(mesi);
                dataString += (controlloData.length() == 1) ? ("0"+controlloData) : controlloData;
                dataString += " / " + std::to_string(anni);
                break;
        }
        return dataString;
}

