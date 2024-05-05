#include <iostream>
#include <stdexcept>

#include "vector.hpp"

namespace MCherevko {

    template <typename T>
    Vector<T>::Vector() noexcept {
        arr = new T[capacity];
    }

    template <typename T>
    Vector<T>::~Vector() noexcept {
        delete[] arr;
    }

    template <typename T>
    void Vector<T>::push_back(const T& value) noexcept {
        if (vec_size >= capacity) {
            capacity *= 2;
            T* new_arr = new T[capacity];
            for (int i = 0; i < vec_size; ++i) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }
        arr[vec_size++] = value;
    }
    // Проверка наличия элемента в векторе
    template <typename T>
    bool Vector<T>::has_item(const T& value) const noexcept {
        for (int i = 0; i < vec_size; ++i) {
            if (arr[i] == value) {
                return true;
            }
        }
        return false;
    }
    // Вставка элемента в позицию 
    template <typename T>
    bool Vector<T>::insert(const int position, const T& value) {
        if (position < 0 || position > vec_size) {
            return false;
        }
        if (vec_size >= capacity) {
            capacity *= 2;
            T* new_arr = new T[capacity];
            for (int i = 0; i < position; ++i) {
                new_arr[i] = arr[i];
            }
            new_arr[position] = value;
            for (int i = position; i < vec_size; ++i) {
                new_arr[i + 1] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }
        else {
            for (int i = vec_size; i > position; --i) {
                arr[i] = arr[i - 1];
            }
            arr[position] = value;
        }
        vec_size++;
        return true;
    }

    template <typename T>
    void Vector<T>::print() const noexcept {
        for (int i = 0; i < vec_size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    // Удаление первого вхождения элемента из вектора
    template <typename T>
    bool Vector<T>::remove_first(const T& value) noexcept {
        for (int i = 0; i < vec_size; ++i) {
            if (arr[i] == value) {
                for (int j = i; j < vec_size - 1; ++j) {
                    arr[j] = arr[j + 1];
                }
                vec_size--;
                return true;
            }
        }
        return false;
    }

    template <typename T>
    bool Vector<T>::remove_all(const T& value) {
        size_t first = 0, result = 0;
        /*T* new_arr = new T[capacity];
            for (int i = 0; i < vec_size; ++i) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;*/
        while(first < vec_size ) {
            if (arr[first] != value && result == first ) {
                first++;
                result++;
            }
            if (arr[first] == value ) {
                first++;
            }
            
            if (arr[first] != value && result != first ) {
                arr[result] = arr[first];
                first++;
                result++;
            }
        }

        int size = vec_size;
        
        /*for (int i = size - 1; i >= result; i--) {
            delete arr[i];
            vec_size--;
        }*/    
        /*for(int i = 0; i < vec_size; i++) {
            if (arr[i] == value) { return false };
            else {return true};
        }*/
        
        vec_size = result-1;

        // Возвращаем true, если были удалены какие-то элементы
        return vec_size < size;
        

    }

    // Получение размера вектора
    template <typename T>
    int Vector<T>::size() const noexcept {
        return this->vec_size;
    }
}
