fun main() {
    val S = readLine()!!.toString()

    val apb = Array<Int>(26) { -1 }

    for (i in S.indices) {
        val idx = S[i] - 'a'

        if (apb[idx] == -1) apb[idx] = i
    }

    for (i in apb) {
        print("$i ")
    }

    println()
}