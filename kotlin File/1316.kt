val vec = ArrayList<String>()
val visited = Array(26) { false }
var state = false
var cnt = 0

fun main() {
    val N = readLine()!!.toInt()

    repeat(N) {
        vec.add(readLine()!!.toString())
    }

    solve()

    println(cnt)
}

fun solve() {
    for (i in vec.indices) {
        init()

        state = false

        val temp = vec[i]
        var prev = temp[0]
        visited[temp[0] - 'a'] = true

        for (j in temp.indices) {
            if (visited[temp[j] - 'a']) {
                if (temp[j] != prev) {
                    state = true
                    break
                }
            } else {
                prev = temp[j]
                visited[temp[j] - 'a'] = true
            }
        }

        if (!state) cnt++
    }
}

fun init() {
    for (i in 0..25) {
        visited[i] = false
    }
}