fun main() {
    var ans = arrayOf<Int>(Int.MIN_VALUE, 0)

    for (i in 1..9) {
        val num = readLine()!!.toInt()

        if (num > ans[0]) {
            ans[0] = num
            ans[1] = i
        }
    }

    println(ans[0])
    println(ans[1])
}