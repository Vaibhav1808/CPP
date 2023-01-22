#include <bits/stdc++.h>
using namespace std;
#include "binaryTreeNodeclass.h"

void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
        return;
    }

    if(root -> right == NULL and root -> left != NULL){
        cout << root -> left -> data << " ";
    }
    else if(root -> left == NULL and root -> right != NULL){
        cout << root -> right -> data << " ";
    }
    printNodesWithoutSibling(root -> left);
    printNodesWithoutSibling(root -> right);
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
    printNodesWithoutSibling(root);
}
