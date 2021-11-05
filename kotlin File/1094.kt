fun main() {
    var X = readLine()!!.toInt()

    var ans = 0

    while (X > 0) {
        if (X and 1 == 1) ans++

        X = X shr 1
    }

    println(ans)
}