fun main() {
    val str = readLine()!!.split(' ')

    var ans = str.size

    if (ans == 0) println(ans)
    else {
        if (str[0] == "") ans--
        if (str[str.size - 1] == "") ans--

        println(ans)
    }
}