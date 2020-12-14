import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * <h1>Binary Tress with N nodes</h1> <b>Purpose</b>
 * <p>
 * Total Number of Binary Tress we can create with N number of nodes
 * </p>
 * <b>Description</b>
 * <p>
 * class BinarySearchTreeCount program is used to implement a program to find a
 * count of the total number of different binary search trees that we can make
 * with N nodes.
 * </p>
 * <p>
 * There are four approaches used to implement the given problem:
 * </p>
 * <ul>
 * <li>Using Dynamic Programming</li>
 * <li>Using Recursion</li>
 * <li>Using the Binomial Coefficient</li>
 * <li>Using a Custom made Formulae</li>
 * </ul>
 */
public class BinarySearchTreeCount {

    /**
     * This is a private method used to calculate the Binomial Coefficient
     * 
     * @param numberOne This is a first Integer parameter to
     *                  calculateBinomialCoefficient method.
     * @param numberTwo This is a second Integer paramter to
     *                  calculateBinomialCoefficient method.
     * @return Long This returns Binomial Coefficient of numberOne and numberTwo.
     */
    private Long calculateBinomialCoefficient(Integer numberOne, Integer numberTwo) {

        // Initialized coefficient to 1
        Long coefficient = 1L;

        /*
         * If substraction of numberOne and numberTwo is smaller than numberTwo then
         * numberTwo is assigned a new value which is the substraction of numberOne and
         * numberTwo.
         */
        if (numberTwo > (numberOne - numberTwo)) {
            numberTwo = numberOne - numberTwo;
        }

        /*
         * Calculating value of coefficient iteratively
         */
        for (int i = 0; i < numberTwo; i++) {
            coefficient *= (numberOne - i);
            coefficient /= (i + 1);
        }
        return coefficient;
    }

    /**
     * This is a public method used to calculate the total count of Binary Search
     * Trees which can be created with N nodes using Binomial Coefficient method.
     * <b>Formulae</b>
     * <p>
     * 1/(n+1) * (2n!/n!(2n-n)!)
     * </p>
     * 
     * <p>
     * <b>Time Complexity</b> O(n)
     * </p>
     * <p>
     * <b>Space Complexity</b> O(1)
     * </p>
     * 
     * @param totalNumberOfNodes This is used to store the value to the total number
     *                           of nodes present.
     * @return Long This returns the total number of Binary Search Trees which can
     *         be created with totalNumberOfNodes nodes
     */
    public Long getCountByBinomialCoefficient(Byte totalNumberOfNodes) {

        /*
         * Calls calculateBinomialCoefficient method to get the Binomial Coefficient of
         * 2 X totalNumberOfNodes and totalNumberOfNodes
         */
        Long binomialNumber = calculateBinomialCoefficient(2 * totalNumberOfNodes, 1 * totalNumberOfNodes);
        /*
         * Divides the binomial coefficient by sum of totalNumberOfNodes and 1 to
         * statisfy the formulae
         */
        Long binaryTreeNodeCount = binomialNumber / (totalNumberOfNodes + 1);
        // Returns the final count
        return binaryTreeNodeCount;
    }

    /**
     * This is a public method used to calculate the total count of Binary Search
     * Trees which can be created with N nodes using Recursive method. *
     * 
     * <p>
     * <b>Time Complexity</b> O(n)
     * </p>
     * 
     * @param totalNumberOfNodes This is used to store the value to the total number
     *                           of nodes present.
     * @return Long This returns the total number of Binary Search Trees which can
     *         be created with totalNumberOfNodes nodes
     */
    public Long getCountByRecursion(Byte totalNumberOfNodes) {

        Long binaryTreeNodeCount = 0L;
        /*
         * If totalNumberOfNodes comes down to 1 or less 1 is returned as the total
         * number of trees that could be created
         */
        if (totalNumberOfNodes <= 1) {
            return 1L;
        }
        for (int i = 0; i < totalNumberOfNodes; i++) {
            binaryTreeNodeCount += getCountByRecursion((byte) i)
                    * getCountByRecursion((byte) (totalNumberOfNodes - i - 1));
        }
        // Returns the final count
        return binaryTreeNodeCount;
    }

    /**
     * This is a public method used to calculate the total count of Binary Search
     * Trees which can be created with N nodes using a custom made formulae.
     * <p>
     * <b>Advantages</b>
     * </p>
     * <p>
     * We don't need to store any previous values or factorial in this solution,
     * which reduces it's time and space complexity
     * </p>
     * <b>Disadvantages</b>
     * <p>
     * The formulae is not functional in 100% test cases, it works best between
     * values 2-7
     * </p>
     * <b>Formulae</b>
     * <p>
     * ROUND( 2^((n-1)+(((n-1)-1)/2)-((n+1)-3)+(8*9^(n-6)) )
     * </p>
     * 
     * @param totalNumberOfNodes This is used to store the value to the total number
     *                           of nodes present.
     * @return Long This returns the total number of Binary Search Trees which can
     *         be created with totalNumberOfNodes nodes
     */
    public Long getCountByFormulae(Byte totalNumberOfNodes) {
        /*
         * If there's a occurance of 0 or 1 it directly returns 1
         */
        if (totalNumberOfNodes == 0 || totalNumberOfNodes == 1) {
            return 1L;
        }
        /*
         * Calculates the power of 2
         */
        Double powerCount = (totalNumberOfNodes - 1) + (((totalNumberOfNodes - 1) - 1) / 2.0);
        /*
         * Calculates the final value statisfying the given formulae
         */
        Long binaryTreeCount = Math.round(Math.pow(2, (powerCount)) - ((totalNumberOfNodes + 1) - 3)
                + (8 * Math.round(Math.pow(9, totalNumberOfNodes - 6))));
        // Returns the final count
        return binaryTreeCount;
    }

