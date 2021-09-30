//
// Created by jaxo on 28/09/21.
//

#include "Data.h"

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

