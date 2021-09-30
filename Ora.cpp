//
// Created by jaxo on 28/09/21.
//

#include "Ora.h"

void Ora::setOraAttuale() {
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);
    setSecondi(now->tm_sec);
    setMinuti(now->tm_min);
    setOre(now->tm_hour);
}

std::string Ora::oraToString() const{
    std::string controlloOra, oraString;
    switch (visualizzazione) {
        case 1:
            controlloOra = std::to_string(ore);
            oraString += (controlloOra.length() == 1) ? ('0'+controlloOra) : controlloOra;
            controlloOra = ":" + std::to_string(minuti);
            oraString += (controlloOra.length() == 1) ? ('0'+controlloOra) : controlloOra;
            controlloOra = ":" + std::to_string(secondi);
            oraString += (controlloOra.length() == 1) ? ('0'+controlloOra) : controlloOra;
            break;
        case 2:
            oraString += std::to_string(ore) + " ore ";
            oraString += std::to_string(minuti) + " minuti ";
            oraString += std::to_string(secondi) + " secondi";
            break;
        default:
            controlloOra = std::to_string(ore);
            oraString += (controlloOra.length() == 1) ? ('0'+controlloOra) : controlloOra;
            controlloOra = "." + std::to_string(minuti);
            oraString += (controlloOra.length() == 1) ? ('0'+controlloOra) : controlloOra;
            break;
    }
    return oraString;
}
