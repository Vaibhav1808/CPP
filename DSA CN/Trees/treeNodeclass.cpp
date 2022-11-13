#include <bits/stdc++.h>
using namespace std;

template <typename T>
class treeNode{
    public:
    T data;
    vector<treeNode<T>*> children;

    treeNode(T data){
        this -> data = data;
    }

    ~treeNode(){
        for(int i = 0; i < root -> children.size(); i++){
            delete children[i];
        }
    }
};

void printTree(treeNode<int>* root){

    if(root == NULL){
        return;
    }

    cout << root->data << ":"; 
    for(int i = 0; i < root -> children.size(); i++){
        cout << root -> children[i] -> data << ",";
    }
    cout << endl;
     
    for(int i = 0; i < root -> children.size(); i++){
        printTree(root -> children[i]);
    }
}

void printLevelWiseQues(treeNode<int>* root) {
    queue<treeNode<int>*> pendingNodes;


    pendingNodes.push(root);
    while(!pendingNodes.empty()){
         treeNode<int>* front = pendingNodes.front();
         pendingNodes.pop();
         cout << front -> data << ":";
         
        for(int i = 0; i < front -> children.size(); i++){
            if(front -> children.size() - 1 > i){
                cout << front -> children[i] -> data << ",";
            }
            else{
                cout << front -> children[i] -> data;
            }
            pendingNodes.push(front -> children[i]);
        }
        cout << endl;
    }
}

treeNode<int>* takeInput(){
    int rootData;
    cout << "Enter data " << endl;
    cin >> rootData;

    treeNode<int>* root = new treeNode<int>(rootData);

    int n;
    cout << "Enter number of children of " << rootData << endl;
    cin >> n;

    for(int i = 0; i < n; i++){
        treeNode<int>* child = takeInput();
        root -> children.push_back(child);
    }
    return root;
}

treeNode<int>* takeInputLevelWise(){
    int rootdata;
    cout << "Enter rootdata " << endl;
    cin >> rootdata;

    treeNode<int>* root = new treeNode<int>(rootdata);

    queue<treeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        treeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front -> data << endl;

        int numChild;
        cin >> numChild;

        for(int i = 0; i  < numChild; i++){
            int childData;
            cout << "Enter " << i << "th child of " << front -> data << endl;
            cin >> childData;

            treeNode<int>* child = new treeNode<int>(childData);
            front -> children.push_back(child);
            pendingNodes.push(child);

        }
    }
    return root;
}

int numNodes(treeNode<int>* root){
    int ans = 1;

    for(int i = 0; i < root -> children.size(); i++){
        ans += numNodes(root -> children[i]);
    }
    return ans;
}

int sumOfNodes(treeNode<int>* root) {
    // Write your code here
    int sum = root -> data;

    for(int i = 0; i < root -> children.size(); i++){
        sum += sumOfNodes(root -> children[i]);
    }
    return sum;
}

treeNode<int>* maxDataNode(treeNode<int>* root) {
    // Write your code here
    // int maxi = root -> data;
    if(root == NULL){
        return root;
    }

    treeNode<int>* maxi = root;
    for(int i = 0; i < root -> children.size(); i++){
        treeNode<int>* temp = maxDataNode(root -> children[i]);
            if(root -> data < temp -> data){
                maxi = temp;
            }
    }
    return maxi;
}

int getHeight(treeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return 0;
    }

    int height = 0;
    for(int i = 0; i < root -> children.size(); i++){
        int h = getHeight(root -> children[i]);
        if(height < h){
            height = h;
        }
    }
    return height + 1;
}

void printAtlevelK(treeNode<int>* root, int k){
    if(root == NULL){
        return;
    }

    if(k == 0){
        cout << root -> data << endl;
        return;
    }

    for(int i = 0; i < root -> children.size(); i++){
        printAtlevelK(root -> children[i], k-1);
    }

}

