import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val AtoI = hashMapOf<String, Int>()
    val ItoA = ArrayList<String>()

    val (N, M) = br.readLine()!!.split(' ').map { it.toInt() }

    repeat(N) {
        val str = br.readLine()!!.toString()

        AtoI[str] = it + 1
        ItoA.add(str)
    }

    repeat(M) {
        val str = br.readLine()!!.toString()

        if (str[0] >= '0' && str[0] <= '9') {
            val idx = str.toInt()
            bw.write("${ItoA[idx - 1]}\n")
        } else {
            bw.write("${AtoI[str].toString()}\n")
        }
    }

    bw.flush()
}