package week1

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

// https://www.acwing.com/problem/content/description/4443/

func AcWing4440(r_ io.Reader, out io.Writer) {
	in := bufio.NewReader(r_)

	var l, n int
	var cows []byte
	fmt.Fscan(in, &l)
	fmt.Fscan(in, &cows)

	nums := make([]int, l/2)
	for i := 0; i < l/2; i++ {
		a := cows[i*2]
		b := cows[i*2+1]

		fmt.Println(a, b)
		if a == b {
			continue
		}
		// save num
		if a == 'G' {
			nums[n] = 1
		} else {
			nums[n] = 0
		}
		n++
	}
	//fmt.Println(nums, n)

	f := make([][2]int, n+1)
	for i := 1; i <= n; i++ {
		if nums[i-1] == 1 {
			f[i][0] = f[i-1][1] + 1
			f[i][1] = f[i-1][1]
		} else {
			f[i][0] = f[i-1][0]
			f[i][1] = f[i-1][0] + 1
		}
		//fmt.Println(f[i])
	}
	fmt.Fprint(out, f[n][0])
}

func main() {
	AcWing4440(os.Stdin, os.Stdout)
}
