#include <iostream>
#include <stack>

using namespace std;
char a[20] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C',
'D', 'E', 'F' };

int main(){
    long x;
    int y;
    cin >> x >> y;

    stack<char> stk;

    while(x != 0) {
        stk.push(a[x % y]);
        x = x/y;
    }

    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }
    
    return 0;
}