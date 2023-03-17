#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(32);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);
	
	for (int x = -360; x <= 360; x += 12) {

		for (int y = -360; y <= 360; y += 12) {

			vector<glm::vec2> vertices;
			vertices.push_back(glm::vec2(x, y));
			for (int i = 0; i < 65; i++) {

				auto deg = ofMap(ofNoise(glm::vec3(vertices.back() * 0.0035, ofGetFrameNum() * 0.015)), 0, 1, -360, 360);
				auto vertex = vertices.back() + glm::vec2(2 * cos(deg * DEG_TO_RAD), 2 * sin(deg * DEG_TO_RAD));
				vertices.push_back(vertex);
			}

			ofNoFill();
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape();

			ofFill();
			ofDrawCircle(x, y, 1);
		}
	}
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}