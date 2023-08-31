#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
	int value; // Value stored in the node
	Node* next; // Pointer to the next node in the linked list
	Node* prew;// Pointer to the previous node in the linked list
	
	Node();// Default constructor to create a node with default values
	Node(int);// Constructor to create a node with a given value
};

// Function to set a new value to the tail of the linked list
void setValueToTail(Node*&, int);

// Function to display the values of nodes in the linked list
void display(Node*);

// Function to get the tail node of the linked list
Node* getTail(Node*);

// Function to check if elements in the linked list are in non-decreasing order
bool checkElements(Node*);

// Function to find the number of pairs with a specific value in the linked list
int findPair(Node*, int);

// Function to swap adjacent elements in the linked list
void swap(Node*&);

// Function to compare two linked lists and check if one is a subsequence of the other
bool compare(Node*, Node*);