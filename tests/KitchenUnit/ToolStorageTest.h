#include <UnitTest++/UnitTest++.h>

#include "../../src/KitchenUnit/StorageUnit/ToolStorage.h"

#include "../../src/Tool/Tool.h"
#include "../../src/Utensil/Utensil.h"
#include "../../src/Ingredient/EdibleUnit.h"

SUITE(ToolStorageTest)
{
    TEST(ToolStorage_SomeTest)
    {

        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")};
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Tool>> tools1;
        tools1.reserve(4);
        tools1.push_back(std::make_unique<Tool>("spoon"));
        tools1.push_back(std::make_unique<Tool>("knife"));
        tools1.push_back(std::make_unique<Tool>("vilka"));
        tools1.push_back(std::make_unique<Tool>("kitchen spatula"));

        std::vector<std::unique_ptr<Tool>> tools2;
        tools2.reserve(4);
        tools2.push_back(std::make_unique<Tool>("spoon"));
        tools2.push_back(std::make_unique<Tool>("knife"));
        tools2.push_back(std::make_unique<Tool>("vilka"));
        tools2.push_back(std::make_unique<Tool>("kitchen spatula"));

        ToolStorage storage(std::move(tools1), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ToolStorage");

        for (int i{0}; i < storage.getUnits().size(); i++){
            CHECK(*tools2[i] == *storage.getUnits()[i]);
        }
        CHECK(KitchenUnitDescription(1102, company, "best oven", Date()) == storage.getDescription());
        CHECK(50 == storage.getCapacityTotal());
        CHECK(4 == storage.getCapacityUsed());
        CHECK("ToolStorage" == storage.getName());
    }
}
