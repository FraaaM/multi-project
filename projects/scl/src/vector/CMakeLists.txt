target_sources(scl_lib  
	PRIVATE
		vector.cpp
		
	PUBLIC
		vector.hpp
)

target_include_directories(scl_lib  PUBLIC
	${PROJECT_SOURCE_DIR}/src/vector
)