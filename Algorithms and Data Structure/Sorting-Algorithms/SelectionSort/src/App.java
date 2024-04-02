public class App {
    void sort(int arr[]) {
        int n = arr.length;

        // One by one move the boundary of the unsorted subarray
        for (int i = 0; i < n - 1; i++) {
            // Find the minimum element in the unsorted array
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            // Swap the found minimum element with the first
            // element of the unsorted section
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }

    // Utility method to print the array
    void printArray(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    // Driver code to test above
    public static void main(String args[]) {
        App ob = new App();
        int arr[] = { 64, 25, 12, 22, 11 };
        ob.sort(arr);
        System.out.println("Sorted array");
        ob.printArray(arr);
    }

}

/*
 * The way it works
 * 
 * Intial: The assumtion is that we have an unstorted array
 * 
 * Step1: Finding the minimum elemenet: For this the algorithm iterates through the unsorted subarray to find
 * the minimum element. (This step requires scanning all the elements in the unsorted section, making comprasion to identify the smallest one)
 * This search for the minimum element is a linear search, with a complexity of O(n) for each pass, where n is the length of the array
 * 
 * Step2: Once the minimum element is the unsorted subarray is identified, it is swapped with the leftmost element of the unsorted subarray 
 * (Unless the element already at the leftmost position (Fun Fact: it still counts as a swap, albeit with itself))
 * 
 * Step3: (Repeating the Process) - After the swap, the boundary between the sorted and the unsorted subarrays moves one element to the right
 * The process repeats, noe considering the new unsorted subarray (which is one element smaller). Each pass through the array results in one
 * element being moved into its correct position within the sorted subarray
 * 
 * 
 */