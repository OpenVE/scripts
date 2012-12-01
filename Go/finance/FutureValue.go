package main

import (
	F "finance/finance"
	"flag"
	"strconv"
)

func main() {
	var f  = flag.Float64("f", 0, "Fee")
	var pv = flag.Float64("pv", 0, "Present Value")
	var r  = flag.Float64("r", 0, "Interest Rate")
	var n  = flag.Int("n", 0, "Number of periods")
	var c  = flag.Bool("c", false, "Compounded Interest")
	var e  = flag.Bool("e", false, "Fees occurs early (at the beginning of the period)")
	var d  = flag.Int("d", 4, "Digits after the decimal point")
	flag.Parse()
	var fv float64
	var err error
	switch *f {
	case 0.0:
		fv, err = F.FV(*pv, *r, *n, *c)
	default:	
		fv, err = F.FVA(*f, *r, *n, *c, *e)
	}
	if err != nil {
		println(err.Error())
		return
	}
	println(strconv.FormatFloat(fv, 'f', *d, 64))
}
