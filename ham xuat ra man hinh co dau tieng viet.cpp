#include <iostream>
#include <fcntl.h> //_O_WTEXT
#include <io.h>    //_setmode()
#include <string>
using namespace std;
int main()
{
    _setmode(_fileno(stdout), _O_WTEXT); // needed for output
    _setmode(_fileno(stdin), _O_WTEXT);  // needed for input
    wcout << L"Nhập tên của bạn: ";
    wstring name;
    getline(wcin, name);
    wcout << L"Xin chào, " << name << L"\n";
}