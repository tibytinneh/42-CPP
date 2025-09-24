
#include <iostream>
#include "Serializer.hpp"

// Use serialize() on the address of the Data object and pass its return value to
// deserialize(). Then, ensure the return value of deserialize() compares equal to the
// original pointer.

int main()
{
    Data og;
    og.id = 369;
    og.name = "og name";

    std::cout << "og pointer: " << &og << std::endl;
    std::cout << "og data id: " << og.id << std::endl;
    std::cout << "og data name : " << og.name << std::endl;
    std::cout << std::endl;
    // serialize() on address of data object og

    uintptr_t rawInt = Serializer::serialize(&og);
    std::cout << "og reinterpreted as uintptr_t type: 0x"
              << std::hex << rawInt << std::dec << std::endl
              << std::endl;
    Data *deserialized = Serializer::deserialize(rawInt);

    std::cout << "deserialized pointer: " << deserialized << std::endl;
    std::cout << "deserialized data id: " << deserialized->id << std::endl;
    std::cout << "deserialized data name : " << deserialized->name << std::endl;
    std::cout << std::endl;

    std::cout << ((deserialized == &og)
                      ? "Pointers match"
                      : "Pointers dont match")
              << std::endl;
}

// THIS causes stack corruption:
// std::cout << "og reinterpreted as uintptr_t type: 0x" << std::hex << static_cast<unsigned long long>(ptr) << std::endl;
