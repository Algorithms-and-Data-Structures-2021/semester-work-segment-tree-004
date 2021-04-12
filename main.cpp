#include <iostream>

#include "segment_tree_sum.hpp"

using namespace std;

int main() {
	int size;
	std::cin>>size;
	int *arr = new int [size];
	for (int i = 0; i < size; ++i) {
		std::cin>>arr[i];
	}
	auto *st = new itis::SegmentTree(arr, size);

	std::cout<<st->getMin(0,0)<<"\n";
	std::cout<<st->getSum(0,st->getSize()-1);
  return 0;
}