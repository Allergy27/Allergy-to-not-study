package main

import "fmt"

const N = 527

// func bfs(x, y, endx, endy int) {

// }

var qwq [N][N]int

func main() {
	var m, n int
	fmt.Scan(&n, &m)
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			fmt.Scanf("%d", qwq[i][j])
			qwq[i][j] = (qwq[i][j] + 1) % 2
		}
	}
}
