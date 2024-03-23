package assignment01;
public class Exercise1_5_Part_A {
    public static int i = 0;
    public static boolean containsOdd(int[] arr, int endIndex){
        if(arr==null || endIndex >= arr.length){
            return false;
        }else {
            if (arr[endIndex] % 2 == 0) {
                return containsOdd(arr,endIndex+1);
            }
            return true;
        }
    }
    public static void main(String[] args) {

        int[] arr = {6,4,2};
        int endIndex = 0;
        boolean Result = containsOdd(arr, endIndex);
        System.out.println("Result: " +Result);

    }
}
