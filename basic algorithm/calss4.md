[TOC]

# 数论

## 预备知识：

### 0. 调和级数：

$1 + \frac{1}{2} +  \frac{1}{3}+ \cdots + \frac{1}{n} = ln(n)$

### 1. 费马小定理

如果 $p$ 是一个质数，而整数 $a$ 不是 $p$ 的倍数，则有 $a^p = a (\%p) \Longrightarrow a^{p-1} \equiv 1\ (\%p)$

应用举例：计算 $2^{100}\ \%\ 13$

解：
由费马小定理可知，$a^{12} \equiv 1\ (\%13)$，当 $a=12$ 时，有
$$
2^{100}\ \%\ 13 = 2^{12 * 8 + 4}\ \%\ 13 = 2^{12 * 8} * 2^4\ \%\ 13 = (2^{12})^8 * 2^4\ \%\ 13 = 1 * 16\ \%\ 13 = 3
$$

### 2. 裴蜀定理

对于任何整数 $a,\ b$ 和他们的最大公约数 $gcd(a, b) = d$，那么对于任意的整数$x,\ y,\ ax+by$都一定是 $d$ 的倍数，特别地，一定存在整数 $x,\ y$，使 $ax+by=d$ 成立。一个重要推论是：$a,\ b$ 互质的**充分必要条件**是存在整数 $x,\ y$ 使 $ax+by=1$


## 质数

在大于 1 的整数中，如果只包含 1 和本身这两个约数，就被称为质数，或者叫素数

**质数定理**：$[1,\ n]$ 中有 $\frac{n}{ln(n)}$ 个质数

### 质数的判定——试除法

从 $2$ 到 $n-1$ 看能否出现 $n$ 的除数，如果有则表明 $n$ 不是质数。

优化：约数总是成对出现，比如：$b$ 和 $n/b$，所以只需要枚举到 $b$ 的最大值就行，也就是：$b = n/b => b = sqrt(n)$。时间复杂度：**严格意义上的** `O(sqrt(n))`

```C++
// y总推荐的写法 不会溢出、也不耗时
bool is_prime(int a) {
    if (a < 2) return false;
    for (int i = 2; i <= a / i; i++) {
        if (a % i == 0) return false;
    }
    return true;
}
```
###  分解质因数——试除法

性质：$n$ 中最多只包含一个大于 $sqrt(n)$ 的质因子，比如：$n=15$ 时，只包含一个大于 $sqrt(15)$ 的质因子 $5$。

时间复杂度：**并不是严格意义上的** `O(sqrt(n))`，比如：$n = 2^x$ 时，时间复杂度是 $log(n)$。

```C++
void divide(int a) {
    for (int i = 2; i <= a / i; i++) {
        if (a % i == 0) {
            int s = 0;
            // 把这个质因子不断除掉
            while (a % i == 0) {
                a /= i;
                s++;
            }
            cout << i << " " << s << endl;
        }
    }
    // 处理大于 sqrt(n) 的质因子
    if (a > 1) cout << a << " " << 1 << endl;
    cout << endl;
}
```

### 筛质数

#### 埃氏筛法

时间复杂度：`O(n*loglogn)`

```C++
const int N = 1e6 + 7;
int cnt, primes[N];
bool st[N]; // 不是质数
// 埃氏筛法
void get_primes(int n) {
    // 质数从 2 开始
    for (int i = 2; i <= n; i++) {
        // 是质数
        if (!st[i]) {
            primes[cnt++] = i;
            // 抹掉质数的倍数
            for (int j = 2 * i; j <= n; j += i) {
                st[j] = true;
            }
        }
    }
}
```

#### 线性筛法

用每一个**合数**的**最小质因子**筛（代码保证了这一点），由于每个数只有一个最小质因子，所以每一个数都能被筛掉，且只会被筛一次，因此该算法称为**线性筛**😊。

时间复杂度：`O(n)`

```C++
// 线性筛
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        // 当前是质数
        if (!st[i]) primes[cnt++] = i;
        // 使用已有的质数 和 i 筛合数
        for (int j = 0; primes[j] <= n / i; j++) { // 保证使用最小质因子筛合数
            st[primes[j] * i] = true;
            // 保证使用最小质因子筛合数
            if (i % primes[j] == 0) break;
        }
    }
}
```

## 约数

### 试除法求约数

时间复杂度：`O(sqrt(n))`

