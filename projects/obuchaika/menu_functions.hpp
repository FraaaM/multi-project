#pragma once

#include "menu.hpp"

namespace MCherevko {
    const MenuItem* show_menu(const MenuItem* current);

    const MenuItem* exit(const MenuItem* current);

    const MenuItem* study_go_back(const MenuItem* current);
    
    //const MenuItem* study_algebra(const MenuItem* current);
    const MenuItem* algebra_summ(const MenuItem* current);
    const MenuItem* algebra_substract(const MenuItem* current);
    const MenuItem* algebra_multiply(const MenuItem* current);
    const MenuItem* algebra_divide(const MenuItem* current);
    const MenuItem* algebra_go_back(const MenuItem* current);

    //const MenuItem* study_matan(const MenuItem* current);
    const MenuItem* matan_diff(const MenuItem* current);
    const MenuItem* matan_integr(const MenuItem* current);
    const MenuItem* matan_go_back(const MenuItem* current);
}
