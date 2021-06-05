#include <iostream>
#include "QueType.h"
#include "TreeType.h"
using namespace std;

TreeNode* PtrToSuccessor(TreeNode*& tree) {
	if (tree->left != NULL)
		return PtrToSuccessor(tree->left);
	else {
		TreeNode* tempPtr = tree;
		tree = tree->right;
		return tempPtr;
	}
}

void DeleteNode(TreeNode*& tree) {
	ItemType data;
	TreeNode* tempPtr;

	tempPtr = tree;
	if (tree->right == NULL) {
		tree = tree->left;
		delete tempPtr;
	}
	else {
		TreeNode* imm_successor = PtrToSuccessor(tree->right);
		tree = imm_successor;
		delete tempPtr;
	}
}