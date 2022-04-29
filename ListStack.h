#pragma once
#include "StackImplementation.h"
#include<list>
using namespace std;

class ListStack : public IStackImplementation 
{
public:
    ListStack();
    ListStack(const ValueType* rawArray, const size_t size);
    // добавление в хвост
    void push(const ValueType& value) override;
    // удаление с хвоста
    void pop() override;
    // посмотреть элемент в хвосте
    const ValueType& top() const override;
    // проверка на пустоту
    bool isEmpty() const override;
    // размер 
    size_t size() const override;
    // виртуальный деструктор
    ~ListStack() override;
private:
    list<ValueType>* _list;
};