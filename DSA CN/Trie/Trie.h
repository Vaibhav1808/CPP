#include <bits/stdc++.h>
#include "TrieClassNode.h"
using namespace std;

class Trie{
    TrieNode* root;

    public:
        Trie(){
            root = new TrieNode('\0');
        }

        void insertWordHelper(TrieNode* root, string word){
            // base case
            if(word.size() == 0){
                root -> isTerminal = true;
                return;
            }
             
            // small calculation
            int index = word[0] - 'a'; 
            TrieNode* child;
            if(root -> children[index] != NULL){
                child = root -> children[index];
            }
            else{
                child = new TrieNode(word[0]); 
                root -> children[index] = child;
            }

            // recursive call
            insertWordHelper(child, word.substr(1)); 
        }
        // for user
        void insertWord(string word){
            insertWordHelper(root, word);
        }

        bool searchHelper(TrieNode* root, string word){
            if(word.size() == 0){
                if(root -> isTerminal == true){
                    return true;
                }
                else{
                    return false;
                }
            }

            int index = word[0] - 'a';
            TrieNode* child;

            if(root -> children[index] != NULL){
                child = root -> children[index];
                return searchHelper(child, word.substr(1));
            }
            else{
                return false;
            }
        }

        bool search(string word){
            return searchHelper(root, word);
        }

        void RemoveWordHelper(TrieNode* root, string word){
            // base case
            if(word.size() == 0){
                root -> isTerminal = false;
                return;
            }

            // small calculation
            TrieNode* child;
            int index = word[0] - 'a';
            if(root -> children[index] != NULL){
                child = root -> children[index];
            }
            else{
                // word not found
                return;
            }
            RemoveWordHelper(child, word.substr(1));

            // removing node child if its useless
            if(child -> isTerminal == false){
                for(int i = 0; i < 26; i++){
                    if(child -> children[i] != NULL){
                        return;
                    }
                }
                delete child;
                root -> children[index] = NULL;
            }
        }

        void removeWord(string word){
            RemoveWordHelper(root, word);
        }

        bool patternMatching(vector<string> vect, string pattern) {
        for(int i = 0;i < vect.size();i++){
            for(int j = 0;j < vect[i].size();j++){
                insertWord(vect[i].substr(j));
            }
        }
        if(search(pattern)){
            return true;
        }
        return false;
    }
};