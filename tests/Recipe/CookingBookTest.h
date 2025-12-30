#include <UnitTest++/UnitTest++.h>

#include "../../src/Recipe/CookingBook.h"


SUITE(CookingBookTest)
{
    TEST(CookingBook_ConstructorAndGetters)
    {
        std::vector<Ingredient> ingr1 =
        {
            Ingredient("mork", Date(), Weight(1, Measur::Kilogram))
        };
        std::string kUnit1{"table"};
        std::string tUnit1{"knife"};
        std::string uUnit1{"board"};

        int complx1 = 70;
        std::string name1 = "Peel";


        std::vector<Ingredient> ingr2 =
        {
            Ingredient("__Peel_1kg_mork", Date(), Weight(1, Measur::Piece))
        };
        std::string kUnit2{"stove"};
        std::string tUnit2{"vilka"};
        std::string uUnit2{"pan"};

        int complx2 = 80;
        std::string name2 = "Fry";

        std::vector<Step> steps = 
        {
            Step(ingr1, kUnit1, tUnit1, uUnit1, complx1, name1),
            Step(ingr2, kUnit2, tUnit2, uUnit2, complx2, name2)
        };

        EdibleUnit dish("fry_mork", Date(), Weight(900, Measur::Gram), 150, Temperature::Warm);

        RecipeDescription note(Grade::z4_0, "Italian fry mork", "Jenius", "The best fry mork by good cooker");

        Recipe recipe(steps, dish, note);
        std::map<std::string, Recipe> recipes =
        {
            {"Italian fry mork", recipe}
        };
        Certification certification("importent", "very importent");
        CookingBookDescription description(Grade::z3_0, certification, "some book", "book with 1 recipe");
        CookingBook book(recipes, description);

        CHECK(std::vector<std::string>({"Italian fry mork"}) == book.getAllRecipes());
        CHECK(description == book.getDescription());
    }

    TEST(CookingBook_getRecipes)
    {
        std::vector<Ingredient> ingr1 =
        {
            Ingredient("mork", Date(), Weight(1, Measur::Kilogram))
        };
        std::string kUnit1{"table"};
        std::string tUnit1{"knife"};
        std::string uUnit1{"board"};

        int complx1 = 70;
        std::string name1 = "Peel";


        std::vector<Ingredient> ingr2 =
        {
            Ingredient("__Peel_1kg_mork", Date(), Weight(1, Measur::Piece))
        };
        std::string kUnit2{"stove"};
        std::string tUnit2{"vilka"};
        std::string uUnit2{"pan"};

        int complx2 = 80;
        std::string name2 = "Fry";

        std::vector<Step> steps = 
        {
            Step(ingr1, kUnit1, tUnit1, uUnit1, complx1, name1),
            Step(ingr2, kUnit2, tUnit2, uUnit2, complx2, name2)
        };

        EdibleUnit dish("fry_mork", Date(), Weight(900, Measur::Gram), 150, Temperature::Warm);

        RecipeDescription note(Grade::z4_0, "Italian fry mork", "Jenius", "The best fry mork by good cooker");

        Recipe recipe(steps, dish, note);


        std::vector<Ingredient> ingrSalad1 =
        {
            Ingredient("potato", Date(), Weight(500, Measur::Gram)),
            Ingredient("carrot", Date(), Weight(200, Measur::Gram)),
            Ingredient("egg", Date(), Weight(4, Measur::Piece)),
            Ingredient("pickle", Date(), Weight(300, Measur::Gram)),
            Ingredient("canned_peas", Date(), Weight(200, Measur::Gram)),
            Ingredient("sausage", Date(), Weight(300, Measur::Gram))
        };
        std::string kUnitSalad1{"table"};
        std::string tUnitSalad1{"scapula"};
        std::string uUnitSalad1{"bowl"};
        int complxSalad1 = 60;
        std::string nameSalad1 = "Mix";
        std::vector<Ingredient> ingrSalad2 =
        {
            Ingredient("__Mix_500g_potato_200g_carrot_4pc_egg_300g_pickle_200g_canned_peas_300g_sausage", Date(), Weight(1, Measur::Piece)),
        };
        std::string kUnitSalad2{"table"};
        std::string tUnitSalad2{"knife"};
        std::string uUnitSalad2{"board"};
        int complxSalad2 = 70;
        std::string nameSalad2 = "Chop";
        std::vector<Step> stepsSalad = 
        {
            Step(ingrSalad1, kUnitSalad1, tUnitSalad1, uUnitSalad1, complxSalad1, nameSalad1),
            Step(ingrSalad2, kUnitSalad2, tUnitSalad2, uUnitSalad2, complxSalad2, nameSalad2)
        };
        EdibleUnit dishSalad("olivier_salad", Date(), Weight(1500, Measur::Gram), 250, Temperature::Cold);
        RecipeDescription noteSalad(Grade::z4_5, "Olivier Salad", "Classic Russian", 
                                "Traditional Russian salad for New Year celebration");

        Recipe recipeSalad(stepsSalad, dishSalad, noteSalad);


        std::vector<Ingredient> ingrCake1 =
        {
            Ingredient("flour", Date(), Weight(200, Measur::Gram)),
            Ingredient("sugar", Date(), Weight(200, Measur::Gram)),
            Ingredient("cocoa_powder", Date(), Weight(50, Measur::Gram)),
            Ingredient("egg", Date(), Weight(3, Measur::Piece)),
            Ingredient("milk", Date(), Weight(100, Measur::Milliliter)),
            Ingredient("butter", Date(), Weight(100, Measur::Gram)),
            Ingredient("baking_powder", Date(), Weight(10, Measur::Gram))
        };
        std::string kUnitCake1{"table"};
        std::string tUnitCake1{"mixer"};
        std::string uUnitCake1{"bowl"};
        int complxCake1 = 75;
        std::string nameCake1 = "Mix";
        std::vector<Ingredient> ingrCake2 =
        {
            Ingredient("__Mix_200g_flour_200g_sugar_50g_cocoa_powder_3pc_egg_100ml_milk_100g_butter_10g_baking_powder", Date(), Weight(1, Measur::Piece))
        };
        std::string kUnitCake2{"oven"};
        std::string tUnitCake2{"oven_mitt"};
        std::string uUnitCake2{"baking_dish"};
        int complxCake2 = 80;
        std::string nameCake2 = "Bake";
        std::vector<Ingredient> ingrCake3 =
        {
            Ingredient("__Bake_1pc_Mix_200g_flour_200g_sugar_50g_cocoa_powder_3pc_egg_100ml_milk_100g_butter_10g_baking_powder", Date(), Weight(1, Measur::Piece)),
            Ingredient("dark_chocolate", Date(), Weight(200, Measur::Gram)),
            Ingredient("cream", Date(), Weight(200, Measur::Milliliter)),
            Ingredient("berries", Date(), Weight(150, Measur::Gram))
        };
        std::string kUnitCake3{"table"};
        std::string tUnitCake3{"spatula"};
        std::string uUnitCake3{"cake_stand"};
        int complxCake3 = 85;
        std::string nameCake3 = "Decorate";
        std::vector<Step> stepsCake = 
        {
            Step(ingrCake1, kUnitCake1, tUnitCake1, uUnitCake1, complxCake1, nameCake1),
            Step(ingrCake2, kUnitCake2, tUnitCake2, uUnitCake2, complxCake2, nameCake2),
            Step(ingrCake3, kUnitCake3, tUnitCake3, uUnitCake3, complxCake3, nameCake3)
        };
        EdibleUnit dishCake("chocolate_cake", Date(), Weight(900, Measur::Gram), 400, Temperature::Cold);
        RecipeDescription noteCake(Grade::z4_0, "Chocolate Dream Cake", "Dessert Master", 
                                "Moist chocolate cake with ganache and fresh berries");

        Recipe recipeCake(stepsCake, dishCake, noteCake);

        std::map<std::string, Recipe> recipes =
        {
            {"Italian fry mork", recipe},
            {"olivier_salad", recipeSalad},
            {"chocolate_cake", recipeCake}
        };

        Certification certification("importent", "very importent");
        CookingBookDescription description(Grade::z3_0, certification, "some book", "book with 1 recipe");
        CookingBook book(recipes, description);

        CHECK(std::vector<std::string>({"chocolate_cake"}) == book.getRecipesByAuthor("Dessert Master"));
        CHECK(std::vector<std::string>({"Italian fry mork", "chocolate_cake"})  == book.getRecipesByGrade(Grade::z3_0, Grade::z4_0));

        CHECK(recipeSalad == book.getRecipeByName("olivier_salad"));
    }
}
