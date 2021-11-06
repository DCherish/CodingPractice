import java.io.*
import kotlin.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine()!!.toInt()
    val rope = ArrayList<Int>()

    var ans = 0

    repeat(N) {
        rope.add(br.readLine()!!.toInt())
    }

    rope.sortDescending()

    for (i in rope.indices) {
        val temp = rope[i] * (i + 1)

        ans = max(ans, temp)
    }

    bw.write("$ans\n")
    bw.flush()
}