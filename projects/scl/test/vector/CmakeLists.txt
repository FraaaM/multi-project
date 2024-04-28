add_executable(vector_tests test_vector.cpp)

target_sources(scl_lib 
	PRIVATE
		test_vector_templates.cpp
)

target_link_libraries(vector_tests 
	gtest_main 
	scl_lib
)

add_test(vector_tests vector_tests)
