#include <iostream>
#include <string>
using namespace std;
class object_cg
{
private:
    string name;
    double mass;
protected:
    object_cg() :mass(0.0) {}
    object_cg(const object_cg& obj) : name(obj.name), mass(obj.mass) {}
    object_cg(const string& _name, double _mass) : name(_name), mass(_mass) {}
    virtual ~object_cg()
    {
        cout << "object_cg deleted" << endl;
    }
    virtual void _print() const { cout << "Name: " << name << ", mass: " << mass; }
public:
    void print() const
    {
        cout << typeid(*this).name() << ": (";
        _print();
        cout << ")" << endl;
    }
    double get_mass() const
    {
        return mass;
    }
};
class creature : public object_cg
{
private:
    int hp;
    int DPS;
public:
    creature() {}
    creature(const creature& obj) : object_cg(obj), hp(obj.hp), DPS(obj.DPS) {}
    creature(const string& _name, double _mass, int _hp, int _DPS) : object_cg(_name, _mass), hp(_hp), DPS(_DPS) {}
    virtual ~creature()
    {
        cout << "creature deleted" << endl;
    }
    int get_hp() const
    {
        return hp;
    }
    int get_DPS() const
    {
        return DPS;
    }
protected:
    void _print() const
    {
        object_cg::_print();
        cout << ", hp: " << hp;
    }
};
class magicitem :virtual public object_cg
{
private:
    int cost;
public:
    magicitem() {}
    magicitem(const magicitem& obj) : object_cg(obj), cost(obj.cost) {}
    magicitem(const string& _name, double _mass, int _cost) : object_cg(_name, _mass), cost(_cost) {}
    virtual ~magicitem()
    {
        cout << "magicitem deleted" << endl;
    }
protected:
    void _print() const
    {
        object_cg::_print();
        cout << ", cost: " << cost;
    }
};
class magic_bread : public magicitem
{
public:
    magic_bread() :magicitem() {}
    magic_bread(const magic_bread& obj) : magicitem(obj), object_cg(obj) {}
    magic_bread(double _mass, int _cost) : object_cg("sweet_bread", _mass), magicitem("", 0, _cost) {}
    virtual ~magic_bread()
    {
        cout << "magic_bread deleted" << endl;
    }
};
class mythical_animal : public creature
{
private:
    bool Horrific_sight;
public:
    mythical_animal() {}
    mythical_animal(const mythical_animal& obj) : creature(obj), Horrific_sight(obj.Horrific_sight) {}
    mythical_animal(const string& _name, double _mass, int _hp, int _DPS, bool _Horrific_sight) : creature(_name, _mass, _hp, _DPS), Horrific_sight(_Horrific_sight) {}
    virtual ~mythical_animal()
    {
        cout << "mythical_animal deleted" << endl;
    }
    bool battle(const creature& obj)
    {
        return obj.get_DPS() < get_DPS() && obj.get_hp() < get_hp();
    }
protected:
    void _print() const
    {
        creature::_print();
        cout << ", horrific_sight: " << Horrific_sight;
    }
};
class humanoid_character : public creature
{
private:
    bool composure;
public:
    humanoid_character() {}
    humanoid_character(const humanoid_character& obj) : creature(obj), composure(obj.composure) {}
    humanoid_character(const string& _name, double _mass, int _hp, int _DPS, bool _composure) : creature(_name, _mass, _hp, _DPS), composure(_composure) {}
    virtual ~humanoid_character()
    {
        cout << "humanoid_character deleted" << endl;
    }
    bool battle(const creature& obj)
    {
        return obj.get_DPS() < get_DPS() && obj.get_hp() < get_hp();
    }
protected:
    void _print() const
    {
        creature::_print();
        cout << ", composure: " << composure;
    }
};
class magic_character : public creature
{
private:
    bool wind_magic;
public:
    magic_character() {}
    magic_character(const magic_character& obj) : creature(obj), wind_magic(obj.wind_magic) {}
    magic_character(const string& _name, double _mass, int _hp, int _DPS, bool _wind_magic) : creature(_name, _mass, _hp, _DPS), wind_magic(_wind_magic) {}
    virtual ~magic_character()
    {
        cout << "magic_character deleted" << endl;
    }
    bool battle(const creature& obj)
    {
        return obj.get_DPS() < get_DPS() && obj.get_hp() < get_hp();
    }
protected:
    void _print() const
    {
        creature::_print();
        cout << ", wind_magic: " << wind_magic;
    }
};
int main()
{
    setlocale(0, "Rus");
    magic_bread sword(10.5, 100);
    sword.print();
    mythical_animal charybdis("Anduin", 100.0, 1500, 300, true);
    humanoid_character worgen("Zeva", 10.5, 500, 90, false);
    magic_character wizard("Orpheus", 5.5, 600, 150, 30);
    cout << "charybdis vs worgen: " << charybdis.battle(worgen) << endl;
    cout << "worgen vs wizard: " << worgen.battle(wizard) << endl;
    wizard.print();
    return 0;
}
