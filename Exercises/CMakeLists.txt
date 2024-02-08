add_executable(Exercises
        tlm_main.cpp
        ##tlm_std.cpp

)

target_include_directories(Exercises
    PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(Exercises
    PRIVATE ${SYSTEMC_LIBRARY}
)

