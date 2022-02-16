cmake_minimum_required(VERSION 3.21)
project(boids)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast")

set(INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(SFML_DIR ${PROJECT_SOURCE_DIR}/dependencies/SFML)
set(OPEN_MP_DIR ${PROJECT_SOURCE_DIR}/dependencies/openMP)
set(PYBIND_DIR ${PROJECT_SOURCE_DIR}/dependencies/pybind11)

set(LIB_HEADERS
        src/Vector2D.h
        src/Boid.h
        src/Flock.h
        src/Simulation.h
        src/KDTree.h)

set(LIB_SOURCES
        src/Vector2D.cpp
        src/Boid.cpp
        src/Flock.cpp
        src/Simulation.cpp
        src/KDTree.cpp)

add_subdirectory(${SFML_DIR})
add_subdirectory(${PYBIND_DIR})

add_library(boids ${LIB_SOURCES} ${LIB_HEADERS})

#include_directories(/usr/local/opt/homebrew/Cellar/libomp/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_DIR}/include ${OPEN_MP_DIR}/include)
target_link_directories(${PROJECT_NAME} PRIVATE ${SFML_DIR}/src)
target_link_libraries(${PROJECT_NAME} pybind11::embed sfml-graphics sfml-window sfml-system)

# To tell the compiler that you want to use OpenMP
SET(OPENMP_COMPILE_FLAGS "-Xpreprocessor -fopenmp")
#SET(OPENMP_LINK_FLAGS    "-fopenmp=libomp")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${OPENMP_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${OPENMP_LINK_FLAGS}")

add_executable(simulate src/main.cpp src/cxxopts.hpp)
target_link_libraries(simulate boids)

pybind11_add_module(pyboids src/pyboids.cpp)
target_link_libraries(pyboids PUBLIC boids)

install(TARGETS simulate DESTINATION ${INSTALL_BIN_DIR})
install(TARGETS pyboids
        COMPONENT python
        LIBRARY DESTINATION ${INSTALL_LIB_DIR})

# You may need to include the [${OPEN_MP_DIR}/lib/libomp.dylib] in usr/local/lib
set(OPEN_MP_LIB "${OPEN_MP_DIR}/lib/libomp.dylib") # Make sure to use the omp library for your computer architecture
target_link_libraries(${PROJECT_NAME} ${OPEN_MP_LIB})


# YOU MAY NEED TO INCLUDE THIS FLAGS tO BE ABLE TO RUN PROGRAM DEPENDING ON SYSTEM
#[[
-DOpenMP_CXX_FLAGS="-Xpreprocessor -fopenmp -I/usr/local/opt/homebrew/Cellar/libomp/include"
-DOpenMP_CXX_LIB_NAMES="omp"
-DOpenMP_omp_LIBRARY=/usr/local/opt/homebrew/Cellar/libomp/lib/libomp.dylib


-D GLFW_NATIVE_API=1
-I/usr/local/opt/homebrew/Cellar/libomp/include"
-DOpenMP_CXX_FLAGS="-Xpreprocessor -fopenmp
-DOpenMP_CXX_LIB_NAMES="omp"
-DOpenMP_omp_LIBRARY=dependencies/openMP/lib/libomp.dylib
]]