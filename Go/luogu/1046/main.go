package main

import "fmt"

func main() {
	var tree [10]int
	var capale int
	var num int = 0
	for i := 0; i < 10; i++ {
		fmt.Scan(&tree[i])
	}
	fmt.Scan(&capale)
	capale += 30
	for i := 0; i < 10; i++ {
		if capale >= tree[i] {
			num++
		}
	}
	fmt.Println(num)
}
