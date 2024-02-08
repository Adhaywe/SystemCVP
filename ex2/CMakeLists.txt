add_executable(ex2
               nand.h
               nand_main.cpp
               exor.h
               exor_main.cpp
               stim.h
               mon.h
)

target_include_directories(ex2
        PRIVATE ${SYSTEMC_AMS_INCLUDE}
        PRIVATE ${SYSTEMC_INCLUDE}
)

target_link_libraries(ex2
        PRIVATE ${SYSTEMC_AMS_LIBRARY}
        PRIVATE ${SYSTEMC_LIBRARY}
)

