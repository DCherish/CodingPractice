import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine()!!.toInt()

    for (i in 0 until N) {
        val s = br.readLine()!!.toString()

        println(s.substring(0, 4))
    }
}