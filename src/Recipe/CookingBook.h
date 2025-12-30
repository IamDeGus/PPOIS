#pragma once

#include <map>
#include <string>
#include "../Common/Types/CookingBookDescription/CookingBookDescription.h"

#include "Recipe.h"
#include "../Common/Types/Grade/GradeHelper.h"

class Management;

class CookingBook
{
private:
    std::map<std::string, Recipe> recipes;

    CookingBookDescription description;

public:
    CookingBook(std::map<std::string, Recipe> recipes, CookingBookDescription description);

    std::vector<std::string> getAllRecipes() const;
    std::vector<std::string> getRecipesByAuthor(std::string author) const;
    std::vector<std::string> getRecipesByGrade(Grade low_grade, Grade up_grade) const;

    CookingBookDescription getDescription() const;

    bool operator== (const CookingBook other) const;

    Recipe getRecipeByName(std::string name) const;

protected:

    void AddRecipe(std::string& name, Recipe& recipe);

    friend class Management;
};
