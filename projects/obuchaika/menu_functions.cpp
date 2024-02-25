#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const MCherevko::MenuItem* MCherevko::show_menu(const MenuItem* current) {
    std::cout << "Обучайка приветствует тебя, мой юный ученик!" << std::endl;
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Обучайка > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const MCherevko::MenuItem* MCherevko::exit(const MenuItem* current) {
    std::exit(0);
}

const MCherevko::MenuItem* MCherevko::study_go_back(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}


const MCherevko::MenuItem* MCherevko::algebra_summ(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const MCherevko::MenuItem* MCherevko::algebra_substract(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const MCherevko::MenuItem* MCherevko::algebra_multiply(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const MCherevko::MenuItem* MCherevko::algebra_divide(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const MCherevko::MenuItem* MCherevko::algebra_go_back(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}


const MCherevko::MenuItem* MCherevko::matan_diff(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const MCherevko::MenuItem* MCherevko::matan_integr(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const MCherevko::MenuItem* MCherevko::matan_go_back(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}
