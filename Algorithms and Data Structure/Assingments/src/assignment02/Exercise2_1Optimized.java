package assignment02;

import java.util.TreeSet;

public class Exercise2_1Optimized {

    public static TreeSet<String> nestedBrackets(int n) {
        TreeSet<String> result = new TreeSet<>();
        // Base case
        if (n == 0) {
            result.add("");
            return result;
        }
        // Recursive case
        generate("", 0, 0, n, result);
        return result;
    }

    private static void generate(String current, int open, int close, int max, TreeSet<String> result) {
        if (current.length() == max * 2) {
            result.add(current);
            return;
        }

        if (open < max) {
            generate(current + "(", open + 1, close, max, result);
        }
        if (close < open) {
            generate(current + ")", open, close + 1, max, result);
        }
    }

    public static void main(String[] args) {
        TreeSet<String> combinations = nestedBrackets(12);
        for (String combination : combinations) {
            System.out.println(combination);
        }
    }
}
