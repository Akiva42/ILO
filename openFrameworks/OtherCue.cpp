#include "OtherCue.h"
#include "ofApp.h"
OtherCue::OtherCue(string name) {

	OSCMessage = "message";

	panel = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	panel->setVisible(false);

	//cue name
	cueName = name;
	panel->addTextInput("Other Cue Name", cueName);
	panel->onTextInputEvent(this, &OtherCue::onCueNameEvent);

	//load file button
	OSCMessageBox = panel->addTextInput("OSC Message", "Message");
	OSCMessageBox->setStripeColor(ofColor::lightSlateGray);
	panel->onTextInputEvent(this, &OtherCue::onOSCMessageBoxEvent);
}

//trigger
//---------------------------------
void OtherCue::trigger() {
	if (OSCMessage != "message") {
		cout << "sending osc message: " << OSCMessage << endl;
		ofApp* app = dynamic_cast<ofApp*>(ofGetAppPtr());
		app->sendOSCMessage(OSCMessage);
	}
	else {
		cout << "no osc message" << endl;
	}
}

//cue name set
void OtherCue::onCueNameEvent(ofxDatGuiTextInputEvent e) {
	ofApp* app = dynamic_cast<ofApp*>(ofGetAppPtr());
	app->setCueName(e.text);
}

//setMessage
//---------------------------------
void OtherCue::onOSCMessageBoxEvent(ofxDatGuiTextInputEvent e) {
	OSCMessage = e.text;
}