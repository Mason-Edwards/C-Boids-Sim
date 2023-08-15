# CMakeList.txt : CMake project for C-Boids-Sim, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("C-Boids-Sim")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add source to this project's executable.
add_executable("C-Boids-Sim" WIN32 "C-Boids-Sim.c")
set(SDL2_LIBRARIES "${CMAKE_PREFIX_PATH}/lib/x64/SDL2.lib;${CMAKE_PREFIX_PATH}/lib/x64/SDL2main.lib")	
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET C-Boids-Sim PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
