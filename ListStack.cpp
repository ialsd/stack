#include "ListStack.h"

ListStack::ListStack(const ValueType* rawArray, const size_t size)
{
    _list.insert(_list.begin(), &rawArray[0], &rawArray[size]);
}
// добавление в хвост
void ListStack::push(const ValueType& value)
{
    _list.push_back(value);
}
// удаление с хвоста
void ListStack::pop()
{
    _list.pop_back();
}
// посмотреть элемент в хвосте
const ValueType& ListStack::top() const 
{
    return _list.back();
}
// проверка на пустоту
bool ListStack::isEmpty() const
{
    return _list.empty();
}
// размер 
size_t ListStack::size() const
{
    return _list.size();
}