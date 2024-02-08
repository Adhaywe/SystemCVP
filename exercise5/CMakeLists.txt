add_executable(exercise5
        main.cpp
        kpn.h
        kpn.cpp
        main.cpp
)

target_include_directories(exercise5
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(exercise5
        PRIVATE ${SYSTEMC_LIBRARY}
)
