add_executable(Exercises
	addermain.cpp
)

target_include_directories(Exercises
    PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(Exercises
    PRIVATE ${SYSTEMC_LIBRARY}
)

