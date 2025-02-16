#include "ofApp.h"

void ofApp::setup() {
    ofBackground(0);
    list.insertAtHead(ofRandom(1, 10));
    cameraX = 0;
}

void ofApp::update() {
    // Update logic if needed
}

void ofApp::draw() {
    ofPushMatrix();
    ofTranslate(cameraX, 0);
    list.draw();
    ofPopMatrix();
}

void ofApp::keyPressed(int key) {
    switch (key) {
        case 'q':
            list.insertAtHead(ofRandom(1, 10));
            break;
        case 'w':
            list.insertAtTail(ofRandom(1, 10));
            break;
        case 'a':
            list.deleteHead();
            break;
        case 's':
            list.deleteTail();
            break;
        case 'z':
            list.increaseAmplitude();
            break;
        case 'x':
            list.decreaseAmplitude();
            break;
        case OF_KEY_LEFT:
            cameraX += 10;
            break;
        case OF_KEY_RIGHT:
            cameraX -= 10;
            break;
    }
}