#pragma once

// Заголовочный файл с объявлением структуры данных

#include <private/node.hpp>

namespace itis {

  struct SegmentTreeSum {
   private:
  	Node *headNode;
    int size_{0};
    int *array_;

    // Рекурсивное построение дерева по изначальному массиву.
    // v - номер текущей вершины; left, right - границы соответствующего отрезка
    // v = 1, left = 0, right = n-1
    Node * buildTree_(int left, int right);

    // Запрос суммы
    // l, r - границы запроса;
    // v - номер текущей вершины; tl, tr - границы соответствующего отрезка
    // v = 1, tl = 0, tr = n-1,
    int getSum_(int l, int r, int v, int tl, int tr);


    // Запрос модификации
    // idx - индекс элемента, val - новое значение
    // v - номер текущей вершины; tl, tr - границы соответствующего отрезка
    void update_(int idx, int val, int v, int tl, int tr);

    

//    Node* tree_{nullptr};

   public:

    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    SegmentTreeSum(int *array, int size);

    ~SegmentTreeSum();

    // Обертка над рекурсивной функцией поиска суммы на отрезке getSum_

    int getSum(int left, int right){
	    if (left>=0 && right<size_ && right>=left){
		    return getSum_(left, right, 1, 0, size_-1);
	    }
	    throw std::invalid_argument("index out of bounds exception");
	    return -1;
    };

    // Обертка над рекурсивной функции обноления элемента update_

    void update(int index, int value){
	    if (index>=0 && index<size_){
		    update_(index, value, 1, 0, size_-1);
	    }
		throw std::invalid_argument("Denominator must not be 0.");
	   
    }


    int getSize() const {
      return size_;
    }
  };

}  // namespace itis