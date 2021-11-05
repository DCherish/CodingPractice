fun main() {
    val ch = readLine()!!.toCharArray()

    ch.sortDescending()

    if (ch.last() == '0') {
        val sum = ch.map { it - '0' }.reduce { acc, i -> acc + i }

        if (sum % 3 == 0) println(ch.concatToString())
        else println(-1)
    } else {
        println(-1)
    }
}