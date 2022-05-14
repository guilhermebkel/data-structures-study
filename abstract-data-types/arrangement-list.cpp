#include <iostream>
#include <string.h>
 
using namespace std;

typedef int ItemKey;

class Item {
	public:
		Item();

		Item(ItemKey itemKey) {
			key = itemKey;
		};

		void setKey(ItemKey newKey) {
			key = newKey;
		};

		ItemKey getKey() {
			return key;
		};

	private:
		ItemKey key;
};

class List {
	public:
		List() {
			size = 0;
		};

		int getSize() {
			return size;
		};

		bool isEmpty() {
			return size == 0;
		};

		virtual Item getItem(int index) = 0;
		virtual void setItem(Item item, int index) = 0;
		virtual void insertStart(Item item) = 0;
		virtual void insertEnd(Item item) = 0;
		virtual void insert(Item item, int index) = 0;
		virtual Item removeStart() = 0;
		virtual Item removeEnd() = 0;
		virtual Item remove(int index) = 0;
		virtual Item search(ItemKey c) = 0;
		virtual void clear() = 0;

	protected:
		int size;
};

class ArrangementList: public List {
	public:
		ArrangementList(): List() {};

		Item getItem(int index) {
			return itens[index];
		};

		void setItem(Item item, int index) {
			itens[index] = item;
		};

		void insertStart(Item item) {
			insert(item, 0);
		};

		void insertEnd(Item item) {
			insert(item, size - 1);
		};

		void insert(Item item, int index) {
			itens[index] = item;
		};

		Item removeStart() {
			return remove(0);
		};

		Item removeEnd() {
			return remove(size - 1);
		};

		Item remove(int index) {
			Item tempItem = itens[index];

			Item newItem;

			itens[index] = newItem;

			return tempItem;
		};

		Item search(ItemKey selectedKey) {
			for (int index = 0; index < size; index++) {
				Item item = itens[index];

				ItemKey itemKey = item.getKey();

				if (itemKey == selectedKey) {
					return item;
				}
			}
		};

		void clear();

	private:
		static const int MAXTAM = 100;
		Item itens[MAXTAM];
};
 
int main() {
	ArrangementList *arrangementList;
	arrangementList = new ArrangementList();
	
	for (int i = 0; i < 10; i++) {
		Item item;
		item.setKey(i);
		
		arrangementList->insert(item, i);
	}

	for (int i = 0; i < arrangementList->getSize(); i++) {
		Item item = arrangementList->getItem(i);
		
		cout << "retrieved item value: " << item.getKey() << endl;
	}

	return 0;
};
