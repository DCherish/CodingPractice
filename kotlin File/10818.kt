import kotlin.math.*

fun main() {
    var min_value = Int.MAX_VALUE
    var max_value = Int.MIN_VALUE

    val N = readLine()!!.toInt()

    val X = readLine()!!.split(' ')

    for (i in X.indices) {
        min_value = min(min_value, X[i].toInt())
        max_value = max(max_value, X[i].toInt())
    }

    println("$min_value $max_value")
}