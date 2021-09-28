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
