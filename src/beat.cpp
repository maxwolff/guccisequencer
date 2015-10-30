//
//  beat.cpp
//  sequence
//
//  Created by stephanie wolff on 10/29/15.
//
//

#include "beat.hpp"
#include <vector>

Beat::Beat(){
}

void Beat::setup(int period){
    times.assign(period, 0);
}

bool Beat::soundAtTime(int time){
    return times[time] == 1;
}

void Beat::setSound(int time){
    times[time] = 1;
    
}

void Beat::clear(){
    times.clear(); 
}




