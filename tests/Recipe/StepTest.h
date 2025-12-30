#include <UnitTest++/UnitTest++.h>

#include "../../src/Recipe/Step/Step.h"


SUITE(StepTest)
{
    TEST(Step_ConstructorAndGetters)
    {
        std::vector<Ingredient> ingr =
        {
            Ingredient("mork", Date(), Weight(1, Measur::Kilogram))
        };
        std::string kUnit{"stove"};
        std::string tUnit{"vilka"};
        std::string uUnit{"pan"};

        int complx = 80;
        std::string name = "Fry";

        Step step(ingr, kUnit, tUnit, uUnit, complx, name);

        CHECK(ingr == step.getIngredients());
        CHECK(kUnit == step.getKitchen_unit());
        CHECK(tUnit == step.getTool());
        CHECK(uUnit == step.getUtensil());
        CHECK(complx == step.getComplexity());
        CHECK(name == step.getName());
    }

    TEST(Step_Do)
    {
        std::vector<Ingredient> ingr =
        {
            Ingredient("mork", Date(), Weight(1, Measur::Kilogram))
        };
        std::string kUnit{"stove"};
        std::string tUnit{"vilka"};
        std::string uUnit{"pan"};

        int complx = 80;
        std::string name = "Fry";

        Step step(ingr, kUnit, tUnit, uUnit, complx, name);

        CHECK(Ingredient("__Fry_1kg_mork", Date(), Weight(1, Measur::Piece)) == step.Do());
    }

}
