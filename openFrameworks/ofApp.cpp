#include "ofApp.h"
#include "videoApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("ILO");
	numberOfCues = 25;
	activeCue = 0;

	fullscreen = false;

	// open an outgoing connection to HOST:PORT
	sender.setup(HOST, PORT);

	//light cues
	lightCueStack = new ofxDatGui(0, 0);
	lightCueStack->setWidth(100);
	lightCueStack->onButtonEvent(this, &ofApp::onLightCueButtonEvent);
	for (int i = 0; i < numberOfCues; i++) {
		ofxDatGuiButton* tempButton = lightCueStack->addButton(to_string(i));
		tempButton->setStripeWidth(10);
		tempButton->setStripeColor(ofColor::darkGoldenRod);
		lightCues.push_back(new LightCue("Light " + ofToString(i)));
	}

	//sound cues
	soundCueStack = new ofxDatGui(100, 0);
	soundCueStack->setWidth(100);
	soundCueStack->onButtonEvent(this, &ofApp::onSoundCueButtonEvent);
	for (int i = 0; i < numberOfCues; i++) {
		ofxDatGuiButton* tempButton = soundCueStack->addButton(to_string(i));
		tempButton->setStripeWidth(10);
		tempButton->setStripeColor(ofColor::darkCyan);
		soundCues.push_back(new SoundCue("Sound " + ofToString(i)));
	}

	//video cues
	videoCueStack = new ofxDatGui(200, 0);
	videoCueStack->setWidth(100);
	videoCueStack->onButtonEvent(this, &ofApp::onVideoCueButtonEvent);
	for (int i = 0; i < numberOfCues; i++) {
		ofxDatGuiButton* tempButton = videoCueStack->addButton(to_string(i));
		tempButton->setStripeWidth(10);
		tempButton->setStripeColor(ofColor::darkMagenta);
		videoCues.push_back(new VideoCue("Video " + ofToString(i)));
	}
	videoApp* app = dynamic_cast<videoApp*>(ofGetAppPtr());
	app->setVideoCues(videoCues, numberOfCues);

	//other cues
	otherCueStack = new ofxDatGui(300, 0);
	otherCueStack->setWidth(100);
	otherCueStack->onButtonEvent(this, &ofApp::onOtherCueButtonEvent);
	for (int i = 0; i < numberOfCues; i++) {
		ofxDatGuiButton* tempButton = otherCueStack->addButton(to_string(i));
		tempButton->setStripeWidth(10);
		tempButton->setStripeColor(ofColor::lightSlateGray);
		otherCues.push_back(new OtherCue("Other " + ofToString(i)));
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor(38, 50, 72));
	ofSetColor(200);
	float cueHeight = lightCueStack->getHeight() / numberOfCues;
	ofDrawEllipse(lightCueStack->getWidth()*4, cueHeight * activeCue + cueHeight/2, cueHeight, cueHeight);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	//pressed GO/space
	if (key == ' ') {
		if (activeCue < numberOfCues-1) {
			lightCues[activeCue]->trigger();
			soundCues[activeCue]->trigger();
			videoCues[activeCue]->trigger();
			otherCues[activeCue]->trigger();

			activeCue = activeCue + 1;

			lightCues[activeCue]->panel->setVisible(false);
			soundCues[activeCue]->panel->setVisible(false);
			videoCues[activeCue]->panel->setVisible(false);
			otherCues[activeCue]->panel->setVisible(false);
		}
	}
	
	//pressed f/fullscreen
	if (key == 'f') {
		ofToggleFullscreen();
	}

	//pressed o/test osc message
	if (key == 'o') {
		ofxOscMessage m;
		m.setAddress("/ILO");
		m.addIntArg(ofRandom(255));
		sender.sendMessage(m, false);
	}
}

//--------------------------------------------------------------
void ofApp::onLightCueButtonEvent(ofxDatGuiButtonEvent e) {
	for (int i = 0; i < numberOfCues; i++) {
		lightCues[i]->panel->setVisible(false);
		soundCues[i]->panel->setVisible(false);
		videoCues[i]->panel->setVisible(false);
		otherCues[i]->panel->setVisible(false);
	}
	activeCue = e.target->getIndex();
	lightCues[activeCue]->panel->setVisible(true);
}

//--------------------------------------------------------------
void ofApp::onSoundCueButtonEvent(ofxDatGuiButtonEvent e) {
	for (int i = 0; i < numberOfCues; i++) {
		lightCues[i]->panel->setVisible(false);
		soundCues[i]->panel->setVisible(false);
		videoCues[i]->panel->setVisible(false);
		otherCues[i]->panel->setVisible(false);
	}
	activeCue = e.target->getIndex();
	soundCues[activeCue]->panel->setVisible(true);
}

//--------------------------------------------------------------
void ofApp::onVideoCueButtonEvent(ofxDatGuiButtonEvent e) {
	for (int i = 0; i < numberOfCues; i++) {
		lightCues[i]->panel->setVisible(false);
		soundCues[i]->panel->setVisible(false);
		videoCues[i]->panel->setVisible(false);
		otherCues[i]->panel->setVisible(false);
	}
	activeCue = e.target->getIndex();
	videoCues[activeCue]->panel->setVisible(true);
}

//--------------------------------------------------------------
void ofApp::onOtherCueButtonEvent(ofxDatGuiButtonEvent e) {
	for (int i = 0; i < numberOfCues; i++) {
		lightCues[i]->panel->setVisible(false);
		soundCues[i]->panel->setVisible(false);
		videoCues[i]->panel->setVisible(false);
		otherCues[i]->panel->setVisible(false);
	}
	activeCue = e.target->getIndex();
	otherCues[activeCue]->panel->setVisible(true);
}

//SendOSCMessage
//--------------------------------------------------------------
void ofApp::sendOSCMessage(string s) {
	ofxOscMessage m;
	m.setAddress("/ILO");
	m.addStringArg(s);
	sender.sendMessage(m, false);
}

//--------------------------------------------------------------
void ofApp::sendOSCMessage(int i) {
	ofxOscMessage m;
	m.setAddress("/ILO");
	m.addIntArg(i);
	sender.sendMessage(m, false);
}

//setCueName
//--------------------------------------------------------------
void ofApp::setCueName(string name) {
	
}