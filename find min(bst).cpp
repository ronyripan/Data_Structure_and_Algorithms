#include<bits/stdc++.h>

using namespace std;

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
bool search(BstNode *root,int data)
{
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(root->data >= data) return search(root->left,data);
    else return search(root->right,data);
}
int findMin(BstNode *root)
{
    if(root == NULL)
    {
        cout<<"The tree is empty"<<endl;
        return -1;
    }
    else
    {
        while(root->left!=NULL)
                root = root->left;
            return root->data;

    }
}
int findMax(BstNode *root)
{
    if(root == NULL)
    {
        cout<<"The tree is empty"<<endl;
        return -1;
    }
    else
    {
        while(root->right!=NULL)
                root = root->right;
            return root->data;
    }
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
    cout<<"Enter the number be searched: ";
    int n;
    cin>>n;
    if(search(root,n)==true)
    {
        cout<<n<<" found"<<endl;
    }
    else
    {
        cout<<n<<" not found"<<endl;
    }
    cout<<"MINIMUM :";
    cout<<findMin(root)<<endl;
    cout<<"MAXIMUM :";
    cout<<findMax(root)<<endl;
}

