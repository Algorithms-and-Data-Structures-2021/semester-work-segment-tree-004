#include <algorithm>
#include "segment_tree.hpp"
// файл с определениями

namespace itis {
	SegmentTree::SegmentTree (int *array, int size) : size_{size} {
		array_ = array;
		segmentTree_ = new int[2 * size];
		std::copy (array, array + size, segmentTree_ + size);
		buildTree_ (1, 0, size_ - 1);
	}
	
	SegmentTree::~SegmentTree () {
		// TODO
		delete[] segmentTree_;
	}
	
	void SegmentTree::buildTree_ (int v, int tl, int tr) {
		// TODO
		if (tl == tr) {
			segmentTree_[v] = array_[tl];    //сумма отрезка из одного элемента равна этому элементу
		} else {
			//tm - средний элемент отрезка.
			//отрезок разбивается на два отрезка [tl; tm], [tm + 1; tr]
			int tm = (tl + tr) / 2;
			buildTree_ (v * 2, tl, tm);
			buildTree_ (v * 2 + 1, tm + 1, tr);
			//todo create node for min search
			segmentTree_[v] = segmentTree_[v * 2] + segmentTree_[v * 2 + 1];
		}
	}
	
	int SegmentTree::getSum_ (int l, int r, int v, int tl, int tr) {
		//вариант 1
		if (l <= tl && tr <= r) {
			return segmentTree_[v];
		}
		
		//вариант 2
		if (tr < l || r < tl) {
			return 0;
		}
		
		//вариант 3
		int tm = (tl + tr) / 2;
		return getSum_ (l, r, v * 2, tl, tm)
		       + getSum_ (l, r, v * 2 + 1, tm + 1, tr);
	}
	
	void SegmentTree::update_ (int idx, int val, int v, int tl, int tr) {
		//вариант 1
		if (idx <= tl && tr <= idx) {    //То же, что и idx == tl == tr
			array_[idx] = val;
			segmentTree_[v] = val;
			return;
		}
		
		//вариант 2
		if (tr < idx || idx < tl) {
			return;
		}
		
		//вариант 3
		int tm = (tl + tr) / 2;
		update_ (idx, val, v * 2, tl, tm);
		update_ (idx, val, v * 2 + 1, tm + 1, tr);
		segmentTree_[v] = segmentTree_[v * 2] + segmentTree_[v * 2 + 1];
	}
	
	int SegmentTree::getMin_ (int l, int r, int v, int tl, int tr) {
		//вариант 1
		if (l <= tl && tr <= r) {
			return segmentTree_[v];
		}
		
		//вариант 2
		if (tr < l || r < tl) {
			return INT_MAX;     //Значение, которое не повлияет на общий минимум
		}
		
		//вариант 3
		int tm = (tl + tr) / 2;
		return std::min(getMin_(l, r, v * 2,     tl,     tm),
				  getMin_(l, r, v * 2 + 1, tm + 1, tr));
	}
	
	
}  // namespace itis