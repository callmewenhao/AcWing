# 第一讲 基础算法

## 快速排序


## 第 Kth 数


## 归并排序


## 逆序对个数


## 整数二分、浮点数二分


## 高精度加、减、乘、除

py 和 java 自带高精度函数🧐


## 前缀和


## 差分


## 同向双指针（滑动窗口）


## 相向双指针


## lowbit

[题目：二进制中1的个数](https://www.acwing.com/problem/content/803/)

lowbit 是数的二进制表示中**最低位的1**对应的数字。比如：0x01001010 的 lowbit 是 0x00000010

计算公式：`lowbit(x) = x & (-x)`


## 离散化

[题目：区间和](https://www.acwing.com/problem/content/804/)

离散化的核心思想就是：排序、去重、二分

在C++中使用的函数如下：

```C++
// 离散化 
// 注意把离散化的所有值都放在一起 比如 alls
sort(alls.begin(), alls.end());  // 排序
alls.erase(unique(alls.begin(), alls.end()), alls.end());  // 去重
int idx = lower_bound(alls.begin(), alls.end(), pairs[i].first) - alls.begin();  // 离散化后的下标
```

## 合并区间


大整数数组存储的顺序：由低位到高位存储 





