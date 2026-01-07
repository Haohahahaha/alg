#include <iostream>
#include <string>
using namespace std;

/*
    函数名：solve
    作用  ：将一个非负整数 n 转换成题目要求的 “0,2 表示” 字符串
    参数  ：n —— 当前需要被表示的整数
    返回值：string —— n 的 0,2 表示形式（不含空格）
*/

string solve(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";

    string result;

    for (int i = 14; i >= 0; i--) {
        if (n & (1 << i)) {
            if (!result.empty())
            {   
                result += "+";
            }

            if (i == 0) {
                result += "2(0)";   // 用 2(0) 表示数字 1
            } else if (i == 1) {
                result += "2";      // 用 2 表示数字 2 
            } else {
                result += "2(" + solve(i) + ")";
            }
        }
    }

    return result;
}

int main() {

    int n;
    cin >> n;          // 输入正整数 n
    cout << solve(n);  // 输出 n 的 0,2 表示

    return 0;
}
