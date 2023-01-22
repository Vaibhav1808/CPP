#include <bits/stdc++.h>
using namespace std;
#include "binaryTreeNodeclass.h"

int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
	
    return 1+ max(height(root->left),height(root->right));
}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root == NULL){
		return true;
	}

	if(root -> left == NULL and root -> right == NULL){
		return true;
	}

	int hL = height(root -> left);
	int hR = height(root -> right);
	int x=hL-hR;

	if(abs(hL - hR) <= 1 and isBalanced(root -> left) != false and isBalanced(root -> right) != false){
		return true;
	}
	return false;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");
}