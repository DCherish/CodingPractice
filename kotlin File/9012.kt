import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val T = br.readLine()!!.toInt()

    repeat(T) {
        val S = ArrayDeque<Int>()

        val str = br.readLine()!!.toString()

        var state = true

        for (i in str.indices) {
            if (str[i] == '(') S.addLast(1)
            else {
                if (S.isEmpty()) {
                    state = false
                    break
                } else S.removeLast()
            }
        }

        if (!S.isEmpty()) state = false

        if (state) bw.write("YES\n")
        else bw.write("NO\n")
    }

    bw.flush()
}