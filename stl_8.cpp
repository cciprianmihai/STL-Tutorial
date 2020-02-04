// 4.1.2 section - Exercises Vector

// Exercise 2: Write a STL program that takes an arbitrary sequence of binary digits 
// (integer values 0 and 1) from cin and stores them into a container. When receiving 
// a value different from 0 or 1 from cin stop reading. Now, you should have a 
// container storing a sequence of 0's and 1's. After finishing the read-process, apply 
// a "bit-stuffing" algorithm to the container. Bit-stuffing is used to transmit data from 
// a sender to a receiver. To avoid bit sequences in the data, which would erroneously 
// be interpreted as the stop flag (here: 01111110), it is necessary to ensure that 
// six consecutive 1's in the data are splitted by inserting a 0 after each consecutive 
// five 1's. Hint: Complexity considerations (inserting in the middle of a vector takes 
// linear time!) and the fact, that inserting into a vector can make all iterators to 
// elements invalid should make you choose the STL container list. A list of integers 
// is defined like a vector by list<int> l; All operations explained in the vector section 
// are provided for the list, too. Get an iterator to the first list element. As long as this 
// iterator is different from the end() iterator increment the iterator and dereference it 
// to get the appropriate binary value. Note that an element is always inserted before 
// a specified iterator-position and that this insertion doesn't affect all the other iterators 
// defined when using a list. 

#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main ()
{
	// define a list of int
	list<int> bit_seq;    
	// value read from cin	
	int input = 0;        
	// counter for number of 1's	
	int count_1 = 0;             

	cout << "Insert values 0 and 1, another value to stop input..." << endl;

	while (cin >> input) {
		if (!(input == 0 || input == 1)) 
			break;
		 // list member function push_back
		bit_seq.push_back (input);            
	}

	// create a new list for bit_stuffing
	list<int> bit_stuffed_seq (bit_seq);

	// define loop iterators
	list<int>::iterator first = bit_stuffed_seq.begin();
	list<int>::iterator last  = bit_stuffed_seq.end();

	// bit stuff loop

	while (first != last) {
		// reset 1's-counter
		if (*first == 0)
			count_1 = 0;    	
		else if (*first == 1)
			// increment number of consecutive 1's
			count_1++;      
		// go to the next list element			
		first++;                        
		if (count_1 == 5) {
			// insert a 0 after the fifth consecutive 1
			bit_stuffed_seq.insert (first, 0);
			// reset counter
			count_1 = 0;				
		}
	}
	
	// reset loop iterators in order to print the new list
	first = bit_stuffed_seq.begin();
	last  = bit_stuffed_seq.end();
	
	while (first != last) {
		cout << *first++ << " ";
	}
}