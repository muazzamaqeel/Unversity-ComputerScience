package assignment01;

public class Exercise1_4_Part_B {



    public static int counter=0;
    public static int i=0;
    public static int j=0;

 /*
    public static boolean isPalindrome(char[] sequence) {
            i = 0;
            j = sequence.length-1;
        if (sequence == null || i >= j) {
            return true;
        } else {
            if (sequence[i] != sequence[j]) {
                return false;
            }
            i++; // Move i forward
            j--; // Move j backward
            return isPalindrome(sequence);
        }
    }


    public static boolean isPalindrome(char[] sequence){

        if (sequence==null || counter>sequence.length){
            return true;
        }else {
            if (sequence[i] != sequence[j]) {
                i=i+1;
                j=j-1;
                return false;
            }
            return isPalindrome(sequence);

        }
    }

    */


    public static boolean isPalindrome(char[] sequence) {
        if (sequence == null) {
            return true;
        }
        return checkPalindrome(sequence, 0, sequence.length - 1);
    }

    private static boolean checkPalindrome(char[] sequence, int i, int j) {
        if (i > j) {
            return true;
        } else {
            if (sequence[i] != sequence[j]) {
                return false;
            }
            return checkPalindrome(sequence, i + 1, j - 1);
        }
    }

    public static void main(String[] args) {
        char[] arr2 = new char[]{'C', 'I','V','I','C'};
        char[] arr1 = new char[]{'I', 'P', 'H', 'O', 'N', 'E'};

        boolean result = isPalindrome(arr1);
        System.out.println("Result 1: " +result);
        boolean result2 = isPalindrome(arr2);
        System.out.println("Result 2: " +result2);

    }

}
