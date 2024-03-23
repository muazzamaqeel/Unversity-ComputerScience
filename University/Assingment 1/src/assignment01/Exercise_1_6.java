package assignment01;

public class Exercise_1_6 {


    public static int funcA(int n) {
        if (n <= 0) {
            return 3 - n;
        } else if (n % 5 == 0) {
            return 42;
        } else if (n > 8) {
            return 2 * funcA(n - 10) + 2;
        } else {
            return (funcA(n - 5) + funcA(n / 3)) / 2;
        }
    }

    public static void main(String[] args) {
        int result;
        result = funcA(25);
        System.out.println(result);
        result = funcA(-0);
        System.out.println(result);
        result = funcA(-1);
        System.out.println(result);
        result = funcA(1);
        System.out.println(result);

        /*

        1. `if (n <= 0)`: Executes when `n` is less than or equal to 0.
                - Returns `3 - n`.

        2. `else if (n % 5 == 0)`: Executes when `n` is greater than 0 and divisible by 5.
                - Returns `42`.

        3. `else if (n > 8)`: Executes when `n` is greater than 8 and not divisible by 5.
                - Calls `funcA(n - 10)`, multiplies the result by 2, and adds 2.

        4. `else`: Executes when `n` is greater than 0, not divisible by 5, and less than or equal to 8.
                - Calls `funcA(n - 5)` and `funcA(n / 3)`, adds the results together, and divides by 2.
                So the specific values of n for which this block runs are: 1, 2, 3, 4, 6, 7, and 8.
         */


    }
}
