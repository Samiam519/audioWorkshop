#pragma once

#include "ofMain.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        void audioIn(float * input, int bufferSize, int nChannels);
    
        float loudness;
    
        //new variables
        int hue;
        ofColor c;
        int vCounter;
        bool goingUp;
        int x;
        int y;
        int velX;
        int velY;
    
        ofSoundStream soundStream;
        ofSoundPlayer player;
};
