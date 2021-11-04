fun main() {
    val A = readLine()!!.toInt()
    val B = readLine()!!.toInt()
    val C = readLine()!!.toInt()

    val cnt = Array<Int>(10) { 0 }

    val answer = (A * B * C).toString()

    for (i in 0 until answer.length) {
        val idx = answer[i] - '0'

        cnt[idx]++
    }

    for (i in 0..9) {
        println(cnt[i])
    }
}