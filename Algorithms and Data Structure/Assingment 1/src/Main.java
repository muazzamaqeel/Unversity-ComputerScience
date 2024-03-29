


public class Main {
    static int cont=0;

        public static boolean areAnagrams(String s1, String s2){
            char[] arr2 = s2.toCharArray();
            char[] arr1 = s1.toCharArray();
            java.util.Arrays.sort(arr1);
            java.util.Arrays.sort(arr2);
            if (arr1.length != arr2.length) {
                return false;
            }
            for (int i = 0; i < arr1.length; i++) {
                if (arr1[i] == arr2[i]) {
                    System.out.println(arr1[i]+""+arr2[i]);
                } else {
                    return false;
                }
            }
            return true;
        }





    public static void main(String[] args) {



        int n=2;
        for (int i = 0; i < 2*n; i++) {
            for (int k = i; k >= 0; k--) {
               // System.out.println("Test!"+cont);
                cont =  cont + 1;

            }
        }







        // Anagrams are words or phrases that are formed by rearranging the letters of another word or phrase,
        // using all the original letters exactly once. The meaning of the anagram is usually unrelated to the
        // meaning of the original word or phrase. For example, "silent" and "listen" are anagrams of each other.
        // The concept of an anagram is centered on the permutation of letters to form different words or phrases.

        boolean result1 = areAnagrams("silen2", "listen");
        System.out.println("result1: "+result1); // Expected: true
        System.out.println("-----------------------------------");


        boolean result2 = areAnagrams("rail safety", "fairy tales");
        System.out.println("result2: "+result2); // Expected: true
        System.out.println("-----------------------------------");


        boolean result3 = areAnagrams("coronavirus", "carnivorous");
        System.out.println("result3: "+result3); // Expected: true
        System.out.println("-----------------------------------");


        boolean result4 = areAnagrams("permutation", "traumpoetin");
        System.out.println("result4: "+result4); // Expected: true
        System.out.println("-----------------------------------");


        boolean result5 = areAnagrams("Muazza1", "mazzauM");
        System.out.println("result5: "+result5); // Expected: true
        System.out.println("-----------------------------------");








    }




}