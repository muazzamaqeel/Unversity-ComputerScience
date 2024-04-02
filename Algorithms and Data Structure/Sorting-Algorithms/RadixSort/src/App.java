import java.util.Arrays;
public class App {
    
    // A utility function to get maximum value in arr[]
    static int getMax(int arr[], int n) {
            int mx = arr[0];
            for (int i = 1; i < n; i++)
                if (arr[i] > mx)
                    mx = arr[i];
            return mx;
        }
    
        // A function to do counting sort of arr[] according to
        // the digit represented by exp.
        static void countSort(int arr[], int n, int exp) {
            int output[] = new int[n]; // output array
            int i;
            int count[] = new int[10];
            Arrays.fill(count, 0);
    
            // Store count of occurrences in count[]
            for (i = 0; i < n; i++)
                count[(arr[i] / exp) % 10]++;
    
            // Change count[i] so that count[i] now contains
            // actual position of this digit in output[]
            for (i = 1; i < 10; i++)
                count[i] += count[i - 1];
    
            // Build the output array
            for (i = n - 1; i >= 0; i--) {
                output[count[(arr[i] / exp) % 10] - 1] = arr[i];
                count[(arr[i] / exp) % 10]--;
            }
    
            // Copy the output array to arr[], so that arr[] now
            // contains sorted numbers according to current digit
            for (i = 0; i < n; i++)
                arr[i] = output[i];
        }
    
        // The main function to that sorts arr[] of size n using
        // Radix Sort
        static void radixsort(int arr[], int n) {
            // Find the maximum number to know number of digits
            int m = getMax(arr, n);
    
            // Do counting sort for every digit. Note that
            // instead of passing digit number, exp is passed.
            // exp is 10^i where i is current digit number
            for (int exp = 1; m / exp > 0; exp *= 10)
                countSort(arr, n, exp);
        }
    
        // A utility function to print an array
        static void print(int arr[], int n) {
            for (int i=0; i<n; i++)
                System.out.print(arr[i]+" ");
        }
    
        // Driver Code
        public static void main(String[] args) {
            int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
            int n = arr.length;
              
            // Function Call
            radixsort(arr, n);
            print(arr, n);
        }
}
    

/*
 * The way it works:
 * 
 * The main idea of Radix Sort Algorithm is that is processes individual digits from the array
 * It sorts numbers from the least sifnificant digit (LSD) to the most significant digit (MSD), using
 * a stable intermediate storing algorithm like counting sort for sorting digits at each position
 * 
 * Steps Involved
 * 
 * 1: Find the maximum number: To determine the number of digits in the largest number, the algorithm first finds
 * the maximum value in the array. This step is crucial because it dictates how many times the algorithm needs to sort the array
 * based on each digit's position
 * 
 * 2: Counting Sort by digit: Instead of coparing the numbers as whole, RadixSort processes one digit at a time for all the numberds.
 * It does so in a way that preserves the order of numbers with the same digit in the current position. This step is
 * repeated for each digit position, starting from the least significant digit (rightmost) to the most significant digit (leftmost)
 * 
 *  a:  Counting Occurreneces: For each digit posistion being sorted, the algorithm counts how many times each digit (0 to 9) appears
 *      using a counting array. This is done by iterating through the entire array and incrementing the count for the digit at the current 
 *      position
 *  b:  Shifting Elements: The orginal array travrsed backwards, and elements are placed nto an output array based on the cumulative counts.
 *      This step ensures that the sorting is stable, meaning that two elements with the same value apprear in the output array in the same 
 *      order as they appeared in the input array.
 *  c:  Repeat for All Digit Positions: This porcess is repeated for each digit position, moving drom the least significant digit to the most significant digit.
 *      With each pass, the array becomes sorted according to the that digit position, and because o the algorithm's stability, the prvious digit's order is
 *      preserved.
 *  d:  Once all digit positions have been processed, the array is fully sorted and the algorithm completes.
 * 
 * 
 *      In the best case, the time complexity of this algorithm is O(n log n). Radix Sort achieves this by effciently distributing and collecting elements based
 *      on their radix (Base), ensuring a globally sorted order through localized, digit-by-digit sorting
 * 
 */
