fun main() {
    val n = readLine()!!.toInt()

    when {
        n % 8 == 1 -> println("1")
        n % 8 == 2 || n % 8 == 0 -> println("2")
        n % 8 == 3 || n % 8 == 7 -> println("3")
        n % 8 == 4 || n % 8 == 6 -> println("4")
        n % 8 == 5 -> println("5")
    }
}