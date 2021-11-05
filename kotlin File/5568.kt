var n = 0
var k = 0
var ans = 0

val card = Array(10) { 0 }
val visited = Array(10) { false }
val hset = hashSetOf<String>()

fun main() {
    n = readLine()!!.toInt()
    k = readLine()!!.toInt()

    for (i in 0 until n) {
        card[i] = readLine()!!.toInt()
    }

    DFS(0, "")

    println(ans)
}

fun DFS(depth: Int, str: String) {
    if (depth == k) {
        if (!hset.contains(str)) {
            hset.add(str)
            ans++
        }

        return
    }

    for (i in 0 until n) {
        if (visited[i]) continue

        visited[i] = true
        DFS(depth + 1, str + card[i].toString())
        visited[i] = false
    }
}