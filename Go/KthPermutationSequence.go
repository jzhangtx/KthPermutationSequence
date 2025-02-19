package main

import (
	"fmt"
)

func GetPermutations(vec []byte, index int, permutations *[][]byte) {
	if index == len(vec) {
		c := make([]byte, len(vec))
		copy(c, vec)
		*permutations = append(*permutations, c)
		return
	}

	for i := index; i < len(vec); i++ {
		vec[i], vec[index] = vec[index], vec[i]
		GetPermutations(vec, index+1, permutations)
		vec[i], vec[index] = vec[index], vec[i]
	}
}

func GetKthPermutation(n, k int) string {
	vec := make([]byte, n)
	for i := 0; i < n; i++ {
		vec[i] = byte(i + 1)
	}

	var permutations [][]byte
	GetPermutations(vec, 0, &permutations)

	if len(permutations) >= k {
		r := permutations[k-1]
		for i := 0; i < len(r); i++ {
			r[i] += '0'
		}
		s := string(r)
		return s
	}
	return ""
}

func main() {
	for {
		fmt.Print("The number: ")
		var n, k int
		fmt.Scan(&n)
		if n == 0 {
			break
		}

		fmt.Print("Which permutation do you want? ")
		fmt.Scan(&k)

		v := GetKthPermutation(n, k)
		fmt.Println("The ", k, "th permutation of 1 to ", n, " is ", string(v))
	}
}
