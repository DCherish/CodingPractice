import kotlin.system.exitProcess

val visited = Array<Boolean>(9) { false }
val arr = Array<Int>(9) { 0 }

fun main() {
    for (i in arr.indices) {
        val num = readLine()!!.toInt()

        arr[i] = num
    }

    DFS(0, 0, 0)
}

fun DFS(depth: Int, idx: Int, sum: Int) {
    if (depth == 7) {
        if (sum == 100) {

            val ans = ArrayList<Int>()

            for (i in visited.indices) {
                if (visited[i]) {
                    ans.add(arr[i])
                }
            }

            ans.sort()

            for (i in ans) {
                println(i)
            }

            exitProcess(0)
        } else return
    }

    for (i in idx until 9) {
        if (visited[i]) continue
        visited[i] = true
        DFS(depth + 1, i + 1, sum + arr[i])
        visited[i] = false
    }
}