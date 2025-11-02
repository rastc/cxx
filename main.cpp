#include "cxx_init.h"

#include <string>
#include <cstdio>

struct Person {
    std::string name;
    int age;
    std::string city;
    double height;

    void print() const 
    {
        printf("%s is %d years old from %s\n", name.c_str(), age, city.c_str());
    }
};

struct LargeStruct 
{
    int field1, field2, field3, field4, field5;
    int field6, field7, field8, field9, field10;
};

void person(const Person& person) 
{
    person.print();
}

#define person_macro(...) person(cxx(__VA_ARGS__))

int main() 
{
    // Example with 4 fields
    Person p = cxx(
        .name = "Alice",
        .age = 30,
        .city = "New York",
        .height = 5.6,
        .print()
    );

    person_macro(
        .name = "Alice",
        .age = 24,
        .city = "New York",
        .height = 5.6
    );
    
    // Example with many fields
    LargeStruct large = cxx(
        .field1 = 1, .field2 = 2, .field3 = 3, .field4 = 4, .field5 = 5,
        .field6 = 6, .field7 = 7, .field8 = 8, .field9 = 9, .field10 = 10
    );

    p.print();

    return 0;
}