```C++
// 与试除法求质数一样的
vector<int> get_divisors(int a) {
    vector<int> res;
    for (int i = 1; i <= a / i; i++) {
        if (a % i == 0) {
            // 约数成对出现，需要判重
            res.push_back(i);
            if (i != a / i) {
                res.push_back(a / i);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}
```

### 约数个数

> 在 `int` 范围内（-2e9～2e9），约数最多的数有 1536 个约数。

将一个数 $a$ 分解质因数：$a = p_{1} ^ {\alpha_1} * p_{2} ^ {\alpha_2} * p_{3} ^ {\alpha_3} * \cdots * p_{k} ^ {\alpha_k}$

则 $a$ 的约数个数为：$(\alpha_1 + 1) * (\alpha_2 + 1) * (\alpha_3 + 1)* \cdots * (\alpha_k+ 1)$

举例：$a = 12 = 2^2 + 3^1$，则 $a$ 的**约数个数**为：$(2 + 1) * (1 + 1) = 3 * 2 = 6$

### 约数之和

将一个数 $a$ 分解质因数：$a = p_{1} ^ {\alpha_1} * p_{2} ^ {\alpha_2} * p_{3} ^ {\alpha_3} * \cdots * p_{k} ^ {\alpha_k}$

则 $a$ 的约数之和为：$(p_{1}^0 + p_{1}^1 + \cdots + p_{1}^{\alpha_1}) * (p_{2}^0 + p_{2}^1 + \cdots + p_{2}^{\alpha_2}) * \cdots * (p_{k}^0 + p_{k}^1 + \cdots + p_{k}^{\alpha_k})$

举例：$a = 12 = 2^2 + 3^1$，则 $a$ 的**约数之和**为：$(2^0 + 2^1 + 2^2) * (3^0 + 3^1) = 7 * 4 = 28
$

```C++
// 计算个数
LL ans = 1;
for (auto [b, p]: primes) {
    LL t = 1; 
    while (p--) t = (t * b + 1) % MOD;  // 实现很有意思😁
    ans = ans * t % MOD;
}
```

### 最大公约数——欧几里得算法

欧几里得算法又叫 **辗转相除算法**，计算公式 $gcd(a,\ b) = gcd(b,\ a\%b)$

时间复杂度：`O(logn)`

```C++
// a b 的大小其实无所谓
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
```

## 欧拉函数

### 单个数的欧拉函数

> 互质定义：两个数**没有**除了 1 以外的其他公约数称为互质，例如：5 和 6 互质

欧拉函数定义：$[1, n)$ 中与 $n$ 互质的数的个数，举例：$\varphi(6) = 2 = \{1, 5\}$。特殊的，一个质数 $n$ 的欧拉函数值是 $n-1$

将一个数 $a$ 分解质因数：$a = p_{1} ^ {\alpha_1} * p_{2} ^ {\alpha_2} * p_{3} ^ {\alpha_3} * \cdots * p_{k} ^ {\alpha_k}$，则其**欧拉函数值**为：$\varphi(a) = a(1-\frac{1}{p_{1}})(1-\frac{1}{p_{2}})\cdots(1-\frac{1}{p_{k}})$，时间复杂度：与分解质因数相同，不是严格意义上的 `O(sqrt(n))`

借助**容斥原理**解释：

1. 从1~N中去掉 p1，p2，...，pk 的所有倍数
2. 加上所有 pi * pj 的倍数
3. 减去所有 pi * pj * pk 的倍数
4. ...

```C++
int res = a;
for (int i = 2; i <= a / i; i++) {
    if (a % i == 0) {
        // 为了防止出现小数强转整数的情况
        res = res / i * (i - 1);  // 先除再乘防止爆 int
        while (a % i == 0) {
            a /= i;
        }
    }
}
// 最后的质数处理
if (a > 1) res = res / a * (a - 1); // 注意这里 res 还是 a 的倍数 所以可以先除，不然不能先除
```

### 筛法求欧拉函数

求出 $[1, n]$ 中每一个数的欧拉函数值。如果对每一个数求欧拉函数，时间复杂度是 `O(n*sqrt(n))`，借助之前线性筛法，实现一个 `O(n)` 的算法。核心思想和线性筛一致：借助已经求出来的欧拉函数值更新后面的欧拉函数值

