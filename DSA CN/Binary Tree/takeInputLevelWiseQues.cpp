#include <bits/stdc++.h>
using namespace std;
#include "binaryTreeNodeclass.h"

void printLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(q.size() != 0){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        cout << root -> data << ":";
        
        if(front -> left != NULL){
            cout << "L:" << front -> left -> data << ",";
            q.push(front -> left);
        }

        else{
            cout << "L:" << "-1" << ",";
        }
        if(front -> right != NULL){
            cout << "R:" << front -> right -> data << ",";
            q.push(front -> right);
        }
        
        else{
            cout << "R:" << "-1" << ",";
        }
        cout << endl;
        root = q.front();
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
        cout << endl;
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}