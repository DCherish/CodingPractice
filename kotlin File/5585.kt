val coin = arrayOf(500, 100, 50, 10, 5, 1)

fun main() {
    var a = readLine()!!.toInt()

    a = 1000 - a

    var cnt = 0

    for (i in 0..5) {
        if (a / coin[i] > 0) {
            cnt += a / coin[i]

            a %= coin[i]
        }
    }

    println(cnt)
}
