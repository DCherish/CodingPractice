fun main() {
    val ans = ArrayList<Int>()

    val T = readLine()!!.toInt()

    for (i in 0 until T) {
        val (H, W, N) = readLine()!!.split(' ').map { it.toInt() }

        var yy = N % H
        var xx = N / H

        if (yy == 0) yy = H
        else xx += 1

        ans.add(yy * 100 + xx)
    }

    for (i in ans.indices) {
        println(ans[i])
    }
}