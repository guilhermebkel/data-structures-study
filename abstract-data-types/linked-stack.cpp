#include <iostream>
#include <string.h>
 
using namespace std;

class Block {
	public:
		Block() {
			nextBlock = NULL;
		}

	private:
		int value;
		Block *nextBlock;

	friend class LinkedStack;
};
 
class LinkedStack {
	public:
		LinkedStack() {
			topBlock = NULL;
			size = 0;
		}

		virtual ~LinkedStack() {
			clear();
		}

		void add(int value) {
			Block *newBlock;
			newBlock = new Block();

			newBlock->value = value;
			newBlock->nextBlock = topBlock;

			topBlock = newBlock;

			size++;
		}

		int remove() {
			int temporaryValue;
			Block *temporaryBlock;

			temporaryValue = topBlock->value;
			temporaryBlock = topBlock;
			topBlock = topBlock->nextBlock;

			delete temporaryBlock;

			size--;

			return temporaryValue;
		}

		void clear() {
			while(!isEmpty()) {
				remove();
			}
		}
		
		bool isEmpty() {
			return size == 0;
		}

	private:
		Block* topBlock;
		int size;
};
 
int main() {
	LinkedStack *linkedStack;
	linkedStack = new LinkedStack();
	
	for (int i = 0; i < 10; i++) {
		linkedStack->add(i);
	}
    
	while (!linkedStack->isEmpty()) {
		int value = linkedStack->remove();
		
		cout << "removed value from stack: " << value << endl;
	}

	return 0;
};
