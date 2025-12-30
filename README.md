# Лабораторная №2 (кулинария)
### Общая статистика

```
Классы: 74
Поля: 150
Методы: 302
Ассоциации: 87
Исключения: 13

```

### Классы исключений:
```
Common/Exeptions/CookExeption.h
Common/Exeptions/DateExeption.h
Common/Exeptions/EnergyExeption.h
Common/Exeptions/GetSomethingExeption.h
Common/Exeptions/KitchenUnitExeption.h
Common/Exeptions/ManagementExeption.h
Common/Exeptions/RecipeExeption.h
Common/Exeptions/StepExeption.h
Common/Exeptions/StorageExeption.h
Common/Exeptions/SupplierExeption.h
Common/Exeptions/TypeExeption.h
Common/Exeptions/WeightExeption.h
Common/Exeptions/XpExeption.h

```

### Enum классы:
```
Common/Types/Gender/Gender.h
Common/Types/Grade/Grade.h
Common/Types/Health/Health.h
Common/Types/Size/Size.h
Common/Types/StateOfPurity/StateOfPurity.h
Common/Types/Temperature/Temperature.h
Common/Types/Weight/Measur.h
```

### Классы, их поля, методы и ассоциации
Формат:
`"класс": <кол-во полей>, <кол-во методов> -> [названия классов ассоциаций]`

1) `GetSomething`: 0, 2 -> DerivedType, BaseType
2) `IDateCreate`: 1, 1 -> Date
3) `IDescription`: 1, 1 -> _
4) `INameable`: 1, 1 -> _
5) `Address`: 5, 6 -> _
6) `Certification`: 0, 1 -> _
7) `Company`: 5, 6 -> Certification, Address, Grade
8) `CookingBookDescription`: 2, 3 -> Grade, Certification
9) `Date`: 7, 11 -> _
10) `DateCalculate`: 0, 1 -> Date
11) `DateChecker`: 0, 6 -> _
12) `GradeHelper`: 0, 2 -> Grade
13) `KitchenDescription`: 5, 6 -> Size
14) `KitchenUnitDescription`: 2, 3 -> Company
15) `PersonDescription`: 7, 8 -> Gender, Date, Health, Tool, Temperature
16) `PersonMetaData`: 14, 29 -> Date
17) `RecipeDescription`: 3, 4 -> Grade
18) `PurityHelper`: 0, 2 -> StateOfPurity
19) `Weight`: 2, 13 -> Measur
20) `VectorConverter`: 0, 1 -> Base, Derived
21) `CookGuide`: 50, 56 -> Date, Certification, Weight, Grade
22) `CookChecker`: 0, 6 -> Recipe, Kitchen, Date, Ingredient, Supplier
23) `Cooking`: 4, 12 -> Person, Kitchen, CookingBook, Date, Recipe, EdibleUnit, Utensil, Tool, Supplier, StorageUnit
24) `CookLimits`: 0, 1 -> _
25) `Management`: 1, 23 -> Cooking, Date, EdibleUnit, Recipe, Ingredient
26) `EdibleUnit`: 2, 3 -> Temperature
27) `Ingredient`: 2, 4 -> Date, Weight
28) `IngredientCalculate`: 0, 2 -> Ingredient, EdibleUnit
29) `IngredientChecker`: 0, 1 -> Date, Ingredient
30) `Liquid`: 1, 2 -> _
31) `Spice`: 2, 2 -> Grade
32) `Kitchen`: 2, 6 -> KitchenDescription, KitchenUnit
33) `KitchenUnit`: 1, 3 -> KitchenUnitDescription
34) `CookUnit`: 1, 1 -> _
35) `Dishwasher`: 2, 3 -> Utensil, Tool
36) `Cupboard`: 0, 3 -> Ingredient
37) `Fridge`: 1, 4 -> Temperature, EdibleUnit
38) `StorageUnit`: 2, 9 -> T
39) `StorageChecker`: 0, 1 -> StorageUnit
40) `ToolStorage`: 0, 0 -> Tool
41) `UtensilStorage`: 0, 0 -> Utensil
42) `Person`: 5, 7 -> PersonMetaData, PersonDescription, PersonLimits
43) `PersonLimits`: 0, 3 -> _
44) `Chef`: 0, 2 -> _
45) `Step`: 6, 8 -> Ingredient
46) `StepChecker`: 0, 6 -> KitchenUnit, Ingredient
47) `CookingBook`: 2, 7 -> Recipe, CookingBookDescription, Grade
48) `Recipe`: 3, 4 -> EdibleUnit, Step, RecipeDescription
49) `RecipeName`: 0, 1 -> _
50) `Calculate`: 0, 2 -> Recipe
51) `Supplier`: 4, 5 -> Company, Date, EdibleUnit
52) `SupplierChecker`: 0, 1 -> Supplier, Date
53) `Tool`: 2, 5 -> StateOfPurity
54) `Utensil`: 2, 5 -> StateOfPurity

### Тесты

![](images/1.png)
![](images/2.png)
