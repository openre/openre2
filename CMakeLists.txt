cmake_minimum_required(VERSION 2.8)

# Options. Turn on with 'cmake -Dmyvarname=ON'.
option(test "Build all tests." OFF) # Makes boolean 'test' available.

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME OpenRE)
project(${PROJECT_NAME})

# gtest-1.6.0
set(CMAKE_CXX_FLAGS "-g -Wall")

# force static runtime libraries for msvc builds
if(MSVC)
  set(variables 
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_RELEASE
	CMAKE_CXX_FLAGS_RELWITHDEBINFO
	CMAKE_CXX_FLAGS_MINSIZEREL
  )
  foreach(variable ${variables})
	if(${variable} MATCHES "/MD")
	  string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
	endif()
  endforeach()
endif()

# If you want your own include/ directory, set this, and then you can do
# include_directories(${COMMON_INCLUDES}) in other CMakeLists.txt files.
# set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

add_compile_options(-std=c++11)

################################
# Normal Libraries & Executables
################################
set (OPENRE_LIB_SOURCES src/openre.cpp src/layer.cpp src/shape.cpp src/index.cpp)
add_library(openre_lib ${OPENRE_LIB_SOURCES})
#add_library(layer_lib src/layer.cpp)
#add_library(shape_lib src/shape.cpp)
add_executable(openre src/main.cpp)
# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere.

target_link_libraries(openre openre_lib)

################################
# Testing
################################
if (test)
  if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
  endif (APPLE)

  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(lib/gtest-1.6.0)

  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} src)

  ##############
  # Unit Tests
  ##############
  add_executable(OpenRETests tests/test_openre.cpp)

  # Standard linking to gtest stuff.
  target_link_libraries(OpenRETests gtest gtest_main)

  # Extra linking for the project.
  target_link_libraries(OpenRETests openre_lib)

  # This is so you can do 'make test' to see all your tests run, instead of
  # manually running the executable runUnitTests to see those specific tests.
  add_test(NAME openre COMMAND OpenRETests)


  add_executable(LayerTests tests/test_layer.cpp)
  target_link_libraries(LayerTests gtest gtest_main openre_lib)
  add_test(NAME layer COMMAND LayerTests)


  add_executable(ShapeTests tests/test_shape.cpp)
  target_link_libraries(ShapeTests gtest gtest_main openre_lib)
  add_test(NAME shape COMMAND ShapeTests)


  add_executable(IndexTests tests/test_index.cpp)
  target_link_libraries(IndexTests gtest gtest_main openre_lib)
  add_test(NAME index COMMAND IndexTests)



endif()
