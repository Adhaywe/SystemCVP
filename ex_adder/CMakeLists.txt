add_executable(ex_adder
        main.cpp
)

target_include_directories(ex_adder
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex_adder
        PRIVATE ${SYSTEMC_LIBRARY}
)
