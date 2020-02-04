// 4.1.1 section - Vector
#include <vector>
#include <iostream>

using namespace std;

int main (){  
	// Define a vector using the default constructor 
	vector<int> v;
	// Get the capacity of the vector 
	// Capacity = how many items can be fit in the vector before it is "full". Once full, adding new items will result in a new, larger block of memory being allocated and the existing items being copied to it.
	vector<int>::size_type capacity = v.capacity();
	// Get the size of the vector 
	// Size = the number of items currently in the vector
	vector<int>::size_type size = v.size();
	cout << "Capacity: " << capacity <<"\n";
	cout << "Size: " << size <<"\n";
}