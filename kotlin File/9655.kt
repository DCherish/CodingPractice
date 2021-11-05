fun main() {
    val N = readLine()!!.toInt()

    when {
        N % 2 == 1 -> println("SK")
        else -> println("CY")
    }
}