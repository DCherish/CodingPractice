import java.io.*
import kotlin.math.*

var s1 = ""
var s2 = ""

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine()!!.toInt()
    var ans = ""

    if (N == 0 || N == 1) {
        ans = N.toString()
    } else {
        for (i in 2..N) {
            ans = func()

            s1 = s2
            s2 = ans
        }
    }

    bw.write("$ans\n")
    bw.flush()
}

fun func(): String {
    var result = Array(max(s1.length, s2.length)) { '0' }.toCharArray()
    var carry = 0

    for (i in result.indices) {
        var temp = carry
        carry = 0

        if (i < s1.length) temp += s1[s1.length - i - 1] - '0'
        if (i < s2.length) temp += s2[s2.length - i - 1] - '0'

        if (temp >= 10) {
            carry = 1
            temp -= 10
        }

        result[result.size - i - 1] = temp.toChar()
    }

    if (carry == 1) {

    }

    return String(result)
}