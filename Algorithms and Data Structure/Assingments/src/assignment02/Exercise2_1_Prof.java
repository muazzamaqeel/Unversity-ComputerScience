package assignment02;
import java.util.Set;
import java.util.TreeSet;
public class Exercise2_1_Prof {

    /** generates all correctly nested sequences of round brackets
     *  that can be build from n pair of brackets.*/
    public static Set<String> nestedBrackets(int n) {
        Set<String> resultSet = new TreeSet<>();
        //TODO
        //TODO
        //TODO
        //TODO
        return resultSet;
    }


    public static void main(String[] args) {
        testBrackets(2);
        testBrackets(3);
        testBrackets(4);
    }

    private static void testBrackets(int n) {
        Set<String> res = nestedBrackets(n);
        System.out.printf("nestedBrackets(%d): %n", n);
        int count = 0;
        for (String s : res) {
            count++;
            System.out.println(count + ": " + s);
        }

    }
}

