fun main() {
    val t = readLine()!!.toInt()

    val ans = ArrayList<Int>()

    for (i in 0 until t) {
        var temp = 1
        var sum = 0

        val str = readLine()!!.toString()

        for (i in str.indices) {
            if (str[i] == 'O') {
                sum += temp
                temp++
            } else {
                temp = 1
            }
        }

        ans.add(sum)
    }

    for (i in ans) {
        println(i)
    }
}