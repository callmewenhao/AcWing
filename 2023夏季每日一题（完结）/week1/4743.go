package week1

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func AcWing4743(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var T int
	fmt.Fscan(in, &T)

	for cases := 1; cases <= T; cases++ {
		var L, n int
		fmt.Fscan(in, &L, &n)

		ans := 0
		last_d := 0
		for i := 0; i < n; i++ {
			var di int
			var ci string // 不想单独输入字符
			fmt.Fscan(in, &di, &ci)

			cur_d := last_d
			if ci == "C" {
				cur_d += di
			} else {
				cur_d -= di
			}

			ans += abs(cur_d / L) // 注意取abs
			last_d = cur_d % L
		}
		fmt.Fprintf(out, "Case #%v: %v\n", cases, ans)
	}
}

func main() {
	AcWing4743(os.Stdin, os.Stdout)
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
