//#include "stdafx.h"
#include <iostream>
#include <locale>
#include <cwchar>
#include <ctime>

#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	/*cout << "geterror\n";
	try
	{
		throw ERROR_THROW(100);
	}
	catch (Error::ERROR e)
	{
		cout << "Error " << e.id << ": " << e.message << endl;
	}
	cout << "geterrorin\n";
	try
	{
		throw ERROR_THROW_IN(111, 7, 7);
	}
	catch (Error::ERROR e)
	{
		cout << "Error " << e.id << ": " << e.message << ", line " << e.inext.line <<
			", column " << e.inext.col << endl;
	}*/

	/*try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		wcout << "-in: " << parm.in << ", -out: " << parm.out << ", -log: " << parm.log << endl;
	}
	catch (Error::ERROR e)
	{
		cout << "Error " << e.id << ": " << e.message << endl;
	}*/

	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		Log::LOG log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"Тест: ", (char*)" Без ошибок \n", "");
		Log::WriteLine(log, (wchar_t*)L"Тест: ", (wchar_t*)L" Без ошибок \n", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}
}