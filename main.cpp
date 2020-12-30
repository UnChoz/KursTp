#include<iostream>
#include"stamps.h"
#include<vector>
#include<Windows.h>
#include<fstream>


using namespace std;
int main(void)
{
	setlocale(LC_ALL, "rus");
	vector <stamps*> s; // коллекция марок
	vector <int> rs; // хранит в себе индексы марок с реальными марками
	vector <int> vs; // хранит в себе индексы марок с виртуальными марками
	int counter = 0; //счетчик для коллекции марок
	fstream f("collection.txt");
	bool isopen_flag = true; // флаг того, что файл с коллекцией был открыт
	if (!f.is_open())
	{
		cerr << "Файл с сборником марок не был открыт, будет создан новый файл..." << endl;
		isopen_flag = false;
	}
	f.close();
	int ans;
	while (1)
	{
		cout << "Введите индекс операции:\n|1| - Добавить марку виртуального государства в коллекцию\n|2| - Добавить марку существующего государства в коллекцию" << endl;
		cout << "|3| - выгрузить коллекцию из файла\n|4| - загрузить в файл новую коллекцию\n|0| - выйти" << endl;
		cin >> ans;
		switch (ans)
		{
		case 0:
		{
			cout << "Осуществляется выход из программы..." << endl;
			for (int i = 0; i < s.size(); i++)
			{
				delete s[i];
			}
			s.clear();

			return 0;
		}
		case 1:// добавление марки вг
		{
			int count;
			try
			{
				cout << "Сколько марок будем добавлять? ";  cin >> count; cout << endl;
				if (count < 0)throw "Ошибка: отрицательное число";
			}
			catch (const char* err)
			{
				cerr << "Было введено отрицательное число, возвращение к меню..." << endl;
				break;
			}

			for (int i = 0; i < count; i++)
			{
				s.push_back(new VC());
				s[counter]->createStamp();
				s[counter]->getStamp(cout);
				vs.push_back(counter); counter++;
			}
			break;
		}
		case 2:// добавление марки рг
		{
			int count;
			try
			{
				cout << "Сколько марок будем добавлять? ";  cin >> count; cout << endl;
				if (count < 0)throw "Ошибка: отрицательное число";
			}
			catch (const char* err)
			{
				cerr << "Было введено отрицательное число, возвращение к меню..." << endl;
				break;
			}

			for (int i = 0; i < count; i++)
			{
				s.push_back(new RC());
				s[counter]->createStamp();
				s[counter]->getStamp(cout);
				rs.push_back(counter); counter++;
			}
			break;

		}
		case 3:
		{
			if (isopen_flag == false)
			{
				cerr << "Ошибка открытия файла, необходимо создать новую коллекцию" << endl;
				break;
			}
			else
			{

				f.open("collection.txt", ios_base::in);
				string fs;
				getline(f, fs);
				if (fs.empty()) { cerr << "Файл пуст, добавьте марок к своей коллекции!.." << endl; }
				while (!fs.empty())
				{
					cout << fs << endl;
					getline(f, fs);
				}
				f.close();
			}
			break;
		}
		case 4:
		{
			f.open("Realcollection.txt", ios_base::app);//создаем файл, состоящий только из марок РГ
			for (int i = 0; i < rs.size(); i++)
			{
				s[rs[i]]->getStamp(f);
			}
			f.close();

			f.open("Virtualcollection.txt", ios_base::app);//создаем и загружаем файл, состоящий только из марок ВГ
			for (int i = 0; i < vs.size(); i++)
			{
				s[vs[i]]->getStamp(f);
			}
			f.close();

			f.open("collection.txt", ios_base::out);

			ifstream fin("Realcollection.txt");
			if (!fin.is_open())
			{
				cerr << "Ахтунг! Проблема открытия файла с марками реальных государств на этапе переноса файла в базу общей коллекции." << endl;
				cerr << "Осуществляется выход из процедуры загрузки базы в файл..." << endl; break;
			}
			f << "==================================== Stamps of Real country ====================================" << endl;
			string fs;
			getline(fin, fs);
			while (!fs.empty())
			{
				f << fs << endl;
				getline(fin, fs);
			}
			fin.close();

			fin.open("Virtualcollection.txt");
			if (!fin.is_open())
			{
				cerr << "Ахтунг! Проблема открытия файла с марками виртуальных государств на этапе переноса файла в базу общей коллекции." << endl;
				cerr << "Осуществляется выход из процедуры загрузки базы в файл..." << endl; break;
			}
			f << "==================================== Stamps of Virtual country ====================================" << endl;
			getline(fin, fs);
			while (!fs.empty())
			{
				f << fs << endl;
				getline(fin, fs);
			}
			fin.close();
			f.close();
			cout << "Файлы загружен." << endl;
			break;
		}
		}
		cin.get(); cin.get();
		system("cls");
	}
	cin.get(); cin.get();
	return 0;

}
