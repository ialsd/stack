#include "Stack.h"

Stack::Stack(StackContainer container)
    : _containerType(container)
{
    switch (container)
    {
    case StackContainer::List: 
        {
            _pimpl = static_cast<IStackImplementation*>(new ListStack());
            break;
        }
    case StackContainer::Vector: 
        {
            _pimpl = static_cast<IStackImplementation*>(new VectorStack());
            break;
        }
    default:
        throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container)
    : _containerType(container)
{
    // принцип тот же, что и в прошлом конструкторе
    switch (container)
    {
    case StackContainer::List: 
        {
            _pimpl = static_cast<IStackImplementation*>(new ListStack(valueArray, arraySize));
            break;
        }
    case StackContainer::Vector: 
        {
            _pimpl = static_cast<IStackImplementation*>(new ListStack(valueArray, arraySize));
            break;
        }
    default:
        throw std::runtime_error("Неизвестный тип контейнера");
    }
}
Stack::Stack(Stack& copyStack)
{
    if (copyStack.size() != 0)
    {
        ValueType* tmp = new ValueType[copyStack.size()];
        for(size_t i = copyStack.size() - 1; i >= 0; i--) 
        {
            tmp[i] = copyStack.top();
            copyStack.pop();
        }
        for(size_t i = 0; i < copyStack.size(); i++) 
        {
            push(tmp[i]);
            copyStack.push(tmp[i]);
        }   
        delete[] tmp;
    }
}

Stack& Stack::operator=(Stack& copyStack)
{
    if (&copyStack == this) 
    {
        return *this;
    }
    delete _pimpl;
    Stack tmp(copyStack);
    _pimpl = tmp._pimpl;
    tmp._pimpl = nullptr;
    _containerType = tmp._containerType;
    return *this;
}
Stack::Stack(Stack&& moveStack) noexcept
{
    _pimpl = moveStack._pimpl;
    moveStack._pimpl = nullptr;
    _containerType = moveStack._containerType;
}
Stack& Stack::operator=(Stack&& moveStack) noexcept
{
    if (&moveStack == this) 
    {
        return *this;
    }
	delete[] _pimpl;
    _pimpl = moveStack._pimpl;
    moveStack._pimpl = nullptr;
    _containerType = moveStack._containerType;
    return *this;
}

Stack::~Stack()
{
    delete _pimpl;        // композиция!
}

void Stack::push(const ValueType& value)
{
    // можно, т.к. push определен в интерфейсе
    _pimpl->push(value);
}

void Stack::pop()
{
    _pimpl->pop();
}

const ValueType& Stack::top() const
{
    return _pimpl->top();
}

bool Stack::isEmpty() const
{
    return _pimpl->isEmpty();
}

size_t Stack::size() const
{
    return _pimpl->size();
}
