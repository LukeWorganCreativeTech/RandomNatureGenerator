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
        
		

    int maxVids, maxSounds; // how many sounds and videos we want to choose from
    
    
    vector<ofVideoPlayer> videoList; // make a vector list of type videoplayer objects - this initially is empty
    vector<ofSoundPlayer> soundList; // make a vector list of type soundplayer objects - this initially is empty
    int currentSound, currentVid; // keep track of what is currently playing
    
    ofTrueTypeFont        font;
    
    ofSerial    serial;
    string sensorValue;
    int byteData;
    string msg;
    
};
