#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	camera.disableOrtho();
	gui.setup();

	gui.setFillColor(ofColor::dimGrey);
	gui.setBackgroundColor(ofColor::black);
	gui.setTextColor(ofColor::white);

//	orthoToggle.addListener(this, &ofApp::toggleOrthoPressed);
	// add a slider with <label>, <initial value>, <min>, <max>
	gui.add(radius.setup("radius", 10, 1, 100));
	gui.add(xPos.setup("xPos", ofGetWidth() / 2, 0, ofGetWidth()));
	gui.add(yPos.setup("yPos", ofGetHeight() / 2, -10, ofGetHeight()));
	gui.add(zPos.setup("zPos", -5, -25,25));
//	gui.add(orthoToggle.setup("Toggle Orthographic"));

	plane.set(512, 512);   ///dimensions for width and height in pixels
	plane.setResolution(2, 2);


	// ------------------- IMAGE RENDERING ------------------------

	int pointX, pointY;
	float pointColor = 0;
	int vRes = 512;
	int hRes = 512;
	img.allocate(hRes, vRes, OF_IMAGE_GRAYSCALE);
	/*
	for (pointX = 0; pointX < hRes; pointX++) {
		for (pointY = 0; pointY < vRes; pointY++) {
			getPointColor(pointX, pointY, pointColor, FALSE);
			pointColor *= 255;
			//printf("%d %d %f \n", pointX, pointY, pointColor);
			img.setColor(pointX, pointY, int(pointColor + 0.5));
		}
	}
	img.save("aliasedImage.jpg", OF_IMAGE_QUALITY_BEST);
	*/

	for (pointX = 0; pointX < hRes; pointX++) {
		for (pointY = 0; pointY < vRes; pointY++) {
			getPointColor(pointX, pointY, pointColor, TRUE);
			pointColor *= 255;
			//printf("%d %d %f \n", pointX, pointY, pointColor);
			img.setColor(pointX, pointY, int(pointColor + 0.5));
		}
	}
	img.save("anti-aliasedImage_5.jpg", OF_IMAGE_QUALITY_BEST);

	// ---------------------------------------------------------------

}

void ofApp::exit() {
//	orthoToggle.removeListener(this, &ofApp::toggleOrthoPressed);
}

/*
void ofApp::toggleOrthoPressed(ofCamera camera) { // how to pass the camera to the function in the listener function???
	if (camera.getOrtho == TRUE) {
		camera.disableOrtho();
	}
	else {
		camera.enableOrtho();
	}
}
*/

void ofApp::getPointColor(int &x, int &y, float &color, bool subSampling) {
	float texScale = 10.83;
	double r1, r2, x2, y2;

	if (subSampling == FALSE) {
		color = 0;
		double xDouble = ((double)(x) / double(512)) * texScale;
		double yDouble = ((double)(y) / double(512)) * texScale;
		double xysquared = xDouble * xDouble * yDouble * yDouble;
		color = 0.5 * (1 + sin(xysquared));
	}
	else {
		int numSamples = 5;
		double xDouble = x;
		double yDouble = y;
		color = 0;
		for (int i = 0; i < numSamples; i++) {
			r1 = abs((((double)rand() / (RAND_MAX + 1)) - (0.5)));
			r2 = abs(((double)rand() / (RAND_MAX + 1)) - (0.5));
			x2 = xDouble + (r1);
			y2 = yDouble + (r2);
			x2 = (x2 / 512) * texScale;
			y2 = (y2 / 512) * texScale;
			double xysquared = x2 * x2 * y2 * y2;
			color += (0.5 * (1 + sin(xysquared)));
		}
		color = color / numSamples;

	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDisableAlphaBlending();
	camera.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 100);
	
	ofEnableDepthTest();
	ofDisableLighting();
	img.update();
	img.getTexture().bind();
	img.update();
	img.draw(0, 0);


	/*
		camera.begin(); //----------------------Start drawing orthographically in this section

	ofEnableDepthTest();
	//ofEnableLighting();
	//light.enable();
	//light.setPosition(-100, 400, 300);

	plane.setPosition(256, 256, zPos);

	img.update();
	//img.getTexture().bind();
	img.draw(0, 0)

		//plane.draw();

		camera.end(); //------------------------End
	*/
	ofDisableDepthTest();
	ofDisableLighting();
	gui.draw();

	
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