package week1

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

// 使用了链式向前星建图，但还是没过😡

// 链式向前星
// N 是点的个数  M 是边的个数
const N, M = 200_010, N * 2

var h, w, cache [N]int
var e, ne [M]int
var idx int

func add(a, b int) {
	e[idx] = b     // e[idx]表示 idx编号的边 从a指向b
	ne[idx] = h[a] // ne[idx]表示 上一条从a出发的边的编号
	h[a] = idx     // h[a]表示 最后一条从a出发的边的编号
	idx++          // 更新边的编号
}

func dfs(x int) int {
	if cache[x] != 0 {
		return cache[x]
	}
	res := 1
	for i := h[x]; i != -1; i = ne[i] {
		y := e[i]
		if w[x] > w[y] {
			res += dfs(y)
		}
	}
	cache[x] = res
	return res
}

func AcWing4742(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var T int
	fmt.Fscan(in, &T)
	for cases := 1; cases <= T; cases++ {
		var n int
		fmt.Fscan(in, &n)
		for i := 1; i <= n; i++ {
			fmt.Fscan(in, &w[i])
		}

		// 重置关键数据结构
		idx = 0
		for i := 0; i <= n; i++ {
			h[i] = -1
		}

		// 加边
		for i := 1; i < n; i++ {
			var a, b int
			fmt.Fscan(in, &a, &b)
			add(a, b)
			add(b, a)
		}

		// ans
		ans := 0
		for i := 0; i <= n; i++ {
			cache[i] = 0
		}
		for i := 1; i <= n; i++ {
			ans = max(ans, dfs(i))
		}
		fmt.Fprintf(out, "Case #%v: %v\n", cases, ans)
	}
}

func main() {
	AcWing4742(os.Stdin, os.Stdout)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
