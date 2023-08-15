cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

#import CMakePrintHelpers for cmake_print_variables.
include(CMakePrintHelpers)

# Grab CMAKE_PREFIX_PATH from environment variables and set it.
# CMAKE_PREFIX_PATH contains SDK folders.
set(SDL2_LIB_PATH $ENV{CMAKE_PREFIX_PATH})


project ("C-Boids-Sim")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_executable("C-Boids-Sim" WIN32 "C-Boids-Sim.c")

# Set SDL2 Libaries ready for linker
set(SDL2_LIBRARIES "${CMAKE_PREFIX_PATH}\\SDL2-2.28.2\\lib\\x64\\SDL2.lib;${CMAKE_PREFIX_PATH}\\SDL2-2.28.2\\lib\\x64\\SDL2main.lib")	

# Link SDL2
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

# Add SDL2.dll to output directory
add_custom_command(TARGET C-Boids-Sim POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/SDL2.dll"
        "${CMAKE_CURRENT_BINARY_DIR}")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET C-Boids-Sim PROPERTY CXX_STANDARD 20)
endif()