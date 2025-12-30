#include <UnitTest++/UnitTest++.h>

#include "../../src/KitchenUnit/StorageUnit/Cupboard.h"


SUITE(CupboardTest)
{
    TEST(Cupboard_ConstructorAndGetters)
    {
        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")
        };
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Ingredient>> ingr1;
        ingr1.reserve(3);
        ingr1.push_back(std::make_unique<EdibleUnit>("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool));
        ingr1.push_back(std::make_unique<Ingredient>("flour", Date(), Weight(1, Measur::Kilogram)));
        ingr1.push_back(std::make_unique<Ingredient>("bean", Date(), Weight(1, Measur::Kilogram)));


        std::vector<std::unique_ptr<Ingredient>> ingr2;
        ingr2.reserve(3);
        ingr2.push_back(std::make_unique<EdibleUnit>("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool));
        ingr2.push_back(std::make_unique<Ingredient>("flour", Date(), Weight(1, Measur::Kilogram)));
        ingr2.push_back(std::make_unique<Ingredient>("bean", Date(), Weight(1, Measur::Kilogram)));

        KitchenUnitDescription description(1102, company, "best oven", Date());

        Cupboard unit(std::move(ingr1), description, 50, "ingr storage");
        
        for (int i{0}; i < unit.getUnits().size(); i++){
            CHECK(*ingr2[i] == *unit.getUnits()[i]);
        }
        CHECK(description == unit.getDescription());
        CHECK(50 == unit.getCapacityTotal());
        CHECK(6 == unit.getCapacityUsed());
        CHECK("ingr storage" == unit.getName());
    }
}
