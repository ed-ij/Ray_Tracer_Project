#include "ofApp.h"

#include "ofxGui.h"
#include "of3dPrimitives.h"
ofxFloatSlider radius;
ofxFloatSlider xPos;
ofxFloatSlider yPos;
ofxPanel gui;

//--------------------------------------------------------------
void ofApp::setup(){

	gui.setup();
	// add a slider with <label>, <initial value>, <min>, <max>
	gui.add(radius.setup("radius", 140, 10, 300));
	gui.add(xPos.setup("xPos", ofGetWidth() / 2, 0, ofGetWidth()));
	gui.add(yPos.setup("yPos", ofGetHeight() / 2, 0, ofGetHeight()));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDisableAlphaBlending();
	ofDisableDepthTest();
	ofDisableLighting();

	gui.setFillColor(ofColor::dimGrey);
	gui.setBackgroundColor(ofColor::black);
	gui.setTextColor(ofColor::white);
	gui.draw();

	
	ofEnableDepthTest();
	ofEnableLighting();
	light.enable();
	//Default circle resolution 10, which draws a regular Icosagon.
	//ofSetCircleResolution(100);

	//int centerX = ofGetWidth() / 2;
	//int centerY = ofGetHeight() / 2;

	sphere.setRadius(radius);
	sphere.setPosition(xPos, yPos, 0);
	//sphere.rotate();

	ofSetColor(ofColor::orangeRed);
	sphere.draw();
	
	//ofDrawCircle(centerX, centerY, radius);
	//gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}