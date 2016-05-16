#include "LightCue.h"
#include "ofApp.h"
LightCue::LightCue(string name) {
	filePath = "Load File ";

	panel = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	panel->setVisible(false);

	//cue name
	cueName = name;
	panel->addTextInput("Light Cue Name", cueName);
	panel->onTextInputEvent(this, &LightCue::onCueNameEvent);

	//load file button
	loadFile = panel->addButton(filePath);
	loadFile->setStripeColor(ofColor::darkGoldenRod);
}
//---------------------------------

//trigger
void LightCue::trigger() {
	cout << "light cue: " << filePath << endl;
}

//cue name set
void LightCue::onCueNameEvent(ofxDatGuiTextInputEvent e) {
	ofApp* app = dynamic_cast<ofApp*>(ofGetAppPtr());
	app->setCueName(e.text);
}