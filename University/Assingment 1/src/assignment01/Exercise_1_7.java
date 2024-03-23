package assignment01;

public class Exercise_1_7 {

    public static String myMeth(int n) {
        if (n < 0) {
            return myMeth(-n);
        } else if (n == 0) {
            return "";
        } else if (n < 10) {
            return "bb" + myMeth(3 * n) + "aa";
        } else if (n < 40) {
            return myMeth(2 * n) + myMeth(n + 1);
        } else {
            return "baab";

        }

    }
    public static void main(String[] args) {
        int[] testCases = {-15, 0, 5, 20, 40};

        for (int n : testCases) {
            String result = myMeth(n);
            long aCount = result.chars().filter(ch -> ch == 'a').count();
            long bCount = result.chars().filter(ch -> ch == 'b').count();

            System.out.println("myMeth(" + n + ") -> " + result);
            System.out.println("'a' count: " + aCount + ", 'b' count: " + bCount);
            System.out.println("Balance of 'a' and 'b': " + (aCount == bCount ? "PASS" : "FAIL"));
            System.out.println();
        }
    }
}


/*
Base Case:
For n == 0, `myMeth` returns an empty string, which trivially has an equal number of 'a's and 'b's (zero each).

Inductive Step:
Assume `myMeth(k)` has an equal number of 'a's and 'b's for all `k < n`. We need to show `myMeth(n)` does as well.

Recursive Cases:
1: n < 0: Calls `myMeth` with `-n`, which by our inductive assumption, returns a balanced string.
2. n < 10: Adds two 'b's and two 'a's around `myMeth(3*n)`, maintaining balance.
3. 10 <= n < 40: Concatenates `myMeth(2*n)` and `myMeth(n+1)`, both assumed to be balanced, keeping overall balance.
4. n >= 40:  Returns "baab", which is balanced.

Conclusion:
For all `n`, `myMeth(n)` maintains an equal number of 'a's and 'b's.

 */