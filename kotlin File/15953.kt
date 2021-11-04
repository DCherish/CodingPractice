import kotlin.math.*

var depth = 0

val cp1_idx = Array<Int>(101) { 0 }
val cp2_idx = Array<Int>(65) { 0 }

val cp1_money = Array<Int>(101) { 0 }
val cp2_money = Array<Int>(65) { 0 }

fun main() {
    pre_setting()

    val ans = ArrayList<Int>()

    val T = readLine()!!.toInt()

    for (i in 0 until T) {
        val (a, b) = readLine()!!.split(' ').map { it.toInt() }

        val sum = cp1_money[cp1_idx[a]] + cp2_money[cp2_idx[b]]

        ans.add(sum)
    }

    for (i in ans) {
        println(i)
    }
}

fun pre_setting() {
    depth = 1

    for (i in 1..6) {
        for (j in 1..i) {
            cp1_idx[depth] = i
            depth++
        }
    }

    depth = 1

    for (i in 1..5) {
        val pow_i = (2.0).pow(i - 1).toInt()

        for (j in 1..pow_i) {
            cp2_idx[depth] = i
            depth++
        }
    }

    cp1_money[1] = 5000000
    cp1_money[2] = 3000000
    cp1_money[3] = 2000000
    cp1_money[4] = 500000
    cp1_money[5] = 300000
    cp1_money[6] = 100000

    cp2_money[1] = 5120000
    cp2_money[2] = 2560000
    cp2_money[3] = 1280000
    cp2_money[4] = 640000
    cp2_money[5] = 320000
}
