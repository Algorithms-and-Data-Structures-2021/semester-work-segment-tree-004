#include <algorithm>
#include "segment_tree_sum.hpp"
// файл с определениями

namespace itis {
	SegmentTreeSum::SegmentTreeSum (int *array, int size) : size_{size}, array_ (array) {
		buildTree_ (0, size_ - 1);
	}
	
	SegmentTreeSum::~SegmentTreeSum () {
		//todo delete nods
		deleteNodes (headNode_);
		size_ = 0;
	}
	
	Node *SegmentTreeSum::buildTree_ (int left, int right) {
		if (left == right) {
			return new Node (array_[right]);
		}
		
		int midl = (left + right) / 2;
		Node *leftChildren = buildTree_ (left, midl);
		Node *rightChildren = buildTree_ (midl + 1, right);
		headNode_ = new Node (leftChildren, rightChildren, leftChildren->data_ + rightChildren->data_);
		return headNode_;
	}
	
	int SegmentTreeSum::getSum_ (Node *node, int left, int right, int tempLeft, int tempRight) {
		if (left > right) {
			return 0;
		}
		if (left == tempLeft && right == tempRight) {
			return node->data_;
		}
		int midl = (tempRight + tempLeft) / 2;
		return getSum_ (node->leftChildren_, left, std::min (right, midl), tempLeft, midl) +
		       getSum_ (node->rightChildren_, std::max (left, midl + 1), right, midl + 1, tempRight);
	}
	
	Node *SegmentTreeSum::update_ (Node *node, int index, int newValue, int tempLeft, int tempRight) {
		if (tempRight == tempLeft) {
			node->data_ = newValue;
			return node;
		}
		int midl = (tempLeft + tempRight) / 2;
		if (index <= midl) {
			update_ (node->leftChildren_, index, newValue, tempLeft, midl);
			node->data_ = node->leftChildren_->data_ + node->rightChildren_->data_;
		} else {
			update_ (node->rightChildren_, index, newValue, midl + 1, tempRight);
			node->data_ = node->leftChildren_->data_ + node->rightChildren_->data_;
		}
		return node;
	}
	
	void SegmentTreeSum::deleteNodes (Node *pNode) {
		if (pNode->leftChildren_ != nullptr) {
			deleteNodes (pNode->leftChildren_);
		}
		if (pNode->rightChildren_ != nullptr) {
			deleteNodes (pNode->rightChildren_);
		}
		delete pNode;
	}
	
	
}  // namespace itis