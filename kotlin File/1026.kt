import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine()!!.toInt()
    var ans = 0

    val A = br.readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    val B = br.readLine()!!.split(' ').map { it.toInt() }

    val tempB = ArrayList<Pair<Int, Int>>()

    for (i in B.indices) {
        tempB.add(Pair(i, B[i]))
    }

    A.sortDescending()
    tempB.sortWith(compareBy({ it.second }))

    for (i in 0 until N) {
        ans += A[i] * B[tempB[i].first]
    }

    bw.write("$ans\n")

    bw.flush()
}