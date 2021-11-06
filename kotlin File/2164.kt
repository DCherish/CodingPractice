import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    var DQ = ArrayDeque<Int>()

    val N = br.readLine()!!.toInt()

    repeat(N) {
        DQ.addLast(it + 1)
    }

    while (DQ.size != 1) {
        DQ.removeFirst()

        val idx = DQ.first()
        DQ.removeFirst()
        DQ.addLast(idx)
    }

    bw.write("${DQ[0]}\n")
    bw.flush()
}