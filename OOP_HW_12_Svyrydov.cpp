// Task 2
// Implement a doubly linked list:
// 
// • Create the specified list(s).
// • Print the list(s) – display the values of the elements on the screen.
// • Perform the actions specified in the task.
// • Display the results on the screen.
// • Check if the elements of the list are ordered in non - decreasing order.
// • Determine if the list contains a pair of elements(not necessarily adjacent) with the same data field values.
// • Swap elements in the list – first with second, third with fourth, and so on.
// • Determine if list L1 is a sublist of list L2(i.e., if list L2 contains all elements of list L1 in the same order).
//

#include <iostream>
#include "Node.h"

using namespace std;

int main()
{
    // Create a new linked list with initial value 1
    Node* node = new Node(1);

    // Adding elements to the linked list
    setValueToTail(node, 2);
    setValueToTail(node, 3);
    setValueToTail(node, 4);
    setValueToTail(node, 4);
    setValueToTail(node, 5);
    setValueToTail(node, 6);
    setValueToTail(node, 7);
    setValueToTail(node, 8);
    setValueToTail(node, 9);

    // Display the linked list from the head
    cout << "\n\nDisplay node list from head:\n";
    display(node);

    // Check if the elements in the linked list are ordered
    if (checkElements(node))
    {
        cout << "\n\nThe elements of the list are ordered in non-decreasing order.";
    }
    else
    {
        cout << "\n\nThe elements of the list are ordered in decreasing order.";
    }

    // Display the linked list from the tail
    cout << "\n\nDisplay node list from tail:\n";
    display(getTail(node));

    // Check if the elements in the tail-linked list are ordered
    if (checkElements(getTail(node)))
    {
        cout << "\n\nThe elements of the list are ordered in non-decreasing order.";
    }
    else
    {
        cout << "\n\nThe elements of the list are ordered in decreasing order.";
    }

    // Count occurrences of a specific value in the linked list
    cout << "\n\nElement \"4\" occurs " << findPair(node, 4) << " times";

    // Swap adjacent elements in the linked list
    cout << "\n\nSwap elements in the list - first with second\n";
    swap(node);
    display(node);

    // Create a new linked list
    Node* node2 = new Node(4);
    setValueToTail(node2, 3);
    setValueToTail(node2, 5);
    setValueToTail(node2, 4);
    setValueToTail(node2, 7);

    // Display the contents of the first linked list
    cout << "\n\nNode 1\n";
    display(node);

    // Display the contents of the second linked list
    cout << "\n\nNode 2\n";
    display(node2);

    // Compare if the second linked list is contained in the first
    if (compare(node2, node))
    {
        cout << "\n\nNode 2 is in Node 1";
    }
    else
    {
        cout << "\n\nNode 2 is not in Node 1";
    }

    // Add a new element to the second linked list
    cout << "\n\nAdd new element to node 2";
    setValueToTail(node2, 5);

    // Display the updated second linked list
    cout << "\n\nNode 2\n";
    display(node2);

    // Compare again after adding an element to the second linked list
    if (compare(node2, node))
    {
        cout << "\n\nNode 2 is in Node 1";
    }
    else
    {
        cout << "\n\nNode 2 is not in Node 1";
    }

    cout << "\n\n\n";
}