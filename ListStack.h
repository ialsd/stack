#pragma once
#include "StackImplementation.h"
#include<list>
using namespace std;

class ListStack : public IStackImplementation 
{
public:
    ListStack() = default;
    ListStack(const ValueType* rawArray, const size_t size);
    void push(const ValueType& value) override;
    void pop() override
    const ValueType& top() const override;
    bool isEmpty() const override;
    size_t size() const override;
private:
    list<ValueType> _list;
};
