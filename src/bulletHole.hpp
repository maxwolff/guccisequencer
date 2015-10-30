//
//  bulletHole.hpp
//  sequence
//
//  Created by stephanie wolff on 10/29/15.
//
//
#ifndef bullethole_h
#define bullethole_h

#include "ofMain.h"
#include <vector>

class BulletHole {
public:
    // Constructor
    BulletHole();
    //    ~Beat();
    void setup(int period, int increment);
    void add(int instrument);
    void draw(int time);
    int ourPeriod;
    int ourIncrement;
    vector <int> positions;
    ofImage bulletHole;
    vector <int> instruments;
};
#endif