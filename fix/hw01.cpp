#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void solve()
{
    
}
int main(void)
{
    int num;
    int w, h;
    char maze[100][100];
    cin >> num;
    for (int i=0; i<num; i++) {
        cin >> w >> h;
        for (int j=0; j<h; j++) {
            for (int k=0; k<w; k++) {
                cin >> maze[j][k];
                cout << maze[j][k];
                if (k!=w-1) cout << " ";
                else cout << endl;
            }
        }
    }
    return 0;
}
