fun main() {
    val (A, B) = readLine()!!.split(' ')

    val a = A.toInt()
    val b = B.toInt()

    when {
        a > b -> println(">")
        a < b -> println("<")
        a == b -> println("==")
    }
}