//
// Created by ЧИКИРЯУ on 12.04.2021.
//
#include <algorithm>
#include "segment_tree_min.hpp"
// файл с определениями

namespace itis {
  SegmentTreeMin::SegmentTreeMin(int *array, int size) : array_(array), size_{size} {
    buildTree_(0, size_ - 1);
  }

  SegmentTreeMin::~SegmentTreeMin() {
    deleteNodes_(headNode_);
    size_ = 0;
  }

  Node *SegmentTreeMin::buildTree_(int left, int right) {
    if (left == right) {
      return new Node(array_[right]);
    }

    int midl = (left + right) / 2;
    Node *leftChildren = buildTree_(left, midl);
    Node *rightChildren = buildTree_(midl + 1, right);
    headNode_ = new Node(leftChildren, rightChildren,
                         leftChildren->data_ > rightChildren->data_ ? rightChildren->data_ : leftChildren->data_);
    return headNode_;
  }

  Node *SegmentTreeMin::update_(Node *node, int index, int newValue, int tempLeft, int tempRight) {
    if (tempRight == tempLeft) {
      node->data_ = newValue;
      return node;
    }
    int midl = (tempLeft + tempRight) / 2;
    if (index <= midl) {
      update_(node->leftChildren_, index, newValue, tempLeft, midl);
      node->data_ = std::min(node->leftChildren_->data_, node->rightChildren_->data_);
    } else {
      update_(node->rightChildren_, index, newValue, midl + 1, tempRight);
      node->data_ = std::min(node->leftChildren_->data_, node->rightChildren_->data_);
    }
    return node;
  }

  int SegmentTreeMin::getMin_(Node *node, int left, int right, int tempLeft, int tempRight) {
    if (left > right) {
      return INT_MAX;
    }
    if (left == tempLeft && right == tempRight) {
      return node->data_;
    }
    int midl = (tempRight + tempLeft) / 2;
    int temp1 = getMin_(node->leftChildren_, left, std::min(right, midl), tempLeft, midl);
    int temp2 = getMin_(node->rightChildren_, std::max(left, midl + 1), right, midl + 1, tempRight);
    return temp1 > temp2 ? temp2 : temp1;
  }

  void SegmentTreeMin::deleteNodes_(Node *pNode) {
    if (pNode->leftChildren_ != nullptr) {
      deleteNodes_(pNode->leftChildren_);
    }
    if (pNode->rightChildren_ != nullptr) {
      deleteNodes_(pNode->rightChildren_);
    }
    delete pNode;
  }

}  // namespace itis
