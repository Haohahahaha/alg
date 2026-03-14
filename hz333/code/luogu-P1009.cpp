#include <iostream>
#include <vector>
using namespace std;

void mult(vector<int> &num, int x){
    int carry = 0;  // 设置 carry 位
    for (
        // 遍历向量内的每个数字位
        int i = 0; i < num.size(); i++){
        
        int t = num[i] * x + carry;
        carry = t / 10; // 进位
        num[i] = t % 10; // 不足10的部分留在本位
    }

    while (carry){
        num.push_back(carry % 10); // 末尾追加最高位
        carry /= 10;    // 迭代，直至carry为0
    }

}

void add(vector<int> &a, vector<int> &b) {
    int carry = 0;  // 设置进位
    int n = max(a.size(), b.size());   // 取最大长度
    if (a.size() < n) a.resize(n, 0);  // 扩位补0

    // 加法实现
    for (int i = 0; i < n; i++) {
        a[i] += (i < b.size() ? b[i] : 0);
        a[i] += carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
    if (carry) a.push_back(carry);  // 高位存储
}

int main(){

    vector<int> num;
    num.push_back(1);

    vector<int> sum;
    sum.push_back(0);

    // 获取输入
    int n;
    cin >> n;
    
    // 计算阶乘与阶乘之和 -- 高精度
    for (int i = 1; i <= n; i++)   
    {   
        mult(num, i);
        add(sum, num);
    }
    
    // 高精度中，最低位在第一个元素。故倒序输出。
    for (int i = sum.size()-1; i >= 0; i--)
    {
        cout << sum[i];
    }
    cout << endl;


    return 0;
}
