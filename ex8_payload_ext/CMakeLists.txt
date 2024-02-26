add_executable(ex8
        main.cpp
        initiator.h
        memory_manager.h
        memory_manager.cpp
        target.h
        tlm2_base_protocol_checker.h
        util.h
)

target_include_directories(ex8
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex8
        PRIVATE ${SYSTEMC_LIBRARY}
)
