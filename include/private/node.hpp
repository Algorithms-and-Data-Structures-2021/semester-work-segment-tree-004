#pragma once

namespace itis {

  struct Node final {
   public:
    // хранимые данные (перечисление)
    int data;
    int minChild;

    // указатель на следующий узел (хранит в себе адрес участка памяти)

    /**
   * Создание узла с данными и указателем на следующий узел.
   *
   * @param e - данные узла
   * @param ptr указатель на следующий узел
   */
    explicit Node(int e) : data{e}, minChild{0} {}

    Node(int e, int minC) : data{e}, minChild{minC} {}
  };

} // namespace itis