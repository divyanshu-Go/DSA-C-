#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->val){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

Node* BuildBST(vector<int> arr){
    Node* root = NULL;

    for(int val: arr){
        root = insert(root, val);
    }

    return root;

}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<< root->val << " ";
    inorder(root->right);
}


int main(){
    vector<int> arr = {4,7,3,9,5,6};
    int idx = 1;
    Node* root = BuildBST(arr);
    inorder(root);
    cout<< endl;
}