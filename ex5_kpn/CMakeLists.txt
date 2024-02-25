add_executable(ex5_kpn
        main.cpp
        kpn.h
        kpn.cpp
        main.cpp
)

target_include_directories(ex5_kpn
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex5_kpn
        PRIVATE ${SYSTEMC_LIBRARY}
)
