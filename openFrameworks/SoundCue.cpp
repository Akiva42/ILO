#include "SoundCue.h"
#include "ofApp.h"
SoundCue::SoundCue(string name) {
	
	filePath = "Load File ";

	panel = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	panel->setVisible(false);

	//cue name
	cueName = name;
	panel->addTextInput("Sound Cue Name", cueName);
	panel->onTextInputEvent(this, &SoundCue::onCueNameEvent);

	//load file button
	loadFile = panel->addButton(filePath);
	loadFile->setStripeColor(ofColor::darkCyan);
	panel->onButtonEvent(this, &SoundCue::onLoadFileButtonEvent);

	//volume
	panel->addSlider("vloume", 0, 1, 0.5)->setStripeColor(ofColor::darkCyan);
	panel->onSliderEvent(this, &SoundCue::onVolumeSliderEvent);

	//pan
	panel->addSlider("Pan", -1, 1, 0)->setStripeColor(ofColor::darkCyan);
	panel->onSliderEvent(this, &SoundCue::onPanSliderEvent);
}
//---------------------------------

//trigger
void SoundCue::trigger() {
	cout << "sound cue: " << filePath << endl;
	soundPlayer.play();
}

//cue name set
void SoundCue::onCueNameEvent(ofxDatGuiTextInputEvent e) {
	ofApp* app = dynamic_cast<ofApp*>(ofGetAppPtr());
	app->setCueName(e.text);
}

//load file button
void SoundCue::onLoadFileButtonEvent(ofxDatGuiButtonEvent e) {
	ofFileDialogResult openFileResult = ofSystemLoadDialog("Select a sound file");
	if (openFileResult.bSuccess) {
		loadFile->setLabel(openFileResult.getPath());
		filePath = openFileResult.getPath();
		soundPlayer.load(filePath);
		soundPlayer.setVolume(0.75f);
	}
}

//volume
void SoundCue::onVolumeSliderEvent(ofxDatGuiSliderEvent e) {
	soundPlayer.setVolume(e.scale);
}

//pan
void SoundCue::onPanSliderEvent(ofxDatGuiSliderEvent e) {
	soundPlayer.setPan(e.scale);
}