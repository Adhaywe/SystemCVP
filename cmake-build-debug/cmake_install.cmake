# Install script for directory: /home/adam/syc/SystemCVP

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/adam/syc/SystemCVP/cmake-build-debug/callbacks/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/clock_generator/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/custom_fifo/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/custom_signal/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/custom_tlm/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/datatypes/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/delta_delay/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/dynamic_processes/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/event_finder/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/feedback_loop/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/fifo_example/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/interfaces_ports/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/kpn_artificial_deadlock/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/kpn_example/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/multiports/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/mutex_example/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/nb_fifo_example/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/not_chain/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/portarrays/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/reporting/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/sc_event_and_queue/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/swapping_example/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/thread_example/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_at_1/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_at_2/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_at_3/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_at_4/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_at_backpressure/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_cpu_example/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_lt_debug_transport/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_lt_dmi/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_lt_initiator_interconnect_target/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_lt_initiator_target/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_memory_manager/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_multipasstrough_sockets/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_payload_extensions/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_protocol_checker/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_quantum_keeper/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/tlm_simple_sockets/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/ams-eln/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/ams-eln2/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/ams-tdf/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/ams-tdf2/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/ams-lsf/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/ams-lsf2/cmake_install.cmake")
  include("/home/adam/syc/SystemCVP/cmake-build-debug/Exercises/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/adam/syc/SystemCVP/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
