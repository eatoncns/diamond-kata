# Build diamond
add_library(diamond src/Diamond.cpp src/StringUtils.cpp)

# Make include directory available
target_include_directories(diamond PUBLIC include)

# Download and unpack googletest at configure time
# Thanks to Craig Scott (https://crascit.com)
configure_file(CMakeLists.txt.in
        ${CMAKE_BINARY_DIR}/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

# Build test executable
add_executable(diamondtest tests/DiamondTest.cpp tests/StringUtilsTest.cpp)

# Give tests access to diamond internals
target_include_directories(diamondtest PRIVATE src)

# Build tests against diamond and gtest/gmock
target_link_libraries(diamondtest diamond gtest gmock_main)