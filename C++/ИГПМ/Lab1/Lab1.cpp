//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include "iostream.h"
#include "conio.h"
#include "windows.h"
#include "iomanip.h"
#include "math.h"
#define eps 0.0001//��������� �������� ����������

void rus(char text[])
 {
 char str[100];
 CharToOem(text,str);
 cout<<str;
 }
 void col()
  { HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsoleHandle, YELLOW|FOREGROUND_INTENSITY);}
  void col1()
  { HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsoleHandle, GREEN|FOREGROUND_INTENSITY);}
  void col2()
  { HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsoleHandle, WHITE|FOREGROUND_INTENSITY);}
  void col3()
  { HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute ( hConsoleHandle, FOREGROUND_RED |FOREGROUND_BLUE |
                           FOREGROUND_INTENSITY );}

 void menu1()
 { col1();
  rus("   ������������ ������ �3");cout<<endl;
  rus("  ������������ ������ ������� ���� ");cout<<endl<<endl;
 }

 void menu() //������� ��� ������ ����
 {
   col3();
 rus(" �������� ������ ����� ����");cout<<endl<<endl;col2();
 rus("1:  ���� �������");cout<<endl;
 rus("2:  ����� ������� ��������(�����)");cout<<endl;
 rus("3:  ����� ���������� ����������(�������)");cout<<endl;
 rus("4:  �����");cout<<endl;

 }

 main()
{ int n,i,j,num,k(0);
   double A[10][10]={0},B[10]={0},X[10]={0},x[10]={0},xn[10]={0},norma;

      menu1();
      menu();
  cin>>num;
  while (num!=4)  //���� ����������� ���� �� ������ ������ 4
  {
  switch(num)
  {
     case 1:
            rus("������� ����������� ������� N*N:");
            cin>>n;
            rus("������� �������� �-��:");cout<<endl;
            for(i=0;i<n;i++)
            { col();
               for(j=0;j<n;j++)
               {
                 cout<<"  A ["<<i+1<<"]["<<j+1<<"] = ";
                  cin>>A[i][j];
               }
            }
            rus("������� ��������� �����:"); cout<<endl;
            for(i=0;i<n;i++)
            {  col();
                cout<<"  B ["<<"|"<<i+1<<"|"<<"] = ";
                cin>>B[i];
            }
            rus("������� ��������� ������:");cout<<endl;
            for(i=0;i<n;i++)
            {    col();
                cout<<"  X ["<<"|"<<i+1<<"|"<<"] = ";
                cin>>X[i];
            }
            break;

         case 2:
            for(i=0;i<10;i++)
            {
            xn[i]=0;
            x[i]=X[i];
            }
            do
            {   k++;
                norma=0;
                for(i=0;i<n;i++)
                {
                   xn[i]=-B[i];
                   for(j=0;j<n;j++)
                   {
                       if(i!=j)
                       xn[i]+=A[i][j]*x[j];
                   }
                   xn[i]/=(-A[i][i]);
                 }
              for(i=0;i<n;i++)
              {
                 if( fabs(x[i]-xn[i]) > norma)
                      norma=fabs(x[i]-xn[i]);
                 x[i]=xn[i];
              }
            }
            while(norma > eps);
            rus("���-�� ��������:");cout<<k<<endl;col1();
            for(i=0;i<n;i++)
            cout<<"x ["<<i+1<<"] = "<<x[i]<<endl;
            break;

          case 3:
            for(i=0;i<10;i++)
            {
            xn[i]=0;
            x[i]=X[i];
            }
            do
            {  k++;
               norma=0;
               for(i=0;i<n;i++)
               {
                  x[i]=-B[i];
                  for(j=0;j<n;j++)
                  {
                      if(i!=j)
                          x[i]+=A[i][j]*x[j];
                  }
                  x[i]/=-A[i][i];
               }
               for(i=0;i<n;i++)
               {
                  if(fabs(x[i]-xn[i]) > norma)
                      norma=fabs(x[i]-xn[i]);
                  xn[i]=x[i];
               }
             }
             while(norma > eps);
             rus("���-�� ��������:");cout<<k<<endl;col1();
             for(i=0;i<n;i++)
             cout<<"x ["<<i+1<<"] = "<<x[i]<<endl;

             break;

  case 4: break;
  default:  rus("��������� ����");
  break;}
  cout<<endl;
  menu();cin>>num;}  
  getch();
  }




