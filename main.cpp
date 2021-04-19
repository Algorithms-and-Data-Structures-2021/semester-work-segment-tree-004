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
	s1->update(1,0);
	s1->update(2,-1);
	s1->update(3,-50);
	cout<<s1->getMin(0,7);

    delete s1;
	return 0;
}