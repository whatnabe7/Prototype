// Prototype.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include<map>
#include<vector>
#include<string>


class Cloneable {
public:
	std::string str;
	Cloneable() { str = ""; }
	Cloneable(std::string s) { str = s; }
};

class PrototypeKeeper {
private:
	std::map<std::string, Cloneable> map;
public:
	PrototypeKeeper() {	}
	void addCloneable(std::string key, Cloneable prototype) {
		map.insert(std::map<std::string, Cloneable>::value_type(key, prototype));
	}
	Cloneable getClone(std::string key) {
		return map[key];
	}
};

int main()
{
	PrototypeKeeper pk = PrototypeKeeper();
	std::vector<Cloneable> magic_list;
	pk.addCloneable("fire1", Cloneable("�t�@�C�A"));
	pk.addCloneable("ice1", Cloneable("�u���U�h"));
	pk.addCloneable("thunder1", Cloneable("�T���_�["));

	magic_list.push_back(pk.getClone("fire1"));
	auto fire2 = pk.getClone("fire1");
	fire2.str = "�t�@�C��";
	auto fire3 = pk.getClone("fire1");
	fire3.str = "�t�@�C�K";
	magic_list.push_back(fire2);
	magic_list.push_back(fire3);

    return 0;
}

