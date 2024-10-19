package luogu

import "fmt"

func main() {
	var res float64
	var Sn float64 = 0
	var tmp float64 = 0
	fmt.Scan(&res)
	for {
		tmp++
		if Sn+(1.0/tmp) > res {
			break
		}
		Sn += 1.0 / tmp
	}
	fmt.Printf("%.0f\n", tmp)
}
