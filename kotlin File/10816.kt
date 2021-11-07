import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine()!!.toInt()
    val card = br.readLine()!!.split(' ').map { it.toInt() }.toIntArray()

    card.sort()

    val M = br.readLine()!!.toInt()
    val idx = br.readLine()!!.split(' ').map { it.toInt() }

    for (i in idx) {
        if (card.binarySearch(i) < 0) bw.write("0 ")
        else {
            val cnt = upper_bound(card, i) - lower_bound(card, i)
            bw.write("$cnt ")
        }
    }

    bw.flush()
}

fun upper_bound(card: IntArray, key: Int): Int {
    var left = 0
    var right = card.size

    while (left < right) {
        val mid = (left + right) / 2

        if (card[mid] <= key) {
            left = mid + 1
        } else {
            right = mid
        }
    }

    return right
}

fun lower_bound(card: IntArray, key: Int): Int {
    var left = 0
    var right = card.size

    while (left < right) {
        val mid = (left + right) / 2

        if (card[mid] >= key) {
            right = mid
        } else {
            left = mid + 1
        }
    }

    return right
}