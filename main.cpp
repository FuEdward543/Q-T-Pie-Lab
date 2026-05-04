#include <iostream>

#include "src/hello.hpp"
#include "src/puppy.hpp"

using namespace std;

int main() {
  QueueTee queue;

  Puppy p1("A big puppy", 10);
  Puppy p2("A small puppy", 9);

  int queue_size = queue.size();
  cout << "Queue size = " << queue_size << endl;

  queue.enqueue(&p1);
  queue.enqueue(&p2);

  int size_after_enqueues = queue.size();
  cout << "Size after enqueues = " << size_after_enqueues << endl;

  Cutie* first_dequeued = queue.dequeue();
  cout << "First dequeued = " << first_dequeued->get_description() << endl;

  Cutie* second_dequeued = queue.dequeue();
  cout << "Second dequeued = " << second_dequeued->get_description() << endl;

  int final_size = queue.size();
  cout << "Final size = " << final_size << endl;

  return 0;
}
