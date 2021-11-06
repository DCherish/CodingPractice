import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val T = br.readLine()!!.toInt()

    repeat(T) {
        val (N, M) = br.readLine()!!.split(' ').map { it.toInt() }

        val vec = Array(N + 1) { ArrayList<Int>() }
        val visited = Array(N + 1) { false }
        var cnt = 0

        val Q = ArrayDeque<Int>()

        repeat(M) {
            val (a, b) = br.readLine()!!.split(' ').map { it.toInt() }

            vec[a].add(b)
            vec[b].add(a)
        }

        for (i in 1..N) {
            if (visited[i]) continue

            visited[i] = true
            Q.addLast(i)

            while (!Q.isEmpty()) {
                val idx = Q.first()
                Q.removeFirst()

                for (j in vec[idx].indices) {
                    if (visited[vec[idx][j]]) continue

                    visited[vec[idx][j]] = true
                    cnt++

                    Q.add(vec[idx][j])
                }
            }
        }

        bw.write("$cnt\n")
    }

    bw.flush()
}