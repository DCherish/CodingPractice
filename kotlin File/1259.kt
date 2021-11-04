fun main() {
    val ans = ArrayList<String>()

    while (true) {
        val n = readLine()!!.toInt()

        if (n == 0) break

        val str = n.toString()
        val len = str.length / 2
        var cnt = 0

        for (i in 0 until len) {
            if (str[i] == str[str.length - i - 1]) cnt++
            else break
        }

        if (cnt == len) ans.add("yes")
        else ans.add("no")
    }

    for (i in ans) {
        println(i)
    }
}