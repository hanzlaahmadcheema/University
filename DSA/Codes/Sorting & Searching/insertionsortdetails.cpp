/*Insertion sort is a simple sorting algorithm that builds the final sorted array one element at a time. It works similarly to the way you might sort playing cards in your hand. Here’s how it works step-by-step:

Steps of Insertion Sort
Start with the second element (index 1) in the list, as a single element is trivially sorted.
Compare this element with the element(s) before it.
If the element is smaller than the one before it, shift the larger element(s) one position to the right to make room.
Insert the element in the correct position.
Repeat this process for each subsequent element in the list until the entire list is sorted.
Example
Suppose we want to sort the array [5, 3, 8, 4, 2].

Initial array: [5, 3, 8, 4, 2]
Start with the second element (3):
Compare 3 with 5. Since 3 < 5, shift 5 to the right and insert 3 in its place.
Array becomes [3, 5, 8, 4, 2]
Move to the third element (8):
Compare 8 with 5. Since 8 > 5, no shifting is needed.
Array remains [3, 5, 8, 4, 2]
Move to the fourth element (4):
Compare 4 with 8, shift 8 to the right.
Compare 4 with 5, shift 5 to the right.
Insert 4 in the correct position.
Array becomes [3, 4, 5, 8, 2]
Move to the fifth element (2):
Compare 2 with 8, shift 8 to the right.
Compare 2 with 5, shift 5 to the right.
Compare 2 with 4, shift 4 to the right.
Compare 2 with 3, shift 3 to the right.
Insert 2 in the correct position.
Array becomes [2, 3, 4, 5, 8]
Complexity
Time Complexity:
Worst-case: 

O(n2) (when the array is in reverse order)
Best-case: 

O(n) (when the array is already sorted)
Space Complexity: 

O(1) (in-place sorting)
Key Points
Insertion sort is efficient for small or nearly sorted lists.
It is stable, meaning equal elements retain their relative order.
It is often used in practice for small input sizes or as a part of more complex algorithms like Timsort.*/