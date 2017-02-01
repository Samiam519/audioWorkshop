#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    soundStream.printDeviceList();
    
    //if you want to set a different device id
    //soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
    
    int bufferSize = 256;
    hue = 0;
    vCounter = 3;
    goingUp = true;
    c = ofColor(0); // c is black
    x = ofGetWidth()/2;
    y = ofGetHeight()/2;
    velX = ofRandom(-10,10);
    velY = ofRandom(-10,10);
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    player.load("top.mp3");
    player.setLoop(true);
    player.play();

}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    //RMS Algorithm. Get loudness of input.
    
    float rms = 0.0;
    int numCounted = 0;
    for (int i = 0; i < bufferSize; i++) {
        float leftSample = input[i * 2] * .5;
        float rightSample = input[i * 2 + 1] * .5;
        rms += leftSample * leftSample;
        rms += rightSample * rightSample;
        numCounted += 2;
    }
    
    rms /= (float)numCounted;
    rms = sqrt(rms);
    loudness = rms;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (hue == 255){
        hue = 0;
    }
    
    if(vCounter  == 30){
        goingUp = false;
    }else if (vCounter == 3){
        goingUp = true;
    }
    
    if(goingUp){
        vCounter ++;
    } else if (!goingUp){
        vCounter --;
    }
    
    //new positions
    x += velX;
    y += velY;
    
    //bounce off walls
    // what are the walls
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    
    if (x > maxx){
        x = maxx; // move to the edge, (important!)
        velX *= -1;
    } else if (x < minx){
        x = minx; // move to the edge, (important!)
        velX *= -1;
    }
    
    if (y > maxy){
        y = maxy; // move to the edge, (important!)
        velY *= -1;
    } else if (y < miny){
        y = miny; // move to the edge, (important!)
        velY *= -1;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    c.setHsb(hue, 255, 255);
    ofSetColor(c);
    hue++;

    ofSetCircleResolution(vCounter);
    //The loudness is a very small number, to see it, we're going to map it with a much larger number of the screen width
    float radius = ofMap(loudness, 0, 1, 0, ofGetWidth());
    
    ofDrawCircle(x, y, radius);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
