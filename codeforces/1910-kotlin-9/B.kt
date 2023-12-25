fun main() {
    val t = readln().toInt()
    for (case in 1..t) {
        val s = readln().toMutableList()
        var k = 0
        var end = false
        var done = false
        var x = -1
        var y = -1
        for (i in 0..<s.size) {
            if(s[i]=='+') k++;
            else {
                if(k<=0) {
                    if(!done && i+1<s.size && s[i+1]=='+') {
                        (s[i] to s[i+1]).apply { 
                            s[i] = second
                            s[i+1] = first
                        }
                        x = i
                        y = i+1
                        done = true
                        k++
                    } else {
                        println(-1);
                        end = true
                        break
                    }
                }else{
                    k--
                }
            }
        }
        if(!end) {
            if(done) println("${x+1} ${y+1}")
            else println("1 1")
        }
    }
}