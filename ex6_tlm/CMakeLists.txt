add_executable(ex6_tlm
        main.cpp
        bus.h
        memory.h
        processor.h
        stimuli1.txt
        stimuli2.txt
        main.cpp
)

target_include_directories(ex6_tlm
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex6_tlm
        PRIVATE ${SYSTEMC_LIBRARY}
)
