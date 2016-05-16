#include "videoApp.h"
#include "VideoCue.h"
#include "ofApp.h"

void videoApp::setup(){
	ofSetWindowTitle("Drag this window to the second display and press 'f' to toggle fullscreen");
	ofBackground(25);
	ofSetVerticalSync(false);
}

void videoApp::update(){
	//for (int i = 0; i < numberOfCues; i++) {
		//videoCues[i]->videoPlayer.update();
	//}
}

void videoApp::draw(){
	//for (int i = 0; i < numberOfCues; i++) {
		//videoCues[i]->videoPlayer.draw(0,0);
	//}
}

void videoApp::setVideoCues(vector<VideoCue*> videoCues_, int numberOfCues_) {
	//videoCues = videoCues_;
	//numberOfCues = numberOfCues_;
	
}

void videoApp::keyPressed(int key) {
	//pressed f/fullscreen
	if (key == 'f') {
		ofToggleFullscreen();
	}
}
