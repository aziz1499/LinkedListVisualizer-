#pragma once
#include "Node.h"

class LinkedList {
public:
    Node* head;
    int size;
    float amplitude;

    LinkedList() {
        head = nullptr;
        size = 0;
        amplitude = 10.0f;
    }

    void insertAtHead(int data) {
        ofPoint pos = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
        Node* newNode = new Node(data, pos);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void insertAtTail(int data) {
        ofPoint pos = ofPoint(ofGetWidth() / 2 + size * 50, ofGetHeight() / 2);
        Node* newNode = new Node(data, pos);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    void deleteHead() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    void deleteTail() {
        if (head != nullptr) {
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head;
                while (temp->next->next != nullptr) {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = nullptr;
            }
            size--;
        }
    }

    void draw() {
        Node* temp = head;
        float time = ofGetElapsedTimef();
        while (temp != nullptr) {
            float oscillation = amplitude * sin(time + temp->position.x * 0.1);
            temp->position.y = ofGetHeight() / 2 + oscillation;

            ofSetColor(temp->color);
            ofDrawCircle(temp->position.x, temp->position.y, temp->data * 5);
            ofSetColor(255);
            ofDrawBitmapString(ofToString(temp->data), temp->position.x - 5, temp->position.y + 5);

            if (temp->next != nullptr) {
                ofSetColor(255);
                ofDrawLine(temp->position, temp->next->position);
            }
            temp = temp->next;
        }
    }

    void increaseAmplitude() {
        amplitude += 2.0f;
    }

    void decreaseAmplitude() {
        amplitude -= 2.0f;
        if (amplitude < 0) amplitude = 0;
    }
};