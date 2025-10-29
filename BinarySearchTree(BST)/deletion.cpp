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


Node* getInorderSuccessor(Node* root){
    if(root->Left ==NULL){
        return root;
    }
    return getInorderSuccessor(root->Left);
}


Node* DeleteNode(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(key < root->data){
        root->Left = DeleteNode(root->Left, key);
    }
    else if(key > root->data){
        root->Right = DeleteNode(root->Right, key);
    }
    else{
        if(root->Left == NULL){
            Node* temp = root->Right;
            delete root;
            return temp;
        }
        else if(root->Right == NULL){
            Node* temp = root->Left;
            delete root;
            return temp;
        }
        else{
            Node* ISC = getInorderSuccessor(root->Right);
            root->data = ISC->data;
            root->Right = DeleteNode(root->Right, ISC->data);
        }
    }
    return root;
}


int main(){
    vector<int> nums = {1,2,3,12,34,56,89,27,69,24,4,5,6,7,8};

    Node* root = BuildBST(nums);

    root =  DeleteNode(root, 69);

    inorder(root);


}
