#include "RecipeChecker.h"

bool RecipeChecker::RecipeName(std::string addname, std::vector<std::string> name){
    for (auto& n : name){
        if (addname == n)
            return true;
    }
    return false;
}
