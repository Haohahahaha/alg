# 刷题笔记

## 输入输出

- 大数组 -- 栈内存不够，应设置全局变量
    ```cpp
    int a[110][110], b[110][110], c[110][110]; //放在 main() 函数外
    static int a[110][110], b[110][110], c[110][110]; // main() 函数内这样写
    ```


- stack 的 用法
    ```cpp
    #include <stack>    // 头文件
    stack<T> stk;       // 声明 存储 T 型的 栈 stk
    stk.empty();        // 检查栈 stk 是否为空
    stk.size();         // 返回栈内元素个数
    stk.top();          // 栈顶元素
    stk.push(i);        // 压入栈 一个元素 i, i需提前声明；
    stk.pop();          // 删除栈顶元素
    stk.emplace(i);     // (无需声明的)就地生成并压入栈 
    stk.swap(foo);      // 与 相同类型 的栈交换底层容器（栈名不变，内容互换） 
    ```

## 线性表

### [P1427 小鱼的数字游戏](https://www.luogu.com.cn/problem/P1427)

### [P8772 [蓝桥杯 2022 省 A] 求和](https://www.luogu.com.cn/problem/P8772)

- 使用 `GCC/Clang` 一揽子头文件 `<bits/stdc++.h>`: 
    
    - 包含绝大多数标准库（iostream、vector、algorithm 等）。
    - 优点是写竞赛代码快；
    - 缺点是非标准、可移植性差（某些编译器或OJ不支持）；
    - 工程代码应改为精确 include。

- 大批量输入输出 加速:
    
    - 竞赛习惯加上以防 I/O 成瓶颈。
  
    !!! bug "详解请看[输入输出+Buffer](https://alg.haohaha.cn/hz333/note/P8772-io&buffer)"
    
    ```cpp
    // 关闭 iostream 与 C stdio 的同步，避免多余锁，读写显著加速。⚠️ 关闭后不要混用 scanf/printf 与 cin/cout，否则可能乱序。
    ios::sync_with_stdio(false);
    
    // 解除 cin 与 cout 的绑定，cin 时不再强制刷新 cout，进一步减少 I/O 开销。若需要交互式输出，可改为 cin.tie(&cout); 或手动 cout.flush()。
    cin.tie(nullptr);
    ```