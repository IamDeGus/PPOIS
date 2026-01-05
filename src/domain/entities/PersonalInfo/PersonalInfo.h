#pragma once

#include <string>

#include "../../value_objects/Ages/Ages.h"
#include "../../value_objects/Date/Date.h"
#include "../../value_objects/Address/Address.h"
#include "../../value_objects/Gender/Gender.h"


class PersonalInfo
{
private:
    std::string fName_;
    std::string lName_;

    Gender gender_;
    Ages age_;
    Date birthday_;

    Address address_;
public:
    PersonalInfo(std::string fName, std::string lName,
                 Gender gender, Ages age, Date birthday, 
                 Address address);

    std::string getFName();
    std::string getLName();
    Gender getGender();
    Ages getAge();
    Date getBirthday();
    Address getAddress();

protected:
    void IncreaseAges();
};
