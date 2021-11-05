import kotlin.math.*

val MAP = Array(50) { Array(50) { ' ' } }
var cnt = Int.MAX_VALUE

fun main() {
    val (R, C) = readLine()!!.split(' ').map { it.toInt() }

    for (i in 0 until R) {
        val str = readLine()!!.toString()
        for (j in 0 until C) {
            MAP[i][j] = str[j]
        }
    }

    for (i in 0..R - 8) {
        for (j in 0..C - 8) {
            solve(i, j)
        }
    }

    println(cnt)
}

fun solve(x: Int, y: Int) {
    var tempcnt = 0

    for (i in 0 until 8) {
        for (j in 0 until 8) {
            if ((i + j) % 2 != 0) {
                if (MAP[x][y] == MAP[x + i][y + j]) tempcnt++
            } else {
                if (MAP[x][y] != MAP[x + i][y + j]) tempcnt++
            }
        }
    }

    if (tempcnt > 32) tempcnt = 64 - tempcnt

    cnt = min(cnt, tempcnt)
}
