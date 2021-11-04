fun main() {
    val T = readLine()!!.toInt()
    val arr = ArrayList<Int>()

    for (i in 0 until T) {
        val (A, B) = readLine()!!.split(' ')

        var a = A.toInt()
        val b = B.toInt()

        a %= 10

        if (a == 1) {
            arr.add(1)
        } else if (a == 2) {
            when {
                b % 4 == 1 -> arr.add(2)
                b % 4 == 2 -> arr.add(4)
                b % 4 == 3 -> arr.add(8)
                b % 4 == 0 -> arr.add(6)
            }
        } else if (a == 3) {
            when {
                b % 4 == 1 -> arr.add(3)
                b % 4 == 2 -> arr.add(9)
                b % 4 == 3 -> arr.add(7)
                b % 4 == 0 -> arr.add(1)
            }
        } else if (a == 4) {
            when {
                b % 2 == 1 -> arr.add(4)
                b % 2 == 0 -> arr.add(6)
            }
        } else if (a == 5) {
            arr.add(5)
        } else if (a == 6) {
            arr.add(6)
        } else if (a == 7) {
            when {
                b % 4 == 1 -> arr.add(7)
                b % 4 == 2 -> arr.add(9)
                b % 4 == 3 -> arr.add(3)
                b % 4 == 0 -> arr.add(1)
            }
        } else if (a == 8) {
            when {
                b % 4 == 1 -> arr.add(8)
                b % 4 == 2 -> arr.add(4)
                b % 4 == 3 -> arr.add(2)
                b % 4 == 0 -> arr.add(6)
            }
        } else if (a == 9) {
            when {
                b % 2 == 1 -> arr.add(9)
                b % 2 == 0 -> arr.add(1)
            }
        } else if (a == 0) {
            arr.add(10)
        }
    }

    for (i in arr.indices) {
        println(arr[i])
    }
}