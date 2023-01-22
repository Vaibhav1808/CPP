#include <bits/stdc++.h>
using namespace std;
#include "binaryTreeNodeclass.h"

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    if(postLength == 0){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(postorder[postLength-1]);
    if(postLength == 1){
        return root;
    }
    int i = 0;
    while(inorder[i] != postorder[postLength-1]){
        i++;
    }
    int lefts = i;
    int rights = inLength - 1 -i;
    BinaryTreeNode<int>* leftside = buildTree(postorder,lefts,inorder,lefts);
    BinaryTreeNode<int>* rightside = buildTree(postorder+lefts,rights,inorder+1+lefts,rights);
    root->left = leftside;
    root->right = rightside;
    return root;
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}