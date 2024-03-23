package assignment01;
public class Exercise1_4 {

    //Program a method that computes recursively (i. e. without loops) how often the
    //character ch is contained in the array arr.
    //public static int count(char ch, char[] arr)
    //Appropriate auxiliary methods can be introduced for this purpose, if needed. Do
    //not use methods from the standard library!


    public static int counter = 0;
    public static int i = 0;

    public static int count(char ch, char[] arr) {
        if (arr == null || i >= arr.length) {
            int result = counter;
            counter = 0;
            i = 0;
            return result;
        } else {
            if (arr[i] == ch) {
                counter++;
            }
            i++;
            return count(ch, arr);
        }
    }
    ///--------------------------------------------

/*
    public static int count(char ch, char[] arr) {
        if (arr == null || i >= arr.length) {
            int result = counter;
            counter = 0;
            i = 0;
            return result;
        } else {
            if (arr[i] == ch) {
                counter++;
            }
            i++;
            return count(ch, arr);
        }
    }
*/

    public static void main(String[] args) {
        char ch = 'u';
        char[] arr = new char[]{'m', 'u', 'a', 'z', 'z', 'a', 'm'};
        int result = count(ch, arr);
        System.out.println("Count: " + result);
    }
}


