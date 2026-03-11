#include "Serializer.hpp"

int main()
{
    Data a = {1, 1.1f, 'A'};
    Data b = {2, 2.2f, 'B'};
    Data c = {3, 3.3f, 'C'};

    uintptr_t r1 = Serializer::serialize(&a);
    uintptr_t r2 = Serializer::serialize(&b);
    uintptr_t r3 = Serializer::serialize(&c);

    std::cout << "a: ptr=" << &a << " raw=" << r1 << " match=" << (Serializer::deserialize(r1) == &a) << "\n";
    std::cout << "b: ptr=" << &b << " raw=" << r2 << " match=" << (Serializer::deserialize(r2) == &b) << "\n";
    std::cout << "c: ptr=" << &c << " raw=" << r3 << " match=" << (Serializer::deserialize(r3) == &c) << "\n";
}
