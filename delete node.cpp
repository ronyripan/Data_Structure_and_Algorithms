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
BstNode *findMin(BstNode *root)
{
    while(root->left != NULL) root = root->left;
    return root;
}
BstNode *Delete(BstNode *root,int data)
{
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left,data);
    else if(data > root->data) root->right = Delete(root->right,data);
    else///when data will be find
    {
        ///case1: NO CHILD/leaf node
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        ///case2: ONE CHILD
        else if(root->left == NULL)
        {
            BstNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            BstNode *temp = root;
            root = root->left;
            delete temp;
        }
        ///case3: TWO CHILD
        else
        {
            BstNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}
void inorder(BstNode *root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
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
    root = Delete(root,15);
    inorder(root);
}




