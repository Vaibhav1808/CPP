#include <bits/stdc++.h>
using namespace std;
#include "binaryTreeNodeclass.h"

#include <bits/stdc++.h>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
	pair <int, int> p;
	p.first = INT_MAX;
	p.second = INT_MIN;

	if(root == NULL){
		return p;
	}

	queue<BinaryTreeNode<int>*> q;
	q.push(root);

	while(q.size() != 0){
		BinaryTreeNode<int>* front = q.front();
		q.pop();
        
		if(front -> data < p.first){
			p.first = front -> data;
		}
		if(front -> data > p.second){
			p.second = front -> data;
		}
		if(front -> right != NULL){
			q.push(front -> right);
		}
		if(front -> left != NULL){
			q.push(front -> left);
		}
	}
	return p;
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
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}