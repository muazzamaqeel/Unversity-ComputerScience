package assignment01;

public class Exercise1_5_Part_B {

    public static int i = 0;
    public static boolean containsOdd(int[] arr, int endIndex){
        if(arr==null || endIndex >= arr.length){
            return true;
        }else {
            if (arr[endIndex] % 2 != 0) {  //Odd
                return containsOdd(arr,endIndex+1);
            }
            if (arr[endIndex] % 2 == 0) { //Even
                return false;
            }
            return true;
        }
    }
    public static void main(String[] args) {

        int[] arr = {3,13,7,2,2,2,2,41,2,3};
        int endIndex = 0;
        boolean Result = containsOdd(arr, endIndex);
        System.out.println("All the values are odd: " + Result);
    }
}
