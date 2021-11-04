fun main() {
    val (N, X) = readLine()!!.split(' ').map { it.toInt() }

    val A = readLine()!!.split(' ').map { it.toInt() }

    for (i in A.indices) {
        if (A[i] < X) print("${A[i]} ")
    }

    println()
}