#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    float x = 0;
    float y = 0;

    cin >> x;

    if(x >= 0 && x < 5){
        y = -x + 2.5f;
    } else if (x >=5 && x < 10) {
        float temp = x - 3;
        y = 2 - 1.5*pow(temp, 2.0);
    } else if (x >=10 && x < 20) {
        y = x/2 - 1.5;
    } else {
        return 0;
    }

    printf("%.3f\n", y);

    return 0;
}