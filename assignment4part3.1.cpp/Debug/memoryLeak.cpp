/*
* memoryLeak.cpp - updated
*
*  Created on: Nov 9, 2017
*      Author: dgv130030
*/
#include "memoryLeak.h"
#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <iomanip>
#include <limits>


unsigned long long int memoryLeak::allAllocated = 0ULL;
unsigned long long int memoryLeak::allFreed = 0ULL;
unsigned long long int memoryLeak::countAllocated = 0ULL;
unsigned long long int memoryLeak::countFreed = 0ULL;
bool memoryLeak::extraOutput = false;
bool memoryLeak::summaryDisplay = true;

std::map<const void*, std::size_t, std::less<const void*>, memoryLeak::memoryLeakAllocator<std::pair<const void*, std::size_t>>> memoryLeak::addressMap;
memoryLeak memoryLeak::memory;

void* operator new(std::size_t size)
{
	return memoryLeak::actualNew(size);
}

void operator delete(void* ptrToFree) noexcept
{
	memoryLeak::actualDelete(ptrToFree);
}

void operator delete(void* ptrToFree, std::size_t) noexcept
{
	memoryLeak::actualDelete(ptrToFree);
}

void* operator new[](std::size_t size)
{
	return memoryLeak::actualNew(size);
}

void operator delete[](void* ptrToFree) noexcept
{
	memoryLeak::actualDelete(ptrToFree);
}

void operator delete[](void* ptrToFree, std::size_t) noexcept
{
	memoryLeak::actualDelete(ptrToFree);
}

