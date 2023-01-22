#include "binaryTreeNodeclass.h"

class BST{
    BinaryTreeNode<int>* root;
    public:
        BST(){
            root = NULL;
        }

        ~BST(){
            delete root;
        }

    private:
        BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node){
            if(node == NULL){
                BinaryTreeNode<int>* newnode = new BinaryTreeNode<int>(data); 
                return newnode;
            }
            if(data < node -> data){
                node -> left = insert(data, node -> left);
            }
            else{
                node -> right = insert(data, node -> right);
            }
            return node;
        }



    public:
        void insert(int data){
            this -> root = insert(data, this -> root);
        }

    private:
        BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node){
            if(node == NULL){
                return NULL;
            }
            if(data > node -> data){
                node -> right = deleteData(data, node -> right);
            }
            else if(data < node -> data){
                node -> left = deleteData(data, node -> left);
            }
            else{
                if(node -> left == NULL and node -> right == NULL){
                    delete node;
                    return NULL;
                }
                else if(node -> left == NULL){
                    BinaryTreeNode<int>* temp = node -> right;
                    node -> right = NULL;
                    delete node;
                    return temp;
                }
                else if(node -> right == NULL){
                    BinaryTreeNode<int>* temp = node -> left;
                    node -> left == NULL;
                    delete node;
                    return temp;
                }
                else{
                    BinaryTreeNode<int>* minnode = node -> right;
                    while(minnode -> left != NULL){
                        minnode = minnode -> left;
                    }
                    int rightmin = minnode -> data;
                    node -> data = rightmin;
                    node -> right = deleteData(rightmin, node -> right);
                    return node;
                }
            }
        }


    
    public:
        void deletedata(int data){

        }
        
    private:
        bool hasData(int data, BinaryTreeNode<int>* node){
            if(node == NULL){
                return true;
            }

            if(node -> data == data){
                return true;
            }

            else if(node -> data < data){
                return hasData(data, node -> left);
            }

            else{
                return hasData(data, node -> right);
            }
        }

    public:        
        bool hasData(int data){
            return hasData(data, root);
        }
};