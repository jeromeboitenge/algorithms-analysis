import java.util.Arrays;

public class ArrayRearrange {
    public static void rearrangeArray(int[] arr) {
        int left = 0; // pointer for negative keys
        int right = arr.length - 1; // pointer for non-negative keys

        while (left <= right) {
            // If the element at the left pointer is negative, move the left pointer to the right
            if (arr[left] < 0) {
                left++;
            }
            // If the element at the right pointer is non-negative, move the right pointer to the left
            else if (arr[right] >= 0) {
                right--;
            }
            // If the element at the left pointer is non-negative and the element at the right pointer is negative,
            // swap them and move both pointers
            else {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {-3, 2, -1, 0, 4, -5};
        rearrangeArray(arr);
        System.out.println(Arrays.toString(arr)); // Output: [-3, -1, -5, 0, 2, 4]
    }
}