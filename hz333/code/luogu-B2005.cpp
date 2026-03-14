#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    
    char c = '\0';
    cin >> c;
    int i,j = 0;
    for(i = 2; i >= 0; i--) {
        for(j = 0; j < i; j++) {
            cout << " ";
        }
        for(; j < 5-i; j++) {
            cout << c;
        }
        for(; j < 5; j++) {
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}