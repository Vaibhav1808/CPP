#include <bits/stdc++.h>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


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


int minimum(BinaryTreeNode<int>* root){
	if(root == NULL){
		return INT_MAX;
	}

	return min(root -> data, min(minimum(root -> left), minimum(root-> right)));
}

int maximum(BinaryTreeNode<int> * root){
	if(root ==NULL){
		return INT_MIN;
	}

	return max(root -> data, max(maximum(root -> left), maximum(root-> right)));
}

bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root == NULL){
		return true;
	}

	int leftmax = maximum(root -> left);
	int rightmin = minimum(root -> right);

	bool output = (root -> data > leftmax) and (root -> data <= rightmin) and isBST(root -> left) and isBST(root -> right);
	return output;
	
}

class IsBSTreturn{
    public:
    bool isBST;
    int maximum;
    int minimum;
};

IsBSTreturn isBST2(BinaryTreeNode<int>* root){
    if(root == NULL){
        IsBSTreturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }

    IsBSTreturn leftOutput = isBST2(root -> left);
    IsBSTreturn rightoutput = isBST2(root -> right);

    int minimum = min(root -> data , min(leftOutput.minimum, rightoutput.minimum));
    int maximum = max(root -> data , max(leftOutput.minimum, rightoutput.minimum));

    bool IsBSTfinal = (root -> data > leftOutput.maximum) and (root -> data <= rightoutput.minimum) and leftOutput.isBST and rightoutput.isBST;
    IsBSTreturn output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = IsBSTfinal; 
    return output;
}


bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root -> data < min or root -> data > max){
        return false;
    }

    bool isLeftOK = isBST3(root -> left, min, root -> data - 1);
    bool isRightOK = isBST3(root -> right, root -> data, max);
    return isLeftOK and isRightOK;

}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}