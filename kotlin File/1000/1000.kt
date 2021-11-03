import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (A, B) = br.readLine().split(' ').map { it.toInt() }

    println(A + B)
}