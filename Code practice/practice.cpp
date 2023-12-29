#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        head = n;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}
void insertathead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
void deleteathead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void deleter(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->data == val or head->next == NULL)
    {
        deleteathead(head);
        return;
    }
    node *temp = head;
    while (temp->next->data != val and temp->next != NULL)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void detectcycle(node* head){
    
}
int main()
{
    node *head = NULL;
    insert(head, 3);
    insert(head, 4);
    insert(head, 565);
    insert(head, 45);
    insert(head, 23);

    insertathead(head, 2);
    print(head);
    cout << endl;
    deleter(head, 4);
    deleter(head, 2);
    print(head);
}