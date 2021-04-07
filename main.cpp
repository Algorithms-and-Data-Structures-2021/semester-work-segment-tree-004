#include <iostream>

#include "segment_tree.hpp"

using namespace std;

int main() {
	int size;
	std::cin>>size;
	int *arr = new int [size];
	for (int i = 0; i < size; ++i) {
		std::cin>>arr[i];
	}
	auto *st = new itis::SegmentTree(arr, size);
	std::cout<<arr;
	std::cout<<st->toString();
  return 0;
}