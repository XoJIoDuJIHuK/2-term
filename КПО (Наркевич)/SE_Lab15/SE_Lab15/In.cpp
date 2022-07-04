#include "In.h"
#include "Error.h"
#include <fstream>
#include <string>
#include <iostream>

namespace In
{
	IN getin(wchar_t infile[])
	{
		/*IN struc;
		std::ifstream file(infile);
		try
		{
			if (!file.is_open()) throw ERROR_THROW(110);
			std::string str;
			std::string text;
			while (!file.eof())
			{
				getline(file, str);
				text += str;
				for (int i = 0; i < str.length(); i++)
				{
					if (struc.code[(int)str[i]] == 2048) throw ERROR_THROW_IN(111, struc.lines, i);
					if (struc.code[(int)str[i]] == 4096) struc.ignor++;
					struc.size++;
				}
				struc.lines++;
			}
			unsigned char* char_text = new unsigned char[text.length()];
			for (int i = 0; i < text.length(); i++) char_text[i] = text[i];
			struc.text = char_text;
			return struc;
		}
		catch (Error::ERROR e)
		{
			Error::ErrorDisplay(e);
		}*/

		try
		{
			IN in;
			in.size = 0; in.lines = 0; in.ignor = 0;
			int col = 0;

			unsigned char* text = new unsigned char[IN_MAX_LEN_TEXT];

			std::ifstream fin(infile);
			if (fin.fail()) throw ERROR_THROW(110);

			while (in.size < IN_MAX_LEN_TEXT)
			{
				char c; fin.get(c);
				unsigned char x = c;
				if (fin.eof())
				{
					text[in.size] = '\0';
					in.lines++;
					break;
				}
				if (in.code[x] == in.T)
				{
					text[in.size] = x;
					in.size++;
					col++;
				}
				else if (in.code[x] == in.I)
				{
					in.ignor++;
				}
				else if (in.code[x] == in.F)
				{
					throw ERROR_THROW_IN(111, in.lines, col);
				}
				else
				{
					text[in.size] = in.code[x];
					in.size++;
					col++;
				}
				if (x == IN_CODE_ENDL)
				{
					in.lines++;
					col = 0;
				}
			}
			in.text = text;

			return in;
		}
		catch (Error::ERROR e)
		{
			Error::ErrorDisplay(e);
		}
	}
}