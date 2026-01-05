# Лабораторная №2 (кулинария)
### Общая статистика

```
Классы: 77
Поля: 153
Методы: 349
Ассоциации: 92
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
21) !!!!!`CookGuide` : 6, 56 -> Date, Temperature, BookMetadata, RequiredData, BookTags
22) `BookMetadata`: 14, 14 -> Date, Certification, Weight, Grade
23) `BookTags`: 30, 30 -> _
24) `RequiredData`: 3, 3 -> _
25) `CookChecker`: 0, 6 -> Recipe, Kitchen, Date, Ingredient, Supplier
26) `Cooking`: 4, 12 -> Person, Kitchen, CookingBook, Date, Recipe, EdibleUnit, Utensil, Tool, Supplier, StorageUnit
27) `CookLimits`: 0, 1 -> _
28) `Management`: 1, 23 -> Cooking, Date, EdibleUnit, Recipe, Ingredient
29) `EdibleUnit`: 2, 3 -> Temperature
30) `Ingredient`: 2, 4 -> Date, Weight
31) `IngredientCalculate`: 0, 2 -> Ingredient, EdibleUnit
32) `IngredientChecker`: 0, 1 -> Date, Ingredient
33) `Liquid`: 1, 2 -> _
34) `Spice`: 2, 2 -> Grade
35) `Kitchen`: 2, 6 -> KitchenDescription, KitchenUnit
36) `KitchenUnit`: 1, 3 -> KitchenUnitDescription
37) `CookUnit`: 1, 1 -> _
38) `Dishwasher`: 2, 3 -> Utensil, Tool
39) `Cupboard`: 0, 3 -> Ingredient
40) `Fridge`: 1, 4 -> Temperature, EdibleUnit
41) `StorageUnit`: 2, 9 -> T
42) `StorageChecker`: 0, 1 -> StorageUnit
43) `ToolStorage`: 0, 0 -> Tool
44) `UtensilStorage`: 0, 0 -> Utensil
45) `Person`: 5, 7 -> PersonMetaData, PersonDescription, PersonLimits
46) `PersonLimits`: 0, 3 -> _
47) `Chef`: 0, 2 -> _
48) `Step`: 6, 8 -> Ingredient
49) `StepChecker`: 0, 6 -> KitchenUnit, Ingredient
50) `CookingBook`: 2, 7 -> Recipe, CookingBookDescription, Grade
51) `Recipe`: 3, 4 -> EdibleUnit, Step, RecipeDescription
52) `RecipeName`: 0, 1 -> _
53) `Calculate`: 0, 2 -> Recipe
54) `Supplier`: 4, 5 -> Company, Date, EdibleUnit
55) `SupplierChecker`: 0, 1 -> Supplier, Date
56) `Tool`: 2, 5 -> StateOfPurity
57) `Utensil`: 2, 5 -> StateOfPurity

### Тесты

![](images/1.png)
![](images/2.png)
