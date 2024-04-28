target_sources(scl_lib  
	PRIVATE
		doubly_linked_list.cpp
		
	PUBLIC
		doubly_linked_list.hpp
)

target_include_directories(scl_lib  PUBLIC
	${PROJECT_SOURCE_DIR}/src/list
)
