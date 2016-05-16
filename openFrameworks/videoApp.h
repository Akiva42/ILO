#pragma once

#include "ofMain.h"
#include "VideoCue.h"

class videoApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void setVideoCues(vector<VideoCue*> videoCues_, int numberOfCues_);
	vector<VideoCue*> videoCues;
	int numberOfCues;
};

