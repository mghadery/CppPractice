# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Part01Core")

add_executable (Part01Core "main.cpp" "chap2_types/chap2_types.cpp" "chap2_types/chap2_types.h")


# Include sub-projects.
add_subdirectory ("chap1_up")
add_subdirectory ("chap2_types")

# Link the chap1_up library to the Part01Core executable
target_link_libraries(Part01Core chap1_up chap2_types)

#if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Part01Core PROPERTY CXX_STANDARD 20)
#endif()

