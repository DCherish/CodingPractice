fun main() {
    val (N, S, P) = readLine()!!.split(' ').map { it.toInt() }

    var ans = 1

    if (N != 0) {
        val score = readLine()!!.split(' ').map { it.toInt() }

        val rank = score.count { it > S } + 1
        val blank = score.count { it >= S } + 1

        if (blank <= P) ans = rank
        else ans = -1
    }

    println(ans)
}