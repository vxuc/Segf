#include "pch.h"
#include "CppUnitTest.h"
#include "../Segf A2/singleton.cpp"
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

	};
}
