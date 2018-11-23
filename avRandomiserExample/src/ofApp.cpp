#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

  //---- SERIAL IN ----
    
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    int baud = 9600;
    serial.setup(0, baud); //open the first device
    
    
    
   //----AUDIO AND VIDEO IN ----
    
    maxVids = maxSounds = 6;
    for (int i=0;i<maxSounds;i++){ // loop from on
        ofSoundPlayer newSound;
        string soundName = "audio/" + ofToString (i +1) + ".wav"; // use i+1 as we start with the filenames numbered from 1 not 0
        newSound.load(soundName); // load the sound file into our new sound object
        soundList.push_back(newSound); // push the sound object onto the end of our vector list of sound objects
    }
    
    for (int i=0;i<maxVids;i++){
        ofVideoPlayer newVideo;
        string videoName = "video/" + ofToString (i +1) + ".mov"; // use i+1 as we start with the filenames numbered from 1 not 0
        newVideo.load(videoName); // load the video file into our new video object
       videoList.push_back(newVideo); // push the video object onto the end of our vector list of video objects
    }
    currentVid = currentSound = 0; // choose our starting video and sound
    soundList[currentSound].play(); // play our start sound
    videoList[currentVid].play(); // play our start video
    
    
   
}




//--------------------------------------------------------------
void ofApp::update(){

        videoList[currentVid].update();// update whatever video we are currently playing

    if (serial.available() < 0) {
        sensorValue = "Arduino Error";
    }
    else {
       
        while (serial.available() > 0) {
            
            byteData = serial.readByte();
            
            sensorValue = "value: " + ofToString(byteData);
        }
    }
    cout << sensorValue << endl; // output the sensorValue
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    videoList[currentVid].draw(0,0); // draw the current video to screen
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    

    switch (key) {
        case ' ': // swap to new random video and sound
            
            soundList[currentSound].stop(); // stop the current sound
            videoList[currentVid].stop(); // stop the current video
            
        
            currentVid = ofRandom(maxVids); // select a new random current video
            currentSound = ofRandom(maxSounds); // select a new random current sound
            videoList[currentVid].play();
            soundList[currentSound].play();
            break;
            
        case 'a':
            soundList[currentSound].stop();
            currentSound = ofRandom(maxSounds);
            soundList[currentSound].play();
            break;
        
        case 's':
            videoList[currentVid].stop();
            currentVid = ofRandom(maxSounds);
            videoList[currentVid].play();
            break;
            
        case 'f':
            ofToggleFullscreen();
            break;
        
    }
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
