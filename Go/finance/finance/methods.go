package finance

import (
	"errors"
	"math"
)

const (
	zero_float64 float64 = 0.0
	zero int = 0
)

// Future Value
// -    `pv` is the present value.
// -    `rate` is the Interest Rate per period.
// -    `periods` is the number of periods.
// -	`compounded` is if the interest rate is compounded.
func FV (pv, rate float64, periods int, compounded bool) (float64, error) {
	if pv == zero_float64 {
		return zero_float64, errors.New("Future Value requires a present value (pv)")
	}
	if rate == zero_float64 {
		return zero_float64, errors.New("Future Value requires an interest rate")
	}
	if periods == zero {
		return zero_float64, errors.New("Future Value requires a number of periods")
	}
	p64 := float64(periods)
	if compounded {
		// Compounded Interest
		rate /= p64
	}
	// Future Value Interest Factor
	fvif := math.Pow(1 + rate, p64)
	fv := pv * fvif
	return fv, nil
}

// Present Value
// -    `fv` is the future value.
// -    `rate` is the Interest Rate per period.
// -    `periods` is the number of periods.
// -	`compounded` is if the interest rate is compounded.
func PV (fv, rate float64, periods int, compounded bool) (float64, error) {
	if fv == zero_float64 {
		return zero_float64, errors.New("Present Value requires a future value (fv)")
	}
	if rate == zero_float64 {
		return zero_float64, errors.New("Present Value requires an interest rate")
	}
	if periods == zero {
		return zero_float64, errors.New("Present Value requires a number of periods")
	}
	p64 := float64(periods)
	if compounded {
		// Compounded Interest
		rate /= p64
	}
	// Present Value Interest Factor
	pvif := math.Pow(1 + rate, -p64)
	pv := fv * pvif
	return pv, nil
}

// Effective or Equivalent Annual Rate
// -    `rate` is the Interest Rate per period.
// -    `periods` is the number of periods.
func EAR (rate float64, periods int) float64 {
	p64 := float64(periods)
	return math.Pow(1 + (rate/p64), p64) - 1
}

// Future Value of an Annuity
// -    `fee` is the ammount of money that is included in the calculation every period.
// -    `rate` is the Interest Rate per period.
// -    `periods` is the number of periods.
// -	`compounded` is if the interest rate is compounded.
// -    `early` is if the payments happen at the beggining of the periods and not at the end.
func FVA (fee, rate float64, periods int, compounded, early bool) (float64, error) {
	if fee == zero_float64 {
		return zero_float64, errors.New("Future Value of an Annuity requires a periodic value (p)")
	}
	if rate == zero_float64 {
		return zero_float64, errors.New("Future Value of an Annuity requires an interest rate (r)")
	}
	if periods == zero {
		return zero_float64, errors.New("Future Value of an Annuity requires a number of periods (n)")
	}
	p64 := float64(periods)
	if compounded {
		// Compounded Interest
		rate /= p64
	}
	// Future Value Interest Factor of an Annuity
	fvifa := (math.Pow(1 + rate, p64) - 1) / rate
	fv := fee * fvifa
	if early {
		return fv * (1 + rate), nil
	}
	return fv, nil
}

// Present Value of an Annuity
// -    `fee` is the ammount of money that is included in the calculation every period.
// -    `rate` is the Interest Rate per period.
// -    `periods` is the number of periods.
// -	`compounded` is if the interest rate is compounded.
// -    `early` is if the payments happen at the beggining of the periods and not at the end.
func PVA (fee, rate float64, periods int, compounded, early bool) (float64, error) {
	if fee == zero_float64 {
		return zero_float64, errors.New("Present Value of an Annuity requires a fee")
	}
	if rate == zero_float64 {
		return zero_float64, errors.New("Present Value of an Annuity requires an interest rate")
	}
	if periods == zero {
		return zero_float64, errors.New("Present Value of an Annuity requires a number of periods")
	}
	p64 := float64(periods)
	if compounded {
		// Compounded Interest
		rate /= p64
	}
	// Present Value Interest Factor of an Annuity
	pvifa := (1 - math.Pow(1 + rate, -p64)) / rate
	pv := fee * pvifa
	if early {
		return pv * (1 + rate), nil
	}
	return pv, nil
}

func Fee (pv, rate float64, periods int, compounded bool) float64 {
	p64 := float64(periods)
	if compounded {
		// Compounded Interest
		rate /= p64
	}
	// Present Value Interest Factor of an Annuity
	pvifa := (1- math.Pow(1 + rate, -p64)) / rate
	return pv / pvifa
}
