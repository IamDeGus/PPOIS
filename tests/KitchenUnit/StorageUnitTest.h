// StorageUnitCommonTest.h
#include <UnitTest++/UnitTest++.h>
#include "../../src/KitchenUnit/StorageUnit/StorageUnit.h"
#include "../../src/KitchenUnit/StorageUnit/ToolStorage.h"
#include "../../src/Common/Types/KitchenUnitDescription/KitchenUnitDescription.h"
#include "../../src/Common/Types/Company/Company.h"
#include "../../src/Common/Types/Certification/Certification.h"
#include "../../src/Common/Types/Address/Address.h"
#include "../../src/Common/Types/Date/Date.h"

SUITE(StorageUnitCommonTest)
{
    // Тест на перемещение (move semantics)
    TEST(StorageUnit_MoveConstructor)
    {
        // Создаем простую компанию
        std::vector<Certification> certs = {Certification("test", "test")};
        Address addr("Test", "Test", "Test", "Test", 1);
        Date date(2020, 1, 1, 0, 0, 0, true);
        Company company(certs, 1, 1000, addr, Grade::z1_0, "Test", "test", date);
        
        KitchenUnitDescription desc(1, company, "test", Date());
        
        // Создаем исходный StorageUnit
        std::vector<std::unique_ptr<Tool>> tools;
        tools.push_back(std::make_unique<Tool>("hammer"));
        tools.push_back(std::make_unique<Tool>("screwdriver"));
        
        ToolStorage original(std::move(tools), desc, 10, "original");
        
        // Перемещаем
        ToolStorage moved(std::move(original));
        
        // Проверяем, что moved содержит данные
        CHECK_EQUAL(2, moved.getUnits().size());
        CHECK_EQUAL("hammer", moved.getUnits()[0]->getName());
        CHECK_EQUAL(10, moved.getCapacityTotal());
        CHECK_EQUAL(2, moved.getCapacityUsed());
        CHECK_EQUAL("original", moved.getName());
    }
    
    TEST(StorageUnit_MoveAssignment)
    {
        // Создаем простую компанию
        std::vector<Certification> certs = {Certification("test", "test")};
        Address addr("Test", "Test", "Test", "Test", 1);
        Date date(2020, 1, 1, 0, 0, 0, true);
        Company company(certs, 1, 1000, addr, Grade::z1_0, "Test", "test", date);
        
        KitchenUnitDescription desc(1, company, "test", Date());
        
        // Создаем два StorageUnit
        std::vector<std::unique_ptr<Tool>> tools1;
        tools1.push_back(std::make_unique<Tool>("hammer"));
        
        std::vector<std::unique_ptr<Tool>> tools2;
        tools2.push_back(std::make_unique<Tool>("screwdriver"));
        tools2.push_back(std::make_unique<Tool>("wrench"));
        
        ToolStorage unit1(std::move(tools1), desc, 5, "unit1");
        ToolStorage unit2(std::move(tools2), desc, 10, "unit2");
        
        // Выполняем перемещение
        unit1 = std::move(unit2);
        
        // Проверяем, что unit1 теперь содержит данные из unit2
        CHECK_EQUAL(2, unit1.getUnits().size());
        CHECK_EQUAL("screwdriver", unit1.getUnits()[0]->getName());
        CHECK_EQUAL(10, unit1.getCapacityTotal());
        CHECK_EQUAL("unit2", unit1.getName());
    }
    
    TEST(StorageUnit_EmptyStorage)
    {
        // Создаем простую компанию
        std::vector<Certification> certs = {Certification("test", "test")};
        Address addr("Test", "Test", "Test", "Test", 1);
        Date date(2020, 1, 1, 0, 0, 0, true);
        Company company(certs, 1, 1000, addr, Grade::z1_0, "Test", "test", date);
        
        KitchenUnitDescription desc(1, company, "test", Date());
        
        // Создаем пустое хранилище
        std::vector<std::unique_ptr<Tool>> tools; // пустой вектор
        
        ToolStorage unit(std::move(tools), desc, 10, "empty storage");
        
        // Проверяем
        CHECK_EQUAL(0, unit.getUnits().size());
        CHECK_EQUAL(10, unit.getCapacityTotal());
        CHECK_EQUAL(0, unit.getCapacityUsed());
        CHECK_EQUAL("empty storage", unit.getName());
    }
}
