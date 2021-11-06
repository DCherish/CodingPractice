import java.io.*
import kotlin.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N, K) = br.readLine()!!.split(' ').map { it.toInt() }

    val prime = Array(1001) { true }

    var cnt = 0
    var state = true

    for (i in 2..N) {
        if (!prime[i]) continue

        for (j in i..N step i) {
            if (!prime[j]) continue

            prime[j] = false
            cnt++

            if (cnt == K) {
                bw.write("$j\n")
                state = false
                break
            }
        }

        if (!state) break
    }

    bw.flush()
}