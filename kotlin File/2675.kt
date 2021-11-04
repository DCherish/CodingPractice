fun main() {
    val T = readLine()!!.toInt()
    val ans = ArrayList<String>()

    for (i in 0 until T) {
        val (R, S) = readLine()!!.split(' ')

        var str = ""

        for (j in S.indices) {
            for (k in 0 until R.toInt()) {
                str += S[j]
            }
        }

        ans.add(str)
    }

    for (i in ans) {
        println(i)
    }
}