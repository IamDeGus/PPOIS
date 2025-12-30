#include "RecipeDescription.h"



RecipeDescription::RecipeDescription(Grade grade, std::string name, std::string author, std::string description)
    : grade(grade), name(name), author(author), IDescription(description){};

bool RecipeDescription::operator==(const RecipeDescription other) const
{
    return this->grade == other.grade &&
            this->name == other.name &&
            this->author == other.author;
};

Grade RecipeDescription::getGrade() const {
    return grade;
};

std::string RecipeDescription::getAuthor() const {
    return author;
};

std::string RecipeDescription::getName() const{
    return name;
};

