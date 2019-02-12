#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "of3dPrimitives.h"
#include "ofCamera.h"
#include "ofImage.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void exit();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

//		void toggleOrthoPressed(ofCamera camera);
		void getPointColor(int &x, int &y, float &color, bool subSampling);

		ofSpherePrimitive sphere;
		ofLight light;
		ofTexture mTex;
		ofCamera camera;
		ofxFloatSlider radius;
		ofxFloatSlider xPos;
		ofxFloatSlider yPos;
		ofxFloatSlider zPos;
		ofxButton orthoToggle;
		ofxPanel gui;
		ofPlanePrimitive plane;
		ofImage img;
		ofImage img2;

};
