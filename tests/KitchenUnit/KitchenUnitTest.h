#include <UnitTest++/UnitTest++.h>

#include "../../src/KitchenUnit/KitchenUnit.h"


SUITE(KitchenUnitTest)
{
    TEST(KitchenUnit_ConstructorAndGetters)
    {
        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")
        };
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);
        

        KitchenUnitDescription description(1101, company, "good pan", Date());
        KitchenUnit unit("pan", description);
        
        CHECK("pan" == unit.getName());
        CHECK(description == unit.getDescription());
    }
}
