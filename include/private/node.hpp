#pragma once

namespace itis {
	
	struct Node final {
	public:
		// хранимые данные (перечисление)
		int data;
		Node *firstChildren;
		
		Node *secondChildren;
		
		// указатель на следующий узел (хранит в себе адрес участка памяти)
		
		/**
	   * Создание узла с данными и указателем на следующий узел.
	   *
	   * @param e - данные узла
	   * @param ptr указатель на следующий узел
	   */
	   
		explicit Node(int e) : data{e}, firstChildren{nullptr}, secondChildren{nullptr} {}
		
		Node(int e, int minC) : data{e}, minChild{minC} {}
		
	};
	
} // namespace itis