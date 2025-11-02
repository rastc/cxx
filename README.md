# CXX Init - Designated Initializer Library

A C++11 library that provides designated initializer syntax using Boost.Preprocessor macros.

## Try it Online

https://godbolt.org/z/Ez1TW7G4v

## Installation

### Cloning the Repository

```bash
git clone --recursive https://github.com/rastc/cxx-init.git
cd cxx-init
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