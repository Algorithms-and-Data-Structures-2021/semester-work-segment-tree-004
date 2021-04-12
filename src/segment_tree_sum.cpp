#include <algorithm>
#include "segment_tree_sum.hpp"
// файл с определениями

namespace itis {
	SegmentTreeSum::SegmentTreeSum (int *array, int size) : size_{size} {
		array_ = array;
		buildTree_ (0, size_ - 1);
	}

	SegmentTreeSum::~SegmentTreeSum () {
		//todo delete nods
		size_ = 0;
	}

	Node * SegmentTreeSum::buildTree_ (int left, int right) {
		if (left == right){
			return new Node (array_[left]);
		}

		int tm = (left + right) / 2;
		Node *firstChildren = buildTree_ (left, tm);
		Node *secondChildren = buildTree_ (tm+1, right);
		return new Node (firstChildren,secondChildren, firstChildren->data+secondChildren->data);
	}

	int SegmentTreeSum::getSum_ (Node *node,int l, int r, int v, int tl, int tr) {
	
	}

//	void SegmentTreeSum::update_ (int idx, int val, int v, int tl, int tr) {
//		//вариант 1
//		if (idx <= tl && tr <= idx) {    //То же, что и idx == tl == tr
//			array_[idx] = val;
//			segmentTree_[v] = val;
//			return;
//		}
//
//		//вариант 2
//		if (tr < idx || idx < tl) {
//			return;
//		}
//
//		//вариант 3
//		int tm = (tl + tr) / 2;
//		update_ (idx, val, v * 2, tl, tm);
//		update_ (idx, val, v * 2 + 1, tm + 1, tr);
//		segmentTree_[v] = segmentTree_[v * 2] + segmentTree_[v * 2 + 1];
//	}


}  // namespace itis