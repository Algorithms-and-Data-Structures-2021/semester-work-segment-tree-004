# Здесь вы можете создавать свои исполняемые файлы (executables)
# исполянемый файл = контрольный тест

# Пример создания контрольного теста (исполняемого файла) под названием demo_benchmark.
# Исходный код предоставлен в файле demo_benchmark.cpp текущей директории.
add_executable(demo_benchmark demo_benchmark.cpp)
add_executable(segment_tree_sum_buildTree_benchmark segment_tree_sum_buildTree_benchmark.cpp)
add_executable(segment_tree_sum_getSum_benchmark segment_tree_sum_getSum_benchmark.cpp)
add_executable(segment_tree_min_getMin_benchmark segment_tree_min_getMin_benchmark.cpp)
# Примечание: Не забываем подключить (прилинковать) библиотеку ${PROJECT_NAME} с реализацией структуры данных.
target_link_libraries(demo_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(segment_tree_sum_buildTree_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(segment_tree_sum_getSum_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(segment_tree_min_getMin_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})