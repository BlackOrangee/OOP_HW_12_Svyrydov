#include "Node.h"

// Default constructor
Node::Node()
{
	value = 0;
	next = nullptr;
	prew = nullptr;
}

// Constructor with value parameter
Node::Node(int value)
{
	this->value = value;
	next = nullptr;
	prew = nullptr;
}

// Function to set value to the tail node of the linked list
void setValueToTail(Node*& head, int value)
{
	Node* n = new Node(value); // Create a new node with the given value

	if (head == nullptr) // If the linked list is empty
	{
		head = n; // Make the new node the head of the linked list
		return;
	}

	Node* slider = head; // Create a slider node to traverse the linked list

	while (slider->next != nullptr) // Traverse until the last node (tail)
	{
		slider = slider->next; // Move to the next node
	}

	n->prew = slider; // Set the previous node of the new node to the current tail node
	slider->next = n; // Set the new node as the next node of the tail node
}

// Display the value of the node and its linked nodes
void display(Node* head)
{
	Node* slider = head; // Create a slider node to traverse the linked list starting from 'head' node

	while (slider != nullptr) // Traverse until the end of the linked list (nullptr)
	{
		cout << slider->value << " "; // Display the value of the current node

		if (head->prew == nullptr) // Check if 'head' has a previous node (used for reverse traversal)
		{
			slider = slider->next; // Move to the next node
		}
		else
		{
			slider = slider->prew; // Move to the prew node
		}
	}
}

// Function to get the tail node of the linked list
Node* getTail(Node* head)
{
	Node* slider = head; // Create a slider node to traverse the linked list starting from 'head' node

	while (slider->next != nullptr) // Traverse until the end of the linked list (nullptr)
	{
		slider = slider->next; // Move to the next node
	}
	return slider; // Return the tail node
}

// Function to check if elements are in increasing order in the linked list
bool checkElements(Node* head)
{
	Node* slider = head; // Create a slider node to traverse the linked list starting from 'head' node
	int temp = slider->value; // Store the value of the current node

	while (slider != nullptr) // Traverse until the end of the linked list (nullptr)
	{
		if (slider->value < temp) // Compare the value of the current node with the stored value
		{
			return false; // If the value is not in increasing order, return false
		}

		if (head->prew == nullptr) // If the linked list is not reversed
		{
			slider = slider->next; // Move to the next node
		}
		else // If the linked list is reversed
		{
			slider = slider->prew; // Move to the previous node (since it's a reversed linked list)
		}
	}
	return true; // All elements are in increasing order
}

// Function to find the number of occurrences of a specific value in the linked list
int findPair(Node* head, int value)
{
	Node* slider = head; // Create a slider node to traverse the linked list starting from 'head' node
	int counter = 0; // Counter to store the number of occurrences

	while (slider != nullptr) // Traverse until the end of the linked list (nullptr)
	{
		if (slider->value == value) // Check if the value of the current node matches the target value
		{
			counter++; // Increment the counter
		}

		if (head->prew == nullptr) // If the linked list is not reversed
		{
			slider = slider->next; // Move to the next node
		}
		else // If the linked list is reversed
		{
			slider = slider->prew; // Move to the previous node (since it's a reversed linked list)
		}
	}
	return counter; // Return the total number of occurrences
}

// Function to swap consecutive elements in the linked list
void swap(Node*& head)
{
	Node* slider = head; // Create a slider node to traverse the linked list starting from 'head' node
	bool counter = false; // A counter to alternate between swapping and not swapping
	int temp = 0; // Temporary variable to store values during swapping

	while (slider != nullptr) // Traverse until the end of the linked list (nullptr)
	{
		if (counter) // Check if it's time to swap
		{
			counter = false; // Reset the counter for the next iteration
		}
		else if (slider->next != nullptr) // Check if there's a next node to swap with
		{
			temp = slider->value; // Store the value of the current node
			slider->value = slider->next->value; // Assign the value of the next node to the current node
			slider->next->value = temp; // Assign the stored value to the next node
			counter = true; // Set the counter to true to indicate that swapping was done
		}

		slider = slider->next; // Move to the next node
	}
}

// Function to compare two linked lists and check if one is a subsequence of the other
bool compare(Node* head1, Node* head2)
{
	Node* slider1 = head1; // Create a slider node to traverse the linked list starting from 'head1'
	Node* slider2 = head2; // Create a slider node to traverse the linked list starting from 'head2'
	bool compare = false; // Variable to track the comparison result

	Node* temp_slider1 = new Node(); // Create a temporary slider for linked list 1
	Node* temp_slider2 = new Node(); // Create a temporary slider for linked list 2

	while (slider2 != nullptr) // Traverse linked list 2 until the end (nullptr)
	{
		while (slider1 != nullptr) // Traverse linked list 1 until the end (nullptr)
		{
			if (slider2->value == slider1->value) // Check if the values match
			{
				temp_slider2 = slider2; // Store the current node of linked list 2
				temp_slider1 = slider1; // Store the current node of linked list 1
				while (temp_slider1 != nullptr) // Traverse both linked lists for comparison
				{
					if (temp_slider2 == nullptr) // If linked list 2 ends before linked list 1
					{
						compare = false; // Set comparison result to false
						break;
					}

					if (temp_slider2->value == temp_slider1->value) // Compare values of both linked lists
					{
						compare = true; // Set comparison result to true
					}
					else
					{
						compare = false; // Set comparison result to false
					}
					temp_slider2 = temp_slider2->next; // Move temp slider for linked list 2
					temp_slider1 = temp_slider1->next; // Move temp slider for linked list 1
				}
			}
			slider1 = slider1->next; // Move to the next node in linked list 1
		}
		slider1 = head1; // Reset slider1 to the head of linked list 1
		slider2 = slider2->next; // Move to the next node in linked list 2
	}
	return compare; // Return the final comparison result
}
