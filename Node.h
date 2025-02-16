#pragma once
#include "ofMain.h"

class Node {
public:
    int data;
    Node* next;
    ofPoint position;
    ofColor color;

    Node(int val, ofPoint pos) {
        data = val;
        next = nullptr;
        position = pos;
        color = ofColor::fromHsb(ofRandom(255), 255, 255);
    }
};