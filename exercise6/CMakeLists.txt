add_executable(exercise6
        main.cpp
        bus.h
        memory.h
        processor.h
        stimuli1.txt
        stimuli2.txt
        main.cpp
)

target_include_directories(exercise6
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(exercise6
        PRIVATE ${SYSTEMC_LIBRARY}
)
