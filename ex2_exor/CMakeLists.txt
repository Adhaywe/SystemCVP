add_executable(ex2_exor
               nand.h
               nand_main.cpp
               exor.h
               exor_main.cpp
               stim.h
               mon.h
)

target_include_directories(ex2_exor
        PRIVATE ${SYSTEMC_AMS_INCLUDE}
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex2_exor
        PRIVATE ${SYSTEMC_AMS_LIBRARY}
        PRIVATE ${SYSTEMC_LIBRARY}
)

