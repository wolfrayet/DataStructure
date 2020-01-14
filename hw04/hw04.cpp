//  Data Structure 
//  104061249 Yu-Hsiu Huang
//  18 May, 2018
#include <iostream>
#include <string>
#include <queue>
using namespace std;
void merge(queue<int> &path, queue<int> path1, queue<int> path2);
bool compare(queue<int> path1, queue<int> path2);
int main(void)
{
    int num;
    int a[100][100];
    int ans[100][100];
    string command;
    queue<int> path[100][100];
    // =============================
    // input
    cin >> num;
    for (int i=0; i<num; i++) {
        for (int j=0; j<num; j++) cin >> a[i][j];
    }
    cin >> command;
    // =============================
    // Floyd-Warshall
    for (int i=0; i<num; i++) {
        for (int j=0; j<num; j++) {
            ans[i][j] = a[i][j];
            path[i][j].push(j);
        }
    }
    for (int k=0; k<num; k++) {
        for (int i=0; i<num ; i++) {
            for (int j=0; j<num ; j++) {
                if (ans[i][j] == 0 && ans[i][k] != 0 && ans[k][j] != 0 && i != j) {
                    ans[i][j] = ans[i][k] + ans[k][j];
                    merge(path[i][j], path[i][k], path[k][j]);
                }
                else if (ans[i][j] > (ans[i][k] + ans[k][j]) && ans[i][k] != 0 && ans[k][j] != 0) {
                    ans[i][j] = ans[i][k] + ans[k][j];
                    merge(path[i][j], path[i][k], path[k][j]);
                }
                else if (ans[i][j] == (ans[i][k] + ans[k][j]) && ans[i][k] != 0 && ans[k][j] != 0) {
                    queue<int> temp;
                    merge(temp, path[i][k], path[k][j]);
                    if (compare(path[i][j], temp) == 0) merge(path[i][j], path[i][k], path[k][j]);
                    else;
                }
            }
        }
    }
    // =============================
    // output
    if (command == "Show-path") {
        for (int i=0; i<num; i++) {
            for (int j=0; j<num; j++) {
                if (ans[i][j] != 0) {
                    cout << "Path(" << i << "," << j << "):" << i;
                    while (!path[i][j].empty()) {
                        cout << "->" << path[i][j].front();
                        path[i][j].pop();
                    }
                    cout << endl;
                    cout << "Cost:" << ans[i][j] << endl;
                }
            }
        }
    }
    else if (command == "Hide-path") {
        for (int i=0; i<num; i++) {
            for (int j=0; j<num; j++) {
                if (ans[i][j] != 0) {
                    cout << "Path(" << i << "," << j << "):" << endl;;
                    cout << "Cost:" << ans[i][j] << endl;
                }
            }
        }
    }
    return 0;
}
void merge(queue <int> &path, queue<int> path1, queue<int> path2)
{
    int temp;
    while (!path.empty()) path.pop();
    while (!path1.empty()) {
        temp = path1.front();
        path.push(temp);
        path1.pop();
    }
    while (!path2.empty()) {
        temp = path2.front();
        path.push(temp);
        path2.pop();
    } 
}
bool compare(queue<int> path1, queue<int> path2)
{
    bool result = 1;
    while (!path1.empty() && !path2.empty()) {
        if (path1.front() < path2.front()) return 1;
        else if (path1.front() > path2.front()) return 0;
        else {
            path1.pop();
            path2.pop();
        }
    }
    return result;
}
