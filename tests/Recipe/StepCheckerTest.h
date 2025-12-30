#include <UnitTest++/UnitTest++.h>

#include "../../src/Recipe/Step/StepChecker.h"

SUITE(StepCheckerTest)
{
    TEST(StepChecker_CheckKitchenUnit)
    {
        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")
        };
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<KitchenUnit>> units;
        units.reserve(4);
        units.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        units.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        units.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        units.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));

        std::string kUnit1{"stove"};
        std::string kUnit2{"microwave"};

        CHECK_EQUAL(true, StepChecker::CheckKitchenUnit(kUnit1, units));
        CHECK_EQUAL(false, StepChecker::CheckKitchenUnit(kUnit2, units));
    }

    TEST(StepChecker_CheckTool)
    {
        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")
        };
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Tool>> tools;
        tools.reserve(3);
        tools.push_back(std::make_unique<Tool>("spoon"));
        tools.push_back(std::make_unique<Tool>("vilka"));
        tools.push_back(std::make_unique<Tool>("kitchen spatula"));

        std::vector<std::unique_ptr<KitchenUnit>> units1;
        units1.reserve(5);
        units1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        units1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        units1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        units1.push_back(std::make_unique<ToolStorage>(std::move(tools), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ToolStorage"));
        units1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));

        std::vector<std::unique_ptr<KitchenUnit>> units2;
        units2.reserve(4);
        units2.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        units2.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        units2.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        units2.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));

        std::string tUnit1{"spoon"};
        std::string tUnit2{"sticks"};

        CHECK_EQUAL(true, StepChecker::CheckTool(tUnit1, units1));
        CHECK_EQUAL(false, StepChecker::CheckTool(tUnit1, units2));
        CHECK_EQUAL(false, StepChecker::CheckTool(tUnit2, units1));
    }

    TEST(StepChecker_Utensil)
    {
        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")
        };
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Utensil>> utensils;
        utensils.reserve(3);
        utensils.push_back(std::make_unique<Utensil>("pan"));
        utensils.push_back(std::make_unique<Utensil>("wok"));
        utensils.push_back(std::make_unique<Utensil>("bowl"));

        std::vector<std::unique_ptr<KitchenUnit>> units1;
        units1.reserve(5);
        units1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        units1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        units1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        units1.push_back(std::make_unique<UtensilStorage>(std::move(utensils), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "UtensilStorage"));
        units1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));

        std::vector<std::unique_ptr<KitchenUnit>> units2;
        units2.reserve(4);
        units2.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        units2.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        units2.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        units2.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));

        std::string uUnit1{"pan"};
        std::string uUnit2{"colander"};

        CHECK_EQUAL(true, StepChecker::CheckUtensil(uUnit1, units1));
        CHECK_EQUAL(false, StepChecker::CheckUtensil(uUnit1, units2));
        CHECK_EQUAL(false, StepChecker::CheckUtensil(uUnit2, units1));
    }

    TEST(StepChecker_Ingredients)
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

        std::vector<std::unique_ptr<EdibleUnit>> ingr2;
        ingr2.reserve(3);
        ingr2.push_back(std::make_unique<Liquid>("milk", Date(), Weight(1, Measur::Liter), 200, Temperature::Cold, 1000));
        ingr2.push_back(std::make_unique<EdibleUnit>("egg", Date(), Weight(6, Measur::Piece), 200, Temperature::Cold));
        ingr2.push_back(std::make_unique<EdibleUnit>("spaghetti", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Cold));

        std::vector<std::unique_ptr<EdibleUnit>> ingr3;
        ingr3.reserve(2);
        ingr3.push_back(std::make_unique<EdibleUnit>("crab", Date(), Weight(2, Measur::Piece), 200, Temperature::Freezing));
        ingr3.push_back(std::make_unique<EdibleUnit>("icecreame", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Freezing));

        std::vector<std::unique_ptr<KitchenUnit>> units1;
        units1.reserve(7);
        units1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        units1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        units1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        units1.push_back(std::make_unique<Cupboard>(std::move(ingr1), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage"));
        units1.push_back(std::make_unique<Fridge>(std::move(ingr2), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Cold));
        units1.push_back(std::make_unique<Fridge>(std::move(ingr3), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Freezing));
        units1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));

        std::vector<std::unique_ptr<KitchenUnit>> units2;
        units2.reserve(4);
        units2.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        units2.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        units2.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        units2.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));

        EdibleUnit i1("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool);
        Liquid i2("milk", Date(), Weight(300, Measur::Milliliter), 200, Temperature::Cold, 1000);
        Liquid i3("milk", Date(), Weight(1.2, Measur::Liter), 200, Temperature::Cold, 1000);
        EdibleUnit i4("crab", Date(), Weight(2, Measur::Piece), 200, Temperature::Freezing);
        EdibleUnit i5("rice", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool);

        CHECK_EQUAL(true, StepChecker::CheckIngredient(i1, units1));
        CHECK_EQUAL(true, StepChecker::CheckIngredient(i2, units1));
        CHECK_EQUAL(false, StepChecker::CheckIngredient(i3, units1));
        CHECK_EQUAL(true, StepChecker::CheckIngredient(i4, units1));
        CHECK_EQUAL(false, StepChecker::CheckIngredient(i5, units1));
        CHECK_THROW(StepChecker::CheckIngredient(i1, units2), GetSomethingException);
    }

    TEST(StepChecker_PurityStatus)
    {
        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")
        };
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Utensil>> utensils;
        utensils.reserve(3);
        utensils.push_back(std::make_unique<Utensil>("pan"));
        utensils.push_back(std::make_unique<Utensil>("wok"));
        utensils.push_back(std::make_unique<Utensil>("bowl", StateOfPurity::Dirty));

        std::vector<std::unique_ptr<Tool>> tools;
        tools.reserve(3);
        tools.push_back(std::make_unique<Tool>("spoon"));
        tools.push_back(std::make_unique<Tool>("vilka", StateOfPurity::Dirty));
        tools.push_back(std::make_unique<Tool>("kitchen spatula"));

        std::vector<std::unique_ptr<KitchenUnit>> units1;
        units1.reserve(6);
        units1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        units1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        units1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        units1.push_back(std::make_unique<ToolStorage>(std::move(tools), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ToolStorage"));
        units1.push_back(std::make_unique<UtensilStorage>(std::move(utensils), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "UtensilStorage"));
        units1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));

        std::vector<std::unique_ptr<KitchenUnit>> units2;
        units2.reserve(4);
        units2.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        units2.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        units2.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        units2.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));

        std::string tUnit1{"spoon"};
        std::string tUnit2{"sticks"};
        std::string tUnit3{"vilka"};

        std::string uUnit1{"pan"};
        std::string uUnit2{"colander"};
        std::string uUnit3{"bowl"};

        CHECK_EQUAL(true, StepChecker::CheckPurityStatus(uUnit1, tUnit1, units1));
        CHECK_THROW(StepChecker::CheckPurityStatus(uUnit1, tUnit1, units2), GetSomethingException);
        CHECK_EQUAL(false, StepChecker::CheckPurityStatus(uUnit2, tUnit2, units1));
        CHECK_EQUAL(false, StepChecker::CheckPurityStatus(uUnit3, tUnit1, units1));
        CHECK_EQUAL(false, StepChecker::CheckPurityStatus(uUnit1, tUnit3, units1));
    }
}
