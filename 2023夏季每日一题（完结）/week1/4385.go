package week1

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func AcWing4385(r_ io.Reader, out io.Writer) {
	in := bufio.NewReader(r_)

	var T int
	fmt.Fscan(in, &T)

	for k := 1; k <= T; k++ {
		var I, P []byte
		fmt.Fscan(in, &I, &P)
		n, m := len(I), len(P)

		// 双指针
		var i, j int
		for ; i < n; i++ {
			for j < m && P[j] != I[i] {
				j++
			}
			if j == m {
				fmt.Fprintf(out, "Case #%v: IMPOSSIBLE\n", k)
				break
			}
			j++
		}
		if i == n {
			fmt.Fprintf(out, "Case #%v: %v\n", k, m-n)
		}
	}
}

func main() {
	AcWing4385(os.Stdin, os.Stdout)
}
