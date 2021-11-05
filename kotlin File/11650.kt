fun main() {
    val N = readLine()!!.toInt()

    val arr = ArrayList<Pair<Int, Int>>()

    repeat(N) {
        val (x, y) = readLine()!!.split(' ').map { it.toInt() }

        arr.add(Pair(x, y))
    }

    arr.sortWith(compareBy({ it.first }, { it.second }))

    for (i in arr) {
        println("${i.first} ${i.second}")
    }
}