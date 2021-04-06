#include "segment_tree.hpp"

// файл с определениями

namespace itis {

  SegmentTree::SegmentTree(int *array, int size) {
    size_ = size;
    buildTree(array);
  }

  SegmentTree::~SegmentTree() {
    // TODO
  }

  void SegmentTree::buildTree_(int *a, int v, int tl, int tr) {
    // TODO
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