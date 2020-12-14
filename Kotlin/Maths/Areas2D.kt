package kotlin.math

// Area of a Square

fun square(a: Double): Double {
    return a * a
}

// Area of a Reactangle

fun rectangle(l: Double, b: Double): Double{
    return l * b
}

// Area of a Circle

fun circle(r: Double): Double{
    return PI * r * r
}

// Area of a Triangle

fun triangle(b: Double, h: Double): Double{
    return b * h/2.0
}

// Area of a Parallelogram

fun parallelogram(b: Double, h: Double): Double{
    return b * h
}

// Area of a Trapezium

fun trapezium(a: Double, b:Double, h:Double): Double{
    return (a+b)*h/2.0
}


fun main() {
    println(square(2.0))
    println(rectangle(2.0, 4.6))
    println(circle(3.0))
    println(triangle(2.0,3.0))
    println(parallelogram(4.5,2.3))
    println(trapezium(1.5,4.5,6.0))
}

// Time Complexity - O(n)
// Space Complexity - O(n)
