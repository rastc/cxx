cmake_minimum_required(VERSION 3.16)

# Set project name and version
project(cxx VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add Boost.Preprocessor from submodule
set(BOOST_PREPROCESSOR_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/third_party/boost_preprocessor)
if(EXISTS ${BOOST_PREPROCESSOR_ROOT}/include)
    message(STATUS "Using Boost.Preprocessor submodule at: ${BOOST_PREPROCESSOR_ROOT}")
    # For header-only libraries, we just need the include path
    add_library(boost_preprocessor INTERFACE)
    target_include_directories(boost_preprocessor INTERFACE ${BOOST_PREPROCESSOR_ROOT}/include)
else()
    message(FATAL_ERROR "Boost.Preprocessor submodule not found! Run 'git submodule update --init --recursive'")
endif()

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Define source files
set(SOURCES
    main.cpp
)

# Define header files
set(HEADERS
    cxx_init.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link Boost.Preprocessor headers
target_link_libraries(${PROJECT_NAME} PRIVATE boost_preprocessor)

# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set compiler-specific options
if(MSVC)
    # Enable additional warnings for MSVC
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
    # Disable specific warnings if needed
    # target_compile_options(${PROJECT_NAME} PRIVATE /wd4996)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # Enable additional warnings for GCC/Clang
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Optional: Set debug and release configurations
if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "/Od /Zi")
    set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
endif()

# Optional: Enable position independent code
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

# Optional: Set properties for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME "cxx"
    DEBUG_POSTFIX "_d"
)

# Print build information
message(STATUS "Building ${PROJECT_NAME} version ${PROJECT_VERSION}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")