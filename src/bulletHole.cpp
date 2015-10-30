//
//  bulletHole.cpp
//  sequence
//
//  Created by stephanie wolff on 10/29/15.
//
//

#include "bulletHole.hpp"

BulletHole::BulletHole(){
    bulletHole.loadImage("bullethole1.png");
}

void BulletHole::setup(int period, int increment){
    ourPeriod = period;
    ourIncrement = increment;
}

void BulletHole::add(int instrument){
    positions.push_back(0);
    instruments.push_back(instrument);
}

void BulletHole::draw(int time){

    for ( int i = 0; i < positions.size(); i ++){
        int thisPosition = positions[i];
        bulletHole.draw(instruments[i] * 150, thisPosition);
        thisPosition = thisPosition - ourIncrement;
        if (thisPosition  < -ourPeriod/2){
            thisPosition += ourPeriod;
        }
        positions[i] = thisPosition;
    }
}


