#include <UnitTest++/UnitTest++.h>

#include "../../src/KitchenUnit/StorageUnit/UtensilStorage.h"

#include "../../src/Tool/Tool.h"
#include "../../src/Utensil/Utensil.h"
#include "../../src/Ingredient/EdibleUnit.h"

SUITE(UtensilStorageTest)
{
    TEST(UtensilStorage_SomeTest)
    {

        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")};
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Utensil>> utensils1;
        utensils1.reserve(4);
        utensils1.push_back(std::make_unique<Utensil>("pan"));
        utensils1.push_back(std::make_unique<Utensil>("wok"));
        utensils1.push_back(std::make_unique<Utensil>("board"));
        utensils1.push_back(std::make_unique<Utensil>("bowl"));

        std::vector<std::unique_ptr<Utensil>> utensils2;
        utensils2.reserve(4);
        utensils2.push_back(std::make_unique<Utensil>("pan"));
        utensils2.push_back(std::make_unique<Utensil>("wok"));
        utensils2.push_back(std::make_unique<Utensil>("board"));
        utensils2.push_back(std::make_unique<Utensil>("bowl"));

        UtensilStorage storage(std::move(utensils1), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "UtensilStorage");

        for (int i{0}; i < storage.getUnits().size(); i++){
            CHECK(*utensils2[i] == *storage.getUnits()[i]);
        }
        CHECK(KitchenUnitDescription(1102, company, "best oven", Date()) == storage.getDescription());
        CHECK(50 == storage.getCapacityTotal());
        CHECK(4 == storage.getCapacityUsed());
        CHECK("UtensilStorage" == storage.getName());

    }
}
