#include <bits/stdc++.h>
using namespace std;
#include "binaryTreeNodeclass.h"

void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		BinaryTreeNode<int>* temp = q.front();
		q.pop();

		if(temp == NULL){
			cout << endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout << temp -> data << " ";
			
			if(temp -> left){
				q.push(temp -> left);
			}
			if(temp -> right){
				q.push(temp -> right);
			}

		}
	}
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
    printLevelWise(root);
}