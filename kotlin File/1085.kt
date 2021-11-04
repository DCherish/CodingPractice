import kotlin.math.*

fun main() {
    val (x, y, w, h) = readLine()!!.split(' ').map { it.toInt() }

    var ans = Int.MAX_VALUE

    ans = min(ans, abs(w - x))
    ans = min(ans, abs(x))
    ans = min(ans, abs(h - y))
    ans = min(ans, abs(y))

    println(ans)
}