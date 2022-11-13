#include <bits/stdc++.h>
using namespace std;
#include "binaryTreeNodeclass.h"

int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root -> left), height(root -> right));
}

int diameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    
    int option1 = diameter(root -> left) + diameter(root -> right);
    int option2 = diameter(root -> left);
    int option3 = diameter(root -> right);

    return max(option1, max(option2, option3));
}