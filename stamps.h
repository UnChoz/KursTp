#pragma once
#include<iostream>
#include<string>



using namespace std;
class stamps
{
protected:
	string country;				//название государства
	string target;				//назначение 
	string character;			//характер эмитета ( официальные, неоф., полуоф. частные)
	string form;				//форма
	string material;			//материал
public:

	//виртуальные сеты для всех свойств
	virtual void setCountry() = 0;
	virtual void setTarget() = 0;
	virtual void setCharacter() = 0;
	virtual void setForm() = 0;
	virtual void setMaterial() = 0;

	void createStamp();					//создание марки, вызывает сеты
	ostream& getStamp(ostream& out);	//вывод марок
};


class VC :		//класс virtual country, то есть здесь будут марки виртуальной страны
	public stamps
{
	void setCountry() override;
	void setTarget()override;
	void setCharacter()override;
	void setForm()override;
	void setMaterial()override;
};

class RC :			//класс Real country , то есть марки реальных стран
	public stamps
{
	void setCountry() override;
	void setTarget()override;
	void setCharacter()override;
	void setForm()override;
	void setMaterial()override;
};
