#include <iostream>
using namespace std;

// Component  
class Cake
{
public:
	virtual string Serve() = 0;
	virtual float price() = 0;
};

// Concrete Component  
class BaseCake : public Cake
{
private:
	float m_price;
	string m_type;
public:
	// ** TODO ** Put your code here!
	BaseCake(string type, float price) : m_type(type), m_price(price){}
	string Serve()
	{
		return m_type;
	}
	float price()
	{
		return m_price;
	}
};

// Decorator  
class CakeDecorator : public Cake
{
protected:
	Cake* m_Cake;
public:
	CakeDecorator(Cake* baseCake) : m_Cake(baseCake) {}
	string Serve()
	{
		return m_Cake->Serve();
	}
	float price()
	{
		return m_Cake->price();
	}
};

// Concrete Decorator  
class ChocolateCake : public CakeDecorator
{
public:
	ChocolateCake(Cake* baseCake) : CakeDecorator(baseCake) {}
	// ** TODO ** Put your code here! 
	string Serve()
	{
		return m_Cake->Serve() + " decorated with Chocolate ";
	}
	float price()
	{
		return m_Cake->price() + 40;
	}
};

class StrawberryCake : public CakeDecorator
{
public:
	StrawberryCake(Cake* baseCake) : CakeDecorator(baseCake) {}
	string Serve()
	{
		return m_Cake->Serve() + " decorated with Strawberry ";
	}
	float price()
	{
		return m_Cake->price() + 80;
	}
};

//int main()
//{
//	Cake* baseCake = new BaseCake("Cake", 30);
//	cout << "Basic Cake :\n";
//	cout << baseCake->Serve() << endl;
//	cout << "Price of Cake : " << baseCake->price() << endl;
//	Cake* decoratedCake = new ChocolateCake(baseCake);
//	cout << "Chocolate decorated Cake \n";
//	cout << decoratedCake->Serve() << endl;
//	cout << "Price of Chocolate Cake : " << decoratedCake->price() << endl;
//
//	delete decoratedCake;
//	decoratedCake = new StrawberryCake(baseCake);
//	cout << "Strawberry decorated Cake \n";
//	cout << decoratedCake->Serve() << endl;
//	cout << "Price of Strawberry Cake : " << decoratedCake->price() << endl;
//	delete decoratedCake;
//	delete baseCake;
//	return 0;
//}