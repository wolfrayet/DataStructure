#include <iostream>
#include <algorithm>
using namespace std;

template <class T> 
void ChangeSize1D(T *&a, const int old, const int newsize) 
{
    if (newsize < 0) throw "size must b > 0";
    T *temp = new T[newsize];
    int num = min(old, newsize);
    copy(a, a+num, temp);
    delete [] a;
    a = temp;
}
template <class T>
class Bag 
{
    public: 
        Bag(int Capacity = 10);
        ~Bag();
        int size() const;
        bool empty() const {return size()==0;}
        T element() const;
        void push(const T);
        void pop();
    private:
        T *array;
        int capacity;
        int top;
};

int main()
{
    Bag<int> intBag;
    intBag.push(1);
    intBag.push(9);
    cout << intBag.size() << endl;
    cout << intBag.element() << endl;

    Bag<float> floatBag;
    for (int i=1; i<10; i++) floatBag.push((float)1.0/i);
    cout << floatBag.size() << endl;
    cout << floatBag.element() << endl;

    Bag<Bag<int> > myBag;
    myBag.push(intBag);
    cout << myBag.size() << endl;
    return 0;
}
template <class T> 
Bag<T>::Bag(int Capacity):capacity(Capacity)
{
    if (capacity < 1) throw "must be > 0";
    array = new T[capacity];
    top = -1;
}
template <class T> 
Bag<T>::~Bag()
{
    delete [] array;
}
template <class T> 
inline int Bag<T>::size() const
{
    return top + 1;
}
template <class T> 
inline T Bag<T>::element() const 
{
    if (empty()) throw "Empty bag.";
    return array[0];
}
template <class T> 
void Bag<T>::push(const T x)
{
    if (capacity == top+1) {
        ChangeSize1D(array, capacity, 2*capacity);
        capacity *= 2;
    }
    array[++top] = x;
}
template <class T> 
void Bag<T>::pop()
{
    if (empty()) throw "Bag is empty.";
    int deletePos = top/2;
    copy(array + deletePos +1, array + top + 1, array + deletePos);
    array[top--].~T();
}