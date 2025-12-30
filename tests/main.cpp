#include <UnitTest++/UnitTest++.h>

// Включаем все тестовые файлы
// Или используйте CMake для автоматического добавления всех .cpp файлов

// #include "Common/AddressTest.h"
// #include "Common/CertificationTest.h"
// #include "Common/CompanyTest.h"
// #include "Common/CookingBookDescriptionTest.h"
// #include "Common/GradeTest.h"
#include "Common/PersonDescriptionTest.h"
// #include "Common/PersonMetaDataTest.h"
// #include "Common/PyrityTest.h"
// #include "Common/RecipeDescriptionTest.h"

#include "Common/DateTest.h"
#include "Common/WeightTest.h"

#include "Common/ITest.h"
// #include "Common/GetSomethingTest.h"

// #include "Tool/ToolTest.h"
// #include "Utensil/UtensilTest.h"

#include "Recipe/StepTest.h"
#include "Recipe/StepCheckerTest.h"
// #include "Recipe/RecipeTest.h"
// #include "Recipe/RecipeCheckerTest.h"
#include "Recipe/CookingBookTest.h"
// #include "Recipe/CalculateTest.h"

// #include "Person/PersonTest.h"
// #include "Person/ChefTest.h"

#include "KitchenUnit/FridgeTest.h"
#include "KitchenUnit/CupboardTest.h"
#include "KitchenUnit/KitchenUnitTest.h"
#include "KitchenUnit/ToolStorageTest.h"
#include "KitchenUnit/UtensilStorageTest.h"
#include "KitchenUnit/StorageUnitTest.h"

#include "Cooking/CookingTest.h"

#include "CookGuide/CookGuideTest.h"


// ...

int main()
{
    return UnitTest::RunAllTests();
}
