#pragma once

namespace itis {
	
	struct Node final {
	public:
		// хранимые данные (перечисление)
		int data;
		
		Node *leftChildren;
		
		Node *rightChildren;
		
		// указатель на следующий узел (хранит в себе адрес участка памяти)
		
		/**
	   * Создание узла с данными и указателем на следующий узел.
	   *
	   * @param e - данные узла
	   * @param ptr указатель на следующий узел
	   */
	   
		explicit Node(int e) : data{e}, leftChildren{nullptr}, rightChildren{nullptr} {}
		
		Node(Node *first, Node *second, int e) : leftChildren{first}, rightChildren{second}, data{e} {}
		
	};
	
} // namespace itis