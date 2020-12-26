class BinarySearch 
{

    fun doBinarySearch () 
    {
        println("Please, enter some integer numbers using space bar")

        val inputList = readLine()!!.split(' ').map(String::toInt)
        val listSorted = inputList.sorted()

        println("Please, enter the number you want to find")

        val item = readLine()!!.toInt()
        var low = 0
        var high = listSorted.size - 1

        var stepCount = 0

        var isItemFound = false

        while (low <= high) 
        {

            val mid = (low + high) / 2
            val guess = listSorted[mid]
            stepCount++

            when 
            {
                guess == item -> 
                {
                    println("Your number $item was found in $stepCount steps")
                    isItemFound = true
                }

                guess > item -> high = mid -1
                else -> low = mid + 1
            }

            if (isItemFound) break //"break" is not allowed in "when" statement
        }

        if (!isItemFound) 
        {
            println("Your number wasn't found")
        }

    }

}