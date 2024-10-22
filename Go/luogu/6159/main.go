package main

import "fmt"

func main() {
	var n int64
	var p int64
	var k int64
	fmt.Scan(&n, &p, &k)
	fmt.Println((p * k) % n)
}
