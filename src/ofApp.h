#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "beat.hpp"
#include "bulletHole.hpp"
#include <iostream>
#include <vector>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    int timer;
    int increment; 
		
        ofCylinderPrimitive cylinder;
        ofxAssimpModelLoader model;
    ofImage pic;
    ofImage bulletHole; 
    
    int mode;
    ofLight pointLight;
    ofLight pointLight2;
    ofLight pointLight3;
    ofMaterial material;
    
    vector<int> bulletHoles; 
    int currentGun;
    int sampleNumber;
    
  //  load sounds
    
    ofSoundPlayer  snare0;
    Beat snareBeat;
    ofSoundPlayer  kick1;
    Beat kickBeat;
    ofSoundPlayer  tom2;
    Beat tomBeat;
    ofSoundPlayer  hihat3;
    Beat hihatBeat;
    ofSoundPlayer gucci4;
    Beat gucciBeat;
    

    
    
    BulletHole bulletholeObj;
    
    vector<Beat> beatVector;
    
    ofTrueTypeFont	font;
    float 			synthPosition;
};
