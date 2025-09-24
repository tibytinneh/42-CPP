#include "Serializer.hpp"

// takes a pointer and converts it to the unsigned integer type uintpr_t
uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

// takes an unsigned integer parameter and converts it to a pointer to Data class.
Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}