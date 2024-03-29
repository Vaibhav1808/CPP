#include <bits/stdc++.h>
using namespace std;
#include "binaryTreeNodeclass.h"

void printTree(BinaryTreeNode<int>* root){

    if(root == NULL){
        return;
    }

    cout << root -> data << ": " ;
    if(root -> left != NULL){
        cout << "L" << root -> left -> data;
    }

    if(root -> right != NULL){
        cout << "R" << root -> right -> data;
    }
    cout << endl;

    printTree(root -> left);
    printTree(root -> right);
}

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data " << endl;
    cin >> rootData;

    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front -> data << endl;
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front -> left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front -> data << endl;
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front -> right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

int countNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root -> left) + countNodes(root -> right);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printTree(root);
    cout << "NUM : " << countNodes(root) << endl;
    delete root;
}