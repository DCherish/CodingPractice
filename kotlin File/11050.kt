fun main() {
    val arr = Array(11) { Array(11) { 0 } }

    var (N, K) = readLine()!!.split(' ').map { it.toInt() }

    if (N / 2 < K) K = N - K

    for (i in 1..N) {
        arr[i][0] = 1
        arr[i][1] = i

        for (j in 2..K) {
            if (j > i) break
            else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j]
        }
    }

    println(arr[N][K])
}