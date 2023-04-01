#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const long giaVeNguoiLon = 40000, long giaVeTreEm = 20000;
struct KhachHang
{
	string hoten, sdt, tenphim, phong, xuatchieu;
	int venguoilon, vetreem;
	long long tienphaitra;
};
struct danhsachKH
{
	KhachHang khachhang[50];
	int n = 0;
};
void readFile( danhsachKH &kh)
{
	ifstream file;
	file.open("input.txt", ios::out);
	file >> kh.n;
	for (int i = 0; i <kh.n; i++)
	{
		getline(file, kh.khachhang[i].hoten, ',');
		getline(file, kh.khachhang[i].sdt, ',');
		file>> kh.khachhang[i].venguoilon;
		file>> kh.khachhang[i].vetreem;
		getline(file, kh.khachhang[i].tenphim, ',');
		getline(file, kh.khachhang[i].phong, ',');
		getline(file, kh.khachhang[i].xuatchieu);
		TienPhaiTra(kh.khachhang[i]);
	}
	file.close();
}
void in_1_kh(KhachHang kh)
{
	cout << kh.hoten;
	cout << kh.sdt;
	cout << kh.venguoilon;
	cout << kh.vetreem;
	cout << kh.tenphim;
	cout << kh.phong;
	cout << kh.xuatchieu;
	cout << kh.tienphaitra;
}
void in_ds_kh(danhsachKH &kh)
{
	cout << " Ho ten " << " Sdt " << " Ten phim " << " Phong " << " Xuat chieu " << " ve nguoi lon " << " ve tre em " << " tien phai tra "<<endl;
	cout << "--------------------------------";
	for (int i = 0; i < kh.n; i++)
	{
		in_1_kh(kh.khachhang[i]);
		cout << endl;
	}
}
void TienPhaiTra(KhachHang &kh)
{
	kh.tienphaitra = kh.venguoilon * giaVeNguoiLon + kh.vetreem * giaVeTreEm;
}
int main()
{
	danhsachKH kh;
	readFile(kh);
	TienPhaiTra(kh);
	in_ds_kh(kh);
	return 0;
}