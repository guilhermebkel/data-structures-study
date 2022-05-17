#include <iostream>
#include <string.h>
 
using namespace std;

typedef int Item;

class Queue {
	public:
		Queue() {
			size = 0;
			front = 0;
			back = 0;
		}

		int getSize() {
			return size;
		}

		bool isEmpty() {
			return size == 0;
		}

		void enqueue(Item item) {
			if (size == MAX_SIZE) {
				throw "Queue Full!";
			}

			itens[back] = item;

			back = (back + 1) % MAX_SIZE;

			size++;
		}

		Item dequeue() {
			Item temporaryItem;
			if (size == 0) {
				throw "Queue Empty!";
			}
			
			temporaryItem = itens[front];

			front = (front + 1) % MAX_SIZE;

			size--;

			return temporaryItem;
		}

		void clear() {
			front = 0;
			back = 0;
			size = 0;
		}

	protected:
		int size;
		int front;
		int back;
		static const int MAX_SIZE = 8;
		Item itens[MAX_SIZE];
};
 
int main() {
	Queue *queue;
	queue = new Queue();
	
	queue->enqueue(1);
	queue->enqueue(2);

	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;

	return 0;
};
