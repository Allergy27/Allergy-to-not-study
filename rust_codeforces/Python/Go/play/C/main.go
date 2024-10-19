package main

import "fmt"

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	if b >= a && b <= 6*a {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
