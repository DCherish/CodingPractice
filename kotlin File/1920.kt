import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine()!!.toInt()
    val A = br.readLine()!!.split(' ').map { it.toInt() }.sorted()

    val M = br.readLine()!!.toInt()
    val B = br.readLine()!!.split(' ').map { it.toInt() }

    for (i in B) {
        if (A.binarySearch(i) >= 0) bw.write("1\n")
        else bw.write("0\n")
    }
    
    /*for (i in B) {
        var left = 0
        var right = A.size - 1

        var state = false

        while (left <= right) {
            var mid = (left + right) / 2

            if (A[mid] == i) {
                state = true
                break
            } else if (A[mid] > i) {
                right = mid - 1
            } else {
                left = mid + 1
            }
        }

        if (state) bw.write("1\n")
        else bw.write("0\n")
    }*/

    bw.flush()
}