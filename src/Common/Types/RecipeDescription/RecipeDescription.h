#pragma once

#include "../../I/IDescription.h"

#include <string>
#include "../Grade/Grade.h"

class RecipeDescription : public IDescription
{
private:
    Grade grade;

    std::string name;
    std::string author;
public:
    RecipeDescription(Grade grade, std::string name, std::string author, std::string description);

    bool operator==(const RecipeDescription other) const;

    Grade getGrade() const;

    std::string getAuthor() const;

    std::string getName() const;
};