int countleaf = 0;
int getLeafNodeCount(treeNode<int>* root) {
    // Write your code here
    
    if(root == NULL){
        return countleaf;
    }
    if(root -> children.size() == 0){
        countleaf++;
    }
    for(int i = 0; i < root -> children.size(); i++){
        getLeafNodeCount(root -> children[i]);
    }
    return countleaf;
}

void preorder(treeNode<int>* root){
    if(root == NULL){
        return;
    }

    cout << root -> data << " ";

    for(int i = 0; i < root -> children.size(); i++){
        preorder(root -> children[i]);
    }
}

void printPostOrder(treeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return;
    }

    for(int i = 0; i < root -> children.size(); i++){
        printPostOrder(root -> children[i]);
    }
    cout << root -> data << " ";
}

// void deleteTree(treeNode<int>* root){
//     for(int i = 0; i < root -> children.size(); i++){
//         deleteTree(root -> children[i]);
//     }
//     delete root;
// }

bool isPresent(treeNode<int>* root, int x) {
    // Write your code here
    if(root == NULL){
        return false;
    }

    if(root -> data == x){
        return true;
    }

    for(int i = 0; i < root -> children.size(); i++){
        int data = isPresent(root -> children[i], x);
        if(data == true){
            return true;
        }
    }
    return false;
}

int countLargeNode = 0;
int getLargeNodeCount(treeNode<int>* root, int x) {
    // Write your code here
    if(root == NULL){
        return 0;
    }

    if(root -> data > x){
        countLargeNode++;
    }

    for(int i = 0; i < root->children.size(); i++){
        getLargeNodeCount(root -> children[i], x);
    }
    return countLargeNode;
}

treeNode<int>* maxSumNode(treeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return root;
    }

    int maxi = 0;

    stack<treeNode<int>*> s;
    queue<treeNode<int>*> q;

    q.push(root);

    while(!q.empty()){
        int maxSum = q.front() -> data;

        for(int i = 0; i <root -> children.size(); i++){
            q.push(root -> children[i]);
            maxSum += root-> children[i] -> data;
        }
        if(maxi < maxSum){
            s.push(q.front());
            maxi = maxSum;
        }
        q.pop();
        root = q.front();
    }
    return s.top();
}

bool areIdentical(treeNode<int> *root1, treeNode<int> * root2) {
    // Write your code here
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 -> children.size() != root2 -> children.size()){
        return false;
    }

    for(int i = 0; i < root1->children.size(); i++){
        areIdentical(root1 -> children[i], root2 ->children[i]);
    }
    if(root1 -> data == root2 -> data){
        return true;
    }
    return false;
}

void helpergetNextLargerElement(treeNode<int> *root, int &x, treeNode<int> * &ans){
    if (root == NULL) {
        return;
    }

    if(root -> data > x){
        if(ans == NULL){
            ans = root;
        }
        
        else if(ans -> data > root -> data){
            ans = root;
        }
    }
    
    for(int i = 0; i < root -> children.size(); i++){
        helpergetNextLargerElement(root -> children[i], x, ans);
    }
}

treeNode<int> *getNextLargerElement(treeNode<int> *root, int x) {
  // Write your code here

    treeNode<int> *ans = NULL;
    helpergetNextLargerElement(root, x, ans);
    return ans;
}

int depth = 0;
void replaceWithDepthValue(treeNode<int>* root) {
    if(root == NULL){
    return;
    }

    root->data = depth;
    for(int i = 0; i < root -> children.size(); i++){
        depth++;
        replaceWithDepthValue(root -> children[i]);
    }
    depth--;
}

int main(){
    /*treeNode<int>* root = new treeNode<int>(1);
    treeNode<int>* node1 = new treeNode<int>(2);
    treeNode<int>* node2 = new treeNode<int>(3);

    root -> children.push_back(node1);
    root -> children.push_back(node2);*/

    treeNode<int>* root = takeInputLevelWise();
    printTree(root); 
    //deleteTree(root);  wrote a function to delete
    delete root; // using destructor
    return 0;
}