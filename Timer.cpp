//
// Created by jaxo on 29/09/21.
//

#include "Timer.h"

void Timer::startTimer() {
    if(o.getSecondi() != 0)
        o.setSecondi(o.getSecondi() - 1);
    else{
        if (o.getMinuti() != 0) {
            o.setMinuti(o.getMinuti() - 1);
            o.setSecondi(59);
        }else{
            if (o.getOre() != 0){
                o.setOre(o.getOre() - 1);
                o.setMinuti(59);
            }
        }
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
