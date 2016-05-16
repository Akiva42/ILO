#include "ofMain.h"
#include "ofApp.h"
#include "videoApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
	ofGLWindowSettings settings;
	settings.width = 900;
	settings.height = 600;
	settings.setPosition(ofVec2f(100, 100));
	auto mainWindow = ofCreateWindow(settings);

	settings.width = 600;
	settings.height = 600;
	settings.setPosition(ofVec2f(1100, 100));
	auto videoWindow = ofCreateWindow(settings);

	auto mainApp = make_shared<ofApp>();
	auto videoAppW = make_shared<videoApp>();

	ofRunApp(videoWindow, videoAppW);
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
}
