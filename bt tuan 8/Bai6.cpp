/*Học sinh A giỏi hơn học sinh B, thì số phần thưởng của A sẽ lớn hơn hoặc bằng B
Tất cả m phần thưởng đều chia hết cho học sinh
Hàm Part(int m,n) là số cách chia
Nếu m = 0, có 1 cách chia, tất cả học sinh đều  có 0 phần thưởng
Nếu n = 0, không có cách chia nào cả
Khi m < n, thì có n-m học sinh cuối không có phần thưởng, Part(m,n) = Part(m,m)
Khi m>n, ta xét hai trường hợp
Khi học sinh cuối cùng không nhận được phần thưởng nào, do đó Part(m,n) = Part(m, n-1)
Khi học sinh cuối cùng nhận được ít nhất 1 phần thưởng, do đó số cách chia là Part(m-n, n)
Tóm lại m > n, có Part(m,n) = Part(m, n-1) + Part(m-n, n)*/


//#include<conio.h>
//#include<stdio.h>
//int PART( int m , int n ) // câu 6 chia thưởng 
//{ 
//	if (m == 0 ) return 1 ; 
//	else 
//	if (n == 0 ) return 0 ; 
//	else 
//	if(m < n ) return ( PART(m , m )) ; 
//	else 
//	return ( PART(m , n -1 ) + PART(m -n , n ) ) ; 
//} 
//
//

//void main()
//{
//	int n,m;	
//	printf("Nhap so phan thuong: ");
//	scanf("%d",&m);
//	printf("Nhap so hoc sinh: ");
//	scanf("%d", &n);
//	printf("\n so cach chia thuong: %d",PART(m,n));
//	getch();
//}