fun main() {
    val N = readLine()!!.toInt()

    val room = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    val ref = readLine()!!.split(' ').map { it.toInt() }

    var cnt: Long = 0

    for (i in 0 until N) {
        room[i] -= ref[0]
        cnt++
    }

    for (i in 0 until N) {
        if (room[i] > 0) {
            val dv = room[i] / ref[1]
            val rv = room[i] % ref[1]

            if (rv == 0) cnt += dv
            else cnt += dv + 1
        }
    }

    println(cnt)
}