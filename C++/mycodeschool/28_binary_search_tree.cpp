// Binary search tree 
#include <iostream>

using namespace std;

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

// Function to insert in BST, returns address of root node
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//void Insert(BstNode** root, int data) {
//	if (*root == NULL) { // empty tree
//		*root = GetNewNode(data);
//	}
//}

BstNode* Insert(BstNode* root, int data) {
	if (root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(BstNode* root, int data) {
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Seach(root->right, data);
}

int main() {
	//BstNode* root; // root node의 주소를 저장함
	//root = NULL; // set tree as empty
	BstNode* root = NULL; // Creating an empty tree
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	int number;
	cout << "Enter the number be searched" << endl;
	cin >> number;
	if (Search(root, number)) == true) cout << "Found" << endl;
	else cout << "Not Found" << endl;
}