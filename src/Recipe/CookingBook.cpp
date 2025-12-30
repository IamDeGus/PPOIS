#include "CookingBook.h"

CookingBook::CookingBook(std::map<std::string, Recipe> recipes, CookingBookDescription description)
                         : recipes(std::move(recipes)), description(description) {}


std::vector<std::string> CookingBook::getAllRecipes() const{
    std::vector<std::string> result;
    for (const auto [n, r]: recipes)
        result.push_back(n);

    return result;
}

std::vector<std::string> CookingBook::getRecipesByAuthor(std::string author) const
{
    std::vector<std::string> result;
    for (const auto [n, r]: recipes)
        if (r.getNote().getAuthor() == author)
            result.push_back(n);

    return result;
}

std::vector<std::string> CookingBook::getRecipesByGrade(Grade low_grade, Grade up_grade) const
{
    std::vector<std::string> result;
    for (const auto [n, r]: recipes)
        if (GradeHelper::GradeAlessB(r.getNote().getGrade(), up_grade) &&
            GradeHelper::GradeAlessB(low_grade, r.getNote().getGrade()))
            result.push_back(n);

    return result;
}

CookingBookDescription CookingBook::getDescription() const
{
    return description;
}

bool CookingBook::operator==(const CookingBook other) const
{
    return this->description == other.description &&
           this->recipes == other.recipes;
}

Recipe CookingBook::getRecipeByName(std::string name) const{
    return recipes.at(name);
}

void CookingBook::AddRecipe(std::string& name, Recipe& recipe){
    recipes.emplace(std::move(name), std::move(recipe));
}
