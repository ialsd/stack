#include "VectorStack.h"

VectorStack::VectorStack(const ValueType* rawArray, const size_t size)
{
    _vector.insert(_vector.begin(), &rawArray[0], &rawArray[size]);
}

void VectorStack::push(const ValueType& value) 
{
    _vector.push_back(value);
}

void VectorStack::pop()
{
    _vector.pop_back();
}

const ValueType& VectorStack::top() const
{
    return _vector.back();
}

bool VectorStack::isEmpty() const
{
    return _vector.empty();
}

size_t VectorStack::size() const
{
    return _vector.size();
}
