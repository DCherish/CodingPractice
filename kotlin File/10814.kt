fun main() {
    val N = readLine()!!.toInt()
    val arr = ArrayList<Pair<Int, Pair<Int, String>>>()

    repeat(N) {
        val (a, b) = readLine()!!.split(' ')

        val idx = it
        val age = a.toInt()
        val name = b.toString()

        arr.add(Pair(idx, Pair(age, name)))
    }

    arr.sortWith(compareBy({ it.second.first }, { it.first }))

    for (i in arr) {
        println("${i.second.first} ${i.second.second}")
    }
}