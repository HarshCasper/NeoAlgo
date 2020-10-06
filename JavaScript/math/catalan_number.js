/*
Catalan numbers is a number sequence, which is found useful in a number of
combinatorial problems, often involving recursively-defined objects.
*/

var n = prompt("Enter the number:");

var c = [];

function catalan(n) {
    if (n == 0) return 1;
    if (!c[n]) {
        var s = 0;
        for (var i = 0; i < n; i++)
            s += catalan(i) * catalan(n - i - 1);
        c[n] = s;
    }
    return c[n];
}
document.write("Nth Catalan Number are:")
document.write("<br>");
for (var i = 0; i <= n; i++) {
    document.write(catalan(i));
    document.write("<br>");
}

/*
Input:
Enter the number:
15
Output:
Nth Catalan Number are:
1
1
2
5
14
42
132
429
1430
4862
16796
58786
208012
742900
2674440
9694845

Time Complexity: O(2^n)
Space Complexity: O(1)
*/