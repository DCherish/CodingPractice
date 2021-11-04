import kotlin.math.*
import kotlin.system.exitProcess

var N = 0
var M = 0
var ans = Int.MAX_VALUE

val arr = ArrayList<Int>()
val visited = Array<Boolean>(100) { false }

fun main() {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }

    N = n
    M = m

    val temp = readLine()!!.split(' ').map { it.toInt() }

    for (i in temp.indices) {
        arr.add(temp[i])
    }

    DFS(0, 0, 0)

    println(ans)
}

fun DFS(depth: Int, idx: Int, sum: Int) {
    if (depth == 3) {
        if (sum == M) {
            println(M)
            exitProcess(0)
        } else if (sum > M) {
            return
        } else {
            if (abs(M - ans) > abs(M - sum)) {
                ans = sum
            }

            return
        }
    }

    for (i in idx until N) {
        if (visited[i]) continue

        visited[i] = true
        DFS(depth + 1, i + 1, sum + arr[i])
        visited[i] = false
    }
}