#include <iostream>
#include <vector>
using namespace std;


class Node{
    public:
        int data;
        Node* Left;
        Node* Right;

        Node(int val){
            data = val;
            Left = Right = NULL;
        }
};


Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->Left = insert(root->Left, val);
    }
    else{
        root->Right = insert(root->Right, val);
    }
    return root;
}


Node* BuildBST(vector<int>& nums){
    Node* root = NULL;
    for(int val:nums){
        root = insert(root, val);
    }
    return root;
}


void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->Left);
    cout << root->data << " ";
    inorder(root->Right);

}

bool search(int key, Node* root){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
        return search(key, root->Left);
    }
    else{
        return search(key, root->Right);
    }
}


int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8};

    Node* root = BuildBST(nums);

    inorder(root);

    search(5, root) ? cout<< "\nFound 5 " <<endl : cout<< "\nNot Found" << endl;
    search(50, root) ? cout<< "\nFound" <<endl : cout<< "\nNot Found" << endl;
}