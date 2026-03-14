# include <iostream>

using namespace std;

int main(){
    int A[12] = {0};
    int height = 0;
    int heightp = 0;
    int i = 0;
    int sum = 0;

    for(i = 0; i < 10; i++) {
        cin >> A[i];
    }

    cin >> height;

    heightp = height + 30;

    for(i = 0; i < 10; i++) {
        if (A[i] <= height) {
            sum++;
        } else if (A[i] <= heightp) {
            sum++;
        }
    }

    cout << sum << endl;

    return 0;
}