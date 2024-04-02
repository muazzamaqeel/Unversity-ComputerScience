public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
    }
}


/*
 * Bucket sort, also known as bin sort, is an algorithm that distributes the elements of an array into a number of buckets. Each bucket is then sorted individually, 
 * either using a different sorting algorithm or by recursively applying the bucket sort algorithm. The sorted elements are then concatenated to get the final sorted 
 * array. This sorting technique is mainly useful when the input is uniformly distributed over a range.
    Here’s a step-by-step breakdown of how bucket sort works:
    1.  Initialization: 
        Decide how many buckets you need, typically denoted as \(n\), which could be equal to the length of the array. Create these buckets, which 
        can be represented as empty lists or arrays.
    2.  Distribution: 
        Go through the input array, and for each element, determine which bucket it belongs to. This can be done based on the range of values and 
        dividing that range by the number of buckets. Place each element into its corresponding bucket.
    3.  Individual Sorting: 
        Sort the elements in each bucket. This can be done using any sorting algorithm, such as quicksort, mergesort, or even another bucket sort 
        recursively if the buckets are large.
    4.  Concatenation: 
        Merge the buckets together in order, one after the other, to form the final sorted array. This step involves concatenating the elements of each bucket, 
        preserving their sorted order.
    An important aspect of bucket sort is the distribution step, where elements must be spread out uniformly for the algorithm to be efficient. If all elements end up in a single bucket, 
    the advantage of bucket sort diminishes, and its complexity approaches that of the sorting algorithm used for sorting individual buckets.
    Bucket sort is most effective when used on data that is uniformly distributed across the range. It's particularly good when you have floating-point numbers ranging from 0 to 1 
    or any other range where the distribution is uniform. The time complexity of bucket sort is \(O(n+k)\) on average, where \(n\) is the number of elements to be sorted, and \(k\) is the number of buckets. 
    However, in the worst case (when all elements are placed into a single bucket), the complexity depends on the sorting algorithm used for the individual buckets.
 * 
 */