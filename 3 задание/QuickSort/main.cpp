#include <iostream>
#include <vector>
#include "log_duration.h"
#include <algorithm>

void QuickSort(std::vector<int>& numbers, size_t left, size_t right) {
    size_t i = left, j = right;
    size_t pivot = numbers[(left + right) / 2];

    // Разделение на две части
    while (i <= j) {
        while (numbers[i] < pivot)
            i++;
        while (numbers[j] > pivot)
            j--;
        if (i <= j) {
            std::swap(numbers[i], numbers[j]);
            i++;
            j--;
        }
    }

    // Рекурсивные вызовы
    if (left < j)
        QuickSort(numbers, left, j);
    if (i < right)
        QuickSort(numbers, i, right);
}

void sortArray(std::vector<int>& numbers) {
    if (numbers.size() > 0) {
        QuickSort(numbers, 0, numbers.size() - 1);
    }
}

int main() {
    std::vector<int> numbers;
    for (size_t i = 0; i < 1000000; ++i) {
        numbers.push_back(rand());
    }

    //std::sort(numbers.begin(), numbers.end());

    {
        LOG_DURATION("stl sort");
        std::sort(numbers.begin(), numbers.end());
    }

    {
        LOG_DURATION("quick sort");
        sortArray(numbers);
    }

    return 0;
}

/*
Выбрал quicksort, так как она довольно простая и понятная.
Видно что функция отрабатывает быстрее даже при заранее отсортированном массиве, 
чем стандартная функция sort из stl.
*/