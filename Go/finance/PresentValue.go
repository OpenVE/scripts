package main

import (
	F "finance/finance"
	"flag"
	"strconv"
)

func main() {
	var f  = flag.Float64("f", 0, "Fee")
	var fv = flag.Float64("fv", 0, "Future Value")
	var r  = flag.Float64("r", 0, "Interest Rate")
	var n  = flag.Int("n", 0, "Number of periods")
	var c  = flag.Bool("c", false, "Compounded Interest")
	var e  = flag.Bool("e", false, "Fees occurs early (at the beginning of the period)")
	var d  = flag.Int("d", 4, "Digits after the decimal point")
	flag.Parse()
	var pv float64
	var err error
	switch *f {
	case 0.0:
		pv, err = F.PV(*fv, *r, *n, *c)
	default:	
		pv, err = F.PVA(*f, *r, *n, *c, *e)
	}
	if err != nil {
		println(err.Error())
		return
	}
	println(strconv.FormatFloat(pv, 'f', *d, 64))
}
