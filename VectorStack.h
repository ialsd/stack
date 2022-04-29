#pragma once
#include "StackImplementation.h"
#include <vector>
using namespace std;

class VectorStack : public IStackImplementation {
public:
    VectorStack() = default;
    VectorStack(const ValueType* rawArray, const size_t size);
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
private:
    vector<ValueType> _vector;
};