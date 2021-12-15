import java.io.*
import java.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val arr = Array(10001) { BigInteger("0") }
    val N = br.readLine()!!.toInt()

    arr[0] = BigInteger("0")
    arr[1] = BigInteger("1")

    for (i in 2..N) {
        arr[i] = arr[i - 1] + arr[i - 2]
    }

    bw.write("${arr[N]}\n")
    bw.flush()
}