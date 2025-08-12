# QuickSort for Singly Linked List in C

## takeaway

okay so linked list quicksort works very differently in contract to using regular array quick sort. this is because for arrays its simply to swap the values, however in liked lists we remap the whole list of nodes. since we cant go back in a linked list instead we do the opposite of what wed generally do in a quick sort algorithm (swap value when current is <= to pivot) which is to move the current value to the end of the list when current > pivot.

conclusion quicksorting a linkid list is FUCKING PAINFUL. TOOK ME LIKE 3 FUCKING HOURS AND STILL DIDNT GET IT RIGHT. anyway the below code was AI assisted :)

enjoy.

## Implementation

```c
#include <stdio.h>
#include <stdlib.h>

// Assuming 'node' is defined as:
// typedef struct node {
//     int value;
//     struct node *nextnode;
// } node;

// Function to find the tail of a linked list
node *get_tail(node *current) {
    while (current != NULL && current->nextnode != NULL) {
        current = current->nextnode;
    }
    return current;
}

// Partition function for quicksort
node *partition(node *head, node *end, node **new_head, node **new_end) {
    node *pivot = end;
    node *prev = NULL, *current = head, *tail = pivot;

    // Traverse the list and rearrange nodes
    while (current != pivot) {
        if (current->value <= pivot->value) {
            // This is the first node of the new list
            if (*new_head == NULL) {
                *new_head = current;
            }
            prev = current;
            current = current->nextnode;
        } else {
            // Move current node to the end of the list
            if (prev) {
                prev->nextnode = current->nextnode;
            }
            node *temp = current->nextnode;
            current->nextnode = NULL;
            tail->nextnode = current;
            tail = current;
            current = temp;
        }
    }

    // If the pivot is the smallest element, it becomes the new head
    if (*new_head == NULL) {
        *new_head = pivot;
    }

    *new_end = tail;
    return pivot;
}

// Recursive quicksort function
node *quicksort_recursive(node *head, node *end) {
    // Base case: list is empty or has one node
    if (!head || head == end) {
        return head;
    }

    node *new_head = NULL, *new_end = NULL;
    node *pivot = partition(head, end, &new_head, &new_end);

    // If pivot is the first element, no need to recurse on the left side
    if (new_head != pivot) {
        // Find the node before the pivot
        node *temp = new_head;
        while (temp->nextnode != pivot) {
            temp = temp->nextnode;
        }
        // Disconnect the left part and recurse
        temp->nextnode = NULL;
        new_head = quicksort_recursive(new_head, temp);

        // Reconnect the left part to the pivot
        temp = get_tail(new_head);
        temp->nextnode = pivot;
    }

    // Recurse on the right part
    pivot->nextnode = quicksort_recursive(pivot->nextnode, new_end);

    return new_head;
}

// Main quicksort function
node *ll_quicksort(node *head) {
    node *tail = get_tail(head);
    return quicksort_recursive(head, tail);
}
```

## Complexity

- **Average case**: `O(n log n)`
- **Worst case**: `O(n²)` (already sorted list with bad pivot choice)
- **Space**: `O(log n)` for recursion stack