```C++
phi[1] = 1; // 1 的欧拉函数值被定义为 1
for (int i = 2; i <= n; i++) {
    if (!st[i]) {
        primes[cnt++] = i;
        // 质数的欧拉函数值是 i-1
        phi[i] = i - 1;
    }
    for (int j = 0; primes[j] <= n / i; j++) {
        st[primes[j] * i] = true;
        if (i % primes[j] == 0) {
            // 当 pj 是 i 的质因子时
            // phi[i] 已经包含 (1 - 1/pj)
            // phi[pj * i] 就是 phi[i] * pj
            phi[primes[j] * i] = phi[i] * primes[j];
            break;
        }
        // 当 pj 不是 i 的质因子时
        // phi[pj * i] = phi[i] * pj * (1 - 1/pj) = phi[i] *(pj - 1)
        phi[primes[j] * i] =  phi[i] * (primes[j] - 1); // 这个是公式化简后的结果
    }
}
```

## 快速幂

快速幂又叫二进制取幂（Binary Exponentiation，也称平方法），快速地求出 $a^k\  \% \ p$ 的结果，时间复杂度：`O(logk)`，其中，$1 <= a, p, k <= 1e9$

借助 $k$ 的二进制表示，优化求取 $a^k\  \% \ p$ 的过程。把 $a^k$ 中的 k 拆成二进制表示：$k = 2^0 + 2^1 + \cdots + 2^i$，我们只要能计算出 $a^{2^i}\  \% \ p$ ，就能 `logk` 的计算出 $a^k\  \% \ p$ 的结果

```C++
int res = 1;
while (k) {
    // 对应的位置为 1
    if (k & 1) res = (LL)res * a % p;
    k >>= 1;
    a = (LL) a * a % p;  // 平方一下
}
return res;
```

### 快速幂求逆元

> AcWing的**模意义下乘法逆元**的定义：
> 
> 若整数 $b，m$ 互质，并且对于任意整数 $a$，如果满足 $b|a$（$b$ 整除 $a$），则存在一个整数 $x$，使得 $a/b≡a×x(\%\ m)$，则称 $x$ 为 $b$ 的模 $m$ 乘法逆元，记为 $b^{−1}(mod\ m)$。

更好理解的**模意义下乘法逆元**的定义：

如果一个线性同余方程 $ax \equiv 1 \pmod b$，则 $x$ 称为 $a \bmod b$ 的逆元，记作 $a^{-1}$。

$a$ 存在乘法逆元的充要条件是 $a$ 与模数 $b$ 互质（也就是说当 $a$ 是 $b$ 的被倍数时，不存在逆元）。当模数 $b$ 为质数时，由预备知识**费马小定理**，$a^{b−2} (mod\ b)$ 即为 $a$ 的乘法逆元。推导：$a^{b-1} = 1 (\%b)  \ =>\ a * a^{b-2} = 1 (\%b)$，所以乘法逆元的本质就是一个快速幂的计算。

**注意对比**：快速幂法使用了费马小定理，要求 $b$ 是一个素数，而扩展欧几里得法只要求 $gcd(a, b) = 1$

```C++
int res = qmi(a, p-2, p);
// 要先判断是否有逆元
if (a % p) cout << res << endl;
else cout << "impossible" << endl;
```

## 扩展欧几里得算法

### 裴蜀定理中的 x 和 y

扩展欧几里得算法：在使用 **欧几里得算法** 计算 gcd 的时候，顺便计算出 **裴蜀定理** 中的 x 和 y。扩展欧几里得算法是借助 **裴蜀定理**，在递归调用前后，通过 gcd 相等，构造一个等式，然后求解出当前的 x 和 y

**公式推导**：

由 **欧几里得算法** 可知，exgcd(a, b, x, y) = d = exgcd(b, a % b, y, x)

再根据 **裴蜀定理**，第一个式子推出 $a*x + b*y = d$，第二个式子推出 $(a\%b)*x' + b*y' = d$，从而得到等式：$a*x + b*y = (a\%b)*x' + b*y'$

假设 $a\%b = a - k*b, k=a/b$，则 $(a\%b)*x' + b*y' = (a - k * b)*x' + b*y' = a*x' + b*(y'-k*x')$，故有，$a*x + b*y = a*x' + b*(y'-k*x')$，根据对应系数相等，得更新公式：

$$
x = x' \\
y = y'-k*x' = y' -a/b * x'
$$

