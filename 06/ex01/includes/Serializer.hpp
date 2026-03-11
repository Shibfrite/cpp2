#pragma once

#include<iostream>
#include<string>
#include<stdint.h>

struct Data { int x; float y; char z; };

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer(void);
	public:
    static uintptr_t serialize(Data* ptr);
    static Data*     deserialize(uintptr_t raw);
};
