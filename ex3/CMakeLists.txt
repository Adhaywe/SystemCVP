add_executable(ex3
        main.cpp
        state_machine.cpp
        stimuli.cpp
        stimuli.h
        state_machine.h
)

target_include_directories(ex3
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex3
        PRIVATE ${SYSTEMC_LIBRARY}
)

