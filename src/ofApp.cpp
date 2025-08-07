#include "ofApp.h"

//--------------------------------------------------------------

void builMesh(ofMesh& mesh, float w, float h, glm::vec3 pos) {
	float verts[] = {
		pos.x - w,pos.y - h,pos.z,
		pos.x - w,pos.y + h,pos.z,
		pos.x + w,pos.y + h,pos.z,
		pos.x + w,pos.y - h,pos.z
	};
	float uvs[] = { 0,0,0,1,1,1,1,0 };
	for (int i = 0; i < 4;i++) {
		int idx = i * 3;
		int uvidx = i * 2;
		mesh.addVertex(glm::vec3(verts[idx], verts[idx + 1], verts[idx + 2]));
		mesh.addTexCoord(glm::vec2(uvs[uvidx], uvs[uvidx + 1]));
	}
	ofIndexType indices[6] = { 0,1,2,2,3,0 };
	mesh.addIndices(indices,6);
}

void ofApp::setup()
{
	ofDisableArbTex();
	ofEnableDepthTest();
	builMesh(alienMesh, 0.1, 0.2, glm::vec3(0.0, -0.3, 0.0));
	builMesh(backgroundMesh, 1.0, 1.0, glm::vec3(0.0, 0.0, 0.5));
	builMesh(cloudMesh, 0.25, 0.15, glm::vec3(-0.55, 0.0, 0.0));

	alienImg.load("alien.png");
	backgroundImg.load("forest.png");
	cloudImg.load("cloud.png");

	shader.load("shader.vert_alpha_test", "shader.frag_alpha_test");
	cloudShader.load("shader.vert_alpha_test", "shader.frag_alpha_test_cloud");
}


//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	shader.begin();
	shader.setUniformTexture("tex", alienImg, 0);
	alienMesh.draw();
	shader.setUniformTexture("tex", backgroundImg, 1);
	backgroundMesh.draw();
	shader.end();

	cloudShader.begin();
	cloudShader.setUniformTexture("tex", cloudImg, 0);
	cloudMesh.draw();
	cloudShader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

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
