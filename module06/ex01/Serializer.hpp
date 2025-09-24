#pragma once

#include <stdint.h> //uintptr_t
#include "Data.hpp"

class Serializer
{
private:
    // not initializable by the user in any way.
    Serializer();
    Serializer(const Serializer &o);
    Serializer &operator=(const Serializer &o);
    ~Serializer();

public:
    // takes a pointer and converts it to the unsigned integer type uintpr_t
    static uintptr_t serialize(Data *ptr);
    // takes an unsigned integer parameter and converts it to a pointer to Data class.
    static Data *deserialize(uintptr_t raw);
};