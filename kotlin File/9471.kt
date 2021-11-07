import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val P = br.readLine()!!.toInt()

    repeat(P) {
        val (N, M) = br.readLine().split(' ').map { it.toInt() }

        var cnt = 0
        var a = 1
        var b = 1

        while (true) {
            val temp = (a + b) % M
            a = b
            b = temp
            cnt++

            if (a == 1 && b == 1) break
        }

        bw.write("$N $cnt\n")
    }

    bw.flush()
}