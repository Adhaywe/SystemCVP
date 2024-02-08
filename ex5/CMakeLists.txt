add_executable(ex5
        main.cpp
        kpn.h
        kpn.cpp
        main.cpp
)

target_include_directories(ex5
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex5
        PRIVATE ${SYSTEMC_LIBRARY}
)
