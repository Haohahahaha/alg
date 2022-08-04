## 2021-10-31

> Today Learned:
>
> ​	[Introduction of Algorithms lecture 3 (Not all)](https://www.bilibili.com/video/BV1Tb411M7FA?p=3)
> ​	(Corresponding to the 3rd chapters of the book)
>
> Today Exercise:
>
> ​	[Sqrt(x) (From LeetCode)](https://leetcode-cn.com/problems/sqrtx/)

```c
int mySqrt(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    int left = 0, right = x, res = 0;
    while (right - left > 1) {
        int mid = (right - left) / 2 + left;
        if (x / mid < mid) {
            right = mid;
        } else {
            left = mid;
            res = left;
        }
    }
    return res;
}
```

Coding Notes:

![2021-10-31_01.png](./Pic/2021-10-31_01.png)