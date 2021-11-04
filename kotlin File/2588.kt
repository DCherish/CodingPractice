fun main() {
    val a = readLine()!!.toInt()
    val b = readLine()!!.toInt()

    println(a * (b % 10))
    println((a * ((b % 100) - (b % 10))) / 10)
    println((a * (b - (b % 100))) / 100)
    println(a * b)
}