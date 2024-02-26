add_executable(ex66
        main.cpp
        bus.h
        memory.h
        processor.h
        stimuli1.txt
        stimuli2.txt
        main.cpp
)

target_include_directories(ex66
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex66
        PRIVATE ${SYSTEMC_LIBRARY}
)
