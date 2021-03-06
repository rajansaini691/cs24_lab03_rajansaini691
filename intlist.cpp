// intlist.cpp
// Implements class IntList
// Rajan Saini, 11/10/2018 

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    first = 0;
    for(Node* s = source.first; s != 0; s = s->next) {
		append(s->info);
    }
    
}

// destructor deletes all nodes
IntList::~IntList() {
	deleteListIter();
}

// Deletes the entire list recursively.
void IntList::deleteList(Node* n) const {
	// Takes an empty list into account
	if(n == NULL) {
		return;
	}

	if(n->next == NULL) {
		delete n;
		return;
	} else {
		deleteList(n->next);
	}
	delete n;
}

// Deletes the entire list iteratively
void IntList::deleteListIter() const {
	Node* next = NULL;
	Node* curr = first;
	bool run = true;
	while(curr) {
		next = curr->next;
		delete curr;
		curr = next;
	}
}


// return sum of values in list
int IntList::sum() const {
	Node *n = first; 
	int sum = 0;

	while(n) {
		sum += n->info;
		n = n->next;
	}

	return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    for(Node *n = first; n != 0; n = n->next) {
	    if(value == n->info) {
		    return true;
	    }
    }

    return false; 
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    // Check for empty list
    if(first == 0) {
	return 0;
    }

    int maxVal = first->info;
    
    for(Node *n = first; n != 0; n = n->next) {
	    if(n->info > maxVal) {
		    maxVal = n->info;
	    }
    }
    return maxVal;
	
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    return (count() != 0) ? (0.0 + sum()) / count() : 0;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node *n = new Node;
    n->info = value;
    n->next = first;
    first = n;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    deleteListIter();

    first = 0;
    
    for(Node* s = source.first; s != NULL; s = s->next) {
	append(s->info);
    }

    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
