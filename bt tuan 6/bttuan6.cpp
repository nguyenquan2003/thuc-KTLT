#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int kt_doi_xung(char s[])
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != s[strlen(s) - i - 1])
		{
			return 0;
		}
	}
	return 1;
}
char xoa_chuoi(char s1[], char s2[])
{
	for (int i = 0; i < strlen(s1); i++)
	{
		if (s1[i] == s2[0])
		{
			int j;
			for (j = i; j < strlen(s1); j++)
			{
				s1[j] = s1[j + 1];
			}
			s1[j + 1] = '\0';
			i--;
		}
	}
	cout << "chuoi ki tu sau khi xoa: " << s1;
	return 0;
}
void chen(char s[], int vitrithem, char kituthem)
{
	int n = strlen(s); // lấy độ dài của chuỗi <=> số lượng phần tử của chuỗi
	for (int i = n - 1; i >= vitrithem; i--)
	{
		s[i + 1] = s[i];
	}
	s[vitrithem] = kituthem; // thêm kí tự vào vị trí bất kì
	s[n + 1] = '\0'; // xác định lại kí tự \0
}
int vi_tri(char* s1, char* s2)
{
	if (strstr(s1, s2) != NULL)
	{
		for (int i = 0; i < strlen(s1); i++)
		{
			if (s1[i] == s2[0])
			{
				return i;
			}
		}
	}
	return -1;
}
void tach_so(char* s)
{
	int a[50], j = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[j] = s[i];
			j++;
			for (int t = i; t < strlen(s); t++)
			{
				s[t] = s[t + 1];
				i--;
			}
		}
	}
	cout << "xuat chuoi : ";
	for (int i = 0; i < j; i++)
	{
		cout << char(a[i]) << " ";
	}
}
int main()
{
	char s[50], s1[50], s2[50];
	int chon;
	cout << "========================MENU======================== " << endl;
	cout << "7. kiem tra chuoi doi xung " << endl;
	cout << "8. tim vi tri xuat hien cua chuoi 2 trong chuoi 1 " << endl;
	cout << "9. chen chuoi " << endl;
	cout << "10. xoa tat ca nhung ki tu trong chuoi " << endl;
	cout << "11. xuat ra chuoi ki tu toan so " << endl;
	cout << "-------------------------------------------------------------------- " << endl;
	cout << "moi ban chon bai : ";
	cin >> chon;
	cin.ignore();
	switch (chon)
	{
	case 7: cout << "nhap chuoi ki tu : ";
		gets_s(s);
		if (kt_doi_xung(s))
			cout << "day la chuoi doi xung ";
		else
			cout << "day la chuoi khong doi xung ";
		break;
	case 8:
	{
		cout << "nhap chuoi s1 : ";
		gets_s(s1);
		cout << "nhap chuoi s2 : ";
		gets_s(s2);
		int vt = vi_tri(s1, s2);
		if (vt == -1)
		{
			cout << strcat(s1, s2);
		}
		else
		{
			cout << "vi tri xuat hien dau tien cua s2 trong s1 : " << vt;
		}
		break;
	}
	case 9: int vitrithem;
		char kituthem;
		cout << "nhap chuoi ki tu : ";
		gets_s(s);
		cout << "nhap vi tri can them : ";
		cin >> vitrithem;
		cin.ignore();
		cout << "nhap ki tu can them : ";
		cin >> kituthem;
		chen(s, vitrithem, kituthem);
		cout << "ki tu sau khi duoc chen la : " << s;
		break;
	case 10: cout << "nhap chuoi ki tu : ";
		gets_s(s1);
		cout << "nhap ki tu muon xoa : ";
		gets_s(s2);
		cout << xoa_chuoi(s1, s2);
		break;
	case 11: cout << "nhap chuoi ki tu : ";
		gets_s(s);
		tach_so(s);
		break;
	default: cout << "Ban nhap sai cu phap. Vui long nhap lai . ";
		break;
	}
}