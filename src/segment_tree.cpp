#include <algorithm>
#include "segment_tree.hpp"
// файл с определениями

namespace itis {
  SegmentTree::SegmentTree(int *array, int size): size_{size} {
	  array_ = array;
      segmentTree_ = new int[2*size];
	  std::copy(array,array+size,segmentTree_+size);
      buildTree_(1, 0, size_-1);
  }

  SegmentTree::~SegmentTree() {
    // TODO
    delete [] segmentTree_;
  }

  void SegmentTree::buildTree_(int v, int tl, int tr) {
    // TODO
	  if (tl == tr) {
		  segmentTree_[v] = array_[tl];    //сумма отрезка из одного элемента равна этому элементу
	  } else {
		  //tm - средний элемент отрезка.
		  //отрезок разбивается на два отрезка [tl; tm], [tm + 1; tr]
		  int tm = (tl + tr) / 2;
		  buildTree_(v * 2, tl, tm);
		  buildTree_(v * 2 + 1, tm + 1, tr);
		  segmentTree_[v] = segmentTree_[v * 2] + segmentTree_[v * 2 + 1];
	  }
  }

  int SegmentTree::getSum_(int l, int r, int v, int tl, int tr) {
    // TODO
  }

  void SegmentTree::update_(int idx, int val, int v, int tl, int tr) {
    // TODO
  }

  int SegmentTree::getMin_(int l, int r, int v, int tl, int tr) {
    // TODO
  }


}  // namespace itis