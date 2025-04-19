Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the list is sorted. The algorithm gets its name because the larger elements "bubble" to the top of the list with each pass.

Steps of Bubble Sort
Start at the beginning of the array.
Compare each pair of adjacent elements.
If the left element is greater than the right element, swap them.
Otherwise, leave them as they are.
Repeat the process for each element in the array, except the last sorted elements, which gradually “bubble up” to their correct position.
After each full pass through the array, the largest unsorted element is in its final position.
Stop when no swaps are needed during a pass, indicating the list is sorted.
Example
Suppose we want to sort the array [5, 3, 8, 4, 2] using bubble sort.

Initial array: [5, 3, 8, 4, 2]
First pass:
Compare 5 and 3: swap → [3, 5, 8, 4, 2]
Compare 5 and 8: no swap → [3, 5, 8, 4, 2]
Compare 8 and 4: swap → [3, 5, 4, 8, 2]
Compare 8 and 2: swap → [3, 5, 4, 2, 8]
Now, 8 is in its correct position.
Second pass:
Compare 3 and 5: no swap → [3, 5, 4, 2, 8]
Compare 5 and 4: swap → [3, 4, 5, 2, 8]
Compare 5 and 2: swap → [3, 4, 2, 5, 8]
Now, 5 is in its correct position.
Third pass:
Compare 3 and 4: no swap → [3, 4, 2, 5, 8]
Compare 4 and 2: swap → [3, 2, 4, 5, 8]
Now, 4 is in its correct position.
Fourth pass:
Compare 3 and 2: swap → [2, 3, 4, 5, 8]
Now, 3 is in its correct position.
The array is now sorted: [2, 3, 4, 5, 8]
Complexity
Time Complexity:
Worst-case: 
𝑂
(𝑛2)
 (when the array is in reverse order)
Best-case: 

O(n) (when the array is already sorted, and we optimize to stop early)
Space Complexity: 

O(1) (in-place sorting)
Key Points
Bubble sort is a simple algorithm suitable for small lists.
It is stable (preserves the order of equal elements).
It is inefficient for large datasets due to its quadratic time complexity.
arr [3,2,5,7,5,8]
arr [2,3,5,5,7,8]