在函数实现时，先通过递归调用 exgcd(b, a % b, y, x) 计算出了 $x'\ y'$，再通过更新公式计算出 $x\ y$

```C++
int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    // x 不变
    // y 更新
    y -= a / b * x;
    return d;
}

// 一个更好理解得代码版本
int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int x_ = 0, y_ = 0;
    int d = exgcd(b, a % b, y_, x_);
    x = x_;
    y = y_ -  a / b * x_;
    return d;
}
```

### 线性同余方程

对于给定的 $a,\ b,\ m$，求一个数 $x$ 使得 $a * x = b\pmod m$，这种方程称为线性同余方程，注意方程可能无解。


**公式推导**：

借助 **扩展欧几里得算法** 求解，方程 $a*x = b\pmod m$ 先转化为 $a*x = m*y + b$，再移项为 $a*x - m*y = b$，由于 $y$ 可以取负值，因此把负号放入 $y$ 中得到 $a*x + m*y = b$

对于式子 $a*x' + m*y' = gcd(a, m)$ 中的 $x'$ 可以使用 **扩展欧几里得算法** 计算，则所求的 $x$ 就是 **扩展欧几里得算法** 的解 $x'$ 的 $b\ /\ gcd(a, m)$ 倍

显然，方程有解的前提是：$b$ 可以整除 $gcd(a, m)$，也就是 $b$ 必须是 $gcd(a, m)$ 的倍数

```C++
int d = exgcd(a, m, x, y);
if (b % d) cout << "impossible" << endl;
else cout << (LL) x * (b / d) % m << endl;  // 最后还需要 mod m
```

### 扩展欧几里得求逆元

求 $a \bmod b$ 意义下的逆元 $x$，前提是 $a$ 和 $b$ 互质：$gcd(a, b) = 1$，公式推导如下：

$$
a * x \equiv 1 \pmod b \\
a * x \equiv b * y' + 1 \pmod b \\
a * x - b * y'\equiv 1 \pmod b \\
a * x + b * y\equiv 1 \pmod b \\
$$

故，$a \bmod b$ 意义下的逆元 $x$ 就是 `exgcd` 中的参数 `x`


## 中国剩余定理

中国剩余定理 (Chinese Remainder Theorem, CRT) 可求解**如下形式（和前面的线性同余方程形式不同）的一元线性同余方程组**（其中 $n_1$, $n_2$, $\cdots$, $n_k$ **两两互质，但不保证全部是质数**）：

$$
\begin{cases}
    &x \equiv a_1\ (mod\ n_1) \\
    &x \equiv a_2\ (mod\ n_2) \\
    & \vdots\\
    &x \equiv a_k\ (mod\ n_k) \\
\end{cases}
$$

求解过程：

1. 计算所有模数的积 $n$
2. 对于第 i 个方程：
    - 计算 $m_i = \frac{n}{n_i}$，这就意味着 $m_i$ 与 $n_i$ 互质
    - 计算 $m_i$ 在模 $n_i$ 意义下的逆元 $m_i^{-1}$，借助扩展欧几里得算法求逆元
    - 计算 $c_i = m_i*m_i^{-1}$ （不要对 $n_i$ 取模）
3. 方程组在模 $n$ 意义下的唯一解为：$x = \sum_{i=1}^{k}a_ic_i\ (mod\ n)$ 

