import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val stk = ArrayDeque<String>()

    val N = br.readLine()!!.toInt()

    for (i in 0 until N) {
        val s = br.readLine()!!.toString()

        if (s.contains("push")) {
            stk.addLast(s.substring(5))
        } else if (s.contains("pop")) {
            if (stk.isEmpty()) {
                bw.write("-1\n");
            } else {
                bw.write("${stk.last()}\n")
                stk.removeLast()
            }
        } else if (s == "size") {
            bw.write("${stk.size}\n")
        } else if (s == "empty") {
            if (stk.isEmpty()) {
                bw.write("1\n")
            } else {
                bw.write("0\n")
            }
        } else if (s == "top") {
            if (stk.isEmpty()) {
                bw.write("-1\n")
            } else {
                bw.write("${stk.last()}\n")
            }
        }
    }

    bw.flush()
}