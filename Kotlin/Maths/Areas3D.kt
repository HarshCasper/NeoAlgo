package kotlin.math

// Area of a Cube

fun cube(a: Double): Double {
    return 6 * a * a
}

// Area of a Cuboid

fun cuboid(l: Double, b: Double, h: Double): Double{
    return 2 * ((l*b) + (b*h) + (h*l))
}

// Area of a Cone

fun cone(r: Double, l: Double): Double{
    return (PI * r * r) + (PI * r * l)
}

// Area of a Cylinder

fun cylinder(r: Double, h: Double): Double{
    return (2.0 * (PI * r * r)) + (r * h)
}

// Area of a Sphere

fun sphere(r: Double): Double{
    return 4.0 * PI * r * r
}
// Area of a Hemi Sphere

fun hemisphere(r: Double): Double{
    return (2.0 * PI * r * r) + (PI * r * r)
}


fun main() {
    println(cube(2.0))
    println(cuboid(2.0, 4.6, 3.5))
    println(cone(5.0, 4.0))
    println(cylinder(2.0,4.0))
    println(sphere(4.5))
    println(hemisphere(2.5))
}


// Time Complexity - O(n)
// Space Complexity - O(n)
