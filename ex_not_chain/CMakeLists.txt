add_executable(ex_not_chain
        main.cpp
)

target_include_directories(ex_not_chain
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex_not_chain
        PRIVATE ${SYSTEMC_LIBRARY}
)
