#ifndef _SoundCue // if this class hasn't been defined, the program can define it
#define _SoundCue // by using this if statement you prevent the class to be called more than once which would confuse the compiler
#include "ofMain.h" // we need to include this to have a reference to the openFrameworks framework
#include "ofxDatGui.h"
class SoundCue {

public: // place public functions or variables declarations here

	void trigger();

	string cueName; //user created name for the cue
	void onCueNameEvent(ofxDatGuiTextInputEvent e);

	string filePath; //path to loaded file
	void onLoadFileButtonEvent(ofxDatGuiButtonEvent e);

	ofxDatGui* panel; //settings panel
	ofxDatGuiButton* loadFile;
	
	void onVolumeSliderEvent(ofxDatGuiSliderEvent e);
	void onPanSliderEvent(ofxDatGuiSliderEvent e);

	SoundCue(string name);  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value

	ofSoundPlayer soundPlayer;
}; // don't forget the semicolon!
#endif