#include <iostream>

using namespace std;

int main() {

    int height[10] = { 0 };
    int tao_h = 0;
    int temp = 0;
    int count = 0;
    int i = 0, j = 0;

    for(i = 0; i < 10; i++) {
        cin >> temp;
        if(temp >= 100 && temp <= 200) {
            height[i] = temp;
        } else {
            cout << "Invalid value" << endl;
            return 1;
        }
    }
    
    cin >> temp;
    if(temp >= 100 && temp <= 120) {
        tao_h = temp;
    } else {
        cout << "Invalid value" << endl;
        return 1;
    }
    tao_h += 30;

    for(j = 0; j < 10; j++) {
        if (height[j] <= tao_h) {
            count++;
        }
    }
    cout << count;
    return 0;
}