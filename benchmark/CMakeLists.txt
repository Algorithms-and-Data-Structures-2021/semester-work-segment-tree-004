add_executable(segment_tree_sum_buildTree_benchmark segment_tree_sum_buildTree_benchmark.cpp)
add_executable(segment_tree_min_buildTree_benchmark segment_tree_min_buildTree_benchmark.cpp)
add_executable(segment_tree_sum_getSum_benchmark segment_tree_sum_getSum_wholeSegment_benchmark.cpp)
add_executable(segment_tree_sum_getSum_average_benchmark segment_tree_sum_getSum_average_benchmark.cpp)
add_executable(segment_tree_min_getMin_benchmark segment_tree_min_getMin_wholeSegment_benchmark.cpp)
add_executable(segment_tree_min_getMin_average_benchmark segment_tree_getMin_average_benchmark.cpp)
add_executable(linear_getSum_benchmark linear_getSum_benchmark.cpp)
add_executable(linear_getMin_benchmark linear_getMin_benchmark.cpp)
add_executable(segment_tree_sum_update_benchmark segment_tree_sum_update_benchmark.cpp)
add_executable(segment_tree_min_update_benchmark segment_tree_min_update_benchmark.cpp)

target_link_libraries(segment_tree_sum_buildTree_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(segment_tree_min_buildTree_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(segment_tree_sum_getSum_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(segment_tree_min_getMin_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(linear_getSum_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(linear_getMin_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(segment_tree_sum_getSum_average_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(segment_tree_min_getMin_average_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(segment_tree_sum_update_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(segment_tree_min_update_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})