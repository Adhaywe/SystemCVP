add_executable(ex_rslatch
        main.cpp
)

target_include_directories(ex_rslatch
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex_rslatch
        PRIVATE ${SYSTEMC_LIBRARY}
)
