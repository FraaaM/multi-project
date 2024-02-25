#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

// -----------------------------------------  ALG ----------------------------------------------------------
const MCherevko::MenuItem MCherevko::ALGEBRA_SUMM = {
    "1 - Хочу научиться складывать!", MCherevko::algebra_summ, &MCherevko::STUDY_ALGEBRA
};
const MCherevko::MenuItem MCherevko::ALGEBRA_SUBSTRACT = {
    "2 - Хочу научиться вычитать!", MCherevko::algebra_substract, &MCherevko::STUDY_ALGEBRA
};
const MCherevko::MenuItem MCherevko::ALGEBRA_MULTIPLY = {
    "3 - Хочу научиться умножать!", MCherevko::algebra_multiply, &MCherevko::STUDY_ALGEBRA
};
const MCherevko::MenuItem MCherevko::ALGEBRA_DIVIDE = {
    "4 - Хочу научиться делить!", MCherevko::algebra_divide, &MCherevko::STUDY_ALGEBRA
};
const MCherevko::MenuItem MCherevko::ALGEBRA_GO_BACK = {
    "0 - Вернуться к выбору предметов.", MCherevko::algebra_go_back, &MCherevko::STUDY_ALGEBRA
};

namespace {
    const MCherevko::MenuItem* const algebra_children[] = {
        &MCherevko::ALGEBRA_GO_BACK,
        &MCherevko::ALGEBRA_SUMM,
        &MCherevko::ALGEBRA_SUBSTRACT,
        &MCherevko::ALGEBRA_MULTIPLY,
        &MCherevko::ALGEBRA_DIVIDE
    };
    const int algebra_size = sizeof(algebra_children) / sizeof(algebra_children[0]);
}

const MCherevko::MenuItem MCherevko::STUDY_ALGEBRA = {
    "1 - Хочу изучать алгебру!", MCherevko::show_menu, &MCherevko::STUDY, algebra_children, algebra_size
};


//==============================          ---     MATAN      ---        ==============================================================================

const MCherevko::MenuItem MCherevko::MATAN_DIFF = {
    "1 - Хочу изучить дифференциальное исчисление!", MCherevko::matan_diff, &MCherevko::STUDY_MATAN
};
const MCherevko::MenuItem MCherevko::MATAN_INTEGR = {
    "2 - Хочу изучить интегральное исчисление!", MCherevko::matan_integr, &MCherevko::STUDY_MATAN
};
const MCherevko::MenuItem MCherevko::MATAN_GO_BACK = {
    "0 - Вернуться к выбору предметов.", MCherevko::matan_go_back, &MCherevko::STUDY_MATAN
};

namespace {
    const MCherevko::MenuItem* const matan_children[] = {
        &MCherevko::MATAN_GO_BACK,
        &MCherevko::MATAN_DIFF,
        &MCherevko::MATAN_INTEGR,
    };
    const int matan_size = sizeof(matan_children) / sizeof(matan_children[0]);
}
const MCherevko::MenuItem MCherevko::STUDY_MATAN = {
    "2 - Хочу изучать математический анализ!",MCherevko::show_menu, &MCherevko::STUDY, matan_children, matan_size 
};

//==============================          ---     STUDY      ---        ==============================================================================
const MCherevko::MenuItem MCherevko::STUDY_GO_BACK = {
    "0 - Выйти в главное меню.", MCherevko::study_go_back, &MCherevko::STUDY
};

namespace {
    const MCherevko::MenuItem* const study_children[] = {
        &MCherevko::STUDY_GO_BACK,
        &MCherevko::STUDY_ALGEBRA,
        &MCherevko::STUDY_MATAN
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}
const MCherevko::MenuItem MCherevko::STUDY = {
    "1 - Хочу учиться математике!", MCherevko::show_menu,& MCherevko::MAIN, study_children, study_size
};
const MCherevko::MenuItem MCherevko::EXIT = {
    "0 - Я лучше пойду полежу...", MCherevko::exit, &MCherevko::MAIN
};

namespace {
    const MCherevko::MenuItem* const main_children[] = {
        &MCherevko::EXIT,
        &MCherevko::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const MCherevko::MenuItem MCherevko::MAIN = {
    nullptr, MCherevko::show_menu, nullptr, main_children, main_size
};

