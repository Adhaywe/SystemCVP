add_executable(exercise4
        main.cpp
        place.h
        subnet.h
        transition.h
)

target_include_directories(exercise4
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(exercise4
        PRIVATE ${SYSTEMC_LIBRARY}
)

