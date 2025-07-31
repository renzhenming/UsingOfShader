#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	quad.addVertex(glm::vec3(-1.0, -1.0, 0.0));
	quad.addVertex(glm::vec3(-1.0, 1.0, 0.0));
	quad.addVertex(glm::vec3(1.0, 1.0, 0.0));
	quad.addVertex(glm::vec3(1.0, -1.0, 0.0));

	quad.addTexCoord(glm::vec2(0, 0));
	quad.addTexCoord(glm::vec2(0, 1));
	quad.addTexCoord(glm::vec2(1, 1));
	quad.addTexCoord(glm::vec2(1, 0));

	ofIndexType indices[6] = { 0,1,2,2,3,0 };
	quad.addIndices(indices, 6);

	bool loaded = shader.load("shader.vert_texture_scroll", "shader.frag_texture_scroll");

	ofDisableArbTex();
	img.load("parrot.png");
	img.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	shader.begin();
	shader.setUniformTexture("parrotTex", img, 0);
	float time = ofGetElapsedTimef();
	cout<<"rzm:"<<"time:"<<time << endl;
	shader.setUniform1f("time", time);
	quad.draw();
	shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	glm::vec3 curPos = quad.getVertex(2);
	quad.setVertex(2, curPos + glm::vec3(0, 20, 0));
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
