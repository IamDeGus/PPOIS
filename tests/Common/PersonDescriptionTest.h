#include <UnitTest++/UnitTest++.h>

#include "../../src/Common/Types/PersonDescription/PersonDescription.h"


SUITE(PersonDescriptionTest)
{
    TEST(PersonDescription_ConstructorAndGetters)
    {
        int age{24};
        Date birthday(2001, 10, 1, 23, 20, 34, true);
        Gender gender{Gender::Male};
        Health health{Health::Normal};
        std::string favoriteDish{"banana"};
        Tool favoriteTool("vilka");
        Temperature favoriteT{Temperature::Hot};
        std::string description{"basic man"};


        PersonDescription person_description(
            age,
            birthday,
            gender,
            health,
            favoriteDish,
            favoriteTool,
            favoriteT,
            description
        );

        CHECK(age == person_description.getAge());
        CHECK(birthday == person_description.getBirthday());
        CHECK(gender == person_description.getGender());
        CHECK(health == person_description.getHealth());
        CHECK(favoriteDish == person_description.getFavoriteDish());
        CHECK(favoriteTool == person_description.getFavoriteTool());
        CHECK(favoriteT == person_description.getFavoriteTemperature());
        CHECK(description == person_description.getDescription());
    }

}
