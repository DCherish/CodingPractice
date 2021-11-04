import kotlin.math.*

fun main() {
    val dp = Array<Int>(5001) { -1 }

    val N = readLine()!!.toInt()

    dp[3] = 1
    dp[5] = 1

    for (i in 6..N) {
        if (dp[i - 5] == -1) {
            if (dp[i - 3] == -1) continue

            dp[i] = dp[i - 3] + 1
        } else if (dp[i - 3] == -1) {
            dp[i] = dp[i - 5] + 1
        } else {
            dp[i] = min(dp[i - 3], dp[i - 5]) + 1
        }
    }

    println(dp[N])
}