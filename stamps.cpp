#include "stamps.h"
//методы вирт. класса stamps
void stamps::createStamp()
{
	setCountry();
	setTarget();
	setCharacter();
	setForm();
	setMaterial();
}


ostream& stamps::getStamp(ostream& out)
{
	out << "Это марка государства: " + country << endl;
	out << "Назначение: " + target << endl;
	out << "Характер эмитета: " + character << endl;
	out << "Форма : " + form << endl;
	out << "Материал: " + material << endl;
	return out;
}

//методы класса VC марок виртуального государства

void VC::setCountry() 
{
ret_error:
	try {
		cout << "Название виртуального государства: ";
		cin.get();
		getline(cin, country);
		cout << endl;
		for (int i = 0; i < country.length(); i++)
		{
			if (country[i] > 127 || country[i] < 0 || country.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* errors)
	{
		cerr << errors << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto ret_error;
		goto ret_error;
	}
}
void VC::setTarget()
{
ret_error:
	try {
		cout << "Назначение марки ВГ: ";
		////cin.get();
		getline(cin, target);
		cout << endl;
		for (int i = 0; i < target.length(); i++)
		{
			if (target[i] > 127 || target[i] < 0 || target.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* errors)
	{
		cerr << errors << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto ret_error;
		goto ret_error;
	}
}
void VC::setCharacter()
{
ret_error:
	try {
		cout << "Характер эмитента марки ВГ: ";
		////cin.get();
		getline(cin, character);
		cout << endl;
		for (int i = 0; i < character.length(); i++)
		{
			if (character[i] > 127 || character[i] < 0 || character.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* errors)
	{
		cerr << errors << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto ret_error;
		goto ret_error;
	}
}
void VC::setForm()
{
ret_error:
	try {
		cout << "Форма марки ВГ: ";
		////cin.get();
		getline(cin, form);
		cout << endl;
		for (int i = 0; i < form.length(); i++)
		{
			if (form[i] > 127 || form[i] < 0 || form.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* errors)
	{
		cerr << errors << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto ret_error;
		goto ret_error;
	}
}
void VC::setMaterial()
{
ret_error:
	try {
		cout << "Материал марки ВГ: ";
		////cin.get();
		getline(cin, material);
		cout << endl;
		for (int i = 0; i < material.length(); i++)
		{
			if (material[i] > 127 || material[i] < 0 || material.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* errors)
	{
		cerr << errors << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto ret_error;
		goto ret_error;
	}
}


// методы класса RC марок реального государства

void RC::setCountry() 
{
ret_error:
	try {
		cout << "Название существующего государства: ";
		cin.get();
		getline(cin, country);
		cout << endl;
		for (int i = 0; i < country.length(); i++)
		{
			if (country[i] > 127 || country[i] < 0 || country.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* errors)
	{
		cerr << errors << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto ret_error;
		goto ret_error;
	}
}
void RC::setTarget()
{
ret_error:
	try {
		cout << "Назначение марки СГ: ";
		//cin.get();
		getline(cin, target);
		cout << endl;
		for (int i = 0; i < target.length(); i++)
		{
			if (target[i] > 127 || target[i] < 0 || target.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* errors)
	{
		cerr << errors << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto ret_error;
		goto ret_error;
	}
}
void RC::setCharacter()
{
ret_error:
	try {
		cout << "Характер эмитента марки СГ: ";
		////cin.get();
		getline(cin, character);
		cout << endl;
		for (int i = 0; i < character.length(); i++)
		{
			if (character[i] > 127 || character[i] < 0 || character.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* errors)
	{
		cerr << errors << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto ret_error;
		goto ret_error;
	}
}
void RC::setForm()
{
ret_error:
	try {
		cout << "Форма марки СГ: ";
		//cin.get();
		getline(cin, form);
		cout << endl;
		for (int i = 0; i < form.length(); i++)
		{
			if (form[i] > 127 || form[i] < 0 || form.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* errors)
	{
		cerr << errors << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto ret_error;
		goto ret_error;
	}
}
void RC::setMaterial()
{
ret_error:
	try {
		cout << "Материал марки СГ: ";
		//cin.get();
		getline(cin, material);
		cout << endl;
		for (int i = 0; i < material.length(); i++)
		{
			if (material[i] > 127 || material[i] < 0 || material.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* errors)
	{
		cerr << errors << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto ret_error;
		goto ret_error;
	}
}
