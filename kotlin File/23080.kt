fun main() {
    val K = readLine()!!.toInt()
    val S = readLine()!!.toString()

    var ans = ""

    for (i in S.indices step K) {
        ans += S[i]
    }

    println(ans)
}