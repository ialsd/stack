#pragma once

#include "ListStack.h"
#include "VectorStack.h"
#include "StackImplementation.h"

#include <stdexcept>
// тип значений в стеке
using ValueType = double;

// на основе какого контейнера работает стек
enum class StackContainer {
    Vector = 0,
    List,
    // можно дополнять другими контейнерами
};

// декларация интерфейса реализации
class IStackImplementation;

class Stack
{
public:
    // Большая пятерка
    Stack(StackContainer container = StackContainer::Vector);
    // элементы массива последовательно подкладываются в стек
    Stack(const ValueType* valueArray, const size_t arraySize, 
          StackContainer container = StackContainer::Vector);

    explicit Stack(Stack& copyStack);
    Stack& operator=(Stack& copyStack);

    // Здесь как обычно
    Stack(Stack&& moveStack) noexcept;
    Stack& operator=(Stack&& moveStack) noexcept;

    ~Stack();

    // добавление в хвост
    void push(const ValueType& value);
    // удаление с хвоста
    void pop();
    // посмотреть элемент в хвосте
    const ValueType& top() const;
    // проверка на пустоту
    bool isEmpty() const;
    // размер 
    size_t size() const;
private:
    // указатель на имплементацию (уровень реализации)
    IStackImplementation* _pimpl = nullptr;
    // тип контейнера, наверняка понадобится
    StackContainer _containerType;
};

