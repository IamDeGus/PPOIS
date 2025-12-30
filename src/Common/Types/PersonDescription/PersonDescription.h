#pragma once

#include "../../I/IDescription.h"

#include <string>
#include "../Date/Date.h"
#include "../../../Tool/Tool.h"
#include "../Temperature/Temperature.h"
#include "../Gender/Gender.h"
#include "../Health/Health.h"

class PersonDescription : public IDescription
{
private:
    int age;
    Date birthday;

    Gender gender;
    Health health;

    std::string favoriteDish;
    Tool favoriteTool;
    Temperature favoriteT;
public:
    PersonDescription(int age, const Date& birthday, Gender gender, Health health,
                      const std::string& favoriteDish, const Tool& favoriteTool,
                      Temperature favoriteT, const std::string& description);

    bool operator== (const PersonDescription other) const;

    int getAge() const;
    Date getBirthday() const;
    Gender getGender() const;
    Health getHealth() const;
    std::string getFavoriteDish() const;
    Tool getFavoriteTool() const;
    Temperature getFavoriteTemperature() const;
};
