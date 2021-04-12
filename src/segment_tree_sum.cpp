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
			return new Node (array_[right]);
		}

		int tm = (left + right) / 2;
		Node *leftChildren = buildTree_ (left, tm);
		Node *rightChildren = buildTree_ (tm + 1, right);
		return new Node (leftChildren, rightChildren, leftChildren->data + rightChildren->data);
	}

	int SegmentTreeSum::getSum_ (Node *node,int left, int right, int tempLeft, int tempRight) {
		if (left>right){
			return getSum_(node,right,left,tempLeft,tempRight);
		}
		if (left==tempLeft && right == tempRight){
			return node->data;
		}
		int midl = (right+left) / 2;
		return getSum_(node->leftChildren, left, right, left, midl) +
			   getSum_(node->rightChildren, left, right, midl, right);
	}
	
	Node * SegmentTreeSum::update_ (Node * node,int index, int newValue, int tempLeft, int tempRight) {
		if (tempRight==tempLeft){
			delete node;
			return new Node(newValue);
		}
		int midl = (tempLeft+tempRight)/2;
		if (index <= midl){
			delete node->leftChildren;
			Node * newLeftNode = update_ (node->leftChildren,index ,newValue, tempLeft, midl);
			return new Node (newLeftNode,node->rightChildren,newLeftNode->data+node->rightChildren->data);
		}
		else{
			delete node->rightChildren;
			Node *newRightNode = update_ (node->rightChildren, index,newValue,midl+1, tempRight);
			return new Node (node->leftChildren, newRightNode,node->leftChildren->data+newRightNode->data);
		}
	}


}  // namespace itis