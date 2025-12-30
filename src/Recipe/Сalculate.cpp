#include "Сalculate.h"

int Calculate::getEnergy(Recipe recipe){
    int result{0};
    for (auto& s : recipe.getSteps()){
        result += s.getComplexity();
    }
    return result / 70;
}

int Calculate::getXP(Recipe recipe){
    int needed{0};
    for (auto& s : recipe.getSteps()){
        if (needed < s.getComplexity())
            needed = s.getComplexity();
    }
    return needed;
}
