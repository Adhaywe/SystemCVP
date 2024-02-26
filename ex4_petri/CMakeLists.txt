add_executable(ex4_petri
        main.cpp
        place.h
        subnet.h
        transition.h
)

target_include_directories(ex4_petri
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex4_petri
        PRIVATE ${SYSTEMC_LIBRARY}
)

