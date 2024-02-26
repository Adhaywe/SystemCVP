add_executable(ex_xnor
        nand.h
        nand_main.cpp
        xnor_main.cpp
        xnor.h
        stim.h
        mon.h
)

target_include_directories(ex_xnor
        PRIVATE ${SYSTEMC_AMS_INCLUDE}
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex_xnor
        PRIVATE ${SYSTEMC_AMS_LIBRARY}
        PRIVATE ${SYSTEMC_LIBRARY}
)

