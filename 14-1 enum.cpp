#include<iostream>
#include<typeinfo>
using namespace std;
/*
	���� ���� �������� ����ϴ� ������
	�Ϲ����� ����ȯ�� ���� ���ؼ��̴�.

	������ C ��Ÿ�Ϸ� ����ϴ� enum�� ���������� ��ȯ�� ����������,
	���� ���� �������� ����ϸ� ������ �Ǵ� char�������� ����ȯ�� �Ұ����ϴ�.
	���� static_cast���� ����ؼ� ����ȯ�� �� �� �ֱ�� �ϴ�.


	���� ���� ������ ���� ('�� ����', 'b' , 'c'�� �ʱ�ȭ)
		enum class monster_enum : char { monster_a_type, monster_b_type = 'b', monster_c_type = 'c' };


	struct�� Ȱ���� ���� ���� ������ ���� (1, 2, 3���� �ʱ�ȭ)
		enum struct terrain_enum { forest_terrain_type, cyber_terrain_type, urban_terrain_type };

	���� ������ ������ ����
		enum weapon_enum { gun_type, machine_gun_type, arrow_type=10 };
*/

enum class monster_enum : char { monster_a_type, monster_b_type = 'b', monster_c_type = 'c' };

enum struct terrain_enum : int { forest_terrain_type, cyber_terrain_type, urban_terrain_type };

enum weapon_enum { gun_type, machine_gun_type, arrow_type = 10 };

class monster {
public:
	monster(monster_enum monster_type, terrain_enum terrain_type, weapon_enum weapon_type)
		: monster_type_definition(monster_type),
		main_field(terrain_type),
		main_weapon(weapon_type) {}
private:
	monster_enum monster_type_definition;
	terrain_enum main_field;
	weapon_enum main_weapon;

	friend void print_monster_location(monster& mon) {
		switch (mon.main_field) {
		case terrain_enum::forest_terrain_type:
			cout << "�� ����";
			break;
		case terrain_enum::cyber_terrain_type:
			cout << "���̹� ����";
			break;
		case terrain_enum::urban_terrain_type:
			cout << "���� ����";
			break;
		}
	}

	friend void print_monster_weapon(monster& mon) {
		switch (mon.main_weapon) {
		case weapon_enum::gun_type:
			cout << "����";
			break;
		case weapon_enum::machine_gun_type:
			cout << "�����";
			break;
		case weapon_enum::arrow_type:
			cout << "ȭ��";
			break;
		}
	}
};

int main()
{
	monster monster_in_forest = monster(
		monster_enum::monster_a_type,
		terrain_enum::forest_terrain_type,
		gun_type
	);

	monster monster_with_arrow = monster(
		monster_enum::monster_b_type,
		terrain_enum::cyber_terrain_type,
		arrow_type
	);

	cout << "ù ��° ���ʹ� ";
	print_monster_location(monster_in_forest);
	cout << "(��)�� Ȱ�� �����̰�, " << endl;
	print_monster_weapon(monster_in_forest);
	cout << " ���⸦ �ַ� �ٷ��." << endl << endl;
	
	cout << "�� ��° ���ʹ� ";
	print_monster_location(monster_with_arrow);
	cout << "(��)�� Ȱ�� �����̰�, " << endl;
	print_monster_weapon(monster_with_arrow);
	cout << " ���⸦ �ַ� �ٷ��." << endl << endl;
	return 0;
}