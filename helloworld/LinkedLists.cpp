#include <bits/stdc++.h>
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
void insertattail(node *&head, int val)
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

void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->data == val || head->next == NULL)
    {
        deleteathead(head);
        return;
    }

    node *temp = head;
    while (temp->next->data != val && temp->next != NULL)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}
void makecycle(node *&head, int pos)
{
    node *temp = head;
    node *startnode = NULL;
    int counter = 1;
    while (temp->next != NULL)
    {
        if (counter == pos)
        {
            startnode = temp;
        }
        temp = temp->next;
        counter++;
    }
    temp->next = startnode;
}

bool detectcycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
void removecycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    if (fast == head)
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else if (fast == slow)
    {
        fast = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = NULL;
    }
}

node *reversion(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *nexptr;
    while (curr != NULL)
    {
        nexptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nexptr;
    }
    return prev;
}

node *reversionrecursive(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newhead = reversionrecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
node *reversionK(node *&head, int k)
{
    node *prev = NULL;
    node *curr = head;
    node *nextptr;
    int count = 0;
    while (curr != NULL && count < k)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        count++;
    }

    if (nextptr != NULL)
    {
        head->next = reversionK(nextptr, k);
    }

    return prev;
}
int length(node *head)
{
    node *temp = head;
    int n = 0;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    return n;
}
node *lasttofront(node *&head, int k)
{
    node *temp = head;
    node *newhead;
    node *newtail;
    int count = 1;
    int l = length(head);
    while (temp->next != NULL)
    {
        if (count == (l - k))
        {
            newtail = temp;
        }
        if (count == (l - k + 1))
        {
            newhead = temp;
        }
        count++;
        temp = temp->next;
    }
    temp->next = head;
    newtail->next = NULL;
    return newhead;
}
void intersect(node *head1, node *head2, int pos)
{
    node *temp1 = head1;
    node *temp2 = head2;
    int count = 1;
    while (count != pos)
    {
        temp1 = temp1->next;
        count++;
    }
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}
int intersection(node *&head1, node *&head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    node *ptr1;
    node *ptr2;
    if (l1 > l2)
    {
        ptr1 = head1;
        d = l1 - l2;
        ptr2 = head2;
    }
    else
    {
        ptr1 = head2;
        ptr2 = head1;
        d = l2 - l1;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}
node *mergelists(node *head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    node *newhead = NULL;
    node *newtemp = newhead;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            insertattail(newhead, temp1->data);
            temp1 = temp1->next;
        }
        else if (temp1->data == temp2->data)
        {
            insertattail(newhead, temp1->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        {
            insertattail(newhead, temp2->data);
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        insertattail(newhead, temp1->data);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        insertattail(newhead, temp2->data);
        temp2 = temp2->next;
    }
    return newhead;
}
node *mergerecursive(node *&head1, node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergerecursive(head1->next, head2);
    }
    else if (head1->data == head2->data)
    {
        result = head1;
        result->next = mergerecursive(head1->next, head2->next);
    }
    else
    {
        result = head2;
        result->next = mergerecursive(head1, head2->next);
    }
    return result;
}
void insertatheadcircular(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void insertattailcircular(node *&head, int val)
{
    if (head == NULL)
    {
        insertatheadcircular(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void deleteatheadcircular(node *&head)
{

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    node *todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
}
void deletioncircular(node *&head, int val)
{
    node *temp = head;
    if (head == NULL)
    {
        return;
    }
    if (head->data == val)
    {
        deleteatheadcircular(head);
        return;
    }
    do
    {
        temp = temp->next;
    } while (temp->next->data != val && temp != head);
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
void displaycircular(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
void displayoddfirst(node *&head)
{
    node *t1 = head;
    node *t2 = head->next;
    node *starteven = t2;
    while (t1->next != NULL && t2->next != NULL)
    {
        t1->next = t2->next;
        t1 = t1->next;
        if (t1->next != NULL)
        {
            t2->next = t1->next;
            t2 = t2->next;
        }
    }
    if (t2->next == NULL)
    {
        t1->next = starteven;
    }
    if (t1->next == NULL)
    {
        t1->next = starteven;
        t2->next = NULL;
    }
}
// DOUBLY LINKED LIST
class noded
{
public:
    int data;
    noded *next;
    noded *prev;
    noded(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertathead(noded *&head, int val)
{
    noded *n = new noded(val);
    n->next = head;
    head = n;
}
void insertattail(noded *&head, int val)
{
    if (head == NULL)
    {
        insertathead(head, val);
        return;
    }
    noded *n = new noded(val);
    noded *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void display(noded *head)
{
    noded *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void deleteathead(noded *&head)
{
    noded *todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}

void deletion(noded *&head, int val)
{
    if (head->data == val)
    {
        deleteathead(head);
        return;
    }
    noded *temp = head;
    while (temp != NULL && temp->data != val)
    {
        temp = temp->next;
    }
    noded *todelete = temp;

    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete todelete;
}
// O(N2) METHOD TO FIND A SUM PAIR IN DLL
void sumpairs(noded *&head, int key)
{
    noded *temp = head;
    noded *nextptr;
    vector<vector<int>> ans;
    while (temp != NULL)
    {
        noded *val1 = temp;
        nextptr = temp->next;
        temp = temp->next;
        while (temp != NULL)
        {
            if (temp->data == (key - val1->data))
            {
                ans.push_back({val1->data, temp->data});
                break;
            }
            temp = temp->next;
        }
        temp = nextptr;
    }
    int num = ans.size();
    for (int i = 0; i < num; i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}
void sumpaireff(noded *&head, int key)
{
    noded *first = head;
    noded *second = head;
    while (second->next != NULL)
    {
        second = second->next;
    }
    bool found = false;
    while (first != second && second->next != first)
    {
        if ((first->data + second->data) == key)
        {
            cout << first->data << " " << second->data << endl;
            first = first->next;
            second = second->prev;
        }
        else
        {
            if ((first->data + second->data) < key)
            {

                first = first->next;
            }
            else
            {
                second = second->prev;
            }
        }
    }
}

int main()
{
    node *head = NULL;
    node *head2 = NULL;
    insertattail(head, 1);
    insertattail(head, 2);
    insertattail(head, 3);
    insertattail(head, 4);
    insertattail(head, 5);
    displayoddfirst(head);
    display(head);
}