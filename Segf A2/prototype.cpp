#include <iostream>
#include <vector>
using namespace std;

class Action {
public:
	virtual Action* clone() = 0;
	virtual string Iam() = 0;
};

class Factory {
public:
	// ** TODO ** Put your code here!
	static Action* do_action(int choice);
	static Action* get_prototype(int choice);

private:
	static Action* s_prototypes[4];
};

int main() {
	vector<Action*> roles;
	int choice;

	while (true)
	{
		cout << "(1)Batman (2)Superman (3)Ironman (0)Go: ";
		cin >> choice;
		if (choice == 0)
			break;
		try {
			roles.push_back(Factory::do_action(choice));
		} catch (exception e) {
			std::cout << e.what() << std::endl;
		}
	}
	for (int i = 0; i < roles.size(); ++i)
		roles[i]->Iam();
	for (int i = 0; i < roles.size(); ++i)
		delete roles[i];
}

class Batman : public Action {
public:
	// ** TODO ** Put your code here!
	string Iam() override {
		cout << "Batman\n";
		return "Batman";
	}
	Action* clone() override {
		return new Batman;
	}
};

class Superman : public Action {
public:
	// ** TODO ** Put your code here! 
	string Iam() override {
		cout << "Superman\n";
		return "Superman";
	}
	Action* clone() override {
		return new Superman;
	}
};

class Ironman : public Action {
public:
	// ** TODO ** Put your code here! 
	string Iam() override {
		cout << "Ironman\n";
		return "Ironman";
	}
	Action* clone() override {
		return new Ironman;
	}
};

Action* Factory::s_prototypes[] = {
 0, new Batman, new Superman, new Ironman
};

Action* Factory::do_action(int choice) {
	if (choice >= sizeof(Factory::s_prototypes) / sizeof(Factory::s_prototypes[0])) {
		throw exception("Invalid Input");
	}
	return Factory::s_prototypes[choice]->clone();
}

Action* Factory::get_prototype(int choice) {
	return Factory::s_prototypes[choice];
}