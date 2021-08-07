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
			//create 2 new objs with the getInstance function
			MyClass* obj1 = MyClass::GetInstance();
			MyClass* obj2 = MyClass::GetInstance();

			//check whether the 2 objs are the same
			Assert::IsTrue(obj1 == obj2);
		}

		TEST_METHOD(SingletonTest2)
		{
			//create 2 new objs with func1 and func2 which returns the address of the new obj respectively
			std::string str1 = func1();
			std::string str2 = func2();

			//check if the 2 objs have the same address
			Assert::AreEqual(str1, str2);
		}

		TEST_METHOD(SingletonTest3)
		{			
			//create a new value variable
			int value = 12;

			//create a new obj with the getInstance function and set the value to the variable
			MyClass* obj1 = MyClass::GetInstance();
			obj1->set_value(value);

			//create another new obj with the getInstance function and get use the get_value function to return its stored value
			MyClass* obj2 = MyClass::GetInstance();
			int value2 = obj2->get_value();

			//check if the value variable is the same as the stored value
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
			//create a new base cake name and price variable
			string baseCakeName = "Cake";
			float baseCakePrice = 40;

			//create a new base case with the cake name and price
			Cake* baseCake = new BaseCake(baseCakeName, baseCakePrice);

			//check whether the base cake name and price variable match the newly created base cake's name and price
			Assert::AreEqual(baseCakeName, baseCake->Serve());
			Assert::AreEqual(baseCakePrice, baseCake->price());

			//create a new chocolate decorated cake using the initial base cake
			Cake* decoratedCake = new ChocolateCake(baseCake);
			string decoratedCakeName = baseCakeName + " decorated with Chocolate ";

			//check whether the name of the new chocolate decorated cake name match the name of a default chocolate decorated cake
			Assert::AreEqual(decoratedCakeName, decoratedCake->Serve());

			//create a variable for the price of the chocolate decorated cake
			float decoratedCakePrice = baseCakePrice + 40;

			//check whether the price of the new chocolate decorated cake match the default chocolate decorated cake price
			Assert::AreEqual(decoratedCakePrice, decoratedCake->price());
		}
		
		TEST_METHOD(PrototypeTest1)
		{
			//choice variable
			int choice = 1;

			//get the default prototype in the choice position and use the Iam function to get the string name
			Action* prototype = Factory::get_prototype(choice);
			string IamString = prototype->Iam();

			//create a new prototype with the do_action function and use the Iam function to get the string name as well
			Action* prototype2 = Factory::do_action(choice);
			string IamString2 = prototype2->Iam();

			//check if both strings are equal
			Assert::AreEqual(IamString, IamString2);
		}

		TEST_METHOD(PrototypeTest2)
		{
			//choice variable with invalid number
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
