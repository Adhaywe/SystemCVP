add_executable(ex6
        main.cpp
        bus.h
        memory.h
        processor.h
        stimuli1.txt
        stimuli2.txt
        main.cpp
)

target_include_directories(ex6
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex6
        PRIVATE ${SYSTEMC_LIBRARY}
)
