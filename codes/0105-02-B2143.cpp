#include <iostream>

using namespace std;

void run(int x, int m, char Set[]){
    // 终止条件
    if (x == 0) return; 
    // 递归操作
    int n = x % m;
    x /= m;
    // 在打印前进入递归，这样就可以反向从最高位打印。
    run(x, m, Set);
    cout << Set[n];
}

int main() {
    char A[32] = { '\0' };
    char Set[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    int x = 0;
    int m = 0;
    cin >> x >> m;
    
    if (x == 0) {
        cout << '0' << endl;
    } else {
        run(x, m, Set);
        cout << endl;
    }

    return 0;
}