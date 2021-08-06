#include "pch.h"
#include "CppUnitTest.h"
#include "../Segf A2/singleton.cpp"
#include "../Segf A2/factory.cpp"
#include "../Segf A2/decorator.cpp"
#include "../Segf A2/prototype.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(SingletonTest1)
		{
			//Singleton Test 1
			MyClass* obj1 = MyClass::GetInstance();
			MyClass* obj2 = MyClass::GetInstance();

			Assert::IsTrue(obj1 == obj2);
		}

		TEST_METHOD(SingletonTest2)
		{
			//Singleton Test 2
			std::string str1 = func1();
			std::string str2 = func2();

			Assert::AreEqual(str1, str2);
		}

		TEST_METHOD(SingletonTest3)
		{			
			//Singleton Test 3
			int value = 12;

			MyClass* obj1 = MyClass::GetInstance();
			obj1->set_value(value);

			MyClass* obj2 = MyClass::GetInstance();
			int value2 = obj2->get_value();

			Assert::AreEqual(value, value2);
		}

		TEST_METHOD(FactoryTest1)
		{
			//field number variable
			const int field_no = 5;

			//produce a new field and obstacle using a factory
			FactoryDesign factory;
			Field* m_field = factory.ProduceField(field_no);
			Obstacle* m_obstacle = factory.ProduceObstacle();

			//create a new map and add the newly produced field and obstacle into the map
			Map* map = new Map();
			map->AddField(m_field);
			map->AddObstacle(m_obstacle);

			//check whether the newly produced field and obstacle is equal to the field and obstacle added into the map
			Assert::IsTrue(m_field == map->GetField());
			Assert::IsTrue(m_obstacle == map->GetObstacle());
		}

		TEST_METHOD(FactoryTest2)
		{
			FactoryDesign factory;
			MergeMap mergeMap;
			Obstacle* obstacle = mergeMap.CreateObstacle(factory); //produce a new Obstacle
			
			//check whether the obstacle produced is the same
			Assert::IsTrue(obstacle == mergeMap.GetObstacle());
		}

		TEST_METHOD(FactoryTest3)
		{
			//field number variable
			const int field_no = 10;

			//produce a new field
			FactoryDesign factory;
			Field* field = factory.ProduceField(field_no);

			//check whether the produced field is the same field number as the variable
			Assert::IsTrue(field_no == field->GetFieldNumber());
		}
		
		TEST_METHOD(DecoratorTest1)
		{			
			//Decorator Test 1
			string baseCakeName = "Cake";
			float baseCakePrice = 40;
			Cake* baseCake = new BaseCake(baseCakeName, baseCakePrice);
			Assert::AreEqual(baseCakeName, baseCake->Serve());
			Assert::AreEqual(baseCakePrice, baseCake->price());

			Cake* decoratedCake = new ChocolateCake(baseCake);
			string decoratedCakeName = baseCakeName + " decorated with Chocolate ";
			Assert::AreEqual(decoratedCakeName, decoratedCake->Serve());

			float decoratedCakePrice = baseCakePrice + 40;
			Assert::AreEqual(decoratedCakePrice, decoratedCake->price());
		}
		
		TEST_METHOD(PrototypeTest1)
		{
			//Prototype Test 1
			int choice = 1;

			Action* action = Factory::do_action(choice);
			string iAm = action->Iam();

			Action* action2 = Factory::get_prototype(choice);
			string iAm2 = action2->Iam();

			Assert::AreEqual(iAm, iAm2);
		}

		TEST_METHOD(PrototypeTest2)
		{
			//Prototype Test 1
			int choice = -1;

			//check for invalid choice input
			try {
				Action* action = Factory::do_action(choice);
				string iAm = action->Iam();
			}
			catch (exception e)
			{
				//catch the exception and check if its catching the "invalid input"
				Assert::AreEqual(e.what(), "Invalid Input");
			}
		}
	};
}