    /**
     * This is a public method used to calculate the total count of Binary Search
     * Trees which can be created with N nodes using Dynamic Programming. *
     * 
     * <p>
     * <b>Time Complexity</b> O(n^2)
     * </p>
     * 
     * @param totalNumberOfNodes This is used to store the value to the total number
     *                           of nodes present.
     * @return Long This returns the total number of Binary Search Trees which can
     *         be created with totalNumberOfNodes nodes
     */
    public Long getCountByDynamicProgramming(Byte totalNumberOfNodes) {
        /*
         * If there's a occurance of 0 or 1 it directly returns 1
         */
        if (totalNumberOfNodes == 0 || totalNumberOfNodes == 1) {
            return 1L;
        }

        /*
         * An array is used to store previous occuring values
         */
        Long[] binaryTreeNodeCount = new Long[totalNumberOfNodes + 1];

        /*
         * binaryTreeNodeCount[] is initialized with 0 as it's initial value
         */
        for (int i = 0; i <= totalNumberOfNodes; i++) {
            binaryTreeNodeCount[i] = 0L;
        }

        /*
         * Index 0 and 1 are assigned value as 1
         */
        binaryTreeNodeCount[0] = 1L;
        binaryTreeNodeCount[1] = 1L;

        /*
         * Iteratively according to the previous values the current value is calculated
         */
        for (int i = 2; i <= totalNumberOfNodes; i++) {
            for (int j = 0; j < i; j++) {
                binaryTreeNodeCount[i] += binaryTreeNodeCount[j] * binaryTreeNodeCount[i - j - 1];
            }
        }

        return binaryTreeNodeCount[totalNumberOfNodes];
    }

    /**
     * This is the main method which makes use of the following methods:
     * 
     * <ul>
     * <li>getCountByDynamicProgramming</li>
     * <li>getCountByRecursion</li>
     * <li>getCountByBinomialCoefficient</li>
     * <li>getCountByFormulae</li>
     * </ul>
     * 
     * And uses the following objects of types:
     * 
     * <ul>
     * <li>java.util.Scanner</li>
     * <li>java.lang.Byte</li>
     * <li>java.lang.Long</li>
     * <li>BinarySearchTreeCount</li>
     * </ul>
     * 
     * @param args for getting command line input [NOT USED].
     * @exception InputMismatchException On input error.
     */
    public static void main(String[] args) {
        // Created an object of Scanner class for asking for user input.
        Scanner scan = new Scanner(System.in);
        try // Openning try block
        {
            // Created an object of BinarySearchTreeCount for accessing it's methods
            BinarySearchTreeCount binarySearchTreeCount = new BinarySearchTreeCount();

            // Asking for user input for entering the total number of nodes
            System.out.println("Enter Total Number Of Nodes: ");
            // The user input is captured in totalNumberOfNodes
            Byte totalNumberOfNodes = scan.nextByte();

            // Calling method to calculate the total using Dynamic Programming
            Long binaryTreeCountByDynamicProgramming = binarySearchTreeCount
                    .getCountByDynamicProgramming(totalNumberOfNodes);

            // Calling method to calculate the total using Recursion
            Long binaryTreeCountByRecursion = binarySearchTreeCount.getCountByRecursion(totalNumberOfNodes);

            // Calling method to calculate the total using Binomial Coefficient
            Long binaryTreeCountByBinomialCoefficient = binarySearchTreeCount
                    .getCountByBinomialCoefficient(totalNumberOfNodes);

            // Printing the respective values
            System.out.println("COUNT By Binomial Coeffient: " + binaryTreeCountByBinomialCoefficient);
            System.out.println("COUNT by Dynamic Programming: " + binaryTreeCountByDynamicProgramming);
            System.out.println("COUNT by Recursion: " + binaryTreeCountByRecursion);

            /*
             * If totalNumberOfNodes is between 0 to 7 then it will call the method to
             * calculate the total using custom formulae, as for now the formulae works well
             * when values are under or equal to 7 and above than 0, the formulae should not
             * be used to calculate values greater than 7 for now.
             */
            if (totalNumberOfNodes >= 0 && totalNumberOfNodes <= 7) {
                // Calling method to calculate the total using Custom Formulae
                Long binaryTreeCountByFormulae = binarySearchTreeCount.getCountByFormulae(totalNumberOfNodes);
                // Printing the respective value
                System.out.println("COUNT by Formulae: " + binaryTreeCountByFormulae);
            }
            // If value of totalNumberOfNodes is entered below 0, an expection is raised
            if (totalNumberOfNodes < 0) {
                throw new InputMismatchException();
            }
        } // Closing try block
        catch (InputMismatchException inputMismatchException) {
            System.out.println("Please Enter values between 0 - 127");
        } finally {
            // Closing the Scanner object scan
            scan.close();
        }
    }
}