#include <iostream>
#include <stack>
using namespace std;

struct item
{
    int x, y, dir;
    item(int x_i, int y_i, int dir_i) {
        x=x_i;
        y=y_i;
        dir=dir_i;
    }
    ~item() {}
};
struct offset
{
     int a, b;
};
offset direction[4];
stack<item> path; 
char maze[101][101];
int op=0;             // determine whether the operator is legal
void Initial();
void ReadMaze(int &w, int &h);  // read maze 
bool Judge(const int w, const int h);   // judge whether the entry and exit satisfy the rule
bool Path(const int w, const int h);    // solve for the path
int isp(char op);
int icp(char op);
void Answer();

int main(void) 
{
    int num=0;          // number of mazes
    int w=0, h=0;
    bool test=0;          // test=0 solved test=1 cannot solve

    cin >> num;
    cout << num << '\n';
    Initial();
    for (int i=0; i<num; i++) {
        op=0;
        ReadMaze(w, h);
        test=Judge(w, h);
        if (test==0) test=Path(w, h);
        if (test==0) Answer();
    }
    return 0;
}
void Initial()          // set the moving direction
{
    direction[0].a=1; direction[0].b=0;
    direction[1].a=0; direction[1].b=1;
    direction[2].a=0; direction[2].b=-1;
    direction[3].a=-1; direction[3].b=0;
}
void ReadMaze(int &w, int &h)  // read maze
{
    cin >> w >> h;
    cout << w << '\n';
    cout << h << '\n';

    for (int i=0; i<=h+1; i++) {
        for (int j=0; j<=w+1; j++) {
            if (i!=0 && i!=h+1 && j!=0 && j!=w+1) {
                cin >> maze[i][j];
                cout << maze[i][j];
                if (j!=w) cout << " ";
            }
            else maze[i][j]=' ';
        }
        if (i!=0 && i!=h+1) cout << '\n';
    }
}
bool Judge(const int w, const int h)
{
    bool fail=0;
    switch(maze[1][1]) {
        case '(':
            if (maze[h][w]=='(') {
                cout << "No" << '\n';
                fail=1;
            }
            else if (maze[h][w]=='+') {
                cout << "No" << '\n';
                fail=1;
            }
            else if (maze[h][w]=='-') {
                cout << "No" << '\n';
                fail=1;
            }
            else if (maze[h][w]=='*') {
                cout << "No" << '\n';
                fail=1;
            }
            else if (maze[h][w]=='/') {
                cout << "No" << '\n';
                fail=1;
            }
            else op++;
        break;
        case ')':
            cout << "No" << '\n';
            fail=1;
        break;
        case '+':
            cout << "No" << '\n';
            fail=1;
        break;
        case '-':
            cout << "No" << '\n';
            fail=1;
        break;
        case '*':
            cout << "No" << '\n';
            fail=1;
        break;
        case '/':
            cout << "No" << '\n';
            fail=1;
        break;
        default: 
            if (maze[h][w]=='(') {
                cout << "No" << '\n';
                fail=1;
            }
            else if (maze[h][w]=='+') {
                cout << "No" << '\n';
                fail=1;
            }
            else if (maze[h][w]=='-') {
                cout << "No" << '\n';
                fail=1;
            }
            else if (maze[h][w]=='*') {
                cout << "No" << '\n';
                fail=1;
            }
            else if (maze[h][w]=='/') {
                cout << "No" << '\n';
                fail=1;
            }
            else {
                fail=0;
            }
        break;
    }
    return fail;
}
bool Path(const int w, const int h)     // return 0 if solved
{
    item temp(1, 1, 0);
    path.push(temp);
    bool success=0;
    bool mark[101][101];
    for (int i=0; i<101; i++) {
        for (int j=0; j<101; j++) {
            mark[i][j]=0;
        }
    }

    while (!path.empty() && success!=1) {   // find path
        temp=path.top();
        //path.pop(); //try
        int i=temp.y; int j=temp.x; int d=temp.dir;
        bool stop=0;
        while (d<4 && stop==0) {    // next move
            //cout << d << '\n';
            int g=i+direction[d].a; int k=j+direction[d].b;
            //cout << stop << " " << g << " " << k <<'\n';
            if (mark[g][k]!=1) {
                switch(maze[g][k]) {
                    case ' ':
                        d++;
                        stop=0;
                    break;
                    case ')':
                        if (maze[i][j]=='(' || maze[i][j]=='+' || maze[i][j]=='-' || maze[i][j]=='*' || maze[i][j]=='/') {
                            d++;
                            stop=0;
                        }
                        else if (op!=0) {
                            op--;
                            stop=1;
                        }
                        else {
                            //op--;
                            d++;
                            stop=0;
                        }
                    break;
                    case '(':
                        if ( maze[i][j]==')' || maze[i][j]=='1' || maze[i][j]=='2' || maze[i][j]=='3' || maze[i][j]=='4' || maze[i][j]=='5' || maze[i][j]=='6' || maze[i][j]=='7' || maze[i][j]=='8' || maze[i][j]=='9') {
                            d++;
                            stop=0;
                        }
                        else {
                            op++;
                            stop=1;
                        }
                    break;
                    case '+':
                        if (maze[i][j]=='(' || maze[i][j]=='+' || maze[i][j]=='-' || maze[i][j]=='*' || maze[i][j]=='/') {
                            d++;
                            stop=0;
                        }
                        else stop=1;
                    break;
                    case '-':
                        if (maze[i][j]=='(' || maze[i][j]=='+' || maze[i][j]=='-' || maze[i][j]=='*' || maze[i][j]=='/') {
                            d++;
                            stop=0;
                        }
                        else stop=1;
                    break;
                    case '*':
                        if (maze[i][j]=='(' || maze[i][j]=='+' || maze[i][j]=='-' || maze[i][j]=='*' || maze[i][j]=='/') {
                            d++;
                            stop=0;
                        }
                        else stop=1;
                    break;
                    case '/':
                        if (maze[i][j]=='(' || maze[i][j]=='+' || maze[i][j]=='-' || maze[i][j]=='*' || maze[i][j]=='/') {
                            d++;
                            stop=0;
                        }
                        else stop=1;
                    break;
                    default:
                        if (maze[i][j]==')') {
                            d++;
                            stop=0;
                        }
                        else stop=1;
                    break;
                }
            }
            else {
                d++;
                stop=0;
            }
        }                   // finish judge
        if (d==4 && !path.empty()) {
            path.pop();
            mark[temp.y][temp.x]=1;
        }
        else {
            temp.y=i+direction[d].a; temp.x=j+direction[d].b; temp.dir=0;
            mark[temp.y][temp.x]=1;
            path.push(temp);
        }
        //cout << maze[temp.y][temp.x] << " " << d << '\n';
        if (temp.y==h && temp.x==w) {
            if (op!=0 && !path.empty()) {
                //if (maze[temp.y][temp.x]=='(') op--;
                mark[temp.y][temp.x]=1;
                path.pop();
                success=0;
            }
            else success=1;
        }
        else success=0;
    }
    if (success==1) {
        cout << "Yes" << '\n';
        return 0;
    }
    else {
        cout << "No" <<'\n';
        return 1;
    }
}
int isp(char op)
{
    int p;
    switch(op) {
        case '(': 
            p=8;
        break;
        case ')':
            p=8;
        break;
        case '+':
            p=3;
        break;
        case '-':
            p=3;
        break;
        case '*':
            p=2;
        break;
        case '/':
            p=2;
        break;
        default:
            p=8;
        break;
    } 
    return p;
}
int icp(char op)
{
    int p;
    switch(op) {
        case '(': 
            p=0;
        break;
        case ')':
            p=8;
        break;
        case '+':
            p=3;
        break;
        case '-':
            p=3;
        break;
        case '*':
            p=2;
        break;
        case '/':
            p=2;
        break;
        default:
            p=8;
        break;
    } 
    return p;
}
void Answer()
{
    item temp(0, 0, 0);
    char out[path.size()];
    char infix[path.size()*2];
    int i=0, j=1;
    int num=path.size();
    int check=0;
    int opt=0;
    int a=0;
    stack<char> postfix;
    while(!path.empty()) {
        temp=path.top();
        out[i]=maze[temp.y][temp.x];
        path.pop();
        i++;
    }
    infix[0]=out[num-1];
    cout << infix[0];
    for (i=num-2; i>=0; i--) {      // infix presentation
        if (infix[j-1]=='(' || infix[j-1]=='+' || infix[j-1]=='-' || infix[j-1]=='*' || infix[j-1]=='/' || infix[j-1]==')') {
            infix[j]=' ';
            j++;
            infix[j]=out[i];
            cout << infix[j];
        }
        else if(out[i]=='(' || out[i]=='+' || out[i]=='-' || out[i]=='*' || out[i]=='/' || out[i]==')') {
            infix[j]=' ';
            j++;
            infix[j]=out[i];
            cout << infix[j];
        }
        else {
            infix[j]=out[i];
            cout << infix[j];
        }
        j++;
    }
    infix[j]='#';
    cout << '\n';
    postfix.push('#');
    for (int k=0; infix[k]!='#'; k++) {
        if (infix[k]==' ' || infix[k]=='1' || infix[k]=='2' || infix[k]=='3' || infix[k]=='4' || infix[k]=='5' || infix[k]=='6' || infix[k]=='7' || infix[k]=='8' || infix[k]=='9') {
            if (infix[k]==' ') check++;
            if (a==0 && infix[k]==' '){}
            else if (check%2==1 || infix[k]!=' ') cout << infix[k];
            a++;
        }
        else if (infix[k]== ')') {
            for (; postfix.top()!='('; postfix.pop()) {
                opt++;
                if (opt==1 && check%2==0) cout << postfix.top();
                else {
                    cout << " ";
                    cout << postfix.top();
                }
            }
            postfix.pop();
        }
        else {
            for (;isp(postfix.top()) <= icp(infix[k]); postfix.pop()) {
                opt++;
                if (opt==1 && check%2==1) cout << postfix.top();
                else {
                    cout << " ";
                    cout << postfix.top();
                }
            }
            postfix.push(infix[k]);
            //check--;
        }
    }
    for (; !postfix.empty() && postfix.top()!='#'; cout << " " << postfix.top(), postfix.pop());
    cout << '\n';
}
