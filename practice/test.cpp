#include <iostream>
#include <memory>
using namespace std;

template <class T>
void SelectionSort(T *a, const int n);

int main(){
    float fa[5] = {1.2, 1.6, 0.9, 0.1, 2.7};
    int ia[5] = {10, 8, 11, 2, 9};

    SelectionSort(fa, 5);
    SelectionSort(ia, 5);

    for (int i=0; i<5; i++) cout << fa[i] << " ";
    cout << '\n';
    for (int i=0; i<5; i++) cout << ia[i] << " ";
    cout << '\n';

    return 0;
}

template <class T>
void SelectionSort(T *a, const int n)
{
    for (int i=0; i<n; i++) {
        int j=i;
        for (int k=i+1; k<n; k++) {
            if (a[k]<a[j]) {
                j=k;
                swap(a[i], a[j]);
            }
        }
    }
}