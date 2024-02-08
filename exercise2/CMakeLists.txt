add_executable(exercise2
               nand.h
               nand_main.cpp
               exor.h
               mon.h
               stim.h
        exor_main.cpp
)

target_include_directories(exercise2
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(exercise2
        PRIVATE ${SYSTEMC_LIBRARY}
)

