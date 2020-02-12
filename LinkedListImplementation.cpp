#include <iostream>

using namespace std;


class Node {
public:
    int data;
    Node* next;

};

Node* head = NULL;
void Insert(int x)
{
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}
void print()
{
    Node* temp1 = head;
    while (temp1 != NULL)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
}
void InsertAtAnyPosition(int k, int n)
{

    Node* temp3 = new Node();
    temp3->data = k;

    if (n == 1)
    {
        temp3->next = head;
        head = temp3;
        return;
    }
    Node* temp4 = head;;
    for (int i = 0; i < n - 2; i++) temp4 = temp4->next;

    temp3->next = temp4->next;
    temp4->next = temp3;



}
void deleteAtAnyPosition(int j)
{

    Node* temp5 = head;
    //go to the j-1, node;
    for (int i = 0; i < j - 2; i++)
        temp5 = temp5->next;

    Node* temp6 = temp5->next;// to store the jth node;
    temp5->next = temp6->next;
}
int main()
{

    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        int p;
        cin >> p;
        Insert(p);
        print();
    }

    int p, g;
    cin >> p >> g;
    InsertAtAnyPosition(p, g);
    print();

    int l, a;
    cin >> l >> a;
    InsertAtAnyPosition(l, a);
    print();

    int w;
    cin >> w;
    deleteAtAnyPosition(w);
    print();

    int v;
    cin >> v;
    deleteAtAnyPosition(v);
    print();

    return 0;
}
