# CXX Init - Designated Initializer Library

A C++14 library that provides designated initializer syntax using Boost.Preprocessor macros.

## Features

- Designated initializer syntax for C++ structs
- Header-only library
- Uses Boost.Preprocessor for macro magic
- Cross-platform support

## Requirements

- C++14 compatible compiler
- CMake 3.16 or higher
- Boost 1.70 or higher (headers only)

## Installation

### Installing Boost

#### Option 1: vcpkg (Recommended)
```bash
vcpkg install boost
```

#### Option 2: System Package Manager

**Ubuntu/Debian:**
```bash
sudo apt-get install libboost-dev
```

**macOS (Homebrew):**
```bash
brew install boost
```

**Windows (Chocolatey):**
```bash
choco install boost-msvc-14.3
```

### Building the Project

```bash
# Configure
cmake --preset vs2022  # Windows with Visual Studio
# or
cmake --preset default  # Linux/macOS with Ninja

# Build
cmake --build build-vs2022 --config Release
# or
cmake --build build --config Release
```

## Usage

```cpp
#include "cxx_init.h"

struct Person {
    std::string name;
    int age;
    std::string city;
    double height;
};

int main() {
    Person p = cxx(
        .name = "Alice",
        .age = 30,
        .city = "New York",
        .height = 5.6
    );
    
    return 0;
}
```

## License

MIT License