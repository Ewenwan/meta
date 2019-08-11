﻿#pragma once

#if defined(__meta_parse__)
#define Meta(...) __attribute__((annotate(#__VA_ARGS__)))
#else
#define Meta(...) 
#endif

#include <vector>
#include <unordered_map>
#include <serialize/encode.h>
#include <serialize/decode.h>
using namespace std;
namespace test
{
	
	class test_class
	{
	private:
		Meta(encode, decode) std::vector<int> a;
		Meta(encode, decode) std::unordered_map<int, int> b;
		Meta(encode) int c;
	public:
#include "test_class_generated.h"

	}Meta(encode(auto), decode(auto));
	class test_class_C
	{
		
	}
	class test_class_B: public test_class
	{
		private:
		Meta(encode) std::vector<std::string> d;
	public:
#include "test_class_B_generated.h"
	}Meta(encode(auto)), decode(auto);
}