[这个题目](https://www.acwing.com/problem/content/206/) 并不满足中国剩余定理中互质的条件，需要进行额外的处理



## 高斯消元

### 高斯消元解线性方程组

异或运算 == 不进位的加法





### 高斯消元解异或线性方程组



## 组合数

组合数公式：

$$
C_a^b = \frac{a!}{(a-b)!b!} = \frac{a*(a-1)*\cdots*(a-b+1)}{b*(b-1)*\cdots*1}
$$

另一个重要的组合数公式：$C_n^0 + C_n^1 + C_n^2 + \cdots + C_n^{n-1} + C_n^n = 2^n$ 推导出 $C_n^1 + C_n^2 + \cdots + C_n^{n-1} + C_n^n = 2^n - 1$

### 组合数 1

数据范围：$1 <= a, b <= 2000$，使用 **递推** 进行预处理

```C++
for (int i = 0; i < N; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) {
        c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    }
}
```

### 组合数 2

数据范围：$1 <= a, b <= 1e5$

借助逆元，分解组合数的公式，预处理出来阶乘和阶乘的逆元

```C++
// 预处理阶乘和阶乘逆元
fact[0] = infact[0] = 1;
for (int i = 1; i < N; i++) {
    fact[i] = (LL)fact[i-1] * i % mod;
    infact[i] = (LL)infact[i-1] * qmi(i, mod-2, mod) % mod;
}

int n;
cin >> n;

while (n--) {
    int a, b;
    cin >> a >> b;
    cout << (LL)fact[a] * infact[b] % mod * infact[a - b] % mod << endl;
}
```

### 组合数 3

数据范围：$1 <= a, b <= 1e18,\ 1 <= p <= 1e5$

使用 [**卢卡斯**](https://oi-wiki.org/math/number-theory/lucas/) 定理，Lucas 定理用于求解大组合数取模的问题，其中模数必须为素数

```C++
int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int C(int a, int b, int p)
{
    if (b > a) return 0;
    int res = 1;
    for (int i = 1, j = a; i <= b; i ++, j -- )
    {
        res = (LL)res * j % p;
        res = (LL)res * qmi(i, p - 2, p) % p;
    }
    return res;
}

int lucas(LL a, LL b, int p)
{
    if (a < p && b < p) return C(a, b, p);
    return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}
```

### 组合数 4

数据范围：$1 <= a, b <= 5000$，但是不**模**某个数，结果可能很大，需要使用高精度计算。

### 卡特兰数

[卡特兰数定义](https://oi-wiki.org/math/combinatorics/catalan/)

**Catalan** 数 $H_n$ 的常见公式:

$$
H_n = C_{2n}^{n} - C_{2n}^{n-1} = \frac{C_{2n}^{n}}{n+1} = \frac{H_{n-1}(4n-2)}{n+1}
$$

## 容斥原理

m 个集合组成的交集中元素的个数：$S = S_1\cup\cdots\cup S_m =\sum_{i}S_i - \sum_{i, j}S_i\cap S_j + \sum_{i, j, k}S_i\cap S_j\cap S_k + \cdots + (-1)^{m-1}S_1\cap\cdots\cap S_m$

容斥原理的时间复杂度为 $2^m$，其中 m 是集合的个数。一般地，如果题目中 m 的范围不大，可以借助位运算优化算法，容斥原理和位运算基本绑定

## 博弈论

### Nim 游戏

给定 n 堆石子，两位玩家轮流操作，每次操作可以从任意一堆石子中拿走任意数量的石子（可以拿完，但不能不拿），最后无法进行操作的人视为失败。问如果两人都采用最优策略，先手是否必胜。

分析：当前 n 堆石子可以分成 2 种状态：**必胜状态**和**必败状态**，必胜状态是指：从当前状态出发，可以拿掉某一堆的某些石子，使得状态变成必败状态；必败状态是指：从当前状态出发，无论怎么拿石子，状态都会变成必胜状态

如果先手是必胜状态，那么先手必胜；否则先手必败

代码一分钟😁：异或定义**必胜状态**和**必败状态**：所有石子堆个数**异或和不为 0** 表示**先手必胜**状态，否则先手必败

### 台阶-Nim游戏

台阶-Nim 游戏只看奇数台阶时，就是原本的 Nim 游戏

### 集合-Nim游戏

给定 n 堆石子以及一个由 k 个不同正整数构成的数字集合 S

现在有两位玩家轮流操作，每次操作可以从任意一堆石子中拿取石子，每次拿取的石子数量必须包含于集合 S ，最后无法进行操作的人视为失败

问如果两人都采用最优策略，先手是否必胜

计算每一堆石子初始值的 $SG(x_0)$ 值。如果所有石子堆的 SG 值异或结果等于 0，就是必败状态；如果等于 1，就是必胜状态。代码实现时使用 记搜 计算石子堆初始值的 SG 值

### 拆分-Nim游戏

给定 n 堆石子，两位玩家轮流操作，每次操作可以取走其中的一堆石子，然后放入两堆规模更小的石子（新堆规模可以为 0 ，且两个新堆的石子总数可以大于取走的那堆石子数），最后无法进行操作的人视为失败。

问如果两人都采用最优策略，先手是否必胜。

不同游戏的 sg 计算方式不同，这里是拆分石头堆，相当于一堆大石头分成两堆小石头。另外根据 sg 定理，这两队石头的 sg 值是各自 sg 值的异或，最终 sg 值就是 mex 所有拆分的 sg 值






