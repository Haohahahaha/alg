## 2021-10-29

> Today Learned:
>
> ​	[Introduction of Algorithms lecture 2](https://www.bilibili.com/video/BV1Tb411M7FA?p=2)
> ​	(Corresponding to the 3rd chapters of the book)
>
> Today Exercise:
>
> ​	[Inorder-Traversal of Binary Tree (From LeetCode)](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

Source Code:

```c
void traversal(struct TreeNode* cur, int* rslt, int* resSize)
{
    if (!cur) return;
    traversal(cur->left, rslt, resSize);
    rslt[(*resSize)++] = cur->val;
    traversal(cur->right, rslt, resSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* rslt = malloc(sizeof(int)*501);
    *returnSize = 0;
    traversal(root, rslt, returnSize);
    return rslt;
}
```

Coding Notes:

![2021-10-29_01.png](./Pic/2021-10-29_01.png)

