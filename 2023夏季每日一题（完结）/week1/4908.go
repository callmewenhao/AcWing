package week1

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func AcWing4908(r_ io.Reader, out io.Writer) {
	in := bufio.NewReader(r_)

	var n, t int
	fmt.Fscan(in, &n, &t)

	var last, cur, ans int
	for i := 0; i <= n; i++ {
		var d, b int
		fmt.Fscan(in, &d, &b)
		days := min(d-1-last, cur)
		ans += days
		cur -= days + b
		last = d - 1
	}
	ans += min(cur, t-last)
	fmt.Fprint(out, ans)
}

func AcWing49081(r_ io.Reader, out io.Writer) {
	in := bufio.NewReader(r_)

	var n, t int
	fmt.Fscan(in, &n, &t)

	var d, b, endTime, ans int
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &d, &b)

		if d > t { // 天数范围判断
			fmt.Fprint(out, ans)
			return
		}
		// end time 维护
		if endTime >= d {
			b += endTime - d + 1
			ans -= endTime - d + 1
		}
		// 天数范围判断
		if (d + b - 1) >= t {
			ans += t - d + 1
			fmt.Fprint(out, ans)
			return
		}
		// 更新
		ans += b
		endTime = d + b - 1
	}
	fmt.Fprint(out, ans)
}

func main() {
	AcWing4908(os.Stdin, os.Stdout)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
