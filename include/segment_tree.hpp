#pragma once

#include "private/node.hpp"
// Заголовочный файл с объявлением структуры данных

namespace itis {

  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  // Пример: объявление константы времени компиляции в заголовочном файле
  inline constexpr auto kStringConstant = "Hello, stranger!";

  // Пример: объявление структуры с полями и методами
  struct SegmentTree {
   private:
    int size_{0};

    // Рекурсивное построение дерева по изначальному массиву.
    // v - номер текущей вершины; tl, tr - границы соответствующего отрезка
    // v = 1, tl = 0, tr = n-1
    void buildTree_(int a[], int v, int tl, int tr);

    // Запрос суммы
    // l, r - границы запроса;
    // v - номер текущей вершины; tl, tr - границы соответствующего отрезка
    // v = 1, tl = 0, tr = n-1,
    int getSum_(int l, int r, int v, int tl, int tr);


    // Запрос модификации
    // idx - индекс элемента, val - новое значение
    // v - номер текущей вершины; tl, tr - границы соответствующего отрезка
    void update_(int idx, int val, int v, int tl, int tr);


    // Запрос минимума
    // v - номер текущей вершины; tl, tr - границы соответствующего отрезка
    int getMin_(int l, int r, int v, int tl, int tr);

    Node* tree_{nullptr};

   public:

    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    SegmentTree(int array[], int size);

    ~SegmentTree();

    // Обертка над рекурсивной функцией построений дерева buildTree_

    void buildTree(int array[]){
        buildTree_(array, 1, 0, size_-1);
    };

    // Обертка над рекурсивной функцией поиска суммы на отрезке getSum_

    int getSum(int left, int right){
        return getSum_(left, right, 1, 0, size_-1);
    };

    // Обертка над рекурсивной функции обноления элемента update_

    void update(int index, int value){
      update_(index, value, 1, 0, size_-1);
    }

    // Обертка над рекурсивной функцией поиска минимума getMin_

    int getMin(int left, int right){
      return getMin_(left, right,1, 0, size_-1);
    }



    int size() const {
      return size_;
    }
  };

}  // namespace itis