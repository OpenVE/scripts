package main

import (
	F "finance/finance"
	"flag"
	"strconv"
)

func main() {
	var r  = flag.Float64("r", 0, "Interest Rate")
	var n  = flag.Int("n", 0, "Number of periods")
	var d  = flag.Int("d", 4, "Digits after the decimal point")
	flag.Parse()
	ear := F.EAR(*r, *n)
	println(strconv.FormatFloat(ear, 'f', *d, 64))
}
