#pragma once
#include <map>
#include <vector>

class myarray
{
	std::map<char, std::vector<int>> arr;
public:
	std::vector<int> Concat(const char &a, const char &b);
	void Remove(const char &a,const size_t &from, const size_t &count);
	void Sort(const char &a, const char &sign);
	void Copy(const char &a, const size_t &from, size_t to, const char &b);
	void Save(const char &key, const std::string &FileName);
	void Load(const char &key, const std::string &FileName);
	void Rand(const char &key, const size_t &count, const size_t &min, const size_t &max);
	void Free(const char &key);
	void Print(const char &key);
	void Print(const char &key, const size_t &from, size_t to);
	void Permute(const char &key);
	void Intersect(const char &a, const char &b);
	void Xor(const char &a, const  char &b);
	void Stat(const char &key);

	myarray();
};

