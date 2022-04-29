#include "VectorStack.h"

VectorStack::VectorStack()
{
    _vector = new vector<ValueType>;
}

VectorStack::VectorStack(const ValueType* rawArray, const size_t size)
{
    _vector = new vector<ValueType>;
    _vector->insert(_vector->begin(), &rawArray[0], &rawArray[size]);
}
// добавление в хвост
void VectorStack::push(const ValueType& value) 
{
    _vector->push_back(value);
}
// удаление с хвоста
void VectorStack::pop()
{
    _vector->pop_back();
}
// посмотреть элемент в хвосте
const ValueType& VectorStack::top() const
{
    return _vector->back();
}
// проверка на пустоту
bool VectorStack::isEmpty() const
{
    return _vector->empty();
}
// размер 
size_t VectorStack::size() const
{
    return _vector->size();
}
// виртуальный деструктор
VectorStack::~VectorStack()
{
    delete _vector;
}