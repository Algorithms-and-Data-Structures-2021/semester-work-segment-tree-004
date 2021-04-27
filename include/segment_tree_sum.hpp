#pragma once

// Заголовочный файл с объявлением структуры данных

#include <private/node.hpp>
#include <stdexcept>
namespace itis {

  struct SegmentTreeSum {
   private:
    Node *headNode_;
    int size_{0};
    int *array_;

    // Рекурсивное построение дерева по изначальному массиву.
    // v - номер текущей вершины; left, right - границы соответствующего отрезка
    // v = 1, left = 0, right = n-1
    Node *buildTree_(int left, int right);

    // Запрос суммы
    // l, r - границы запроса;
    // v - номер текущей вершины; tl, tr - границы соответствующего отрезка
    // v = 1, tl = 0, tr = n-1,
    int getSum_(Node *node, int left, int right, int tempLeft, int tempRight);

    // Запрос модификации
    // idx - индекс элемента, val - новое значение
    // v - номер текущей вершины; tl, tr - границы соответствующего отрезка
    Node *update_(Node *node, int index, int newValue, int tempLeft, int tempRight);

    //рекурсивное удаление узлов
    void deleteNodes(Node *pNode);

   public:
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    SegmentTreeSum(int *array, int size);

    ~SegmentTreeSum();

    // Обертка над рекурсивной функцией поиска суммы на отрезке getSum_

    int getSum(int left, int right) {
      if (left == right && left < size_ && right >= 0) {
        return array_[right];
      }
      if (left > right) {
        return getSum_(headNode_, right, left, 0, size_ - 1);
      }
      if (left >= 0 && right < size_) {
        return getSum_(headNode_, left, right, 0, size_ - 1);
      }
      throw std::invalid_argument("invalid_argument");
    };

    // Обертка над рекурсивной функции обноления элемента update_

    void update(int index, int value) {
      if (index >= 0 && index < size_) {
        update_(headNode_, index, value, 0, size_ - 1);
      } else {
        throw std::invalid_argument("invalid_argument");
      }
    }

    int getSize() const {
      return size_;
    }
  };

}  // namespace itis