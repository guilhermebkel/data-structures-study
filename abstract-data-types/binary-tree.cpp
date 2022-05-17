#include <iostream>
#include <string.h>
 
using namespace std;

typedef int Item;

class Node {
	public:
		Node() {
			item = -1;
			left = NULL;
			right = NULL;
		}

		Item getItem () {
			return item;
		}

		Node *getLeft () {
			return left;
		}

		Node *getRight () {
			return right;
		}

	private:
		Item item;
		Node *left;
		Node *right;

	friend class BinaryTree;
};

class BinaryTree {
	public:
		BinaryTree() {
			root = NULL;
		}

		~BinaryTree() {
			clear();
		}

		void insert(Item item) {
			recursiveInsert(root, item);
		}

		void clear() {
			recursiveDelete(root);
			root = NULL;
		}

		Node *getRoot() {
			return root;
		}

	private:
		void recursiveInsert(Node* &node, Item item) {
			if(node == NULL) {
				node = new Node();
				node->item = item;
			} else {
				if (item < node->item) {
					recursiveInsert(node->left, item);
				} else {
					recursiveInsert(node->right, item);
				}
			}
		}

		void recursiveDelete(Node* node) {
			if(node != NULL){
				recursiveDelete(node->left);
				recursiveDelete(node->right);
				delete node;
			}
		}

		Node *root;
};

int main() {
	BinaryTree *binaryTree;
	binaryTree = new BinaryTree();
	
	binaryTree->insert(8);
	binaryTree->insert(3);
	binaryTree->insert(10);
	binaryTree->insert(14);
	binaryTree->insert(6);
	binaryTree->insert(4);
	binaryTree->insert(13);
	binaryTree->insert(7);
	binaryTree->insert(1);

	return 0;
};