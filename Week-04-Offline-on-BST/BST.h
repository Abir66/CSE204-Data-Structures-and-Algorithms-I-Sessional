#ifndef BST_H
#define BST_H

#include<iostream>

template<typename T>
struct Node
{
    T val;
    Node *left, *right;
    
    Node(){ left = right = nullptr; }
    Node(T val, Node* left = nullptr, Node* right = nullptr){
        this->val = val;
        this->left = left;
        this->right = right;
    }
    bool isLeaf() { return left==nullptr && right == nullptr;}
};


template<typename T>
class BST{
    
    Node<T>* root;
    int count;

    bool findHelp(Node<T>* root, const T& val){
        if(root == nullptr) return false;
        if(root->val == val) return true;
        return findHelp(root->left, val) || findHelp(root->right, val);
    }

    Node<T>* insertHelp(Node<T>* root, const T& val){
        if(root==nullptr) return new Node<T>(val);
        if(val < root->val) root->left = insertHelp(root->left, val);
        else root->right = insertHelp(root->right, val);
        return root;
    }

    Node<T>* deleteMax(Node<T>* root){
        if(root->right == nullptr) return root->left;
        else{
            root->right = deleteMax(root->right);
            return root;
        }
    }

    Node<T>* getMax(Node<T>* root){
        if(root->right==nullptr) return root;
        return getMax(root->right);
    } 

    Node<T>* removeHelp(Node<T>* root, const T& val){
        if(root==nullptr) return nullptr;
        if(val < root->val) root->left = removeHelp(root->left, val);
        else if(val > root->val) root->right = removeHelp(root->right, val);
        else{
            Node<T>* temp = root;
            if(root->left == nullptr){
                root = root->right;
                delete temp;
            }
            else if(root->right == nullptr){
                root = root->left;
                delete temp;
            }
            else{
                temp = getMax(root->left);
                root->val = temp->val;
                root->left = deleteMax(root->left);
                delete temp;
            }
        } 

        return root;
    }

    void printHelp(Node<T>* root){
        if(root == nullptr) return;
        std::cout<<root->val;
        if(root->isLeaf()) return;
        
        std::cout<<"(";
        printHelp(root->left);
        std::cout<<")";

        std::cout<<"(";
        printHelp(root->right);
        std::cout<<")";
    }


    void preorderHelp(Node<T>* root){
        if(root==nullptr) return;
        std::cout<<root->val<<" ";
        preorderHelp(root->left);
        preorderHelp(root->right);
    }

    void postorderHelp(Node<T>* root){
        if(root==nullptr) return;
        postorderHelp(root->left);
        postorderHelp(root->right);
        std::cout<<root->val<<" ";
    }

    void inorderHelp(Node<T>* root){
        if(root==nullptr) return;
        inorderHelp(root->left);
        std::cout<<root->val<<" ";
        inorderHelp(root->right);
    }

    void clear(Node<T> * root){
        if(root==nullptr) return;
        clear(root->left);
        clear(root->right);
        delete root;
    }

public:
    
    BST(){
        root = nullptr;
        count = 0;
    }

    ~BST(){clear(root);}
    
    bool find(const T& val){ return findHelp(root,val);}
    
    void insert(const T& val){ root = insertHelp(root, val); count++;}
    
    bool remove(const T& val){
        if(find(val)){
            root = removeHelp(root,val);
            count--;
            return true;
        }
        return false;
    }
    
    void preOrder(){preorderHelp(root); std::cout<<std::endl;}
    
    void postOrder(){postorderHelp(root); std::cout<<std::endl;}
    
    void inOrder(){inorderHelp(root); std::cout<<std::endl;}

    void print(){
        printHelp(root);
        std::cout<<std::endl;
    }

};


#endif