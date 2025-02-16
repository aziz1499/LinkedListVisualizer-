#pragma once

#include "ofMain.h"
#include "LinkedList.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    LinkedList list;
};