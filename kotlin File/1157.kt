fun main() {
    val apb = Array<Int>(26) { 0 }

    var str = readLine()!!.toString().uppercase()

    var maxcnt = Int.MIN_VALUE
    var maxidx = 0

    for (i in str.indices) {
        val idx = str[i] - 'A'

        apb[idx]++

        if (apb[idx] > maxcnt) {
            maxcnt = apb[idx]
            maxidx = idx
        }
    }

    var state = true
    var ans = '?'

    for (i in apb.indices) {
        if (i == maxidx) continue

        if (apb[i] == maxcnt) {
            state = false
            break
        }
    }

    if (state) ans = ('A'.code + maxidx).toChar()

    println(ans)
}