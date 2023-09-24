#include <iostream>

using namespace std;
const int STACK_EMPTY = -32768;

struct Node
{
    int data;
    Node* next;
};

void push(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

int pop(Node*& head) {
    if (head == nullptr)
    {
        return STACK_EMPTY;
    }
    Node* del = head;
    int del_data = del->data;
    head = head->next;
    delete del;
    return del_data;
}

int peek(Node* head) {
    if (head == nullptr)
    {
        return STACK_EMPTY;
    }
    return head->data;
}

bool is_empty(Node* head) {
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void print(Node* head) {
    Node* curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;
}

int maxElementStack(Node*& head) {

    int max = head->data;
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        if (curr->data > max) max = curr->data;
    }
    return max;
}
int minElementStack(Node*& head) {

    int min = head->data;
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        if (curr->data > min) min = curr->data;
    }
    return min;
}

void minAndHead(Node*& head){

    int min = head->data;
    Node* pMin = head;
    for (Node* curr = head ; curr != nullptr; curr = curr->next)
    {
        if (curr->data < min) {
            min = curr->data;
            pMin = curr;
        }
    }
    int a = head->data;
    head->data = min;
    pMin->data = a;
    print(head);
}

void sortStack(Node*& head) {
    for (Node* curr = head; curr != nullptr; curr = curr->next)
    {
        int min = curr->data;
        Node* pMin = curr;
        for (Node* curr1 = curr; curr1!= nullptr; curr1 = curr1->next)
        {
            if (curr1->data < min) {
                min = curr1->data;
                pMin = curr1;
            }
        }
        
        int a = curr->data;
        curr->data = min;
        pMin->data = a;


        //curr1 = curr1->next
    }
    print(head);
}

void del_stack(Node*& head) {
    while (pop(head) != STACK_EMPTY) {}
    cout << " " << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    Node* head = nullptr;
    //while (true)
    //{
    //    cout << "Выберите действие:\n 1.Добавить\n 2.Вывести\n 3.Удалить стек\n 4.Удалить 1-н элемент\n 5.Значение головы\n\n";
    //    int a;
    //    cin >> a;
    //    switch (a)
    //    {
    //    case 1:
    //        int dop;
    //        cin >> dop;
    //        push(head, dop);
    //        break;
    //    case 2:
    //        print(head);
    //        system("pause");
    //        break;
    //    case 3:
    //        del_stack(head);
    //        break;
    //    case 4:
    //        pop(head);
    //        break;
    //    case 5:
    //        cout<<peek(head)<<endl;
    //        system("pause");
    //        break;
    //    }
    //    system("cls");
    //}
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int data;
        data = rand() % 10;
        push(head, data);
    }
    print(head);

    sortStack(head);

    del_stack(head);
}