#include "ofApp.h"
#include <iostream>
#include <vector>

void ofApp::setup(){
    
    
    snare0.loadSound("sounds/snare.wav");
    kick1.loadSound("sounds/kick-cult.wav");
    tom2.loadSound("sounds/tom.wav");
    hihat3.loadSound("sounds/hihat.wav");
    gucci4.loadSound("sounds/gucci.mp3");
    

    snare0.setVolume(0.75f);
    kick1.setVolume(0.75f);
    tom2.setVolume(.75f);
    hihat3.setVolume(.75f);
    gucci4.setVolume(.75f);
    
    snare0.setMultiPlay(true);
    kick1.setMultiPlay(true);
    tom2.setMultiPlay(true);
    hihat3.setMultiPlay(true);
    gucci4.setMultiPlay(true);
    
    model.loadModel("guns/Ak-47.obj");
    cylinder.set( 100, 100 );
    pic.loadImage("tp.jpg");
    bulletHole.loadImage("bulletHole1.png");
    timer = 0;
    currentGun = 0;
    increment = 5;
    int period =  2* pic.getWidth();
    snareBeat.setup(period);
    kickBeat.setup(period);
    bulletholeObj.setup(period, increment);
    
    mode = 0;
    ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    
    pointLight2.setDiffuseColor( ofFloatColor( 238.f/255.f, 57.f/255.f, 135.f/255.f ));
    pointLight2.setSpecularColor(ofFloatColor(.8f, .8f, .9f));
    
    pointLight3.setDiffuseColor( ofFloatColor(19.f/255.f,94.f/255.f,77.f/255.f) );
    pointLight3.setSpecularColor( ofFloatColor(18.f/255.f,150.f/255.f,135.f/255.f) );
    
    // shininess is a value between 0 - 128, 128 being the most shiny //
    material.setShininess( 10 );
    // the light highlight of the material //
    material.setSpecularColor(ofColor(140, 255, 30, 255));
    
    ofSetSphereResolution(24);

}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    timer += increment;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int tpCounter1 = timer % (int)(2* pic.getWidth());
    
    if (snareBeat.soundAtTime(tpCounter1) == 1){
        snare0.play();
    }
    if (kickBeat.soundAtTime(tpCounter1) == 1){
        kick1.play();
    }
    if (tomBeat.soundAtTime(tpCounter1) == 1){
        tom2.play();
    }
    if (hihatBeat.soundAtTime(tpCounter1) == 1){
        hihat3.play();
    }
    if (gucciBeat.soundAtTime(tpCounter1) == 1){
        gucci4.play();
    }
    


    
    ofDisableLighting();
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofRotate(90);
    
    
  
        
    int offset = timer + pic.getWidth();
    int tpCounter2 = offset % (int)(2* pic.getWidth());
    pic.draw( -tpCounter1 + ofGetHeight()/2, 0, 10 );
    pic.draw( -tpCounter2 + ofGetHeight()/2, 0 , 10);
    
    
    
    
    
/*    } else {
        pic.draw(spinX , 0);
        pic.draw(spinX +  pic.getWidth(), 0);
        pic.draw(spinX + (2) * pic.getWidth(), 0);
    } */
    
    ofPopMatrix();
    
    ofEnableDepthTest();
    
    ofEnableLighting();
    pointLight.enable();
    pointLight2.enable();
    pointLight3.enable();
    
    material.begin();
    
    /*
    if( ofGetWidth() + spinX < pic.getWidth()){
        spinX = 0;
    } */
    
  //  cylinder.rotate(spinX, 1.0, 0.0, 0.0);
 //   cylinder.rotate(spinY, 0, 1.0, 0.0);
 
    // get all the faces from the icoSphere, handy when you want to copy
    // individual vertices or tweak them a little ;)
  //  vector<ofMeshFace> triangles = cylinder.getMesh().getUniqueFaces();
    
    
    
  //  ofBackground(50, 50, 50, 0);
  //  ofSetColor(255, 255, 255, 255);
    ofFill();
    model.setPosition(ofGetWidth()*5/6, (float)ofGetHeight() * 0.8,0);
  //  model.setRotation(0,spinX,0,1,0);
    ofPushMatrix();
     //   ofTranslate(ofGetWidth()*5/6, (float)ofGetHeight() * 0.8);
      //  ofScale(.5,.5,0);
        ofRotate(5 , 0,.1, 0);
        model.draw(OF_MESH_FILL); //same as model.drawFaces();
    ofPopMatrix();
    
    
    ofDisableDepthTest();
    
    bulletholeObj.draw(-tpCounter1 + ofGetHeight()/2);
    ofLog()<< "tpcounter " << tpCounter1<<endl;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    int beatCount = timer % (int)(2* pic.getWidth());
    

    
    if ( key == 'a'){
        currentGun = 0;
        snareBeat.setSound(beatCount);
        snareBeat.setSound(beatCount);
        bulletholeObj.add(currentGun);
        snare0.play();
    }
    if ( key  == 's'){
        currentGun = 1;
        kickBeat.setSound(beatCount);
        kickBeat.setSound(beatCount);
        bulletholeObj.add(currentGun);
        kick1.play();
    }
    if ( key  == 'd'){
        currentGun = 2;
        tomBeat.setSound(beatCount);
        tomBeat.setSound(beatCount);
        bulletholeObj.add(currentGun);
        tom2.play();
    }
    if ( key  == 'f'){
        currentGun = 0;
        hihatBeat.setSound(beatCount);
        hihatBeat.setSound(beatCount);
        bulletholeObj.add(currentGun);
        hihat3.play();
    }
    if ( key  == 'g'){
        currentGun = 0;
        gucciBeat.setSound(beatCount);
        gucciBeat.setSound(beatCount);
        bulletholeObj.add(currentGun);
        gucci4.play();
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    model.setRotation(0,x,0,1,0);
    
    ofBackground(200 , 100 +  x/2, 130 + x);
    
    pointLight.setDiffuseColor( ofFloatColor(x * .001, x * .005, x * .1) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    
    pointLight2.setDiffuseColor( ofFloatColor( 238.f/255.f, 57.f/255.f, 135.f/255.f ));
    pointLight2.setSpecularColor(ofFloatColor(.8f, .8f, .9f));
    
    pointLight3.setDiffuseColor( ofFloatColor(19.f/255.f,94.f/255.f,77.f/255.f) );
    pointLight3.setSpecularColor( ofFloatColor(18.f/255.f,150.f/255.f,135.f/255.f) );
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    int beatCount = timer % (int)(2* pic.getWidth());
    if ( currentGun == 0){
        model.loadModel("guns/Shotblaster.stl");
        currentGun = 0;
        snareBeat.setSound(beatCount);
        bulletholeObj.add(currentGun);
        snare0.play();
    }
    if ( currentGun == 1){
        model.loadModel("guns/nerdGun.stl");
        currentGun = 1;
        kickBeat.setSound(beatCount);
        bulletholeObj.add(currentGun);
        kick1.play();
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
