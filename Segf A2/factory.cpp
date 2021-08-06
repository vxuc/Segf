#include <iostream>
using namespace std;

class Map;
class Field;
class Obstacle;

class FactoryDesign {
public:
    // ** TODO ** 
    // Add your code here to make a virtual factories for Map, Field and Obstacle.
    FactoryDesign() {};

    static Map* ProduceMap();
    static Field* ProduceField(const int i);
    static Obstacle* ProduceObstacle();
};

class Map {
private:
    Field* m_field;
    Obstacle* m_obstacle;
public:
    Map() : m_field(nullptr), m_obstacle(nullptr) {};
    void AddField(Field* field) { // Add the field into the map.
        m_field = field;
        std::cout << "Added Field" << std::endl;
    }
    void AddObstacle(Obstacle* obstacle) { // Add the obstacle into the map. 
        m_obstacle = obstacle;
        std::cout << "Added Obstacle" << std::endl;
    }
    Field* GetField() {
        return m_field;
    }
    Obstacle* GetObstacle() {
        return m_obstacle;
    }
};

class Field {
private:
    int m_field_no;
public:
    Field(int n) : m_field_no(n) { std::cout << "Field no: " << n << std::endl; };
    int GetFieldNumber() { return m_field_no; }
};

class Obstacle {
public:
    Obstacle() {};
};

Map* FactoryDesign::ProduceMap()
{
    return new Map();
}
Field* FactoryDesign::ProduceField(const int i)
{
    return new Field(i);
}
Obstacle* FactoryDesign::ProduceObstacle()
{
    return new Obstacle();
}

class MergeMap {
private:
    Obstacle* m_obstacle;
public:
    MergeMap() : m_obstacle(nullptr) {};
    Map* CreateMap(FactoryDesign& factory);

    Obstacle* CreateObstacle(FactoryDesign& factory);
    Obstacle* GetObstacle() { return m_obstacle; }

    Map* CreateField(FactoryDesign& factory, const int field_no);
};

Map* MergeMap::CreateMap(FactoryDesign& factory)
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

Obstacle* MergeMap::CreateObstacle(FactoryDesign& factory)
{
    Obstacle* new_obstacle = factory.ProduceObstacle();
    m_obstacle = new_obstacle;
    return new_obstacle;
}

Map* MergeMap::CreateField(FactoryDesign& factory, const int field_no)
{
    Map* map = factory.ProduceMap();
    Field* new_field = factory.ProduceField(field_no);
    map->AddField(new_field);
    return map;
}

//int main(void)
//{
//    //field number variable
//    const int field_no = 5;
//
//    //produce a new field and obstacle using a factory
//    FactoryDesign factory;
//    Field* m_field = factory.ProduceField(field_no);
//    Obstacle* m_obstacle = factory.ProduceObstacle();
//
//    //create a new map and add the newly produced field and obstacle into the map
//    Map* map = new Map();
//    map->AddField(m_field);
//    map->AddObstacle(m_obstacle);
//}