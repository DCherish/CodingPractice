import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val arr = ArrayList<Int>()

    val N = br.readLine()!!.toInt()

    repeat(N) {
        arr.add(br.readLine()!!.toInt())
    }

    arr.sort()

    for (i in arr) {
        bw.write("$i\n")
    }

    bw.flush()
}