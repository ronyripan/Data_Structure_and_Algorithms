#include<bits/stdc++.h>

using namespace std;
int previous = -1;
struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};
BstNode* GetNewNode(int data){
    BstNode * newNode = new BstNode;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
BstNode* insert(BstNode *root,int data)
{
    if(root == NULL)///empty tree
    {
        root = GetNewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = insert(root->left,data);
    }
    else{

        root->right = insert(root->right,data);
    }
    return root;
}
void inorder(BstNode *root)
{
    if(root == NULL) return;
    inorder(root->left);
    if(root->data>=previous)
    {
        previous = root->data;
    }
    else
    {
        cout<<"NO"<<endl;
        return;
    }
    inorder(root->right);
}
int main()
{
    BstNode *root = NULL; ///creating an empty tree
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,8);
    root = insert(root,12);
    root = insert(root,11);
    root = insert(root,13);
    root = insert(root,17);
    inorder(root);
}



