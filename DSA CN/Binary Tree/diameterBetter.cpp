#include <bits/stdc++.h>
using namespace std;
#include "binaryTreeNodeclass.h"

pair<int, int> heightDiameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p; 
    }
    pair<int, int> leftAns = heightDiameter(root ->left);
    pair<int, int> rightAns = heightDiameter(root -> right);

    int ld = leftAns.second;
    int lh = leftAns.first;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;

    p.first = height;
    p.second = diameter;
    return p;
}

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

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printTree(root);
    pair<int, int> p = heightDiameter(root);
    cout << "Height: " << p.first << endl;
    cout << "Diameter: " << p.second << endl;
    delete root;

}
