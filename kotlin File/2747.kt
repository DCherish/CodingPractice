fun main() {
    val F = Array<Long>(46) { 0 }

    val n = readLine()!!.toInt()

    F[0] = 0
    F[1] = 1

    for (i in 2..n) {
        F[i] = F[i - 1] + F[i - 2]
    }

    println(F[n])
}