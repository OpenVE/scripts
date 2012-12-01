package main

import (
	F "finance/finance"
	"flag"
	"strconv"
)

func main() {
	var pv = flag.Float64("pv", 0, "Present Value")
	var r  = flag.Float64("r", 0, "Interest Rate")
	var n  = flag.Int("n", 0, "Number of periods")
	var c  = flag.Bool("c", false, "Compounded Interest")
	var d  = flag.Int("d", 4, "Digits after the decimal point")
	flag.Parse()
	f := F.Fee(*pv, *r, *n, *c)
	println(strconv.FormatFloat(f, 'f', *d, 64))
}
