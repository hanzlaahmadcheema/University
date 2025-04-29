/*
Memory Allocation
Array: Allocated in contiguous blocks of memory, which makes indexing fast but requires a block of memory large enough to hold the entire array.
Linked List: Each element (node) is stored in separate memory locations, and each node points to the next. This allows flexible memory allocation and makes it easier to grow dynamically.
2. Size and Dynamic Resizing
Array: Fixed size in most programming languages, meaning you need to know the size in advance. In languages like Python (which uses dynamic arrays), resizing may involve copying to a new location.
Linked List: Dynamic size; nodes can be added or removed at any point, which makes linked lists more flexible for applications where the number of elements can change frequently.
3. Access Speed
Array: Direct access by index (e.g., arr[3]), making access time 

O(1).
Linked List: Sequential access only, requiring traversal from the head node to access a specific element. Access time is 

O(n) in the worst case.
4. Insertion and Deletion
Array: Expensive to insert or delete elements, especially in the middle or the beginning (

O(n)), because other elements have to be shifted.
Linked List: Efficient insertion and deletion at any position (especially at the beginning or end), as it only requires updating pointers. Insertion or deletion is 

O(1) if the position is known.
5. Memory Usage
Array: Memory-efficient as it only stores data.
Linked List: Requires additional memory to store pointers for each node (usually a reference to the next node, and sometimes to the previous node in doubly linked lists). This overhead makes linked lists more memory-intensive than arrays.
6. Cache Locality
Array: Better cache locality due to contiguous memory allocation. This can lead to faster access times because of CPU caching.
Linked List: Poor cache locality since nodes are scattered in memory, leading to more cache misses and generally slower access time.
7. Reverse Traversal
Array: Reverse traversal is straightforward by iterating backwards through indices.
Linked List: In singly linked lists, reverse traversal is not possible without additional data structures or reversing the list first. Doubly linked lists support reverse traversal but require extra memory for backward pointers.
*/