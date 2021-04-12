#include <iostream>
#include <segment_tree_min.hpp>

#include "segment_tree_sum.hpp"

using namespace itis;
using namespace std;

int main () {
	int  size;
	cin>>size;
	int *firstArray = new int[size];
	for (int i = 0; i < size; ++i) {
		cin>>firstArray[i];
	}
	SegmentTreeMin *s1 = new SegmentTreeMin (firstArray, size);
//	cout<<s1->getMin(0,7);
//	cout<<s1->getMin(0,0);
	cout<<s1->getMin(0,1);
//	cout<<s1->getMin(8,8);
//	cout<<s1->getMin(5,6);
//	cout<<s1->getMin(0,7);

	return 0;
}