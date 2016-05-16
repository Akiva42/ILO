#ifndef _OtherCue // if this class hasn't been defined, the program can define it
#define _OtherCue // by using this if statement you prevent the class to be called more than once which would confuse the compiler
#include "ofMain.h" // we need to include this to have a reference to the openFrameworks framework
#include "ofxDatGui.h"
class OtherCue {

public: // place public functions or variables declarations here

	void trigger();

	string cueName; //user created name for the cue
	void onCueNameEvent(ofxDatGuiTextInputEvent e);

	string OSCMessage;

	ofxDatGui* panel; //settings panel
	ofxDatGuiTextInput* OSCMessageBox;
	void onOSCMessageBoxEvent(ofxDatGuiTextInputEvent e);

	OtherCue(string name);  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value

}; // don't forget the semicolon!
#endif