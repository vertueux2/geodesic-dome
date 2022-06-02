cmake_minimum_required(VERSION 3.9)
project(GeodesicDome)

# Create a sources variable with a link to all cpp files to compile.
set(SOURCES
  geodesic/geodesic_dome_entry.cpp
  geodesic/geodesic_shape_manager.cpp
  geodesic/triangular_geodesic_dome.cpp 
)

add_executable(GeodesicDome ${SOURCES})

target_include_directories(GeodesicDome
  PRIVATE
    ${PROJECT_SOURCE_DIR}/geodesic
)