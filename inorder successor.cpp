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
BstNode* Insert(BstNode *root,int data)
{
    if(root == NULL)///empty tree
    {
        root = GetNewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left,data);
    }
    else{

        root->right = Insert(root->right,data);
    }
    return root;
}
BstNode *Find(BstNode *root,int data)
{
    if(root==NULL) return root;
    else if(root->data == data) return root;
    else if(root->data < data) return Find(root->right,data);
    else return Find(root->left,data);
}
BstNode *findMin(BstNode *root)
{
    while(root->left != NULL) root = root->left;
    return root;
}
BstNode *GetSuccessor(BstNode *root,int data)
{
    ///search the data
    BstNode *current = Find(root,data);
    if(current == NULL) return NULL;
    ///case1: Node has right subtree
    if(current->right!=NULL)
    {
        return findMin(current->right);
    }
    ///case2: Node has no right subtree
    else
    {
        BstNode *successor = NULL;
        BstNode *anchestor = root;
        while(anchestor!=current)
        {
            if(current->data<anchestor->data)
            {
                successor = anchestor;
                anchestor = anchestor->left;
            }
            else
                anchestor = anchestor->right;
        }
        return successor;
    }
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
   BstNode* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4);
	root = Insert(root,1); root = Insert(root,11);

	//Print Nodes in Inorder
	cout<<"Inorder Traversal: ";
	inorder(root);
	cout<<"\n";

	// Find Inorder successor of some node.
	BstNode* successor = GetSuccessor(root,10);
	if(successor == NULL) cout<<"No successor Found\n";
	else
    cout<<"Successor is "<<successor->data<<"\n";
}




