#include "stdafx.h"
#include "myarray.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
#include <array>

std::vector<std::string>split(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	std::stringstream ss(s);
	std::string item;
	while (getline(ss, item, delim))
	{
		if (item[item.size() - 1] == ',')item[item.size() - 1] = 0;
		elems.push_back(item);
	}		
	return elems;
}

int main()
{
	char A,B;
	std::array<std::string, 13>commands = { "Load","Save","Rand","Concat","Free","Remove","Copy","Sort","Permute","Intersect","Xor","Stat","Print"};
	std::string str;
	myarray a;
	const std::string FileName = "task.txt";
	std::ifstream fin(FileName, std::ios_base::in);
	if (!fin)
	{
		std::cerr << "cannot open file" << std::endl;
		system("pause");
		exit(1);
	}
	while (getline(fin, str))
	{
		std::vector<std::string>tmp = split(str, ' ');
		if (tmp.size() < 2) continue;
		int swtch = std::distance(commands.begin(), find(commands.begin(), commands.end(), tmp[0]))+1;
		A = toupper(tmp[1][0]);
		toupper(A);
		
		switch (swtch)
		{
		case 1:
			if (tmp.size() < 3) continue;
			a.Load(A, tmp[2]);
			break;
		case 2:
			if (tmp.size() < 3) continue;
			a.Save(A, tmp[2]);
			break;
		case 3:
			if (tmp.size() < 5) continue;
			a.Rand(A, atoi(tmp[2].c_str()), atoi(tmp[3].c_str()), atoi(tmp[4].c_str()));
			break;
		case 4:
			if (tmp.size() < 3) continue;
			B = toupper(tmp[2][0]);
			a.Concat(A,B);
			break;
		case 5:
			a.Free(A);
			break;
		case 6:
			if (tmp.size() < 4) continue;
			a.Remove(A, atoi(tmp[2].c_str()), atoi(tmp[3].c_str()));
			break;
		case 7:
			if (tmp.size() < 5) continue;
			B = tmp[4][0];
			toupper(B);
			a.Copy(A, atoi(tmp[2].c_str()), atoi(tmp[3].c_str()), B);
			break;
		case 8:
			a.Sort(A, tmp[1][1]);
			break;
		case 9:
			a.Permute(A);
			break;
		case 10:
			if (tmp.size() < 3) continue;
			B = toupper(tmp[2][0]);			
			a.Intersect(A, B);
			break;
		case 11:
			if (tmp.size() < 3) continue;
			B = toupper(tmp[2][0]);			
			a.Xor(A, B);
			break;
		case 12:
			a.Stat(A);
			break;
		case 13:
			if (tmp.size() == 2) a.Print(A); 
			else if (tmp.size() == 4) a.Print(A, atoi(tmp[2].c_str()), atoi(tmp[3].c_str()));
			break;
		}

}
	//a.Load('a', "base.txt");
	//a.Rand('b', 10, 1, 10);
	//a.Print('a');
	//a.Print('b');
	////a.Print('b',5,100);
	//a.Intersect('a', 'b');
	////a.Remove('a', 3, 2);
	//a.Print('a');
	//a.Stat('b');
	//a.Concat('a', 'b');
	//a.Copy('a', 1, 200, 'b');
	//a.Free('a');
	//a.Print('a');
	//a.Save('b', "out.txt");
	//a.Sort('a', '-');
	//a.Print('a');
	//a.Sort('a', '+');
	//a.Print('a');
	//a.Permute('a');
	//a.Print('a');

	system("pause");
    return 0;
}