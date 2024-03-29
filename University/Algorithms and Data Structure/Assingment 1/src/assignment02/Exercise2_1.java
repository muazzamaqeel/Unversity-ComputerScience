package assignment02;

import java.util.TreeSet;

public class Exercise2_1 {

    public static TreeSet<String> nestedBrackets(int n){

        TreeSet<String> baseSet = new TreeSet<>();

        if (n == 0) {
            return baseSet;
        }else{
            baseSet.add("()");
            return nestedBrackets(n-1);
        }
    }
    public static void main(String[] args) {


        System.out.println(nestedBrackets(11));

    }


}
