# 数据结构

## 链表

> 使用数组模拟链表 

### 单链表

邻接表：存储图和树

AcWing 826. 单链表 https://www.acwing.com/problem/content/828/

### 双链表

优化某些问题

## 模拟栈

表达式求值

## 模拟队列

## 单调栈

找到数组中每一个数 $n_i$ 的

1. 右侧第一个比 $n_i$ 大的数

2. 左侧第一个比 $n_i$ 大的数

3. 右侧第一个比 $n_i$ 小的数

4. 左侧第一个比 $n_i$ 小的数

## 单调队列

维护区间（窗口）最小、最大值


## KMP 字符串

[OI WiKi 关于 KMP 的介绍](https://oi-wiki.org/string/kmp/)：通过**前缀函数**求 `next` 数组，以及 KMP 匹配、字符串的循环节等

```C++
// 求 next 数组
// ne[0] = 0;
for (int i = 1; i < n; i++) {
    int j = ne[i - 1];
    while (j && p[i] != p[j]) j = ne[j-1];
    if (p[i] == p[j]) j++;
    ne[i] = j;
}

// KMP 匹配过程
for (int i = 0, j = 0; i < m; i++) {
    while (j && s[i] != p[j]) j = ne[j-1];
    if (s[i] == p[j]) j++;
    if (j == n) {
        cout << i - n + 1 << " ";
        j = ne[j-1];
    }
}
```



