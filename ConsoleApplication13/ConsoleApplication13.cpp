#include <iostream>

using namespace std;
const int STACK_QUEUE = -32768;

struct Node
{
    int data;
    Node* next;
};
//struct Queue {
//    Node* head;
//    Node* tail;
//    Queue() {
//        head = nullptr;
//        tail = nullptr;
//    }
//};

void push(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node();
    newNode->next = nullptr;
    newNode->data = data;
    if (head == nullptr && tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int pop(Node*& head, Node*& tail) {
    if (head == nullptr && tail == nullptr)
    {
        return STACK_QUEUE;
    }
    if (head == tail)
    {
        int dataDel = head->data;
        delete head;
        head = tail = nullptr;
        return dataDel;
    }
    int dataDel = head->data;
    Node* delNode = head;
    head = head->next;
    delete delNode;
    return dataDel;
}

void printQueue(Node* head) {
    Node* curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void deleteQueue(Node*& head, Node*& tail) {
    while (pop(head, tail) != -32768) {}
    cout << "\nОчередь удалена!\n";
}

//void delPolElements(Node*& head) {
//    for (Node* curr = head; curr != nullptr; curr = curr->next)
//    {
//        int pol = curr->data;
//        Node* pPol = curr;
//        Node* pNext = curr->next;
//        if (pol > 0)
//        {
//            goto go;
//        }
//        else
//        {
//            int a = pol;
//            pPol->data = pNext->data;
//            pNext->data = pol;
//        }
//    go:;
//    }
//    printQueue(head);
//}

void delPolElements(Node*& head, Node*& tail) {
    int col = 0;
    for (Node* curr = head; curr != nullptr; curr = curr->next)
    {
        for (Node* curr1 = curr; curr1 != nullptr; curr1 = curr1->next)
        {

            if (curr->data <= 0 && curr1->data > 0)
            {
                int a = curr->data;
                curr->data = curr1->data;
                curr1->data = a;
            }
        }
    }
    for (Node* curr2 = head; curr2 != nullptr; curr2 = curr2->next)
    {
        if (curr2->data > 0)
        {
            col++;
        }
    }
    for (int i = 0; i < col; i++)
    {
        pop(head, tail);
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    Node* head = nullptr, * tail = nullptr;
    Node* head1 = nullptr, * tail1 = nullptr;
    //Queue* q1 = new Queue();
    //q1->head = nullptr;
    //int a;
    //cin >> a;
    for (int i = 0; i < 10; i++)
    {
        int data = rand() % 201 - 100 + 1;
        push(head, tail, data);
    }
    printQueue(head);
    Node* curr = head;
    while (curr != nullptr)
    {
        if (curr->data > 0)
        {
            push(head1, tail1, curr->data);
        }
        curr = curr->next;
    }

    printQueue(head1);

    deleteQueue(head, tail);
    deleteQueue(head1, tail1);

}