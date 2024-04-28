#include "doubly_linked_list.hpp"
#include <iostream>

namespace MCherevko {
    // Деструктор
    template <typename T>
    DoublyLinkedList<T>::~DoublyLinkedList() noexcept {
        while (begin) {
            Node* temp = begin;
            begin = begin->next;
            delete temp;
        }
    }

    // Добавление элемента в конец списка
    template <typename T>
    void DoublyLinkedList<T>::push_back(const T& value) noexcept {
        Node* newNode = new Node(value);
        if (!begin) {
            begin = end = newNode;
        }
        else {
            end->next = newNode;
            newNode->prev = end;
            end = newNode;
        }
    }

    // Проверка наличия элемента в списке
    template <typename T>
    bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
        for (Node* current = begin; current; current = current->next) {
            if (current->value == value) {
                return true;
            }
        }
        return false;
    }

    // Вывод списка на экран
    template <typename T>
    void DoublyLinkedList<T>::print() const noexcept {
        for (Node* current = begin; current; current = current->next) {
            std::cout << current->value << " ";
        }
        std::cout << std::endl;
    }

    // Удаление первого вхождения элемента из списка
    template <typename T>
    bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
        for (Node* current = begin; current; current = current->next) {
            if (current->value == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                }
                else {
                    begin = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                else {
                    end = current->prev;
                }
                delete current;
                return true;
            }
        }
        return false;
    }

    // Получение размера списка
    template <typename T>
    std::size_t DoublyLinkedList<T>::size() const noexcept {
        std::size_t count = 0;
        for (Node* current = begin; current; current = current->next) {
            count++;
        }
        return count;
    }
}
