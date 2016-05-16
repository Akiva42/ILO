#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "LightCue.h"
#include "SoundCue.h"
#include "VideoCue.h"
#include "OtherCue.h"

#include "ofxOsc.h"
#define HOST "localhost"
#define PORT 12345

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		int numberOfCues;
		ofxDatGui* lightCueStack;
		vector<LightCue*> lightCues;
		void onLightCueButtonEvent(ofxDatGuiButtonEvent e);

		ofxDatGui* soundCueStack;
		vector<SoundCue*> soundCues;
		void onSoundCueButtonEvent(ofxDatGuiButtonEvent e);

		ofxDatGui* videoCueStack;
		vector<VideoCue*> videoCues;
		void onVideoCueButtonEvent(ofxDatGuiButtonEvent e);

		ofxDatGui* otherCueStack;
		vector<OtherCue*> otherCues;
		void onOtherCueButtonEvent(ofxDatGuiButtonEvent e);


		void keyPressed(int key);
		int activeCue;

		bool fullscreen;

		ofxOscSender sender;
		void sendOSCMessage(string s);
		void sendOSCMessage(int i);

		void setCueName(string name);
};