//
// Created by jaxo on 28/09/21.
//

#include "Ora.h"

Ora::Ora(int s, int m, int o, int v) {
    visualizzazione = 0;
    if (o < 0 || o > 24)
        throw std::out_of_range("Ora non valida");
    else{
        ore = o;
        if (m < 0 || m > 60)
            throw std::out_of_range("Minuto non valido");
        else{
            minuti = m;
            if (s < 0 || s > 60)
                throw std::out_of_range("Secondo non disponibile");
            else
                secondi = s;
        }
    }
}

int Ora::getSecondi() const {
    return secondi;
}

int Ora::getMinuti() const {
    return minuti;
}

int Ora::getOre() const {
    return ore;
}

int Ora::getVisualizzazione() const {
    return visualizzazione;
}

void Ora::setSecondi(int s) {
    if (s < 0 || s > 60)
        throw std::out_of_range("Secondo non disponibile");
    else
        secondi = s;
}

void Ora::setMinuti(int m) {
    if (m < 0 || m > 60)
        throw std::out_of_range("Minuto non valido");
    else
        minuti = m;
}

void Ora::setOre(int o) {
    if (o < 0 || o > 24)
        throw std::out_of_range("Ora non valida");
    else
        ore = o;
}

void Ora::setVisualizzazione(int v) {
    visualizzazione = v;
}

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
            oraString += (controlloOra.length() == 1) ? ("0"+controlloOra) : controlloOra;
            controlloOra = ":" + std::to_string(minuti);
            oraString += (controlloOra.length() == 1) ? ("0"+controlloOra) : controlloOra;
            controlloOra = ":" + std::to_string(secondi);
            oraString += (controlloOra.length() == 1) ? ("0"+controlloOra) : controlloOra;
            break;
        case 2:
            oraString += std::to_string(ore) + " ore ";
            oraString += std::to_string(minuti) + " min ";
            oraString += std::to_string(secondi) + " sec";
            break;
        default:
            controlloOra = std::to_string(ore);
            oraString += (controlloOra.length() == 1) ? ("0"+controlloOra) : controlloOra;
            controlloOra = "." + std::to_string(minuti);
            oraString += (controlloOra.length() == 1) ? ("0"+controlloOra) : controlloOra;
            break;
    }
    return oraString;
}

int Ora::turnToSecond() {
    int secondiTotali = secondi;
    secondiTotali += (minuti*60);
    secondiTotali += (ore*60*60);
    return secondiTotali;
}
