#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <stdio.h>

bool is_separator(char c)
{
	return c == ' ' || c == ',' || c == '.' || c == '?' || c == '!';
}
std::string lower_case(std::string text)
{
	for (size_t i = 0; i < text.size(); i++)
		if (text[i] >= 'A' && text[i] <= 'Z')
			text[i] += 32;
	return text;
}

struct compare 
{
	bool operator() (std::map<std::string, int>::iterator s1, std::map<std::string, int>::iterator s2)
	{
		if (s1->second < s2->second) return true;
		if (s1->second > s2->second) return false;
		if (s1->first < s2->first) return false;
		return true;
	}
};

void H8_string_main()
{
	FILE* input = fopen("ex 1/input.txt", "r");
	if (input == nullptr)
	{
		std::cout << "error - file openning: input text not available.\n";
		return;
	}

	std::string text = "";
	std::map<std::string, int> words;

	//read
	char character = 0;
	while ((character = fgetc(input)) != EOF)
		text += character;

	// split and map (case-insensitive)
	int index_text = 0;
	std::string word = "";

	while (text[index_text])
	{
		if (is_separator(text[index_text]) && word != "")
		{
			words[lower_case(word)]++;
			word = "";
		}

		else word += text[index_text];
		index_text++;
	}

	// priority_queue: k then lexic
	std::priority_queue <std::map<std::string, int>::iterator, std::vector<std::map<std::string, int>::iterator>, compare> p;
	std::map<std::string, int>::iterator it = words.begin();
	while (it != words.end())
	{
		p.push(it);
		it++;
	}

	// print
	while (!p.empty())
	{
		std::cout << "The word " << p.top()->first << " appears " << p.top()->second << " times.\n";
		p.pop();
	}

	fclose(input);
}