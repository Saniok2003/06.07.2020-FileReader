#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class FileReader
{
protected:
	string path;
public:
	virtual void Display(string path) {	  };
	virtual void OpenFile() {	};
	int charToBinary(unsigned char val)
	{
		int binary = 0;

		for (int i = 7; i >= 0; --i)
		{
			binary *= 10;

			if (val & (1 << i))
				binary += 1;
		}

		return binary;
	}
};



class ASCIIFileReader : public FileReader
{
private:
	string path;
public:
	ASCIIFileReader() : path("")
	{	}
	void OpenFile() override
	{
		ifstream fin;
		char word[255];
		int tmpint;
		fin.open(this->path);
		bool isOpen = fin.is_open();
		if (isOpen == true)
		{
			while (!fin.eof())
			{
				fin >> word;
				int size = strlen(word);
				for (int i = 0; i < size; i++)
				{
					tmpint = word[i];
					if (i + 1 == size)
					{
						cout << tmpint << " ";
					}
					else
					{
						cout << tmpint << ", ";
					}
				}
				cout << endl;
			}
		}
		else
		{
			cout << "File not find" << endl;
		}

		fin.close();
	}

	virtual void Display(string path) override
	{
		this->path = path;
		OpenFile();
	}

};
class BinaryFileReader : public FileReader
{
private:
	string path;
public:
	BinaryFileReader() : path("")
	{	}
	virtual void OpenFile() override
	{
		ifstream fin;
		char word[255];
		fin.open(this->path);
		bool isOpen = fin.is_open();
		char tmpwa;
		if (isOpen == true)
		{
			while (!fin.eof())
			{
				fin >> word;
				int size = strlen(word);
				for (int i = 0; i < size; i++)
				{
					tmpwa = word[i];
					cout << charToBinary(tmpwa) << " ";
				}
				cout << endl;
			}
		}
		else
		{
			cout << "File not find" << endl;
		}
		fin.close();
	}
	virtual void Display(string path) override
	{
		this->path = path;
		OpenFile();
	}
};

int main()
{
	BinaryFileReader q;
	q.Display("C:\\Users\\Hp\\source\\repos\\FileReader\\FileReader\\Fila.txt");

	ASCIIFileReader s;
	s.Display("C:\\Users\\Hp\\source\\repos\\FileReader\\FileReader\\lolB.txt");

	return 0;
}