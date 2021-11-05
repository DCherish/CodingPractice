fun main() {
    val N = readLine()!!.toInt()

    val arr = ArrayList<String>()

    repeat(N) {
        arr.add(readLine()!!.toString())
    }

    arr.sortWith(compareBy({ it.length }, { it }))

    arr.distinct().forEach {
        println(it)
    }
}