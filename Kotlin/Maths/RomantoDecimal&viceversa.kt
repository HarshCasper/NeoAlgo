package example

fun Int.toRomanNumeral(): String = Symbol.closestBelow(this)
    .let { symbol ->
        if (symbol != null) {
            "$symbol${(this - symbol.decimalValue).toRomanNumeral()}"
        } else {
            ""
        }
    }

fun String.toDecimal() : Int {
    return Symbol.highestStartingSymbol(this)
        .let{symbol ->
            if (symbol != null) {
                symbol.decimalValue + this.drop(symbol.name.length).toDecimal()
            } else {
                0
            }
        }
}

private enum class Symbol(val decimalValue: Int) {
    I(1),
    IV(4),
    V(5),
    IX(9),
    X(10),
    XL(40),
    L(50),
    XC(90),
    C(100),
    CD(400),
    D(500),
    CM(900),
    M(1000);

    companion object {
        fun closestBelow(value: Int) =
            values()
                .sortedByDescending { it.decimalValue }
                .firstOrNull { value >= it.decimalValue }

        fun highestStartingSymbol(value: String) =
            values()
            .sortedByDescending { it.decimalValue }
            .firstOrNull { value.startsWith(it.name) }
    }
}

fun main() {
    println(3575.toRomanNumeral()) // Input the decimal number that you want to convert into roman.
    println("MMDLXXXIII".toDecimal())  // Input the roman number that you want to convert into decimal.
}