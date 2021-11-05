import java.io.*
import kotlin.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine()!!.toInt()

    var cnt2 = 0
    var cnt5 = 0

    var i = 2

    while (i <= N) {
        cnt2 += N / i
        i *= 2
    }

    i = 5

    while (i <= N) {
        cnt5 += N / i
        i *= 5
    }

    val ans = min(cnt2, cnt5)

    bw.write("$ans\n")
    bw.flush()
}
