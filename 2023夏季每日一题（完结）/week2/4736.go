package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func AcWing4736(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var T int
	fmt.Fscan(in, &T)

	for cases := 1; cases <= T; cases++ {
		var M, N, P int
		fmt.Fscan(in, &M, &N, &P)
		S := make([][]int, M)
		for i := range S {
			S[i] = make([]int, N)
			for j := range S[i] {
				fmt.Fscan(in, &S[i][j])
			}
		}

		ans := 0
		for j := 0; j < N; j++ {
			mx := 0
			for i := 0; i < M; i++ {
				if S[mx][j] < S[i][j] {
					mx = i
				}
			}
			ans += S[mx][j] - S[P-1][j]
		}
		fmt.Fprintf(out, "Case #%v: %v\n", cases, ans)
	}
}

func main() {
	AcWing4736(os.Stdin, os.Stdout)
}
