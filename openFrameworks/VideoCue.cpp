#include "VideoCue.h"
#include "ofApp.h"
VideoCue::VideoCue(string name) {
	filePath = "Load File ";

	panel = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	panel->setVisible(false);

	//cue name
	cueName = name;
	panel->addTextInput("Video Cue Name", cueName);
	panel->onTextInputEvent(this, &VideoCue::onCueNameEvent);

	//load file button
	loadFile = panel->addButton(filePath);
	loadFile->setStripeColor(ofColor::darkMagenta);
	panel->onButtonEvent(this, &VideoCue::onLoadFileButtonEvent);
}
//---------------------------------

//trigger
void VideoCue::trigger() {
	if (filePath != "Load File") {
		cout << "video cue: " << filePath << endl;
		videoPlayer.play();
	}else {
		cout << "no video file" << endl;
	}
}

//cue name set
void VideoCue::onCueNameEvent(ofxDatGuiTextInputEvent e) {
	ofApp* app = dynamic_cast<ofApp*>(ofGetAppPtr());
	app->setCueName(e.text);
}

//load video file
void VideoCue::onLoadFileButtonEvent(ofxDatGuiButtonEvent e) {
	ofFileDialogResult openFileResult = ofSystemLoadDialog("Select a video file");
	if (openFileResult.bSuccess) {
		loadFile->setLabel(openFileResult.getPath());
		filePath = openFileResult.getPath();
		videoPlayer.load(filePath);
		videoPlayer.setLoopState(OF_LOOP_NORMAL);
	}
}