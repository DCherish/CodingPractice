fun main() {
    var (a, b) = readLine()!!.split(' ').map { it.toInt() }

    if (a < b) {
        a = b.also { b = a }
    }

    println(gcd(a, b))
    println(a * b / gcd(a, b))
}

fun gcd(a: Int, b: Int): Int {
    var x = a
    var y = b

    while (true) {
        var r = x % y

        if (r == 0) break

        x = y
        y = r
    }

    return y
}
