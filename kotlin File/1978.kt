import java.io.*
import kotlin.math.*

val d = 1000.0
val prime = Array(1001) { true }

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    pre_setting()

    val N = br.readLine()!!.toInt()
    val arr = br.readLine()!!.split(' ').map { it.toInt() }

    var cnt = 0

    repeat(N) {
        if (prime[arr[it]]) cnt++
    }

    bw.write("$cnt\n")
    bw.flush()
}

fun pre_setting() {
    val lim = sqrt(d).toInt()

    prime[0] = false
    prime[1] = false

    var i = 2
    var j = 0

    while (i <= lim) {
        if (!prime[i]) {
            i++
            continue
        }

        j = i * i

        while (j <= 1000) {
            prime[j] = false

            j += i
        }

        i++
    }
}