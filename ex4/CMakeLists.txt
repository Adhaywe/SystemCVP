add_executable(ex4
        main.cpp
        place.h
        subnet.h
        transition.h
)

target_include_directories(ex4
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex4
        PRIVATE ${SYSTEMC_LIBRARY}
)

