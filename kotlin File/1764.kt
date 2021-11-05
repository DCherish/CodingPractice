import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val hset = hashSetOf<String>()
    val ans = ArrayList<String>()

    val (N, M) = br.readLine()!!.split(' ').map { it.toInt() }

    repeat(N) {
        hset.add(br.readLine().toString())
    }

    repeat(M) {
        val str = br.readLine().toString()

        if (hset.contains(str)) ans.add(str)
    }

    ans.sort()

    bw.write("${ans.size}\n")

    for (i in ans) {
        bw.write("$i\n")
    }

    bw.flush()
}