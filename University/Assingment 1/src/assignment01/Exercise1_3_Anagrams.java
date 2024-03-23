package assignment01;

import org.junit.Test;

import java.util.Random;
import javax.swing.JOptionPane;

public class Exercise1_3_Anagrams {

    /**
     * Checks if both strings are anagrams, i.e. one string can be formed by
     * rearranging the characters of the other.
     */
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
                //System.out.println(arr1[i]+""+arr2[i]);
            } else {
                return false;
            }
        }
        return true;
    }



    private static Random rand = new Random();

    /**
     * Measures running time of the anagram check
     * Important: Use option -Xint of the java interpreter in order to get
     * meaningful results.
     *
     */


    @Test
    public static void main(String[] args) {
        simpleTests();

        String eingabe = JOptionPane.showInputDialog("maximum length:");
        if (eingabe == null) {
            System.out.println("good-bye.");
            return;
        }
        int laenge = Integer.parseInt(eingabe);

        System.out.println("Anagrams: ");
        for (int len = 100; len <= laenge; len *= 10) {
            String[] anas = generateAnagrams(len);
            boolean result = measureReorderingTest(anas[0], anas[1]);
            if (result == false) {
                throw new RuntimeException("Wrong result of anagram test");
            }

            System.out.println();
        }

        System.out.println();
        System.out.println("NOT anagram:");
        for (int len = 100; len <= laenge; len *= 10) {
            String[] nonAnas = generateNonAnagrams(len);
            boolean result = measureReorderingTest(nonAnas[0], nonAnas[1]);
            if (result == true) {
                throw new RuntimeException("Wrong result of anagram test");
            }
            System.out.println();
        }

        System.out.println("finished!");
    }


    /**
     *
     * Generates a string of the specified length consisting of randomly selected
     * characters in the range from 'A' to 'Z'

     */
    public static String generateRandomString(int length) {
        StringBuilder sb1 = new StringBuilder(length);
        for (int i = 0; i < length; i++) {
            char ch = (char) (rand.nextInt('z'-'A') + 'A');
            sb1.append(ch);
        }
        return sb1.toString();
    }

    /** Generates a pair of anagram strings of the given length */
    public static String[] generateAnagrams(int length) {
        // generate randomly first string
        String s1 = generateRandomString(length);

        // generate a random permutation of s1

        // at first build a copy
        StringBuilder sb2 = new StringBuilder(s1);
        for (int j = 0; j <= length / 4; j++) {
            //swap characters at two randomly choosen positions
            int pos1 = rand.nextInt(length);
            int pos2 = rand.nextInt(length);
            char tmp1 = sb2.charAt(pos1);
            char tmp2 = sb2.charAt(pos2);
            sb2.setCharAt(pos1, tmp2);
            sb2.setCharAt(pos2, tmp1);
        }

        // result of permutations is second string
        String s2 = sb2.toString();

        //return pair of both strings
        return new String[]{s1,s2};

    }

    /** Generates two strings of the specified length that are not anagrams */
    public static String[] generateNonAnagrams(int length) {
        // randomly generate first string
        String s1 = generateRandomString(length);

        // build copy of string s1
        StringBuilder sb2 = new StringBuilder(s1);

        // modify last character of the second string, so that it
        // is different from the first string
        int pos = sb2.length()  - 1;
        if (sb2.charAt(pos) == 'X') {
            sb2.setCharAt(pos, 'a');
        }
        else {
            sb2.setCharAt(pos, 'X');
        }

        String s2 = sb2.toString();

        // return both strings
        return new String[]{s1,s2};

    }




    /** Measures running time for test if s1 and s2 are anagrams */
    private static boolean measureReorderingTest(String s1, String s2) {
        System.out.println("L�nge s1: " + s1.length());
        System.out.println("L�nge s2: " + s2.length());

        long tStart = System.nanoTime();

        boolean res = areAnagrams(s1, s2);

        long tEnd = System.nanoTime();

        System.out.println("anagrams? : " + res);

        System.out.println("running time: " + (tEnd - tStart)/1e6 + " ms");
        return res;
    }


    /** simple anagram tests  */
    private static void simpleTests() {
        System.out.println("silent/listen: " + areAnagrams("silenp", "listen"));
        System.out.println("railsafety/fairytales: " + areAnagrams("rail safety", "fairy tales"));
        System.out.println("coronavirus/carnivorous: " + areAnagrams("coronavirus", "carnivorous"));
        System.out.println("LAMPE/PALME: " + areAnagrams("LAMPE", "PALME"));
        System.out.println("WIEN/WEIN: " + areAnagrams("WIEN","WEIN"));
        System.out.println("ERBGUT/BETRUG: " + areAnagrams("ERBGUT","BETRUG"));
        System.out.println("SCHUTZUMSCHLAG/UMZUGSSCHLACHT: " + areAnagrams("SCHUTZUMSCHLAG","UMZUGSSCHLACHT"));
    }
}
