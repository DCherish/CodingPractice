import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine()!!.toInt()
    val hset = hashSetOf<Int>()

    repeat(N) {
        val str = br.readLine()!!.toString()
        val cmd = str.split(' ')

        when (cmd[0]) {
            "add" -> hset.add(cmd[1].toInt())
            "remove" -> hset.remove(cmd[1].toInt())
            "check" -> {
                if (hset.contains(cmd[1].toInt())) bw.write("1\n")
                else bw.write("0\n")
            }
            "toggle" -> {
                if (hset.contains(cmd[1].toInt())) hset.remove(cmd[1].toInt())
                else hset.add(cmd[1].toInt())
            }
            "all" -> {
                for (i in 1..20) {
                    hset.add(i)
                }
            }
            "empty" -> hset.clear()
        }
    }

    bw.flush()
}