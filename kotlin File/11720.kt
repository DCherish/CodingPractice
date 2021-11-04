fun main() {
    val N = readLine()!!.toInt()

    val arr = readLine()!!.toString()

    var ans = 0

    for (i in 0 until N) {
        ans += arr[i] - '0'
    }

    println(ans)
}