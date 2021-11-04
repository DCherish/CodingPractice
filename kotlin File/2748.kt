fun main() {
    val n = readLine()!!.toInt()

    val arr = Array<Long>(100) { 0 }

    arr[0] = 0
    arr[1] = 1

    for (i in 2..n) {
        arr[i] = arr[i - 1] + arr[i - 2]
    }

    println(arr[n])
}