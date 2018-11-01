#include "stdafx.h"
#include "myarray.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <valarray>

size_t abr, bbr;



int random()
{
	return abr + rand() % (bbr - abr);
}

int RandomNumber() { return (std::rand() % 100); }

std::vector<int>split(const std::string &s, char delim)
{
	std::vector<int> elems;
	std::stringstream ss(s);
	std::string item;
	while (getline(ss, item, delim))
		elems.push_back(atoi(item.c_str()));
	return elems;
}


void myarray::Save(const char &key, const std::string &FileName)
{
	std::ofstream fout(FileName, std::ios_base::trunc);
	if (!fout)
	{
		std::cerr << "cannot open file" << std::endl;
		system("pause");
		exit(1);
	}
	for(std::vector<int>::iterator it =arr[key].begin(); it!=arr[key].end();++it)
	{
		fout << *it << ' ';
	}	
}

void myarray::Load(const char &key, const std::string &FileName)
{
	std::string str;
	std::ifstream fin(FileName, std::ios_base::in);
	if (!fin)
	{
		std::cerr << "cannot open file" << std::endl;
		system("pause");
		exit(1);
	}
	getline(fin, str);
		arr[key] = split(str,' ');
}

void myarray::Rand(const char &key, const size_t &count,const size_t &min, const size_t &max)
{
	arr[key].clear();
	arr[key].resize(count);
	abr = min; bbr = max;
	generate(arr[key].begin(), arr[key].end(), random);
}

void myarray::Free(const char &key)
{
	arr[key].clear();
}

myarray::myarray()
{
	srand(time(0));
}

std::vector<int> myarray::Concat(const char &a, const char &b)
{
	arr[a].insert(arr[a].end(), arr[b].begin(), arr[b].end());
	return arr[a];
}

void myarray::Sort(const char &a, const char &sign)
{
	if(sign=='+')
		std::sort(arr[a].rbegin(), arr[a].rend());
	if(sign=='-') 
		std::sort(arr[a].begin(), arr[a].end());
}


void myarray::Copy(const char &a, const size_t &from, size_t to, const char &b)
{
	if (to > arr[a].size()) to = arr[a].size();
	arr[b].clear();
	for(size_t i=from-1;i!=to;i++)
	{
		arr[b].push_back(arr[a][i]);
	}
}

void myarray::Print(const char &key)
{
	for (std::vector<int>::iterator it = arr[key].begin(); it != arr[key].end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

void myarray::Print(const char &key, const size_t &from, size_t to)
{
	if (to < from) return;
	if (to > arr[key].size()) to = arr[key].size();
	for (size_t i = from - 1; i != to; i++)
	{
	 std::cout<<arr[key][i]<<' ';
	}
	std::cout << std::endl;
}

void myarray::Permute(const char &key)
{
	random_shuffle(arr[key].begin(), arr[key].end());
}

void myarray::Intersect(const char &a, const char &b)
{
	std::vector<int> c;
	for (std::vector<int>::iterator it = arr[a].begin(); it != arr[a].end(); ++it)
	{
		if (std::find(arr[b].begin(), arr[b].end(), *it) != arr[b].end())
			if (std::find(c.begin(), c.end(), *it) == c.end()) c.push_back(*it);
	}
	arr[a] = c; 
}

void myarray::Xor(const char &a, const char &b)
{
	std::vector<int> c;
	for (std::vector<int>::iterator it = arr[a].begin(); it !=  arr[a].end(); ++it)
	{
		if (std::find(arr[b].begin(), arr[b].end(), *it) == arr[b].end())
			if (std::find(c.begin(), c.end(), *it) == c.end()) c.push_back(*it);
	}
	arr[a] = c;
}

void myarray::Stat(const char &key)
{
	std::vector<int>tmp = arr[key];
	int MAX = *max_element(arr[key].begin(), arr[key].end());
	int MIN = *min_element(arr[key].begin(), arr[key].end());
	std::cout << "Size: " << arr[key].size()<<std::endl;

	std::cout << "Max["<< std::distance(arr[key].begin(), std::max_element(arr[key].begin(), arr[key].end())) <<"] = "<<MAX << std::endl;

	std::cout << "Min[" << std::distance(arr[key].begin(), std::min_element(arr[key].begin(), arr[key].end())) << "] = "<<MIN<< std::endl;

	std::sort(tmp.begin(), tmp.end());
	int most = 0,count=0,max=0,sum;
	int _it = sum = *tmp.begin();
	for(std::vector<int>::iterator it=tmp.begin()+1;it!=tmp.end();++it)
	{
		if (_it == *it) count++;
		if (*it != _it)
		{
			if (count>max)
			{
				most = _it;
				max = count;
			}
			count = 0;
		}
		sum += *it;
		_it = *it;
	}max++;
	std::cout << "most popular element: " << most << " (" << max << " elements)" << std::endl;

	std::cout << "average element: " << (int)sum/tmp.size() << std::endl;

	std::cout << "difference between max/min and average: " << 
		((abs((int)(sum / tmp.size() - MAX)) >abs((int)(sum / tmp.size() - MIN))) ?
		(abs((int)(sum / tmp.size() - MAX))):
	    (abs((int)(sum / tmp.size() - MIN)))) << std::endl;
}

void myarray::Remove(const char &key, const size_t &from, const size_t &count)
{
	for (size_t i = 0; i < count; i++) {
		std::vector<int>::iterator it = arr[key].begin() + from;
		if (it == arr[key].end()) break;
		arr[key].erase(it);
	}	
}
