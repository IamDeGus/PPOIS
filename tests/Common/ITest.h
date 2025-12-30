#include <UnitTest++/UnitTest++.h>

#include "../../src/Common/I/IDateCreate.h"
#include "../../src/Common/I/IDescription.h"
#include "../../src/Common/I/INameable.h"

SUITE(ITest)
{
    TEST(IDate_ConstructorAndGetters)
    {
        Date date;
        IDateCreate idate(date);

        CHECK(date == idate.getDateCreate());
    }

    TEST(IDescription_ConstructorAndGetters)
    {
        std::string description{"lalala"};
        IDescription idescription(description);

        CHECK(description == idescription.getDescription());
    }

    TEST(INameable_ConstructorAndGetters)
    {
        std::string name{"anton"};
        INameable iname(name);

        CHECK(name == iname.getName());
    }

}
