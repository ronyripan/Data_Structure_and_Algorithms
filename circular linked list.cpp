#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};
node *head = NULL;

void insert(int x)
{
    node *temp = new node;
    temp->data = x;
    //temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        node *temp1 = head;
        if(head !=NULL)
        {
            do
            {
                temp1 = temp1->next;
            }while(temp1->next != head);
        }
        temp1->next = temp;
    }
 temp->next = head;

}
void print()
{
    node *temp = head;
    if(head !=NULL)
    {
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != head);
    }

}
int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    print();
}
