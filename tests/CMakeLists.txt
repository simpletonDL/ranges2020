project(tests)

add_executable(rand_test test.cpp)
target_link_libraries(rand_test min_dist)

add_test(SmallTests rand_test  10000 100   1000)
add_test(MiddleTests rand_test 1000  1000  10000)
add_test(LargeTests rand_test  10    10000 100000)