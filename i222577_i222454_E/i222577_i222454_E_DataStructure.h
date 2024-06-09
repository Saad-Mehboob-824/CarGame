// Saad 22i-2577 _ E  --  Hassan Mohiuddin 22i-2454
#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "i222577_i222454_E_DataStructure.h"
#include <thread> 
#include <chrono>
#include <windows.h>
#include<fstream>
#include<string>
#include <sstream>  


using namespace std;


class NodeList {
public:
    char data;
    NodeList* next;

    NodeList(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    NodeList* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void insertAtBeginning(char value) {
        NodeList* newNode = new NodeList(value);  // Corrected the type to NodeList*
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(char value) {
        NodeList* newNode = new NodeList(value);  // Corrected the type to NodeList*
        if (!head) {
            head = newNode;
            return;
        }

        NodeList* current = head;
        while (current->next) {
            current = current->next;
        }

        current->next = newNode;
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        NodeList* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        NodeList* current = head;
        while (current->next->next) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    void display() {
        NodeList* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        
    }

    void clear() {
        while (head) {
            NodeList* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


class QueueNode {
public:
    char data;
    QueueNode* next;

    QueueNode(char value){
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(char value) {
        QueueNode* newNode = new QueueNode(value);

        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " enqueued to the queue." << endl;
    }

    char dequeue() {
        if (front == nullptr) {
            return ' ';
        }

        QueueNode* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        return temp->data;
        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        QueueNode* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


struct User {
    int score;
    string name;
    int level;
    User(){}
};

class MaxHeap {
private:
    User* heap;
    int capacity;
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int index) {
        while (index > 0 && heap[index].score > heap[parent(index)].score) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int maxIndex = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < size && heap[left].score > heap[maxIndex].score) {
            maxIndex = left;
        }

        if (right < size && heap[right].score > heap[maxIndex].score) {
            maxIndex = right;
        }

        if (index != maxIndex) {
            swap(heap[index], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:
    MaxHeap(int capacity) : capacity(capacity), size(0) {
        heap = new User[capacity];
    }

    ~MaxHeap() {
        delete[] heap;
    }

    void insert(const User& newUser) {
        if (size == capacity) {
            cerr << "Heap is full!" << endl;
            return;
        }

        int currentIndex = size;
        heap[currentIndex] = newUser;
        size++;

        heapifyUp(currentIndex);
    }

    User extractMax() {
        if (size <= 0) {
            cerr << "Heap is empty!" << endl;
            
        }

        User maxValue = heap[0];
        size--;

        if (size > 0) {
            heap[0] = heap[size];
            heapifyDown(0);
        }

        return maxValue;
    }

    bool isEmpty() const {
        return size == 0;
    }
};
