package assignment02;

import java.util.Set;
import java.util.TreeSet;

public class Exercise2_2_Sum {

    /**
     * Computes all combinations how the given value 'sum' > 0 can be partitioned
     * into n integer summands (where each summand >= 1).
     */
    public static TreeSet<String> summands(int sum, int n) {
        TreeSet<String> result = new TreeSet<>();
        // Base case: If only one summand is to be found, it has to be the sum itself.
        if (n == 1) {
            result.add(Integer.toString(sum));
        } else {
            // Recursive case: Consider all possible values for the first summand.
            for (int firstSummand = 1; firstSummand <= sum - n + 1; firstSummand++) {
                TreeSet<String> subPartitions = summands(sum - firstSummand, n - 1);
                for (String subPartition : subPartitions) {
                    result.add(firstSummand + "+" + subPartition);
                }
            }
        }
        return result;
    }

    public static void demoPartitions_1() {
        Set<String> partitions = summands(6, 3);
        int count = 0;
        for (String part : partitions) {
            count++;
            System.out.println(count + ": " + part);
        }
    }

    public static void demoPartitions_2() {
        Set<String> partitions = summands(6, 4);
        int count = 0;
        for (String part : partitions) {
            count++;
            System.out.println(count + ": " + part);
        }
    }

    public static void main(String[] args) {
        demoPartitions_1();
        System.out.println();
        demoPartitions_2();
    }

}
