#include <iostream>

using namespace std;

int n, x;

int h(int x, int n){
    if (n = 0) {
        return 1;
    } else if (n = 1) {
        return (2*x);
    } else {
        int temp = 2*x*h(x, (n-1)) - 2*(n-1)*h(x,(n-2));
        return temp;
    }
}


int main(){

    cin >> n >> x;

    int res;
    res = h(x,n);

    cout << res << endl;

    return 0;
}