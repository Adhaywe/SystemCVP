add_executable(exercise3
        main.cpp
        state_machine.cpp
        stimuli.cpp
        stimuli.h
        state_machine.h
)

target_include_directories(exercise3
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(exercise3
        PRIVATE ${SYSTEMC_LIBRARY}
)

