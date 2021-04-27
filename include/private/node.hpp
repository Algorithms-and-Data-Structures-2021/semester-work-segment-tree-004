#pragma once

namespace itis {

  struct Node final {
   public:
    // хранимые данные (перечисление)
    int data_;

    Node *leftChildren_;

    Node *rightChildren_;

    // указатель на следующий узел (хранит в себе адрес участка памяти)

    /**
	   * Создание узла с данными и указателем на следующий узел.
	   *
	   * @param e - данные узла
	   * @param ptr указатель на следующий узел
	   */

    explicit Node(int e) : data_{e}, leftChildren_{nullptr}, rightChildren_{nullptr} {}

    Node(Node *first, Node *second, int e) : leftChildren_{first}, rightChildren_{second}, data_{e} {}
  };

}  // namespace itis