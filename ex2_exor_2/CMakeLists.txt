add_executable(ex2_exor_2
        nand.h

        exor_main.cpp
        exor.h
        stim.h
        mon.h
)

target_include_directories(ex2_exor_2
        PRIVATE ${SYSTEMC_AMS_INCLUDE}
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex2_exor_2
        PRIVATE ${SYSTEMC_AMS_LIBRARY}
        PRIVATE ${SYSTEMC_LIBRARY}
)

