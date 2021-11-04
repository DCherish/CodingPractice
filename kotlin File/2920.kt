val arr = Array<Int>(8) { 0 }

fun main() {
    val temp = readLine()!!.split(' ').map { it.toInt() }

    for (i in temp.indices) {
        arr[i] = temp[i]
    }

    if (isA()) println("ascending")
    else if (isD()) println("descending")
    else println("mixed")
}

fun isA(): Boolean {
    for (i in arr.indices) {
        if (arr[i] != i + 1) return false
    }

    return true
}

fun isD(): Boolean {
    for (i in arr.indices) {
        if (arr[i] != 8 - i) return false
    }

    return true
}