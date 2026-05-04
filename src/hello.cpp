#include "hello.hpp"

using namespace std;

QueueTee::QueueTee() {
   front = 0;
   rear = -1;
   count = 0;
}

void QueueTee::enqueue(Cutie* c) {
   if (count == MAX_SIZE) {
      cout << "Queue is full" << endl;
      return;
   }
   rear = (rear + 1) % MAX_SIZE;
   items[rear] = c;
   count++;
}

Cutie* QueueTee::dequeue() {
   if (count == 0) {
      cout << "Queue is empty" << endl;
      return nullptr;
   }
   Cutie* removed = items[front];

   front = (front + 1) % MAX_SIZE;
   count--;

   return removed;
}

int QueueTee::size() {
   return count;
}
