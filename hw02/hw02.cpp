// Data Structure HW02
#include <iostream>
#include <string>
using namespace std;

class Node;
class Chain
{
    public:
        Chain() {first = 0;}      // constructor
        ~Chain() {}             // destructor
        bool empty() const;
        void InsertBack(string gift_i, int price_i);
        void InsertAfter(string gift_i, int price_i, const int insertafter);
        void Delete(int price);
        void Reverse();
        void Print();
    private:
        Node *first;
};
class Node
{
    friend class Chain;
    public:
        Node(string gift_i, int price_i=0, Node* next=0) {
            gift=gift_i;
            price=price_i;
            link=next;
        }
        ~Node() {}
    private:
        string gift;
        int price;
        Node *link;
};
int main(void)
{
    Chain list;
    string command;
    string gift;
    int price;
    int target;
    cin >> command;
    while (command != "End") {
        if (command == "InsertBack") {
            cin >> gift >> price;
            list.InsertBack(gift, price);
        }
        else if (command == "InsertAfter") {
            cin >> gift >> price >> target;
            list.InsertAfter(gift, price, target);
        }
        else if (command == "Delete") {
            cin >> target;
            list.Delete(target);
        }
        else {
            list.Reverse();
        }
        cin >> command;
    }
    list.Print();
    return 0;
}
bool Chain::empty() const
{
    if (first==0) return 1;
    else return 0;
}
void Chain::InsertBack(string gift, int price)
{
    bool test=0;
    Node* temp = new Node(gift, price, 0);
    if (first==0) {
        first = temp;
    }
    else {
        Node* current = first;
        while (current->link != 0) {
            if (current->price==price) test=1;
            current = current->link;
        }
        if (test==0) current->link = temp;
    }
}
void Chain::InsertAfter(string gift, int price, const int insertafter)
{
    bool test=0;
    if (first==0);
    else {
        Node* current = first;
        while (current->link != 0) {
            if (current->price==price) test=1;
            if (current->price==insertafter && test==0) {
                current->link = new Node(gift, price, current->link);
                current = current->link;
            }
            else current = current->link;
        }
        if (current->price==insertafter && test==0) {
                current->link = new Node(gift, price, current->link);
        }
    }
}
void Chain::Delete(int price)
{
    if (first==0);
    else {
        Node* current = first;
        Node* prev = 0;
        while (current != 0 && current->price != price) {
            prev = current;
            current = current->link;
        }
        if (current==0);
        else if (current==first) {
            first = current->link;
            delete current;
            current = 0;
        }
        else {
            prev->link = current->link;
            delete current;
            current = 0;
        }
    }
}
void Chain::Reverse()
{
    if (first==0);
    else {
        Node* current = first;
        Node* next = first->link;
        Node* prev = 0;
        while (next != 0) {
            current->link = prev;
            prev = current;
            current = next;
            next = next->link;
        }
        current->link = prev;
        first = current;
    }
}
void Chain::Print()
{
    if (first==0) cout << "Empty" <<'\n';
    else {
        cout << "List" <<'\n';
        Node* current = first;
        while (current->link!=0) {
            cout << "(" << current->gift << "," << current->price << ")" << "->";
            current = current->link;
        }
        cout << "(" << current->gift << "," << current->price << ")" <<'\n';
    }
}