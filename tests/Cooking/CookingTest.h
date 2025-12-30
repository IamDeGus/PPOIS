#include <UnitTest++/UnitTest++.h>

#include "../../src/Cooking/Cooking.h"
#include "../../src/Cooking/Management.h"
#include <algorithm>

#include <iostream>

SUITE(CookingTest)
{

    TEST(Cooking_ConstructorAndGetters)
    {
        Date DateLastCooked(2001, 1, 1, 1, 0, 0, true);
        Date DateLastEaten(2002, 1, 1, 1, 0, 0, true);
        Date DateLastRemoving(2003, 1, 1, 1, 0, 0, true);
        Date DateLastWash(2004, 1, 1, 1, 0, 0, true);
        Date DateLastAddRecipe(2005, 1, 1, 1, 0, 0, true);

        std::map<std::string, int> cookedDishesbyName = {
            {"eag", 5},
            {"soup", 2}};
        std::map<std::string, int> eatenFoodbyName{
            {"eag", 4},
            {"chease", 1}};

        PersonMetaData metadata(7, 5, 5, 0, 3, 1, 2, DateLastCooked,
                                DateLastEaten, DateLastRemoving,
                                DateLastWash, DateLastAddRecipe,
                                eatenFoodbyName, cookedDishesbyName);

        Date birthday(2000, 1, 2, 0, 30, 0, true);
        Gender gender{Gender::Male};
        Health health{Health::Bad};
        Tool favorite("vilka");
        Temperature favoriteT{Temperature::Hot};

        PersonDescription Pdescription(25, birthday, gender, health, "eag", favorite, favoriteT, "really god person");

        Person anton(750, "Anton", metadata, Pdescription);

        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")};
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Ingredient>> ingrr1;
        ingrr1.reserve(3);
        ingrr1.push_back(std::make_unique<EdibleUnit>("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool));
        ingrr1.push_back(std::make_unique<Ingredient>("flour", Date(), Weight(1, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<Ingredient>("bean", Date(), Weight(1, Measur::Kilogram)));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr2;
        ingrr2.reserve(3);
        ingrr2.push_back(std::make_unique<Liquid>("milk", Date(), Weight(1, Measur::Liter), 200, Temperature::Cold, 1000));
        ingrr2.push_back(std::make_unique<EdibleUnit>("egg", Date(), Weight(6, Measur::Piece), 200, Temperature::Cold));
        ingrr2.push_back(std::make_unique<EdibleUnit>("spaghetti", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Cold));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr3;
        ingrr3.reserve(2);
        ingrr3.push_back(std::make_unique<EdibleUnit>("crab", Date(), Weight(2, Measur::Piece), 200, Temperature::Freezing));
        ingrr3.push_back(std::make_unique<EdibleUnit>("icecreame", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Freezing));

        std::vector<std::unique_ptr<KitchenUnit>> unitss1;
        unitss1.reserve(7);
        unitss1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<Cupboard>(std::move(ingrr1), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage"));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr2), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Cold));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr3), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Freezing));
        unitss1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));

        KitchenDescription kdescription(Size::Large, true, true, true, true, "mega kitchen");

        Kitchen kitchen1(std::move(unitss1), kdescription);

        std::vector<std::unique_ptr<Ingredient>> Dingrr1;
        Dingrr1.reserve(3);
        Dingrr1.push_back(std::make_unique<EdibleUnit>("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool));
        Dingrr1.push_back(std::make_unique<Ingredient>("flour", Date(), Weight(1, Measur::Kilogram)));
        Dingrr1.push_back(std::make_unique<Ingredient>("bean", Date(), Weight(1, Measur::Kilogram)));

        std::vector<std::unique_ptr<EdibleUnit>> Dingrr2;
        Dingrr2.reserve(3);
        Dingrr2.push_back(std::make_unique<Liquid>("milk", Date(), Weight(1, Measur::Liter), 200, Temperature::Cold, 1000));
        Dingrr2.push_back(std::make_unique<EdibleUnit>("egg", Date(), Weight(6, Measur::Piece), 200, Temperature::Cold));
        ingrr2.push_back(std::make_unique<EdibleUnit>("spaghetti", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Cold));

        std::vector<std::unique_ptr<EdibleUnit>> Dingrr3;
        Dingrr3.reserve(2);
        Dingrr3.push_back(std::make_unique<EdibleUnit>("crab", Date(), Weight(2, Measur::Piece), 200, Temperature::Freezing));
        Dingrr3.push_back(std::make_unique<EdibleUnit>("icecreame", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Freezing));

        std::vector<std::unique_ptr<KitchenUnit>> Dunitss1;
        Dunitss1.reserve(7);
        Dunitss1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        Dunitss1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        Dunitss1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        Dunitss1.push_back(std::make_unique<Cupboard>(std::move(Dingrr1), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage"));
        Dunitss1.push_back(std::make_unique<Fridge>(std::move(Dingrr2), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Cold));
        Dunitss1.push_back(std::make_unique<Fridge>(std::move(Dingrr3), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Freezing));
        Dunitss1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));

        Kitchen kitchen2(std::move(Dunitss1), kdescription);

        std::vector<Ingredient> ingr1 =
            {
                Ingredient("mork", Date(), Weight(1, Measur::Kilogram))};
        std::string kUnit1{"table"};
        std::string tUnit1{"knife"};
        std::string uUnit1{"board"};

        int complx1 = 70;
        std::string name1 = "Peel";

        std::vector<Ingredient> ingr2 =
            {
                Ingredient("__Peel_1kg_mork", Date(), Weight(1, Measur::Piece))};
        std::string kUnit2{"stove"};
        std::string tUnit2{"vilka"};
        std::string uUnit2{"pan"};

        int complx2 = 80;
        std::string name2 = "Fry";

        std::vector<Step> steps =
            {
                Step(ingr1, kUnit1, tUnit1, uUnit1, complx1, name1),
                Step(ingr2, kUnit2, tUnit2, uUnit2, complx2, name2)};

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
                Ingredient("sausage", Date(), Weight(300, Measur::Gram))};
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
                Step(ingrSalad2, kUnitSalad2, tUnitSalad2, uUnitSalad2, complxSalad2, nameSalad2)};
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
                Ingredient("baking_powder", Date(), Weight(10, Measur::Gram))};
        std::string kUnitCake1{"table"};
        std::string tUnitCake1{"mixer"};
        std::string uUnitCake1{"bowl"};
        int complxCake1 = 75;
        std::string nameCake1 = "Mix";
        std::vector<Ingredient> ingrCake2 =
            {
                Ingredient("__Mix_200g_flour_200g_sugar_50g_cocoa_powder_3pc_egg_100ml_milk_100g_butter_10g_baking_powder", Date(), Weight(1, Measur::Piece))};
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
                Ingredient("berries", Date(), Weight(150, Measur::Gram))};
        std::string kUnitCake3{"table"};
        std::string tUnitCake3{"spatula"};
        std::string uUnitCake3{"cake_stand"};
        int complxCake3 = 85;
        std::string nameCake3 = "Decorate";
        std::vector<Step> stepsCake =
            {
                Step(ingrCake1, kUnitCake1, tUnitCake1, uUnitCake1, complxCake1, nameCake1),
                Step(ingrCake2, kUnitCake2, tUnitCake2, uUnitCake2, complxCake2, nameCake2),
                Step(ingrCake3, kUnitCake3, tUnitCake3, uUnitCake3, complxCake3, nameCake3)};
        EdibleUnit dishCake("chocolate_cake", Date(), Weight(900, Measur::Gram), 400, Temperature::Cold);
        RecipeDescription noteCake(Grade::z4_0, "Chocolate Dream Cake", "Dessert Master",
                                   "Moist chocolate cake with ganache and fresh berries");

        Recipe recipeCake(stepsCake, dishCake, noteCake);

        std::map<std::string, Recipe> recipes =
            {
                {"Italian fry mork", recipe},
                {"olivier_salad", recipeSalad},
                {"chocolate_cake", recipeCake}};

        Certification certification("importent", "very importent");
        CookingBookDescription description(Grade::z3_0, certification, "some book", "book with 1 recipe");
        CookingBook book(recipes, description);

        Cooking cooking(anton, std::move(kitchen1), book, Date());

        CHECK(anton == cooking.getCook());
        for (int i{0}; i < cooking.getKitchen().getUnits().size(); i++)
        {
            CHECK(*kitchen2.getUnits()[i] == *cooking.getKitchen().getUnits()[i]);
        }
        CHECK(kitchen2.getDescription() == cooking.getKitchen().getDescription());
        CHECK(book == cooking.getRecipes());
        CHECK(Date() == cooking.getDate());
    }

    TEST(Cooking_Cook)
    {
        Date DateLastCooked(2001, 1, 1, 1, 0, 0, true);
        Date DateLastEaten(2002, 1, 1, 1, 0, 0, true);
        Date DateLastRemoving(2003, 1, 1, 1, 0, 0, true);
        Date DateLastWash(2004, 1, 1, 1, 0, 0, true);
        Date DateLastAddRecipe(2005, 1, 1, 1, 0, 0, true);

        std::map<std::string, int> cookedDishesbyName = {
            {"eag", 5},
            {"soup", 2}};
        std::map<std::string, int> eatenFoodbyName{
            {"eag", 4},
            {"chease", 1}};

        PersonMetaData metadata(7, 5, 5, 0, 3, 1, 2, DateLastCooked,
                                DateLastEaten, DateLastRemoving,
                                DateLastWash, DateLastAddRecipe,
                                eatenFoodbyName, cookedDishesbyName);

        Date birthday(2000, 1, 2, 0, 30, 0, true);
        Gender gender{Gender::Male};
        Health health{Health::Bad};
        Tool favorite("vilka");
        Temperature favoriteT{Temperature::Hot};

        PersonDescription Pdescription(25, birthday, gender, health, "eag", favorite, favoriteT, "really god person");

        Person anton(750, "Anton", metadata, Pdescription);
        Person anton2(50, "Anton", metadata, Pdescription);

        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")};
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Ingredient>> ingrr1;
        ingrr1.reserve(3);
        ingrr1.push_back(std::make_unique<Ingredient>("mork", Date(), Weight(5, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<EdibleUnit>("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool));
        ingrr1.push_back(std::make_unique<Ingredient>("flour", Date(), Weight(1, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<Ingredient>("bean", Date(), Weight(1, Measur::Kilogram)));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr2;
        ingrr2.reserve(3);
        ingrr2.push_back(std::make_unique<Liquid>("milk", Date(), Weight(1, Measur::Liter), 200, Temperature::Cold, 1000));
        ingrr2.push_back(std::make_unique<EdibleUnit>("egg", Date(), Weight(6, Measur::Piece), 200, Temperature::Cold));
        ingrr2.push_back(std::make_unique<EdibleUnit>("spaghetti", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Cold));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr3;
        ingrr3.reserve(2);
        ingrr3.push_back(std::make_unique<EdibleUnit>("crab", Date(), Weight(2, Measur::Piece), 200, Temperature::Freezing));
        ingrr3.push_back(std::make_unique<EdibleUnit>("icecreame", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Freezing));

        std::vector<std::unique_ptr<Utensil>> utensils;
        utensils.reserve(4);
        utensils.push_back(std::make_unique<Utensil>("pan", StateOfPurity::QuiteDirty));
        utensils.push_back(std::make_unique<Utensil>("wok"));
        utensils.push_back(std::make_unique<Utensil>("board", StateOfPurity::QuiteDirty));
        utensils.push_back(std::make_unique<Utensil>("bowl", StateOfPurity::Dirty));

        std::vector<std::unique_ptr<Tool>> tools;
        tools.reserve(4);
        tools.push_back(std::make_unique<Tool>("spoon"));
        tools.push_back(std::make_unique<Tool>("knife", StateOfPurity::QuiteDirty));
        tools.push_back(std::make_unique<Tool>("vilka", StateOfPurity::QuiteDirty));
        tools.push_back(std::make_unique<Tool>("kitchen spatula"));

        std::vector<std::unique_ptr<KitchenUnit>> unitss1;
        unitss1.reserve(10);
        unitss1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<ToolStorage>(std::move(tools), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ToolStorage"));
        unitss1.push_back(std::make_unique<UtensilStorage>(std::move(utensils), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "UtensilStorage"));
        unitss1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<Cupboard>(std::move(ingrr1), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage"));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr2), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Cold));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr3), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Freezing));
        unitss1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("table", KitchenUnitDescription(1102, company, "best oven", Date())));

        KitchenDescription kdescription(Size::Large, true, true, true, true, "mega kitchen");

        Kitchen kitchen1(std::move(unitss1), kdescription);

        std::vector<Ingredient> ingr1 =
            {
                Ingredient("mork", Date(), Weight(1, Measur::Kilogram))};
        std::string kUnit1{"table"};
        std::string tUnit1{"knife"};
        std::string uUnit1{"board"};

        int complx1 = 70;
        std::string name1 = "Peel";

        std::vector<Ingredient> ingr2 =
            {
                Ingredient("__Peel_1kg_mork", Date(), Weight(1, Measur::Piece))};
        std::string kUnit2{"stove"};
        std::string tUnit2{"vilka"};
        std::string uUnit2{"pan"};

        int complx2 = 80;
        std::string name2 = "Fry";

        std::vector<Step> steps =
            {
                Step(ingr1, kUnit1, tUnit1, uUnit1, complx1, name1),
                Step(ingr2, kUnit2, tUnit2, uUnit2, complx2, name2)};

        EdibleUnit dish("fry_mork", Date(), Weight(900, Measur::Gram), 150, Temperature::Cool);

        RecipeDescription note(Grade::z4_0, "Italian fry mork", "Jenius", "The best fry mork by good cooker");

        Recipe recipe(steps, dish, note);

        std::vector<Ingredient> ingrSalad1 =
            {
                Ingredient("potato", Date(), Weight(500, Measur::Gram)),
                Ingredient("carrot", Date(), Weight(200, Measur::Gram)),
                Ingredient("egg", Date(), Weight(4, Measur::Piece)),
                Ingredient("pickle", Date(), Weight(300, Measur::Gram)),
                Ingredient("canned_peas", Date(), Weight(200, Measur::Gram)),
                Ingredient("sausage", Date(), Weight(300, Measur::Gram))};
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
                Step(ingrSalad2, kUnitSalad2, tUnitSalad2, uUnitSalad2, complxSalad2, nameSalad2)};
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
                Ingredient("baking_powder", Date(), Weight(10, Measur::Gram))};
        std::string kUnitCake1{"table"};
        std::string tUnitCake1{"mixer"};
        std::string uUnitCake1{"bowl"};
        int complxCake1 = 75;
        std::string nameCake1 = "Mix";
        std::vector<Ingredient> ingrCake2 =
            {
                Ingredient("__Mix_200g_flour_200g_sugar_50g_cocoa_powder_3pc_egg_100ml_milk_100g_butter_10g_baking_powder", Date(), Weight(1, Measur::Piece))};
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
                Ingredient("berries", Date(), Weight(150, Measur::Gram))};
        std::string kUnitCake3{"table"};
        std::string tUnitCake3{"spatula"};
        std::string uUnitCake3{"cake_stand"};
        int complxCake3 = 85;
        std::string nameCake3 = "Decorate";
        std::vector<Step> stepsCake =
            {
                Step(ingrCake1, kUnitCake1, tUnitCake1, uUnitCake1, complxCake1, nameCake1),
                Step(ingrCake2, kUnitCake2, tUnitCake2, uUnitCake2, complxCake2, nameCake2),
                Step(ingrCake3, kUnitCake3, tUnitCake3, uUnitCake3, complxCake3, nameCake3)};
        EdibleUnit dishCake("chocolate_cake", Date(), Weight(900, Measur::Gram), 400, Temperature::Cold);
        RecipeDescription noteCake(Grade::z4_0, "Chocolate Dream Cake", "Dessert Master",
                                   "Moist chocolate cake with ganache and fresh berries");

        Recipe recipeCake(stepsCake, dishCake, noteCake);

        std::map<std::string, Recipe> recipes =
            {
                {"Italian fry mork", recipe},
                {"olivier_salad", recipeSalad},
                {"chocolate_cake", recipeCake}};

        Certification certification("importent", "very importent");
        CookingBookDescription description(Grade::z3_0, certification, "some book", "book with 1 recipe");
        CookingBook book(recipes, description);

        Cooking cooking(anton, std::move(kitchen1), book, Date(2025, 5, 1, 12, 0, 0, true));
        Date lastdate(2025, 1, 1, 0, 0, 0, true);
        lastdate = cooking.getDate();

        cooking.Cook(cooking.getRecipes().getRecipeByName("Italian fry mork"));

        for (auto &s : cooking.getRecipes().getRecipeByName("Italian fry mork").getSteps())
        {
            CHECK_EQUAL(false, StepChecker::CheckPurityStatus(s.getUtensil(), s.getTool(), cooking.getKitchen().getUnits()));
        }

        CHECK_EQUAL(false, StepChecker::CheckIngredient(Ingredient("mork", Date(), Weight(4.1, Measur::Kilogram)), cooking.getKitchen().getUnits()));
        CHECK_EQUAL(true, StepChecker::CheckIngredient(Ingredient("mork", Date(), Weight(4, Measur::Kilogram)), cooking.getKitchen().getUnits()));
        CHECK_EQUAL(true, StepChecker::CheckIngredient(EdibleUnit("fry_mork", Date(), Weight(900, Measur::Gram), 150, Temperature::Cool), cooking.getKitchen().getUnits()));

        lastdate += Date(0, 0, 0, 0, 0, 138, false);

        CHECK(cooking.getDate() == lastdate);
        CHECK_EQUAL(cooking.getCook().getMetaData().getCookedDishes(), 8);
        CHECK_EQUAL(cooking.getCook().getMetaData().getCookedDishesbyName()["fry_mork"], 1);
        CHECK(cooking.getCook().getMetaData().getDateLastCooked() == lastdate);
        CHECK_EQUAL(cooking.getCook().getXP(), 752);
        CHECK_EQUAL(cooking.getCook().getEnergy(), 98);
    }

    TEST(Cooking_Eat)
    {
        Date DateLastCooked(2001, 1, 1, 1, 0, 0, true);
        Date DateLastEaten(2002, 1, 1, 1, 0, 0, true);
        Date DateLastRemoving(2003, 1, 1, 1, 0, 0, true);
        Date DateLastWash(2004, 1, 1, 1, 0, 0, true);
        Date DateLastAddRecipe(2005, 1, 1, 1, 0, 0, true);

        std::map<std::string, int> cookedDishesbyName = {
            {"eag", 5},
            {"soup", 2}};
        std::map<std::string, int> eatenFoodbyName{
            {"eag", 4},
            {"chease", 1},
            {"banana", 1}};

        PersonMetaData metadata(7, 6, 5, 0, 3, 1, 2, DateLastCooked,
                                DateLastEaten, DateLastRemoving,
                                DateLastWash, DateLastAddRecipe,
                                eatenFoodbyName, cookedDishesbyName);

        Date birthday(2000, 1, 2, 0, 30, 0, true);
        Gender gender{Gender::Male};
        Health health{Health::Bad};
        Tool favorite("vilka");
        Temperature favoriteT{Temperature::Hot};

        PersonDescription Pdescription(25, birthday, gender, health, "eag", favorite, favoriteT, "really god person");

        Person anton(750, "Anton", metadata, Pdescription);
        Person anton2(50, "Anton", metadata, Pdescription);

        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")};
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Ingredient>> ingrr1;
        ingrr1.reserve(3);
        ingrr1.push_back(std::make_unique<Ingredient>("mork", Date(), Weight(5, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<EdibleUnit>("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool));
        ingrr1.push_back(std::make_unique<Ingredient>("flour", Date(), Weight(1, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<Ingredient>("bean", Date(), Weight(1, Measur::Kilogram)));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr2;
        ingrr2.reserve(3);
        ingrr2.push_back(std::make_unique<Liquid>("milk", Date(), Weight(1, Measur::Liter), 200, Temperature::Cold, 1000));
        ingrr2.push_back(std::make_unique<EdibleUnit>("egg", Date(), Weight(6, Measur::Piece), 200, Temperature::Cold));
        ingrr2.push_back(std::make_unique<EdibleUnit>("spaghetti", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Cold));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr3;
        ingrr3.reserve(2);
        ingrr3.push_back(std::make_unique<EdibleUnit>("crab", Date(), Weight(2, Measur::Piece), 200, Temperature::Freezing));
        ingrr3.push_back(std::make_unique<EdibleUnit>("icecreame", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Freezing));

        std::vector<std::unique_ptr<Utensil>> utensils;
        utensils.reserve(4);
        utensils.push_back(std::make_unique<Utensil>("pan", StateOfPurity::QuiteDirty));
        utensils.push_back(std::make_unique<Utensil>("wok"));
        utensils.push_back(std::make_unique<Utensil>("board", StateOfPurity::QuiteDirty));
        utensils.push_back(std::make_unique<Utensil>("bowl", StateOfPurity::Dirty));

        std::vector<std::unique_ptr<Tool>> tools;
        tools.reserve(4);
        tools.push_back(std::make_unique<Tool>("spoon"));
        tools.push_back(std::make_unique<Tool>("knife", StateOfPurity::QuiteDirty));
        tools.push_back(std::make_unique<Tool>("vilka", StateOfPurity::QuiteDirty));
        tools.push_back(std::make_unique<Tool>("kitchen spatula"));

        std::vector<std::unique_ptr<KitchenUnit>> unitss1;
        unitss1.reserve(10);
        unitss1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<ToolStorage>(std::move(tools), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ToolStorage"));
        unitss1.push_back(std::make_unique<UtensilStorage>(std::move(utensils), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "UtensilStorage"));
        unitss1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<Cupboard>(std::move(ingrr1), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage"));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr2), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Cold));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr3), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Freezing));
        unitss1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("table", KitchenUnitDescription(1102, company, "best oven", Date())));

        KitchenDescription kdescription(Size::Large, true, true, true, true, "mega kitchen");

        Kitchen kitchen1(std::move(unitss1), kdescription);

        std::vector<Ingredient> ingr1 =
            {
                Ingredient("mork", Date(), Weight(1, Measur::Kilogram))};
        std::string kUnit1{"table"};
        std::string tUnit1{"knife"};
        std::string uUnit1{"board"};

        int complx1 = 700;
        std::string name1 = "Peel";

        std::vector<Ingredient> ingr2 =
            {
                Ingredient("__Peel_1kg_mork", Date(), Weight(1, Measur::Piece))};
        std::string kUnit2{"stove"};
        std::string tUnit2{"vilka"};
        std::string uUnit2{"pan"};

        int complx2 = 700;
        std::string name2 = "Fry";

        std::vector<Step> steps =
            {
                Step(ingr1, kUnit1, tUnit1, uUnit1, complx1, name1),
                Step(ingr2, kUnit2, tUnit2, uUnit2, complx2, name2)};

        EdibleUnit dish("fry_mork", Date(), Weight(900, Measur::Gram), 150, Temperature::Cool);

        RecipeDescription note(Grade::z4_0, "Italian fry mork", "Jenius", "The best fry mork by good cooker");

        Recipe recipe(steps, dish, note);

        std::vector<Ingredient> ingrSalad1 =
            {
                Ingredient("potato", Date(), Weight(500, Measur::Gram)),
                Ingredient("carrot", Date(), Weight(200, Measur::Gram)),
                Ingredient("egg", Date(), Weight(4, Measur::Piece)),
                Ingredient("pickle", Date(), Weight(300, Measur::Gram)),
                Ingredient("canned_peas", Date(), Weight(200, Measur::Gram)),
                Ingredient("sausage", Date(), Weight(300, Measur::Gram))};
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
                Step(ingrSalad2, kUnitSalad2, tUnitSalad2, uUnitSalad2, complxSalad2, nameSalad2)};
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
                Ingredient("baking_powder", Date(), Weight(10, Measur::Gram))};
        std::string kUnitCake1{"table"};
        std::string tUnitCake1{"mixer"};
        std::string uUnitCake1{"bowl"};
        int complxCake1 = 75;
        std::string nameCake1 = "Mix";
        std::vector<Ingredient> ingrCake2 =
            {
                Ingredient("__Mix_200g_flour_200g_sugar_50g_cocoa_powder_3pc_egg_100ml_milk_100g_butter_10g_baking_powder", Date(), Weight(1, Measur::Piece))};
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
                Ingredient("berries", Date(), Weight(150, Measur::Gram))};
        std::string kUnitCake3{"table"};
        std::string tUnitCake3{"spatula"};
        std::string uUnitCake3{"cake_stand"};
        int complxCake3 = 85;
        std::string nameCake3 = "Decorate";
        std::vector<Step> stepsCake =
            {
                Step(ingrCake1, kUnitCake1, tUnitCake1, uUnitCake1, complxCake1, nameCake1),
                Step(ingrCake2, kUnitCake2, tUnitCake2, uUnitCake2, complxCake2, nameCake2),
                Step(ingrCake3, kUnitCake3, tUnitCake3, uUnitCake3, complxCake3, nameCake3)};
        EdibleUnit dishCake("chocolate_cake", Date(), Weight(900, Measur::Gram), 400, Temperature::Cold);
        RecipeDescription noteCake(Grade::z4_0, "Chocolate Dream Cake", "Dessert Master",
                                   "Moist chocolate cake with ganache and fresh berries");

        Recipe recipeCake(stepsCake, dishCake, noteCake);

        std::map<std::string, Recipe> recipes =
            {
                {"Italian fry mork", recipe},
                {"olivier_salad", recipeSalad},
                {"chocolate_cake", recipeCake}};

        Certification certification("importent", "very importent");
        CookingBookDescription description(Grade::z3_0, certification, "some book", "book with 1 recipe");
        CookingBook book(recipes, description);

        Cooking cooking(anton, std::move(kitchen1), book, Date(2025, 5, 1, 12, 0, 0, true));
        Date lastdate(2025, 1, 1, 0, 0, 0, true);
        lastdate = cooking.getDate();

        cooking.Cook(cooking.getRecipes().getRecipeByName("Italian fry mork"));
        cooking.Eat(EdibleUnit("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool));

        lastdate += Date(0, 0, 0, 0, 15, 833, false);

        CHECK(cooking.getDate() == lastdate);
        CHECK_EQUAL(false, StepChecker::CheckIngredient(EdibleUnit("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool), cooking.getKitchen().getUnits()));
        CHECK_EQUAL(cooking.getCook().getEnergy(), 100); // -20 + 30
        CHECK_EQUAL(cooking.getCook().getMetaData().getEatenFood(), 7);
        CHECK_EQUAL(cooking.getCook().getMetaData().getEatenFoodbyName()["banana"], 2);
        CHECK(cooking.getCook().getMetaData().getDateLastEaten() == lastdate);
    }

    TEST(Cooking_Sleep)
    {
        Date DateLastCooked(2001, 1, 1, 1, 0, 0, true);
        Date DateLastEaten(2002, 1, 1, 1, 0, 0, true);
        Date DateLastRemoving(2003, 1, 1, 1, 0, 0, true);
        Date DateLastWash(2004, 1, 1, 1, 0, 0, true);
        Date DateLastAddRecipe(2005, 1, 1, 1, 0, 0, true);

        std::map<std::string, int> cookedDishesbyName = {
            {"eag", 5},
            {"soup", 2}};
        std::map<std::string, int> eatenFoodbyName{
            {"eag", 4},
            {"chease", 1},
            {"banana", 1}};

        PersonMetaData metadata(7, 6, 5, 0, 3, 1, 2, DateLastCooked,
                                DateLastEaten, DateLastRemoving,
                                DateLastWash, DateLastAddRecipe,
                                eatenFoodbyName, cookedDishesbyName);

        Date birthday(2000, 1, 2, 0, 30, 0, true);
        Gender gender{Gender::Male};
        Health health{Health::Bad};
        Tool favorite("vilka");
        Temperature favoriteT{Temperature::Hot};

        PersonDescription Pdescription(25, birthday, gender, health, "eag", favorite, favoriteT, "really god person");

        Person anton(750, "Anton", metadata, Pdescription);
        Person anton2(50, "Anton", metadata, Pdescription);

        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")};
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Ingredient>> ingrr1;
        ingrr1.reserve(3);
        ingrr1.push_back(std::make_unique<Ingredient>("mork", Date(), Weight(5, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<EdibleUnit>("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool));
        ingrr1.push_back(std::make_unique<Ingredient>("flour", Date(), Weight(1, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<Ingredient>("bean", Date(), Weight(1, Measur::Kilogram)));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr2;
        ingrr2.reserve(3);
        ingrr2.push_back(std::make_unique<Liquid>("milk", Date(), Weight(1, Measur::Liter), 200, Temperature::Cold, 1000));
        ingrr2.push_back(std::make_unique<EdibleUnit>("egg", Date(), Weight(6, Measur::Piece), 200, Temperature::Cold));
        ingrr2.push_back(std::make_unique<EdibleUnit>("spaghetti", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Cold));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr3;
        ingrr3.reserve(2);
        ingrr3.push_back(std::make_unique<EdibleUnit>("crab", Date(), Weight(2, Measur::Piece), 200, Temperature::Freezing));
        ingrr3.push_back(std::make_unique<EdibleUnit>("icecreame", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Freezing));

        std::vector<std::unique_ptr<Utensil>> utensils;
        utensils.reserve(4);
        utensils.push_back(std::make_unique<Utensil>("pan", StateOfPurity::QuiteDirty));
        utensils.push_back(std::make_unique<Utensil>("wok"));
        utensils.push_back(std::make_unique<Utensil>("board", StateOfPurity::QuiteDirty));
        utensils.push_back(std::make_unique<Utensil>("bowl", StateOfPurity::Dirty));

        std::vector<std::unique_ptr<Tool>> tools;
        tools.reserve(4);
        tools.push_back(std::make_unique<Tool>("spoon"));
        tools.push_back(std::make_unique<Tool>("knife", StateOfPurity::QuiteDirty));
        tools.push_back(std::make_unique<Tool>("vilka", StateOfPurity::QuiteDirty));
        tools.push_back(std::make_unique<Tool>("kitchen spatula"));

        std::vector<std::unique_ptr<KitchenUnit>> unitss1;
        unitss1.reserve(10);
        unitss1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<ToolStorage>(std::move(tools), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ToolStorage"));
        unitss1.push_back(std::make_unique<UtensilStorage>(std::move(utensils), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "UtensilStorage"));
        unitss1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<Cupboard>(std::move(ingrr1), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage"));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr2), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Cold));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr3), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Freezing));
        unitss1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("table", KitchenUnitDescription(1102, company, "best oven", Date())));

        KitchenDescription kdescription(Size::Large, true, true, true, true, "mega kitchen");

        Kitchen kitchen1(std::move(unitss1), kdescription);

        std::vector<Ingredient> ingr1 =
            {
                Ingredient("mork", Date(), Weight(1, Measur::Kilogram))};
        std::string kUnit1{"table"};
        std::string tUnit1{"knife"};
        std::string uUnit1{"board"};

        int complx1 = 700;
        std::string name1 = "Peel";

        std::vector<Ingredient> ingr2 =
            {
                Ingredient("__Peel_1kg_mork", Date(), Weight(1, Measur::Piece))};
        std::string kUnit2{"stove"};
        std::string tUnit2{"vilka"};
        std::string uUnit2{"pan"};

        int complx2 = 700;
        std::string name2 = "Fry";

        std::vector<Step> steps =
            {
                Step(ingr1, kUnit1, tUnit1, uUnit1, complx1, name1),
                Step(ingr2, kUnit2, tUnit2, uUnit2, complx2, name2)};

        EdibleUnit dish("fry_mork", Date(), Weight(900, Measur::Gram), 150, Temperature::Cool);

        RecipeDescription note(Grade::z4_0, "Italian fry mork", "Jenius", "The best fry mork by good cooker");

        Recipe recipe(steps, dish, note);

        std::vector<Ingredient> ingrSalad1 =
            {
                Ingredient("potato", Date(), Weight(500, Measur::Gram)),
                Ingredient("carrot", Date(), Weight(200, Measur::Gram)),
                Ingredient("egg", Date(), Weight(4, Measur::Piece)),
                Ingredient("pickle", Date(), Weight(300, Measur::Gram)),
                Ingredient("canned_peas", Date(), Weight(200, Measur::Gram)),
                Ingredient("sausage", Date(), Weight(300, Measur::Gram))};
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
                Step(ingrSalad2, kUnitSalad2, tUnitSalad2, uUnitSalad2, complxSalad2, nameSalad2)};
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
                Ingredient("baking_powder", Date(), Weight(10, Measur::Gram))};
        std::string kUnitCake1{"table"};
        std::string tUnitCake1{"mixer"};
        std::string uUnitCake1{"bowl"};
        int complxCake1 = 75;
        std::string nameCake1 = "Mix";
        std::vector<Ingredient> ingrCake2 =
            {
                Ingredient("__Mix_200g_flour_200g_sugar_50g_cocoa_powder_3pc_egg_100ml_milk_100g_butter_10g_baking_powder", Date(), Weight(1, Measur::Piece))};
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
                Ingredient("berries", Date(), Weight(150, Measur::Gram))};
        std::string kUnitCake3{"table"};
        std::string tUnitCake3{"spatula"};
        std::string uUnitCake3{"cake_stand"};
        int complxCake3 = 85;
        std::string nameCake3 = "Decorate";
        std::vector<Step> stepsCake =
            {
                Step(ingrCake1, kUnitCake1, tUnitCake1, uUnitCake1, complxCake1, nameCake1),
                Step(ingrCake2, kUnitCake2, tUnitCake2, uUnitCake2, complxCake2, nameCake2),
                Step(ingrCake3, kUnitCake3, tUnitCake3, uUnitCake3, complxCake3, nameCake3)};
        EdibleUnit dishCake("chocolate_cake", Date(), Weight(900, Measur::Gram), 400, Temperature::Cold);
        RecipeDescription noteCake(Grade::z4_0, "Chocolate Dream Cake", "Dessert Master",
                                   "Moist chocolate cake with ganache and fresh berries");

        Recipe recipeCake(stepsCake, dishCake, noteCake);

        std::map<std::string, Recipe> recipes =
            {
                {"Italian fry mork", recipe},
                {"olivier_salad", recipeSalad},
                {"chocolate_cake", recipeCake}};

        Certification certification("importent", "very importent");
        CookingBookDescription description(Grade::z3_0, certification, "some book", "book with 1 recipe");
        CookingBook book(recipes, description);

        Cooking cooking(anton, std::move(kitchen1), book, Date(2025, 5, 1, 12, 0, 0, true));

        cooking.Cook(cooking.getRecipes().getRecipeByName("Italian fry mork"));
        cooking.Sleep();
        Date lastdate(2025, 5, 2, 7, 0, 0, true);

        CHECK(cooking.getDate() == lastdate);
        CHECK_EQUAL(cooking.getCook().getXP(), 759);
        CHECK_EQUAL(cooking.getCook().getEnergy(), 85);
        CHECK_EQUAL(cooking.getCook().getMetaData().getSleptNights(), 6);
    }

    TEST(Cooking_WashDish)
    {
        Date DateLastCooked(2001, 1, 1, 1, 0, 0, true);
        Date DateLastEaten(2002, 1, 1, 1, 0, 0, true);
        Date DateLastRemoving(2003, 1, 1, 1, 0, 0, true);
        Date DateLastWash(2004, 1, 1, 1, 0, 0, true);
        Date DateLastAddRecipe(2005, 1, 1, 1, 0, 0, true);

        std::map<std::string, int> cookedDishesbyName = {
            {"eag", 5},
            {"soup", 2}};
        std::map<std::string, int> eatenFoodbyName{
            {"eag", 4},
            {"chease", 1}};

        PersonMetaData metadata(7, 5, 5, 0, 3, 1, 2, DateLastCooked,
                                DateLastEaten, DateLastRemoving,
                                DateLastWash, DateLastAddRecipe,
                                eatenFoodbyName, cookedDishesbyName);

        Date birthday(2000, 1, 2, 0, 30, 0, true);
        Gender gender{Gender::Male};
        Health health{Health::Bad};
        Tool favorite("vilka");
        Temperature favoriteT{Temperature::Hot};

        PersonDescription Pdescription(25, birthday, gender, health, "eag", favorite, favoriteT, "really god person");

        Person anton(750, "Anton", metadata, Pdescription);
        Person anton2(50, "Anton", metadata, Pdescription);

        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")};
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Ingredient>> ingrr1;
        ingrr1.reserve(3);
        ingrr1.push_back(std::make_unique<Ingredient>("mork", Date(), Weight(5, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<EdibleUnit>("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool));
        ingrr1.push_back(std::make_unique<Ingredient>("flour", Date(), Weight(1, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<Ingredient>("bean", Date(), Weight(1, Measur::Kilogram)));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr2;
        ingrr2.reserve(3);
        ingrr2.push_back(std::make_unique<Liquid>("milk", Date(), Weight(1, Measur::Liter), 200, Temperature::Cold, 1000));
        ingrr2.push_back(std::make_unique<EdibleUnit>("egg", Date(), Weight(6, Measur::Piece), 200, Temperature::Cold));
        ingrr2.push_back(std::make_unique<EdibleUnit>("spaghetti", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Cold));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr3;
        ingrr3.reserve(2);
        ingrr3.push_back(std::make_unique<EdibleUnit>("crab", Date(), Weight(2, Measur::Piece), 200, Temperature::Freezing));
        ingrr3.push_back(std::make_unique<EdibleUnit>("icecreame", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Freezing));

        std::vector<std::unique_ptr<Utensil>> utensils;
        utensils.reserve(4);
        utensils.push_back(std::make_unique<Utensil>("pan", StateOfPurity::QuiteDirty));
        utensils.push_back(std::make_unique<Utensil>("wok", StateOfPurity::SlightlySoiled));
        utensils.push_back(std::make_unique<Utensil>("board", StateOfPurity::QuiteDirty));
        utensils.push_back(std::make_unique<Utensil>("bowl"));

        std::vector<std::unique_ptr<Tool>> tools;
        tools.reserve(4);
        tools.push_back(std::make_unique<Tool>("spoon"));
        tools.push_back(std::make_unique<Tool>("knife", StateOfPurity::QuiteDirty));
        tools.push_back(std::make_unique<Tool>("vilka", StateOfPurity::QuiteDirty));
        tools.push_back(std::make_unique<Tool>("kitchen spatula", StateOfPurity::NearlyClean));

        std::vector<std::unique_ptr<KitchenUnit>> unitss1;
        unitss1.reserve(10);
        unitss1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<ToolStorage>(std::move(tools), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ToolStorage"));
        unitss1.push_back(std::make_unique<UtensilStorage>(std::move(utensils), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "UtensilStorage"));
        unitss1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<Cupboard>(std::move(ingrr1), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage"));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr2), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Cold));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr3), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Freezing));
        unitss1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("table", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<Dishwasher>("dishwasher", KitchenUnitDescription(1102, company, "best oven", Date()), 5, 5));

        KitchenDescription kdescription(Size::Large, true, true, true, true, "mega kitchen");

        Kitchen kitchen1(std::move(unitss1), kdescription);

        std::vector<Ingredient> ingr1 =
            {
                Ingredient("mork", Date(), Weight(1, Measur::Kilogram))};
        std::string kUnit1{"table"};
        std::string tUnit1{"knife"};
        std::string uUnit1{"board"};

        int complx1 = 70;
        std::string name1 = "Peel";

        std::vector<Ingredient> ingr2 =
            {
                Ingredient("__Peel_1kg_mork", Date(), Weight(1, Measur::Piece))};
        std::string kUnit2{"stove"};
        std::string tUnit2{"vilka"};
        std::string uUnit2{"pan"};

        int complx2 = 80;
        std::string name2 = "Fry";

        std::vector<Step> steps =
            {
                Step(ingr1, kUnit1, tUnit1, uUnit1, complx1, name1),
                Step(ingr2, kUnit2, tUnit2, uUnit2, complx2, name2)};

        EdibleUnit dish("fry_mork", Date(), Weight(900, Measur::Gram), 150, Temperature::Cool);

        RecipeDescription note(Grade::z4_0, "Italian fry mork", "Jenius", "The best fry mork by good cooker");

        Recipe recipe(steps, dish, note);

        std::vector<Ingredient> ingrSalad1 =
            {
                Ingredient("potato", Date(), Weight(500, Measur::Gram)),
                Ingredient("carrot", Date(), Weight(200, Measur::Gram)),
                Ingredient("egg", Date(), Weight(4, Measur::Piece)),
                Ingredient("pickle", Date(), Weight(300, Measur::Gram)),
                Ingredient("canned_peas", Date(), Weight(200, Measur::Gram)),
                Ingredient("sausage", Date(), Weight(300, Measur::Gram))};
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
                Step(ingrSalad2, kUnitSalad2, tUnitSalad2, uUnitSalad2, complxSalad2, nameSalad2)};
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
                Ingredient("baking_powder", Date(), Weight(10, Measur::Gram))};
        std::string kUnitCake1{"table"};
        std::string tUnitCake1{"mixer"};
        std::string uUnitCake1{"bowl"};
        int complxCake1 = 75;
        std::string nameCake1 = "Mix";
        std::vector<Ingredient> ingrCake2 =
            {
                Ingredient("__Mix_200g_flour_200g_sugar_50g_cocoa_powder_3pc_egg_100ml_milk_100g_butter_10g_baking_powder", Date(), Weight(1, Measur::Piece))};
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
                Ingredient("berries", Date(), Weight(150, Measur::Gram))};
        std::string kUnitCake3{"table"};
        std::string tUnitCake3{"spatula"};
        std::string uUnitCake3{"cake_stand"};
        int complxCake3 = 85;
        std::string nameCake3 = "Decorate";
        std::vector<Step> stepsCake =
            {
                Step(ingrCake1, kUnitCake1, tUnitCake1, uUnitCake1, complxCake1, nameCake1),
                Step(ingrCake2, kUnitCake2, tUnitCake2, uUnitCake2, complxCake2, nameCake2),
                Step(ingrCake3, kUnitCake3, tUnitCake3, uUnitCake3, complxCake3, nameCake3)};
        EdibleUnit dishCake("chocolate_cake", Date(), Weight(900, Measur::Gram), 400, Temperature::Cold);
        RecipeDescription noteCake(Grade::z4_0, "Chocolate Dream Cake", "Dessert Master",
                                   "Moist chocolate cake with ganache and fresh berries");

        Recipe recipeCake(stepsCake, dishCake, noteCake);

        std::map<std::string, Recipe> recipes =
            {
                {"Italian fry mork", recipe},
                {"olivier_salad", recipeSalad},
                {"chocolate_cake", recipeCake}};

        Certification certification("importent", "very importent");
        CookingBookDescription description(Grade::z3_0, certification, "some book", "book with 1 recipe");
        CookingBook book(recipes, description);

        Cooking cooking(anton, std::move(kitchen1), book, Date(2025, 5, 1, 12, 0, 0, true));

        cooking.Cook(cooking.getRecipes().getRecipeByName("Italian fry mork"));

        cooking.WashDish(std::move(GetSomething::TakeThis<UtensilStorage, KitchenUnit>(cooking.getKitchen().getUnits())->getUnits()),
                         std::move(GetSomething::TakeThis<ToolStorage, KitchenUnit>(cooking.getKitchen().getUnits())->getUnits()));

        Date lastdate(2025, 5, 1, 13, 42, 18, true);

        CHECK(cooking.getDate() == lastdate);
        CHECK_EQUAL(cooking.getCook().getMetaData().getWashedTools(), 6);
        CHECK_EQUAL(cooking.getCook().getMetaData().getWashedUtils(), 5);
        CHECK(cooking.getCook().getMetaData().getDateLastWash() == lastdate);
    }


    TEST(Cooking_RemovingIngredients)
    {
        Date DateLastCooked(2001, 1, 1, 1, 0, 0, true);
        Date DateLastEaten(2002, 1, 1, 1, 0, 0, true);
        Date DateLastRemoving(2003, 1, 1, 1, 0, 0, true);
        Date DateLastWash(2004, 1, 1, 1, 0, 0, true);
        Date DateLastAddRecipe(2005, 1, 1, 1, 0, 0, true);

        std::map<std::string, int> cookedDishesbyName = {
            {"eag", 5},
            {"soup", 2}};
        std::map<std::string, int> eatenFoodbyName{
            {"eag", 4},
            {"chease", 1}};

        PersonMetaData metadata(7, 5, 5, 0, 3, 1, 2, DateLastCooked,
                                DateLastEaten, DateLastRemoving,
                                DateLastWash, DateLastAddRecipe,
                                eatenFoodbyName, cookedDishesbyName);

        Date birthday(2000, 1, 2, 0, 30, 0, true);
        Gender gender{Gender::Male};
        Health health{Health::Bad};
        Tool favorite("vilka");
        Temperature favoriteT{Temperature::Hot};

        PersonDescription Pdescription(25, birthday, gender, health, "eag", favorite, favoriteT, "really god person");

        Person anton(750, "Anton", metadata, Pdescription);
        Person anton2(50, "Anton", metadata, Pdescription);

        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")};
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Ingredient>> ingrr1;
        ingrr1.reserve(3);
        ingrr1.push_back(std::make_unique<Ingredient>("mork", Date(), Weight(5, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<EdibleUnit>("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool));
        ingrr1.push_back(std::make_unique<Ingredient>("flour", Date(2023, 1, 1, 12, 0, 0, true), Weight(1, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<Ingredient>("bean", Date(), Weight(1, Measur::Kilogram)));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr2;
        ingrr2.reserve(3);
        ingrr2.push_back(std::make_unique<Liquid>("milk", Date(2023, 1, 1, 12, 0, 0, true), Weight(1, Measur::Liter), 200, Temperature::Cold, 1000));
        ingrr2.push_back(std::make_unique<EdibleUnit>("egg", Date(), Weight(6, Measur::Piece), 200, Temperature::Cold));
        ingrr2.push_back(std::make_unique<EdibleUnit>("spaghetti", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Cold));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr3;
        ingrr3.reserve(2);
        ingrr3.push_back(std::make_unique<EdibleUnit>("crab", Date(2023, 1, 1, 12, 0, 0, true), Weight(2, Measur::Piece), 200, Temperature::Freezing));
        ingrr3.push_back(std::make_unique<EdibleUnit>("icecreame", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Freezing));

        std::vector<std::unique_ptr<Utensil>> utensils;
        utensils.reserve(4);
        utensils.push_back(std::make_unique<Utensil>("pan", StateOfPurity::QuiteDirty));
        utensils.push_back(std::make_unique<Utensil>("wok"));
        utensils.push_back(std::make_unique<Utensil>("board", StateOfPurity::QuiteDirty));
        utensils.push_back(std::make_unique<Utensil>("bowl", StateOfPurity::Dirty));

        std::vector<std::unique_ptr<Tool>> tools;
        tools.reserve(4);
        tools.push_back(std::make_unique<Tool>("spoon"));
        tools.push_back(std::make_unique<Tool>("knife", StateOfPurity::QuiteDirty));
        tools.push_back(std::make_unique<Tool>("vilka", StateOfPurity::QuiteDirty));
        tools.push_back(std::make_unique<Tool>("kitchen spatula"));

        std::vector<std::unique_ptr<KitchenUnit>> unitss1;
        unitss1.reserve(10);
        unitss1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<ToolStorage>(std::move(tools), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ToolStorage"));
        unitss1.push_back(std::make_unique<UtensilStorage>(std::move(utensils), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "UtensilStorage"));
        unitss1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<Cupboard>(std::move(ingrr1), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage"));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr2), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Cold));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr3), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Freezing));
        unitss1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("table", KitchenUnitDescription(1102, company, "best oven", Date())));

        KitchenDescription kdescription(Size::Large, true, true, true, true, "mega kitchen");

        Kitchen kitchen1(std::move(unitss1), kdescription);

        std::vector<Ingredient> ingr1 =
            {
                Ingredient("mork", Date(), Weight(1, Measur::Kilogram))};
        std::string kUnit1{"table"};
        std::string tUnit1{"knife"};
        std::string uUnit1{"board"};

        int complx1 = 70;
        std::string name1 = "Peel";

        std::vector<Ingredient> ingr2 =
            {
                Ingredient("__Peel_1kg_mork", Date(), Weight(1, Measur::Piece))};
        std::string kUnit2{"stove"};
        std::string tUnit2{"vilka"};
        std::string uUnit2{"pan"};

        int complx2 = 80;
        std::string name2 = "Fry";

        std::vector<Step> steps =
            {
                Step(ingr1, kUnit1, tUnit1, uUnit1, complx1, name1),
                Step(ingr2, kUnit2, tUnit2, uUnit2, complx2, name2)};

        EdibleUnit dish("fry_mork", Date(), Weight(900, Measur::Gram), 150, Temperature::Cool);

        RecipeDescription note(Grade::z4_0, "Italian fry mork", "Jenius", "The best fry mork by good cooker");

        Recipe recipe(steps, dish, note);

        std::vector<Ingredient> ingrSalad1 =
            {
                Ingredient("potato", Date(), Weight(500, Measur::Gram)),
                Ingredient("carrot", Date(), Weight(200, Measur::Gram)),
                Ingredient("egg", Date(), Weight(4, Measur::Piece)),
                Ingredient("pickle", Date(), Weight(300, Measur::Gram)),
                Ingredient("canned_peas", Date(), Weight(200, Measur::Gram)),
                Ingredient("sausage", Date(), Weight(300, Measur::Gram))};
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
                Step(ingrSalad2, kUnitSalad2, tUnitSalad2, uUnitSalad2, complxSalad2, nameSalad2)};
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
                Ingredient("baking_powder", Date(), Weight(10, Measur::Gram))};
        std::string kUnitCake1{"table"};
        std::string tUnitCake1{"mixer"};
        std::string uUnitCake1{"bowl"};
        int complxCake1 = 75;
        std::string nameCake1 = "Mix";
        std::vector<Ingredient> ingrCake2 =
            {
                Ingredient("__Mix_200g_flour_200g_sugar_50g_cocoa_powder_3pc_egg_100ml_milk_100g_butter_10g_baking_powder", Date(), Weight(1, Measur::Piece))};
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
                Ingredient("berries", Date(), Weight(150, Measur::Gram))};
        std::string kUnitCake3{"table"};
        std::string tUnitCake3{"spatula"};
        std::string uUnitCake3{"cake_stand"};
        int complxCake3 = 85;
        std::string nameCake3 = "Decorate";
        std::vector<Step> stepsCake =
            {
                Step(ingrCake1, kUnitCake1, tUnitCake1, uUnitCake1, complxCake1, nameCake1),
                Step(ingrCake2, kUnitCake2, tUnitCake2, uUnitCake2, complxCake2, nameCake2),
                Step(ingrCake3, kUnitCake3, tUnitCake3, uUnitCake3, complxCake3, nameCake3)};
        EdibleUnit dishCake("chocolate_cake", Date(), Weight(900, Measur::Gram), 400, Temperature::Cold);
        RecipeDescription noteCake(Grade::z4_0, "Chocolate Dream Cake", "Dessert Master",
                                   "Moist chocolate cake with ganache and fresh berries");

        Recipe recipeCake(stepsCake, dishCake, noteCake);

        std::map<std::string, Recipe> recipes =
            {
                {"Italian fry mork", recipe},
                {"olivier_salad", recipeSalad},
                {"chocolate_cake", recipeCake}};

        Certification certification("importent", "very importent");
        CookingBookDescription description(Grade::z3_0, certification, "some book", "book with 1 recipe");
        CookingBook book(recipes, description);

        Cooking cooking(anton, std::move(kitchen1), book, Date(2024, 1, 1, 12, 0, 0, true));

        cooking.RemoveSpoiledFood();

        CHECK_EQUAL(false, StepChecker::CheckIngredient(Ingredient("flour", Date(2023, 1, 1, 12, 0, 0, true), Weight(1, Measur::Kilogram)), cooking.getKitchen().getUnits()));
        CHECK_EQUAL(false, StepChecker::CheckIngredient(Liquid("milk", Date(2023, 1, 1, 12, 0, 0, true), Weight(1, Measur::Liter), 200, Temperature::Cold, 1000), cooking.getKitchen().getUnits()));
        CHECK_EQUAL(false, StepChecker::CheckIngredient(EdibleUnit("crab", Date(2023, 1, 1, 12, 0, 0, true), Weight(2, Measur::Piece), 200, Temperature::Freezing), cooking.getKitchen().getUnits()));
        CHECK_EQUAL(true, StepChecker::CheckIngredient(Ingredient("flour", Date(2023, 1, 1, 12, 0, 0, true), Weight(0, Measur::Kilogram)), cooking.getKitchen().getUnits()));
        CHECK_EQUAL(true, StepChecker::CheckIngredient(Liquid("milk", Date(2023, 1, 1, 12, 0, 0, true), Weight(0, Measur::Liter), 200, Temperature::Cold, 1000), cooking.getKitchen().getUnits()));
        CHECK_EQUAL(true, StepChecker::CheckIngredient(EdibleUnit("crab", Date(2023, 1, 1, 12, 0, 0, true), Weight(0, Measur::Piece), 200, Temperature::Freezing), cooking.getKitchen().getUnits()));
        CHECK_EQUAL(cooking.getCook().getMetaData().getRemovedIngredient(), 6);
        CHECK(cooking.getCook().getMetaData().getDateLastRemoving() == cooking.getDate());
    }


    TEST(Cooking_AddRecipe)
    {
        Date DateLastCooked(2001, 1, 1, 1, 0, 0, true);
        Date DateLastEaten(2002, 1, 1, 1, 0, 0, true);
        Date DateLastRemoving(2003, 1, 1, 1, 0, 0, true);
        Date DateLastWash(2004, 1, 1, 1, 0, 0, true);
        Date DateLastAddRecipe(2005, 1, 1, 1, 0, 0, true);

        std::map<std::string, int> cookedDishesbyName = {
            {"eag", 5},
            {"soup", 2}};
        std::map<std::string, int> eatenFoodbyName{
            {"eag", 4},
            {"chease", 1}};

        PersonMetaData metadata(7, 5, 5, 0, 3, 1, 2, DateLastCooked,
                                DateLastEaten, DateLastRemoving,
                                DateLastWash, DateLastAddRecipe,
                                eatenFoodbyName, cookedDishesbyName);

        Date birthday(2000, 1, 2, 0, 30, 0, true);
        Gender gender{Gender::Male};
        Health health{Health::Bad};
        Tool favorite("vilka");
        Temperature favoriteT{Temperature::Hot};

        PersonDescription Pdescription(25, birthday, gender, health, "eag", favorite, favoriteT, "really god person");

        Person anton(22001, "Anton", metadata, Pdescription);
        Person anton2(50, "Anton", metadata, Pdescription);

        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")};
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Ingredient>> ingrr1;
        ingrr1.reserve(3);
        ingrr1.push_back(std::make_unique<Ingredient>("mork", Date(), Weight(5, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<EdibleUnit>("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool));
        ingrr1.push_back(std::make_unique<Ingredient>("flour", Date(2023, 1, 1, 12, 0, 0, true), Weight(1, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<Ingredient>("bean", Date(), Weight(1, Measur::Kilogram)));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr2;
        ingrr2.reserve(3);
        ingrr2.push_back(std::make_unique<Liquid>("milk", Date(2023, 1, 1, 12, 0, 0, true), Weight(1, Measur::Liter), 200, Temperature::Cold, 1000));
        ingrr2.push_back(std::make_unique<EdibleUnit>("egg", Date(), Weight(6, Measur::Piece), 200, Temperature::Cold));
        ingrr2.push_back(std::make_unique<EdibleUnit>("spaghetti", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Cold));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr3;
        ingrr3.reserve(2);
        ingrr3.push_back(std::make_unique<EdibleUnit>("crab", Date(2023, 1, 1, 12, 0, 0, true), Weight(2, Measur::Piece), 200, Temperature::Freezing));
        ingrr3.push_back(std::make_unique<EdibleUnit>("icecreame", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Freezing));

        std::vector<std::unique_ptr<Utensil>> utensils;
        utensils.reserve(4);
        utensils.push_back(std::make_unique<Utensil>("pan", StateOfPurity::QuiteDirty));
        utensils.push_back(std::make_unique<Utensil>("wok"));
        utensils.push_back(std::make_unique<Utensil>("board", StateOfPurity::QuiteDirty));
        utensils.push_back(std::make_unique<Utensil>("bowl", StateOfPurity::Dirty));

        std::vector<std::unique_ptr<Tool>> tools;
        tools.reserve(4);
        tools.push_back(std::make_unique<Tool>("spoon"));
        tools.push_back(std::make_unique<Tool>("knife", StateOfPurity::QuiteDirty));
        tools.push_back(std::make_unique<Tool>("vilka", StateOfPurity::QuiteDirty));
        tools.push_back(std::make_unique<Tool>("kitchen spatula"));

        std::vector<std::unique_ptr<KitchenUnit>> unitss1;
        unitss1.reserve(10);
        unitss1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<ToolStorage>(std::move(tools), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ToolStorage"));
        unitss1.push_back(std::make_unique<UtensilStorage>(std::move(utensils), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "UtensilStorage"));
        unitss1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<Cupboard>(std::move(ingrr1), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage"));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr2), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Cold));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr3), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Freezing));
        unitss1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("table", KitchenUnitDescription(1102, company, "best oven", Date())));

        KitchenDescription kdescription(Size::Large, true, true, true, true, "mega kitchen");

        Kitchen kitchen1(std::move(unitss1), kdescription);

        std::vector<Ingredient> ingr1 =
            {
                Ingredient("mork", Date(), Weight(1, Measur::Kilogram))};
        std::string kUnit1{"table"};
        std::string tUnit1{"knife"};
        std::string uUnit1{"board"};

        int complx1 = 70;
        std::string name1 = "Peel";

        std::vector<Ingredient> ingr2 =
            {
                Ingredient("__Peel_1kg_mork", Date(), Weight(1, Measur::Piece))};
        std::string kUnit2{"stove"};
        std::string tUnit2{"vilka"};
        std::string uUnit2{"pan"};

        int complx2 = 80;
        std::string name2 = "Fry";

        std::vector<Step> steps =
            {
                Step(ingr1, kUnit1, tUnit1, uUnit1, complx1, name1),
                Step(ingr2, kUnit2, tUnit2, uUnit2, complx2, name2)};

        EdibleUnit dish("fry_mork", Date(), Weight(900, Measur::Gram), 150, Temperature::Cool);

        RecipeDescription note(Grade::z4_0, "Italian fry mork", "Jenius", "The best fry mork by good cooker");

        Recipe recipe(steps, dish, note);

        std::vector<Ingredient> ingrSalad1 =
            {
                Ingredient("potato", Date(), Weight(500, Measur::Gram)),
                Ingredient("carrot", Date(), Weight(200, Measur::Gram)),
                Ingredient("egg", Date(), Weight(4, Measur::Piece)),
                Ingredient("pickle", Date(), Weight(300, Measur::Gram)),
                Ingredient("canned_peas", Date(), Weight(200, Measur::Gram)),
                Ingredient("sausage", Date(), Weight(300, Measur::Gram))};
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
                Step(ingrSalad2, kUnitSalad2, tUnitSalad2, uUnitSalad2, complxSalad2, nameSalad2)};
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
                Ingredient("baking_powder", Date(), Weight(10, Measur::Gram))};
        std::string kUnitCake1{"table"};
        std::string tUnitCake1{"mixer"};
        std::string uUnitCake1{"bowl"};
        int complxCake1 = 75;
        std::string nameCake1 = "Mix";
        std::vector<Ingredient> ingrCake2 =
            {
                Ingredient("__Mix_200g_flour_200g_sugar_50g_cocoa_powder_3pc_egg_100ml_milk_100g_butter_10g_baking_powder", Date(), Weight(1, Measur::Piece))};
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
                Ingredient("berries", Date(), Weight(150, Measur::Gram))};
        std::string kUnitCake3{"table"};
        std::string tUnitCake3{"spatula"};
        std::string uUnitCake3{"cake_stand"};
        int complxCake3 = 85;
        std::string nameCake3 = "Decorate";
        std::vector<Step> stepsCake =
            {
                Step(ingrCake1, kUnitCake1, tUnitCake1, uUnitCake1, complxCake1, nameCake1),
                Step(ingrCake2, kUnitCake2, tUnitCake2, uUnitCake2, complxCake2, nameCake2),
                Step(ingrCake3, kUnitCake3, tUnitCake3, uUnitCake3, complxCake3, nameCake3)};
        EdibleUnit dishCake("chocolate_cake", Date(), Weight(900, Measur::Gram), 400, Temperature::Cold);
        RecipeDescription noteCake(Grade::z4_0, "Chocolate Dream Cake", "Dessert Master",
                                   "Moist chocolate cake with ganache and fresh berries");

        Recipe recipeCake(stepsCake, dishCake, noteCake);

        std::map<std::string, Recipe> recipes =
            {
                {"Italian fry mork", recipe},
                {"olivier_salad", recipeSalad}};

        Certification certification("importent", "very importent");
        CookingBookDescription description(Grade::z3_0, certification, "some book", "book with 1 recipe");
        CookingBook book(recipes, description);

        Cooking cooking(anton, std::move(kitchen1), book, Date(2024, 1, 1, 12, 0, 0, true));

        std::string nameRecipe = "chocolate_cake";

        cooking.AddRecipe(nameRecipe, recipeCake);

        Date lastdate(2024, 1, 1, 12, 5, 0, true);

        CHECK(std::find(cooking.getRecipes().getAllRecipes().begin(), cooking.getRecipes().getAllRecipes().end(), "chocolate_cake") != cooking.getRecipes().getAllRecipes().end());
        CHECK(cooking.getDate() == lastdate);
        CHECK_EQUAL(cooking.getCook().getMetaData().getAddedRecipe(), 1);
        CHECK(cooking.getCook().getMetaData().getDateLastAddRecipe() == lastdate);
    }


    TEST(Cooking_PickUPSupplier)
    {
        Date DateLastCooked(2001, 1, 1, 1, 0, 0, true);
        Date DateLastEaten(2002, 1, 1, 1, 0, 0, true);
        Date DateLastRemoving(2003, 1, 1, 1, 0, 0, true);
        Date DateLastWash(2004, 1, 1, 1, 0, 0, true);
        Date DateLastAddRecipe(2005, 1, 1, 1, 0, 0, true);

        std::map<std::string, int> cookedDishesbyName = {
            {"eag", 5},
            {"soup", 2}};
        std::map<std::string, int> eatenFoodbyName{
            {"eag", 4},
            {"chease", 1}};

        PersonMetaData metadata(7, 5, 5, 0, 3, 1, 2, DateLastCooked,
                                DateLastEaten, DateLastRemoving,
                                DateLastWash, DateLastAddRecipe,
                                eatenFoodbyName, cookedDishesbyName);

        Date birthday(2000, 1, 2, 0, 30, 0, true);
        Gender gender{Gender::Male};
        Health health{Health::Bad};
        Tool favorite("vilka");
        Temperature favoriteT{Temperature::Hot};

        PersonDescription Pdescription(25, birthday, gender, health, "eag", favorite, favoriteT, "really god person");

        Person anton(750, "Anton", metadata, Pdescription);
        Person anton2(50, "Anton", metadata, Pdescription);

        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")};
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Ingredient>> ingrr1;
        ingrr1.reserve(3);
        ingrr1.push_back(std::make_unique<Ingredient>("mork", Date(), Weight(5, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<EdibleUnit>("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool));
        ingrr1.push_back(std::make_unique<Ingredient>("flour", Date(), Weight(1, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<Ingredient>("bean", Date(), Weight(1, Measur::Kilogram)));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr2;
        ingrr2.reserve(3);
        ingrr2.push_back(std::make_unique<Liquid>("milk", Date(), Weight(1, Measur::Liter), 200, Temperature::Cold, 1000));
        ingrr2.push_back(std::make_unique<EdibleUnit>("egg", Date(), Weight(6, Measur::Piece), 200, Temperature::Cold));
        ingrr2.push_back(std::make_unique<EdibleUnit>("spaghetti", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Cold));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr3;
        ingrr3.reserve(2);
        ingrr3.push_back(std::make_unique<EdibleUnit>("crab", Date(), Weight(2, Measur::Piece), 200, Temperature::Freezing));
        ingrr3.push_back(std::make_unique<EdibleUnit>("icecreame", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Freezing));

        std::vector<std::unique_ptr<Utensil>> utensils;
        utensils.reserve(4);
        utensils.push_back(std::make_unique<Utensil>("pan", StateOfPurity::QuiteDirty));
        utensils.push_back(std::make_unique<Utensil>("wok", StateOfPurity::SlightlySoiled));
        utensils.push_back(std::make_unique<Utensil>("board", StateOfPurity::QuiteDirty));
        utensils.push_back(std::make_unique<Utensil>("bowl"));

        std::vector<std::unique_ptr<Tool>> tools;
        tools.reserve(4);
        tools.push_back(std::make_unique<Tool>("spoon"));
        tools.push_back(std::make_unique<Tool>("knife", StateOfPurity::QuiteDirty));
        tools.push_back(std::make_unique<Tool>("vilka", StateOfPurity::QuiteDirty));
        tools.push_back(std::make_unique<Tool>("kitchen spatula", StateOfPurity::NearlyClean));

        std::vector<std::unique_ptr<KitchenUnit>> unitss1;
        unitss1.reserve(10);
        unitss1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<ToolStorage>(std::move(tools), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ToolStorage"));
        unitss1.push_back(std::make_unique<UtensilStorage>(std::move(utensils), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "UtensilStorage"));
        unitss1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<Cupboard>(std::move(ingrr1), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage"));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr2), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Cold));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr3), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Freezing));
        unitss1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("table", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<Dishwasher>("dishwasher", KitchenUnitDescription(1102, company, "best oven", Date()), 5, 5));

        KitchenDescription kdescription(Size::Large, true, true, true, true, "mega kitchen");

        Kitchen kitchen1(std::move(unitss1), kdescription);

        std::vector<Ingredient> ingr1 =
            {
                Ingredient("mork", Date(), Weight(1, Measur::Kilogram))};
        std::string kUnit1{"table"};
        std::string tUnit1{"knife"};
        std::string uUnit1{"board"};

        int complx1 = 70;
        std::string name1 = "Peel";

        std::vector<Ingredient> ingr2 =
            {
                Ingredient("__Peel_1kg_mork", Date(), Weight(1, Measur::Piece))};
        std::string kUnit2{"stove"};
        std::string tUnit2{"vilka"};
        std::string uUnit2{"pan"};

        int complx2 = 80;
        std::string name2 = "Fry";

        std::vector<Step> steps =
            {
                Step(ingr1, kUnit1, tUnit1, uUnit1, complx1, name1),
                Step(ingr2, kUnit2, tUnit2, uUnit2, complx2, name2)};

        EdibleUnit dish("fry_mork", Date(), Weight(900, Measur::Gram), 150, Temperature::Cool);

        RecipeDescription note(Grade::z4_0, "Italian fry mork", "Jenius", "The best fry mork by good cooker");

        Recipe recipe(steps, dish, note);

        std::vector<Ingredient> ingrSalad1 =
            {
                Ingredient("potato", Date(), Weight(500, Measur::Gram)),
                Ingredient("carrot", Date(), Weight(200, Measur::Gram)),
                Ingredient("egg", Date(), Weight(4, Measur::Piece)),
                Ingredient("pickle", Date(), Weight(300, Measur::Gram)),
                Ingredient("canned_peas", Date(), Weight(200, Measur::Gram)),
                Ingredient("sausage", Date(), Weight(300, Measur::Gram))};
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
                Step(ingrSalad2, kUnitSalad2, tUnitSalad2, uUnitSalad2, complxSalad2, nameSalad2)};
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
                Ingredient("baking_powder", Date(), Weight(10, Measur::Gram))};
        std::string kUnitCake1{"table"};
        std::string tUnitCake1{"mixer"};
        std::string uUnitCake1{"bowl"};
        int complxCake1 = 75;
        std::string nameCake1 = "Mix";
        std::vector<Ingredient> ingrCake2 =
            {
                Ingredient("__Mix_200g_flour_200g_sugar_50g_cocoa_powder_3pc_egg_100ml_milk_100g_butter_10g_baking_powder", Date(), Weight(1, Measur::Piece))};
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
                Ingredient("berries", Date(), Weight(150, Measur::Gram))};
        std::string kUnitCake3{"table"};
        std::string tUnitCake3{"spatula"};
        std::string uUnitCake3{"cake_stand"};
        int complxCake3 = 85;
        std::string nameCake3 = "Decorate";
        std::vector<Step> stepsCake =
            {
                Step(ingrCake1, kUnitCake1, tUnitCake1, uUnitCake1, complxCake1, nameCake1),
                Step(ingrCake2, kUnitCake2, tUnitCake2, uUnitCake2, complxCake2, nameCake2),
                Step(ingrCake3, kUnitCake3, tUnitCake3, uUnitCake3, complxCake3, nameCake3)};
        EdibleUnit dishCake("chocolate_cake", Date(), Weight(900, Measur::Gram), 400, Temperature::Cold);
        RecipeDescription noteCake(Grade::z4_0, "Chocolate Dream Cake", "Dessert Master",
                                   "Moist chocolate cake with ganache and fresh berries");

        Recipe recipeCake(stepsCake, dishCake, noteCake);

        std::map<std::string, Recipe> recipes =
            {
                {"Italian fry mork", recipe},
                {"olivier_salad", recipeSalad},
                {"chocolate_cake", recipeCake}};

        Certification certification("importent", "very importent");
        CookingBookDescription description(Grade::z3_0, certification, "some book", "book with 1 recipe");
        CookingBook book(recipes, description);

        Cooking cooking(anton, std::move(kitchen1), book, Date(2025, 5, 1, 12, 0, 0, true));

        std::vector<EdibleUnit> supl;
        supl.reserve(3);
        supl.push_back(EdibleUnit("orange", Date(), Weight(700, Measur::Gram), 300, Temperature::Cool));
        supl.push_back(EdibleUnit("icecreame", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Freezing));
        supl.push_back(EdibleUnit("egg", Date(), Weight(2, Measur::Piece), 200, Temperature::Cold));

        std::map<std::string, Date> supplies = {};

        std::string nameSupl = "1 supplier";

        Supplier supplier(company, std::move(supl), supplies, Date(0, 0, 7, 0, 0, 0, false), nameSupl);

        cooking.PickUPSupplier(supplier);

        CHECK_EQUAL(true, StepChecker::CheckIngredient(EdibleUnit("orange", Date(), Weight(700, Measur::Gram), 300, Temperature::Cool), cooking.getKitchen().getUnits()));
        CHECK_EQUAL(true, StepChecker::CheckIngredient(EdibleUnit("icecreame", Date(), Weight(2, Measur::Kilogram), 200, Temperature::Freezing), cooking.getKitchen().getUnits()));
        CHECK_EQUAL(true, StepChecker::CheckIngredient(EdibleUnit("egg", Date(), Weight(2, Measur::Piece), 200, Temperature::Cold), cooking.getKitchen().getUnits()));
        CHECK(cooking.getDate() == supplier.getSupplies()["Anton"]);
    }


    TEST(Cooking_Exception)
    {
        Date DateLastCooked(2001, 1, 1, 1, 0, 0, true);
        Date DateLastEaten(2002, 1, 1, 1, 0, 0, true);
        Date DateLastRemoving(2003, 1, 1, 1, 0, 0, true);
        Date DateLastWash(2004, 1, 1, 1, 0, 0, true);
        Date DateLastAddRecipe(2005, 1, 1, 1, 0, 0, true);

        std::map<std::string, int> cookedDishesbyName = {
            {"eag", 5},
            {"soup", 2}};
        std::map<std::string, int> eatenFoodbyName{
            {"eag", 4},
            {"chease", 1}};

        PersonMetaData metadata(7, 5, 5, 0, 3, 1, 2, DateLastCooked,
                                DateLastEaten, DateLastRemoving,
                                DateLastWash, DateLastAddRecipe,
                                eatenFoodbyName, cookedDishesbyName);

        Date birthday(2000, 1, 2, 0, 30, 0, true);
        Gender gender{Gender::Male};
        Health health{Health::Bad};
        Tool favorite("vilka");
        Temperature favoriteT{Temperature::Hot};

        PersonDescription Pdescription(25, birthday, gender, health, "eag", favorite, favoriteT, "really god person");

        Person anton(750, "Anton", metadata, Pdescription);
        Person anton2(50, "Anton", metadata, Pdescription);

        std::vector<Certification> certifications = {
            Certification("importent", "very importent"),
            Certification("national", "national importent certification")};
        Grade grade = Grade::z4_5;
        Address address("Belarus", "Minsk Region", "Minsk", "Independence Avenue", 55);

        Date date(1978, 4, 23, 12, 0, 0, true);

        Company company(certifications, 1500, 5400100, address, grade, "MegaCompany", "rocket manufacturing company", date);

        std::vector<std::unique_ptr<Ingredient>> ingrr1;
        ingrr1.reserve(3);
        ingrr1.push_back(std::make_unique<Ingredient>("mork", Date(), Weight(10, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<EdibleUnit>("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool));
        ingrr1.push_back(std::make_unique<Ingredient>("flour", Date(), Weight(1, Measur::Kilogram)));
        ingrr1.push_back(std::make_unique<Ingredient>("bean", Date(), Weight(1, Measur::Kilogram)));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr2;
        ingrr2.reserve(3);
        ingrr2.push_back(std::make_unique<Liquid>("milk", Date(), Weight(1, Measur::Liter), 200, Temperature::Cold, 1000));
        ingrr2.push_back(std::make_unique<EdibleUnit>("egg", Date(), Weight(6, Measur::Piece), 200, Temperature::Cold));
        ingrr2.push_back(std::make_unique<EdibleUnit>("spaghetti", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Cold));

        std::vector<std::unique_ptr<EdibleUnit>> ingrr3;
        ingrr3.reserve(2);
        ingrr3.push_back(std::make_unique<EdibleUnit>("crab", Date(), Weight(2, Measur::Piece), 200, Temperature::Freezing));
        ingrr3.push_back(std::make_unique<EdibleUnit>("icecreame", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Freezing));

        std::vector<std::unique_ptr<Utensil>> utensils;
        utensils.reserve(4);
        utensils.push_back(std::make_unique<Utensil>("pan"));
        utensils.push_back(std::make_unique<Utensil>("wok"));
        utensils.push_back(std::make_unique<Utensil>("board"));
        utensils.push_back(std::make_unique<Utensil>("bowl"));

        std::vector<std::unique_ptr<Tool>> tools;
        tools.reserve(4);
        tools.push_back(std::make_unique<Tool>("spoon"));
        tools.push_back(std::make_unique<Tool>("knife"));
        tools.push_back(std::make_unique<Tool>("vilka"));
        tools.push_back(std::make_unique<Tool>("kitchen spatula"));

        std::vector<std::unique_ptr<KitchenUnit>> unitss1;
        unitss1.reserve(10);
        unitss1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<ToolStorage>(std::move(tools), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ToolStorage"));
        unitss1.push_back(std::make_unique<UtensilStorage>(std::move(utensils), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "UtensilStorage"));
        unitss1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<Cupboard>(std::move(ingrr1), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage"));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr2), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Cold));
        unitss1.push_back(std::make_unique<Fridge>(std::move(ingrr3), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ingr storage", Temperature::Freezing));
        unitss1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<KitchenUnit>("table", KitchenUnitDescription(1102, company, "best oven", Date())));
        unitss1.push_back(std::make_unique<Dishwasher>("dishwasher", KitchenUnitDescription(1102, company, "best oven", Date()), 5, 5));

        KitchenDescription kdescription(Size::Large, true, true, true, true, "mega kitchen");

        Kitchen kitchen1(std::move(unitss1), kdescription);

        std::vector<Ingredient> ingr1 =
            {
                Ingredient("mork", Date(), Weight(1, Measur::Kilogram))};
        std::string kUnit1{"table"};
        std::string tUnit1{"knife"};
        std::string uUnit1{"board"};

        int complx1 = 700;
        std::string name1 = "Peel";

        std::vector<Ingredient> ingr2 =
            {
                Ingredient("__Peel_1kg_mork", Date(), Weight(1, Measur::Piece))};
        std::string kUnit2{"stove"};
        std::string tUnit2{"vilka"};
        std::string uUnit2{"pan"};

        int complx2 = 700;
        std::string name2 = "Fry";

        std::vector<Step> steps =
            {
                Step(ingr1, kUnit1, tUnit1, uUnit1, complx1, name1),
                Step(ingr2, kUnit2, tUnit2, uUnit2, complx2, name2)};

        EdibleUnit dish("fry_mork", Date(), Weight(900, Measur::Gram), 150, Temperature::Cool);

        RecipeDescription note(Grade::z4_0, "Italian fry mork", "Jenius", "The best fry mork by good cooker");

        Recipe recipe(steps, dish, note);

        std::vector<Ingredient> ingrSalad1 =
            {
                Ingredient("potato", Date(), Weight(500, Measur::Gram)),
                Ingredient("carrot", Date(), Weight(200, Measur::Gram)),
                Ingredient("egg", Date(), Weight(4, Measur::Piece)),
                Ingredient("pickle", Date(), Weight(300, Measur::Gram)),
                Ingredient("canned_peas", Date(), Weight(200, Measur::Gram)),
                Ingredient("sausage", Date(), Weight(300, Measur::Gram))};
        std::string kUnitSalad1{"table"};
        std::string tUnitSalad1{"scapula"};
        std::string uUnitSalad1{"bowl"};
        int complxSalad1 = 4000;
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
                Step(ingrSalad2, kUnitSalad2, tUnitSalad2, uUnitSalad2, complxSalad2, nameSalad2)};
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
                Ingredient("baking_powder", Date(), Weight(10, Measur::Gram))};
        std::string kUnitCake1{"table"};
        std::string tUnitCake1{"mixer"};
        std::string uUnitCake1{"bowl"};
        int complxCake1 = 75;
        std::string nameCake1 = "Mix";
        std::vector<Ingredient> ingrCake2 =
            {
                Ingredient("__Mix_200g_flour_200g_sugar_50g_cocoa_powder_3pc_egg_100ml_milk_100g_butter_10g_baking_powder", Date(), Weight(1, Measur::Piece))};
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
                Ingredient("berries", Date(), Weight(150, Measur::Gram))};
        std::string kUnitCake3{"table"};
        std::string tUnitCake3{"spatula"};
        std::string uUnitCake3{"cake_stand"};
        int complxCake3 = 85;
        std::string nameCake3 = "Decorate";
        std::vector<Step> stepsCake =
            {
                Step(ingrCake1, kUnitCake1, tUnitCake1, uUnitCake1, complxCake1, nameCake1),
                Step(ingrCake2, kUnitCake2, tUnitCake2, uUnitCake2, complxCake2, nameCake2),
                Step(ingrCake3, kUnitCake3, tUnitCake3, uUnitCake3, complxCake3, nameCake3)};
        EdibleUnit dishCake("chocolate_cake", Date(), Weight(900, Measur::Gram), 400, Temperature::Cold);
        RecipeDescription noteCake(Grade::z4_0, "Chocolate Dream Cake", "Dessert Master",
                                   "Moist chocolate cake with ganache and fresh berries");

        Recipe recipeCake(stepsCake, dishCake, noteCake);

        std::map<std::string, Recipe> recipes =
            {
                {"Italian fry mork", recipe},
                {"olivier_salad", recipeSalad}};

        Certification certification("importent", "very importent");
        CookingBookDescription description(Grade::z3_0, certification, "some book", "book with 1 recipe");
        CookingBook book(recipes, description);

        std::string nameRecipe = "chocolate_cake";


        Cooking cooking1(anton, std::move(kitchen1), book, Date(2025, 5, 1, 23, 0, 0, true));

        CHECK_THROW(cooking1.Cook(recipe), CookException);
        CHECK_THROW(cooking1.Eat(EdibleUnit("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool)), CookException);
        cooking1.Sleep();

        CHECK_THROW(cooking1.Cook(recipeSalad), XpException);

        cooking1.Cook(recipe);
        cooking1.WashDish(std::move(GetSomething::TakeThis<UtensilStorage, KitchenUnit>(cooking1.getKitchen().getUnits())->getUnits()),
                          std::move(GetSomething::TakeThis<ToolStorage, KitchenUnit>(cooking1.getKitchen().getUnits())->getUnits()));
        cooking1.Cook(recipe);
        cooking1.Cook(recipe);
        cooking1.Cook(recipe);
        cooking1.Cook(recipe);

        CHECK_THROW(cooking1.Cook(recipe), EnergyException);
        cooking1.Eat(EdibleUnit("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool));
        CHECK_THROW(cooking1.Cook(recipe), StepException);

        CHECK_THROW(cooking1.Eat(EdibleUnit("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cool)), StepException);

        CHECK_THROW(cooking1.AddRecipe(nameRecipe, recipeCake), XpException);


        std::vector<EdibleUnit> supl;
        supl.reserve(3);
        supl.push_back(EdibleUnit("orange", Date(), Weight(700, Measur::Gram), 300, Temperature::Cool));
        supl.push_back(EdibleUnit("icecreame", Date(), Weight(1, Measur::Kilogram), 200, Temperature::Freezing));
        supl.push_back(EdibleUnit("egg", Date(), Weight(2, Measur::Piece), 200, Temperature::Cold));

        std::map<std::string, Date> supplies = 
        {
            {"Anton", Date(2025, 5, 1, 22, 0, 0, true)}
        };

        std::string nameSupl = "1 supplier";

        Supplier supplier(company, std::move(supl), supplies, Date(0, 0, 7, 0, 0, 0, false), nameSupl);

        CHECK_THROW(cooking1.PickUPSupplier(supplier), SupplierException);

        std::vector<std::unique_ptr<KitchenUnit>> dodepunitss1;
        dodepunitss1.reserve(10);
        dodepunitss1.push_back(std::make_unique<KitchenUnit>("oven", KitchenUnitDescription(1102, company, "best oven", Date())));
        dodepunitss1.push_back(std::make_unique<ToolStorage>(std::move(tools), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "ToolStorage"));
        dodepunitss1.push_back(std::make_unique<UtensilStorage>(std::move(utensils), KitchenUnitDescription(1102, company, "best oven", Date()), 50, "UtensilStorage"));
        dodepunitss1.push_back(std::make_unique<KitchenUnit>("mixer", KitchenUnitDescription(1102, company, "best oven", Date())));
        dodepunitss1.push_back(std::make_unique<KitchenUnit>("stove", KitchenUnitDescription(1102, company, "best oven", Date())));
        dodepunitss1.push_back(std::make_unique<KitchenUnit>("grinder", KitchenUnitDescription(1102, company, "best oven", Date())));
        dodepunitss1.push_back(std::make_unique<KitchenUnit>("table", KitchenUnitDescription(1102, company, "best oven", Date())));

        Kitchen dodepkitchen1(std::move(dodepunitss1), kdescription);


        Cooking cooking2(anton, std::move(dodepkitchen1), book, Date(2025, 5, 1, 22, 0, 0, true));

        CHECK_THROW(cooking2.WashDish(std::move(GetSomething::TakeThis<UtensilStorage, KitchenUnit>(cooking1.getKitchen().getUnits())->getUnits()),
                                      std::move(GetSomething::TakeThis<ToolStorage, KitchenUnit>(cooking1.getKitchen().getUnits())->getUnits())),
                    GetSomethingException);
        
        Management manager(cooking2);

        CHECK_THROW(manager.addDish(std::make_unique<EdibleUnit>("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cold)), ManagementException);
        EdibleUnit banan("banana", Date(), Weight(1, Measur::Piece), 300, Temperature::Cold);
        CHECK_THROW(manager.removeIngredient(banan), ManagementException);
    }

}
