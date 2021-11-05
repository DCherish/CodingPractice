val dp = Array(30) { Array(30) { 0 } }

fun main() {
    pre_setting()

    val T = readLine()!!.toInt()

    val ans = ArrayList<Int>()

    for (i in 0 until T) {
        var (N, M) = readLine()!!.split(' ').map { it.toInt() }

        if (M / 2 < N) N = M - N

        ans.add(dp[M][N])
    }

    for (i in ans) {
        println(i)
    }
}

fun pre_setting() {
    for (i in 1..29) {
        dp[i][0] = 1
        dp[i][1] = i
        for (j in 2..i) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
        }
    }
}