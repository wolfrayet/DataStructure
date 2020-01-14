// Data Structure
// HW03 Matrix to Tree
// ID: 104061249
#include <iostream>
#include <string>
#include <queue>
using namespace std;
bool mark[100][100];

template <class T> class Tree;
template <class T>
class Node
{
    friend class Tree<T>;
    public:
        Node(T data, Node<T> *left, Node<T> *down, Node<T> *right, Node<T> *up):
        data(data),left(left),down(down),right(right),up(up){
        }
        /*~Node() {
            delete left;
            delete down;
            delete right;
            delete up;
            delete parent;
        }*/
        T getdata() const {return data;}
    private:
        T data;
        Node<T> *left;
        Node<T> *down;
        Node<T> *right;
        Node<T> *up;
        //Node<T> *parent;
};
template <class T> 
class Tree
{
    public:
        Tree(const T data) {root = new Node<T>(data, 0, 0, 0, 0);}; // constructor
        ~Tree() {delete root;}  // destructor
        bool empty();
        Node<T> *getroot() {return root;};
        T RootData() {return root->data;};
        void LevelOrder();
        void PreOrder(Node<T> *current);
        void PostOrder(Node<T> *current);
        void MatrixToTree(Node<T> *current, T array[][100], int x, int y, int const w, int const h);
    private:
        Node<T> *root;
};

int main(void) 
{
    int num = 0;
    int width, height;
    int x, y;
    int array[100][100];
    
    string traversal;

    cin >> num;
    cout << num << '\n';
    for (int i=0; i < num; i++) {
        // ========= initial array =============
        for (int j=0; j < 100; j++) {
            for (int k=0; k < 100; k++) {
                array[j][k] = 0;
                mark[j][k] = 0;
            }
        }
        // ========= read data =================
        cin >> width >> height;
        cout << width << " " << height << '\n';
        cin >> y >> x;
        cout << y << " " << x << '\n';
        mark[x][y] = 1;
        // ========= Load Matrix ===============
        for (int j=0; j < height; j++) {
            for (int k=0; k < width; k++) {
                cin >> array[j][k];
                cout << array[j][k];
                if (k != width-1) cout << " ";
            }
            cout << '\n';
        }
        // ========= Conversion ================
        Tree<int> tree(array[x][y]);
        tree.MatrixToTree(tree.getroot(), array, x, y, width, height);
        // ========= Output Result =============
        cin >> traversal;
        cout << traversal << '\n';
        if (traversal == "Level-order-traversal") {
            tree.LevelOrder();
            cout << '\n';
        }
        else if (traversal == "Pre-order-traversal") {
            tree.PreOrder(tree.getroot());
            cout << '\n';
        }
        else if (traversal == "Post-order-traversal") {
            tree.PostOrder(tree.getroot());
            cout << '\n';
        }
    }
    return 0;
}
template <class T>
bool Tree<T>::empty()
{
    if (root == 0) return true;
    else return false;
}
template <class T>
void Tree<T>::LevelOrder()
{
    queue <Node<T> *> q;
    Node<T> *current = root;
    while (current) {
        if (current == root) cout << current->data;
        else cout << " " << current->data;
        if (current->left) q.push(current->left);
        if (current->down) q.push(current->down);
        if (current->right) q.push(current->right);
        if (current->up) q.push(current->up); 
        if (q.empty()) return;
        current = q.front();
        q.pop();
    }
}
template <class T>
void Tree<T>::PreOrder(Node<T> *current)
{
    if (current) {
        if (current == root) cout << current->data;
        else cout << " " << current->data;
        PreOrder(current->left);
        PreOrder(current->down);
        PreOrder(current->right);
        PreOrder(current->up);
    }
}
template <class T>
void Tree<T>::PostOrder(Node<T> *current)
{
    if (current) {
        PostOrder(current->left);
        PostOrder(current->down);
        PostOrder(current->right);
        PostOrder(current->up);
        cout << current->data;
        if (current != root) cout << " ";
    }
}
template <class T>
void Tree<T>::MatrixToTree(Node<T> *current, T array[][100], int x, int y, int const w, int const h)
{
    if (y-1 >= 0 && array[x][y-1] != 0 && current != 0 && mark[x][y-1] == 0) {
        Node<T> *next = new Node<T>(array[x][y-1], 0, 0 , 0, 0);
        current->left = next;
        mark[x][y-1] = 1;
        MatrixToTree(next, array, x, y-1, w ,h);
    }
    if (x+1 < h && array[x+1][y] != 0 && current != 0 && mark[x+1][y] == 0) {
        Node<T> *next = new Node<T>(array[x+1][y], 0, 0 , 0, 0);
        current->down = next;
        mark[x+1][y] = 1;
        MatrixToTree(next, array, x+1, y, w ,h);
    }
    if (y+1 < w && array[x][y+1] != 0 && current != 0 && mark[x][y+1] == 0) {
        Node<T> *next = new Node<T>(array[x][y+1], 0, 0 , 0, 0);
        current->right = next;
        mark[x][y+1] = 1;
        MatrixToTree(next, array, x, y+1, w ,h);
    }
    if (x-1 >= 0 && array[x-1][y] != 0 && current != 0 && mark[x-1][y] == 0) {
        Node<T> *next = new Node<T>(array[x-1][y], 0, 0 , 0, 0);
        current->up = next;
        mark[x-1][y] = 1;
        MatrixToTree(next, array, x-1, y, w ,h);
    } 
}
