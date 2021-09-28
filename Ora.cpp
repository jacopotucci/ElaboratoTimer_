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
