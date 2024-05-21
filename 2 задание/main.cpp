#include <cassert>
#include <iostream>
#include "CircularBufferArray.h"
#include "CircularBufferVector.h"

bool BufferArrayTest(CircularBufferArray<int>& buffer) {
    // Тест проверки IsEmpty() и IsFull() в начальном состоянии
    assert(buffer.IsEmpty());
    assert(!buffer.IsFull());

    // Тест добавления элементов в буфер
    buffer.Push_back(10);
    buffer.Push_back(20);
    buffer.Push_back(30);
    buffer.Push_front(5);

    // Тест проверки IsEmpty() после добавления элементов
    assert(!buffer.IsEmpty());
    assert(!buffer.IsFull());

    // Тест извлечения элементов из буфера
    assert(buffer.Pop_front() == 5);
    assert(buffer.Pop_back() == 30);

    // Тест изменения размера буфера и корректной сохранности элементов
    buffer.Resize(3);
    assert(buffer.length() == 3);
    assert(!buffer.IsEmpty());
    assert(!buffer.IsFull());
    assert(buffer.Pop_front() == 10);
    assert(buffer.Pop_back() == 20);

    // Тест попытки извлечения элементов из пустого буфера
    assert(buffer.IsEmpty());
    try {
        buffer.Pop_front();
        assert(false);  // Должны были получить исключение
    }
    catch (std::runtime_error&) {
        assert(true);
    }

    // Тест попытки добавления элементов в заполненный буфер
    buffer.Push_back(1);
    buffer.Push_back(2);
    buffer.Push_back(3);
    try {
        buffer.Push_back(4);
        assert(false);  // Должны были получить исключение
    }
    catch (std::runtime_error&) {
        assert(true);
    }

    buffer.Print();

    std::cout << "All tests passed successfully!" << std::endl;
    return true;
}

bool BufferVectorTest(CircularBufferVector<int>& buffer) {
    // Тест проверки IsEmpty() и IsFull() в начальном состоянии
    assert(buffer.IsEmpty());
    assert(!buffer.IsFull());

    // Тест добавления элементов в буфер
    buffer.Push_back(10);
    buffer.Push_back(20);
    buffer.Push_back(30);
    buffer.Push_front(5);

    // Тест проверки IsEmpty() после добавления элементов
    assert(!buffer.IsEmpty());
    assert(!buffer.IsFull());

    // Тест извлечения элементов из буфера
    assert(buffer.Pop_front() == 5);
    assert(buffer.Pop_back() == 30);

    // Тест изменения размера буфера и корректной сохранности элементов
    buffer.Resize(3);
    assert(buffer.length() == 3);
    assert(!buffer.IsEmpty());
    assert(!buffer.IsFull());
    assert(buffer.Pop_front() == 10);
    assert(buffer.Pop_back() == 20);

    // Тест попытки извлечения элементов из пустого буфера
    assert(buffer.IsEmpty());
    try {
        buffer.Pop_front();
        assert(false);  // Должны были получить исключение
    }
    catch (std::runtime_error&) {
        assert(true);
    }

    // Тест попытки добавления элементов в заполненный буфер
    buffer.Push_back(1);
    buffer.Push_back(2);
    buffer.Push_back(3);
    try {
        buffer.Push_back(4);
        assert(false);  // Должны были получить исключение
    }
    catch (std::runtime_error&) {
        assert(true);
    }

    buffer.Print();

    std::cout << "All tests passed successfully!" << std::endl;
    return true;
}

int main() {
    CircularBufferArray<int> array_buffer(5);
    assert(BufferArrayTest(array_buffer));
    int c = 3;
    CircularBufferVector<int> vector_buffer(5);
    assert(BufferVectorTest(vector_buffer));
}

/*
Плюсы класса использующего динамический массив:
Возможность непосредственно управлять памятью, эффективное её выделение

Минусы:
Есть риск утечек памяти или ошибок при работе с ней.

Плюсы класса использующего вектор:
Удобство и простота использования, не нужно заботится о выделении и освобождении
памяти, следовательно не нужно боятся утечек памяти, встроенный метод Resize, 

Минусы:
Из-за специфики работы класса vector возможно неэффективное использование памяти
*/