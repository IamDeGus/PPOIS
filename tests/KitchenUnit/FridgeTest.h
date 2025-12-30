#include <UnitTest++/UnitTest++.h>

#include "../../src/KitchenUnit/StorageUnit/Fridge.h"

#include <iostream>


SUITE(FridgeTest)
{
    TEST(Fridge_ConstructorAndGetters)
    {
        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")
        };
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);
        
        std::vector<std::unique_ptr<EdibleUnit>> ingr1;
        ingr1.reserve(3);
        ingr1.push_back(std::make_unique<Liquid>("milk", Date(), Weight(1, Measur::Liter), 200, Temperature::Cold, 1000));
        ingr1.push_back(std::make_unique<EdibleUnit>("egg", Date(), Weight(6, Measur::Piece), 200, Temperature::Cold));
        ingr1.push_back(std::make_unique<EdibleUnit>("spaghetti", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Cold));

        std::vector<std::unique_ptr<EdibleUnit>> ingr2;
        ingr2.reserve(3);
        ingr2.push_back(std::make_unique<Liquid>("milk", Date(), Weight(1, Measur::Liter), 200, Temperature::Cold, 1000));
        ingr2.push_back(std::make_unique<EdibleUnit>("egg", Date(), Weight(6, Measur::Piece), 200, Temperature::Cold));
        ingr2.push_back(std::make_unique<EdibleUnit>("spaghetti", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Cold));

        KitchenUnitDescription description(1102, company, "best oven", Date());

        Fridge unit(std::move(ingr2), description, 50, "ingr storage", Temperature::Cold);
        

        for (int i{0}; i < unit.getUnits().size(); i++){
            CHECK(*ingr1[i] == *unit.getUnits()[i]);
        }
        CHECK(description == unit.getDescription());
        CHECK(50 == unit.getCapacityTotal());
        CHECK(11 == unit.getCapacityUsed());
        CHECK("ingr storage" == unit.getName());
        CHECK(Temperature::Cold == unit.getT());
    }
}
