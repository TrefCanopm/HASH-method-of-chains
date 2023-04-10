#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>

using namespace std;

struct Element
{
	string FIO = "";
	string data;
	string adress;
	Element* next = nullptr;
};

Element* Mas;
int N = 0;

int Hash(int sum, int HashTable);
int Sum(string str);

void CinElement(int i);
void CinElementK(int i);

void CoutHash(int i);
void Chek(int i);

void Menu();

int main()
{
	setlocale(0, "RUS");
	SetConsoleCP(1251);
	int i, n;
	bool F = 1;
	cout << "Enter the dimension of the hash table" << endl;
	cin >> i;
	Mas = new Element[i];
	while (F)
	{
		Menu();
		cin >> n;
		switch (n)
		{
		case 1:
		{
			CinElement(i);
			break;
		}
		case 2:
		{
			CinElementK(i);
		}
		case 3:
		{
			CoutHash(i);
			break;
		}
		case 4:
		{
			Chek(i);
			break;
		}
		case 5:
			F = 0;
		default:
		{
			cout << "" << endl;
		}
		}
	}
}

void Menu()
{
	cout << "\tMenu" << endl;
	cout << "1) Adding an element to a HASH table" << endl;
	cout << "2) Adding multiple elements to a HASH table" << endl;
	cout << "3) Output of the HASH table" << endl;
	cout << "4) Output an element by key" << endl;
	cout << "5) Finish working with HASH" << endl;
	cout << "Enter the action number" << endl;
}

void CinElement(int i)
{
	string a, b, c;
	int Key, sum;
	cout << "Enter your full name:" << endl;
	getline(cin >> ws, a);
	cout << "Enter your date of birth:" << endl;
	getline(cin >> ws, b);
	cout << "Enter your residential address:" << endl;
	getline(cin >> ws, c);
	sum = Sum(a);
	Key = Hash(sum, i);
	if (Mas[Key].FIO == "")
	{
		Element element;
		element.FIO = a;
		element.data = b;
		element.adress = c;
		Mas[Key] = element;
	}
	else
	{
		N++;
		Element* element = new Element;
		element->FIO = a;
		element->data = b;
		element->adress = c;
		if (Mas[Key].next == nullptr)
		{
			Mas[Key].next = element;
		}
		else
		{
			try {
				Element* temp = Mas[Key].next;
				while (temp->next != nullptr)
				{
					temp = temp->next;
				}
				temp->next = element;
			}
			catch (const exception& ex) {
				cout << ex.what() << endl;

			}

		}
	}
}

void CinElementK(int i)
{
	int n;
	cout << "Specify the number of elements to enter" << endl;
	cin >> n;
	while (n > 0)
	{
		string a, b, c;
		int Key, sum;
		cout << "Enter your full name:" << endl;
		getline(cin >> ws, a);
		cout << "Enter your date of birth:" << endl;
		getline(cin >> ws, b);
		cout << "Enter your residential address:" << endl;
		getline(cin >> ws, c);
		sum = Sum(a);
		Key = Hash(sum, i);
		if (Mas[Key].FIO == "")
		{
			Element element;
			element.FIO = a;
			element.data = b;
			element.adress = c;
			Mas[Key] = element;
		}
		else
		{
			N++;
			Element* element = new Element;
			element->FIO = a;
			element->data = b;
			element->adress = c;
			if (Mas[Key].next == nullptr)
			{
				Mas[Key].next = element;
			}
			else
			{
				Element* temp = Mas[Key].next;
				while (temp->next != nullptr)
				{
					temp = temp->next;
				}
				temp->next = element;
			}
		}
		n--;
	}
}

int Sum(string str)
{
	int sum = 0;
	for (int k = 0; k < str.size(); k++)
	{
		sum = sum + (int)str[k];
	}
	sum = abs(sum);
	return sum;
}

void CoutHash(int i)
{
	int n = 1;
	int m = 0;
	int k = 1;
	while (i > 0)
	{
		if (Mas[m].FIO != "")
		{
			cout << n << ") " << Mas[m].FIO << endl;
			cout << "   " << Mas[m].data << endl;
			cout << "   " << Mas[m].adress << endl;
			if (Mas[m].next != nullptr)
			{
				Element* temp = Mas[m].next;
				while (temp->next != nullptr)
				{
					cout << n << '.' << k << ") " << temp->FIO << endl;
					cout << "     " << temp->data << endl;
					cout << "     " << temp->adress << endl;
					temp = temp->next;
					k++;
				}
				k++;
				cout << n << '.' << k << ") " << temp->FIO << endl;
				cout << "     " << temp->data << endl;
				cout << "     " << temp->adress << endl;
				k = 1;
			}
			n++;
		}
		m++;
		i--;
	}
	cout << "The number of collisions is equal to " << N << endl;
}

void Chek(int i)
{
	string a;
	bool F = 1;
	cout << "" << endl;
	getline(cin >> ws, a);
	int sum = Sum(a);
	int key = Hash(sum, i);
	if (a == Mas[key].FIO)
	{
		cout << Mas[key].FIO << endl;
		cout << Mas[key].data << endl;
		cout << Mas[key].adress << endl;
	}
	else
	{
		if (Mas[key].FIO != "")
		{
			Element* temp = Mas[key].next;
			while ((temp->FIO != a) && F)
			{
				if (temp == nullptr)
				{
					F = 0;
				}
				else
				{
					temp = temp->next;
				}
			}
			if (F)
			{
				cout << temp->FIO << endl;
				cout << temp->data << endl;
				cout << temp->adress << endl;
			}
			else
			{
				cout << "This element is not in the table or the key is entered incorrectly" << endl;
			}
		}
		else
		{
			cout << "This element is not in the table or the key is entered incorrectly" << endl;
		}
	}
}

int Hash(int sum, int HashTable)
{
	int Key = sum % HashTable;
	return Key;
}