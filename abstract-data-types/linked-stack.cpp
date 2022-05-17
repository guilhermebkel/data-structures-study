#include <iostream>
#include <string.h>
 
using namespace std;

typedef int Item;

class Block {
	public:
		Block() {
			nextBlock = NULL;
		}

	private:
		Item item;
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

		void add(Item item) {
			Block *newBlock;
			newBlock = new Block();

			newBlock->item = item;
			newBlock->nextBlock = topBlock;

			topBlock = newBlock;

			size++;
		}

		int remove() {
			Item temporaryItem;
			Block *temporaryBlock;

			temporaryItem = topBlock->item;
			temporaryBlock = topBlock;
			topBlock = topBlock->nextBlock;

			delete temporaryBlock;

			size--;

			return temporaryItem;
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
