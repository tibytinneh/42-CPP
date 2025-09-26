#pragma once

// polymorphism via virtual destructor
//  a class must be polymorphic for dynamic_cast to work

class Base
{
public:
    virtual ~Base();
};

class A : public Base
{
};
class B : public Base
{
};
class C : public Base
{
};
