#include <iostream>
using namespace std;

class Map;
class Field;
class Obstacle;

class Factory {
public:
    // ** TODO ** 
    // Add your code here to make a virtual factdories for Map, Field and Obstacle.

    virtual Map* ProduceMap() = 0;
    virtual Field* ProduceField(const int) = 0;
    virtual Obstacle* ProduceObstacle() = 0;
};

class Map : public Factory {
private:
    // ... 
public:
    Map() {};
    Map* ProduceMap() override {
        std::cout << "Producing map" << std::endl;
    }
    void AddField(Field*) { // Add the field into the map.  
        std::cout << "Added Field" << std::endl;
    }
    void AddObstacle(Obstacle*) { // Add the obstacle into the map. 
        std::cout << "Added Obstacle" << std::endl;
    }
};

class Field : public Factory {
private:
    int m_field_no;
public:
    Field(int n) : m_field_no(n) {};
    Field* ProduceField(const int field_no) override {
        m_field_no = field_no;
        std::cout << "Producing field " << field_no << std::endl;
    }
};

class Obstacle : public Factory {
public:
    Obstacle() {};
    Obstacle* ProduceObstacle() override {
        std::cout << "Producing obstacle" << std::endl;
    }
};

class MergeMap : public Factory {
private:
    // ... 
public:
    MergeMap() {};
    Map* CreateMap(Factory& factory);
};

Map* MergeMap::CreateMap(Factory& factory)
{
    Map* map = factory.ProduceMap();
    Field* first_field = factory.ProduceField(1);
    Field* second_field = factory.ProduceField(2);
    Obstacle* obstacle = factory.ProduceObstacle();
    map->AddField(first_field);
    map->AddField(second_field);
    map->AddObstacle(obstacle);
    return map;
}

int main(void)
{
    Factory* factory;
    MergeMap* mergeMap;
    mergeMap->CreateMap((*factory));
}