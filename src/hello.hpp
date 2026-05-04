#include "cutie.hpp"

#include <iostream>
#include <string>

using namespace std;

class QueueTee {
private:
    static const int MAX_SIZE = 10;
    Cutie* items[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    QueueTee();

    void enqueue(Cutie* c);
    Cutie* dequeue();
    int size();
};
