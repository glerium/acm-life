fun main() {
    val t = readln().toInt()
    for (case in 1..t) {
        var s = readln()
        var cnt = 1
        for (i in s.count() - 1 downTo 0) {
            if (s[i] == '0') cnt++
            else break
        }
        println(s.dropLast(cnt))
    }
}