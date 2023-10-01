package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

const N = 100_010

var dp = [N]int{}

func init() {
	for i := range dp {
		dp[i] = math.MaxInt
	}
	dp[0] = 0
	for i := 1; i < N; i++ {
		dp[i] = min(dp[i], dp[i-1]+1)
		for k := 1; i+k*i < N; k++ {
			j := i + k*i
			dp[j] = min(dp[j], dp[i]+4+k*2)
		}
	}
}

func AcWing4741(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var T int
	fmt.Fscan(in, &T)

	for cases := 1; cases <= T; cases++ {
		var n int
		fmt.Fscan(in, &n)
		res := dp[n]
		fmt.Fprintf(out, "Case #%v: %v\n", cases, res)
	}
}

func main() {
	AcWing4741(os.Stdin, os.Stdout)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
