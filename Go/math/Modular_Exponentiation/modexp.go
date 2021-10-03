package modexp

import (
	"fmt"
	"math/big"
)

// ModExpGoBigInteger calculates modular exponentiation using math/big package.
func ModExpGoBigInteger(base, exponent, modulus int64) int64 {
	return new(big.Int).Mod(new(big.Int).Exp(big.NewInt(base), big.NewInt(exponent), nil), big.NewInt(modulus)).Int64()
}

// ModExpGoBigIntegerExp calculates modular exponentiation using native Exp method from math/big package.
func ModExpGoBigIntegerExp(base, exponent, modulus int64) int64 {
	return new(big.Int).Exp(big.NewInt(base), big.NewInt(exponent), big.NewInt(modulus)).Int64()
}

// ModExp calculates modular exponentiation in O(exponent).
func ModExp(base, exponent, modulus int64) int64 {
	if modulus == 1 {
		return 0
	}
	base = base % modulus
	result := int64(1)
	for i := int64(0); i < exponent; i++ {
		result = (result * base) % modulus
	}
	return result
}

// ModExpWithSquaring calculates modular exponentiation with exponentiation by squaring, O(log exponent).
func ModExpWithSquaring(base, exponent, modulus int64) int64 {
	if modulus == 1 {
		return 0
	}
	if exponent == 0 {
		return 1
	}

	result := ModExpWithSquaring(base, exponent/2, modulus)
	result = (result * result) % modulus
	if exponent&1 != 0 {
		return ((base % modulus) * result) % modulus
	}
	return result % modulus
}

func main() {
	fmt.Print(ModExp(123, 343, 34))
}
