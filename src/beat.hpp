#ifndef beat_h
#define beat_h

#include "ofMain.h"
#include <vector>

class Beat {
public:
    // Constructor
    Beat();
//    ~Beat();

    void setup(int period);
    
    // Methods
    void setSound(int time );
    bool soundAtTime(int time);
    vector<int> times;
    void clear(); 
};
#endif