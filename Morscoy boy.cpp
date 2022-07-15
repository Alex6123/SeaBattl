#include <iostream>
#include<stdlib.h>
  
using namespace std;

const char a_1 [4] = " . "; //пусто
const char a_2 [4] = " + ";//занят 
const char a_3 [4] = "[=]";//корабль                  
const char a_4 [4] = "[X]";//ранен или убит
const char a_5 [4] = "[*]";//выстрел по кораблю
const char a_6 [4] = " * ";//выстрел по пустоте 

// 4-палубных = 1 шт, 3-палубных = 2 шт, 2-палубных = 3 шт, 1-палубных = 4 шт, всего 10 кораблей
// горизонталь A, B, C, D, E, F, G, H, I, J вертикаль 1-10

char userNAME [20];

int f_gor (char gor)
{
  if (gor == 'A') return 1; else if (gor == 'B') return 2; else  if (gor == 'C') return 3;
  else  if (gor == 'D') return 4; else  if (gor == 'E') return 5; else  if (gor == 'F') return 6;
  else  if (gor == 'G') return 7; else  if (gor == 'H') return 8; else  if (gor == 'I') return 9;
  else  if (gor == 'J') return 10; else return 0;
}
void f_cout (int arr[10][10])
{
  cout << "            " << userNAME;
  cout << endl;
  cout << "    A  B  C  D  E  F  G  H  I  J";
  cout << endl;
  for (int i = 0; i< 10; i++)
  {
    int N = i+1;
    if (N==10) {cout << N << " ";}
    else cout << N << "  ";
    for (int j= 0; j< 10; j++)
      { 
        if (arr [i] [j] == 1) cout << a_1;
        else if (arr [i] [j] == 2) cout << a_2;
        else if (arr [i] [j] == 3) cout << a_3;
        else if (arr [i] [j] == 4) cout << a_4;
        else if (arr [i] [j] == 5) {cout << a_5; arr [i] [j] = 4;}
        else if (arr [i] [j] == 6) cout << a_6;
      }
    cout << endl;
  }
  cout << endl << endl;
}
void f_zanjat (int arr[10][10])
{
  for (int i = 0; i< 10; i++)
  {    
    for (int j= 0; j< 10; j++)
      { 
        if ((arr [i] [j] == 3) & (arr [(i+1)] [j] == 1)) arr [(i+1)] [j] = 2;
        if ((arr [i] [j] == 3) & (arr [(i-1)] [j] == 1)) arr [(i-1)] [j] = 2;                
        if ((j==0) & (arr [i] [j] == 3) & (arr [i] [(j+1)] == 1)) {arr [i] [(j+1)] = 2;}
        else if ((0<j) & (j<9) & (arr [i] [j] == 3) & (arr [i] [(j+1)] == 1)) {arr [i] [(j+1)] = 2;}
        if ((j==9) & (arr [i] [j] == 3) & (arr [i] [(j-1)] == 1)) {arr [i] [(j-1)] = 2;}
        else if ((0<j) & (j<9) & (arr [i] [j] == 3) & (arr [i] [(j-1)] == 1)) {arr [i] [(j-1)] = 2;}
      }
  }
}

void f_cout_COMP (int arr[10][10])
{
  cout << "             COMPUTER";
  cout << endl;
  cout << "    A  B  C  D  E  F  G  H  I  J";
  cout << endl;
  for (int i = 0; i< 10; i++)
  {
    int N = i+1;
    if (N==10) {cout << N << " ";}
    else cout << N << "  ";
    for (int j= 0; j< 10; j++)
      { 
        if (arr [i] [j] == 1) cout << a_1;
        else if (arr [i] [j] == 2) cout << a_2;
        else if (arr [i] [j] == 3) cout << a_3;
        else if (arr [i] [j] == 4) cout << a_4;
        else if (arr [i] [j] == 5) {cout << a_5; arr [i] [j] = 4;}
        else if (arr [i] [j] == 6) cout << a_6;
      }
    cout << endl;
  }
  cout << endl << endl;
}
bool BOY (int arr[10][10], int arr_boy[10][10], int v, int g)
{
  if (arr[v][g] == 1) arr_boy[v][g] = 6;
  else if (arr[v][g] == 3) {arr_boy[v][g] = 5; return true;}
  return false;     
}
bool f_igra (int arr_boy[10][10])
{
  int s = 0;
  for (int i = 0; i< 10; i++)
  {    
    for (int j= 0; j< 10; j++)
      { 
        if ((arr_boy [i] [j] == 4) || (arr_boy [i] [j] == 5)) s++;
      }
  }
  if (s == 20) return false; 
  else return true; 
}

int main ()
{
  bool flag = false;
  
  cout << "Введите ваше имя (EN)" << endl;
  cin >> userNAME;
  //------заполним пустыми поля пользователя-------------
  int User [10][10];
  for (int i = 0; i< 10; i++)
  {
    for (int j= 0; j< 10; j++)
      { 
         User [i] [j] = 1;
      }
  }
  //-----------------------------------------------------
  f_cout (User);
  char gor_11, gor_12;
  int ver_1, ver_2, gor_1, gor_2;

  //-------------пользователь распологает 4-х палубный корабль-------  
  for (;;)
  { 
    cout << "Выберите расположение 4-х палубного корабля" << endl;
    cout << "Введите первое значение по горизонтали A - J: ";
    cin >> gor_11;
    cout << "Введите второе значение по горизонтали A - J: ";
    cin >> gor_12;
    cout << "Введите первое значение по вертикали 1 - 10: ";
    cin >> ver_1;
    cout << "Введите второе значение по вертикали 1 - 10: ";
    cin >> ver_2;
    gor_1 = f_gor (gor_11);
    gor_2 = f_gor (gor_12);
    if ( (gor_1 == 0) || (gor_2 == 0) || (ver_1 > 10) || (ver_1 < 1) || (ver_2 > 10) || (ver_2 < 1)) 
    {cout << "Ошибка ввода данных" << endl; cin.clear(); continue;}
    if ((gor_1 == gor_2 || ver_1 == ver_2) & ((abs((ver_1)-(ver_2)) ==3) || (abs((gor_1)-(gor_2)) ==3))) break;
   
    if (gor_1 == gor_2 || ver_1 == ver_2) cout << endl; else 
    cout << "Ошибка ввода данных - корабль должен распологаться строго по вертикали или горизонтали"<< endl;
    if ((abs((ver_1) - (ver_2)) !=3) || (abs((gor_1) - (gor_2)) !=3))
    cout << "Ошибка ввода данных - корабль должен иметь четыре палубы"<< endl;
  }
  if (gor_1 < gor_2) 
    {
      User [(ver_1-1)][(gor_1-1)] = 3; User [(ver_1-1)][(gor_1)] = 3;
      User [(ver_1-1)][(gor_1+1)] = 3; User [(ver_1-1)][(gor_2-1)] = 3;
    }
  else if (gor_1 >gor_2)
    {
      User [(ver_1-1)][(gor_2-1)] = 3; User [(ver_1-1)][(gor_2)] = 3;
      User [(ver_1-1)][(gor_2+1)] = 3; User [(ver_1-1)][(gor_1-1)] = 3;
    }
else if (ver_1 < ver_2)
    {
      User [(ver_1-1)][(gor_2-1)] = 3; User [(ver_1)][(gor_2-1)] = 3;
      User [(ver_1+1)][(gor_2-1)] = 3; User [(ver_2-1)][(gor_2-1)] = 3;
    }
else if (ver_1 > ver_2)
    {
      User [(ver_2-1)][(gor_2-1)] = 3; User [(ver_2)][(gor_2-1)] = 3;
      User [(ver_2+1)][(gor_2-1)] = 3; User [(ver_1-1)][(gor_2-1)] = 3;
    }        
  f_zanjat (User);
  f_cout (User);
    //-------завершение расположения пользователем 4-х палубного корабля--------------
//-------------пользователь распологает 2 3-х палубныx корабля------- 
for (int i = 0; i< 2; i++)
{
 for (;;)
  {
    cout << "Выберите расположение 3-х палубного корабля" << endl;
    cout << "Введите первое значение по горизонтали A - J: ";
    cin >> gor_11;
    cout << "Введите второе значение по горизонтали A - J: ";
    cin >> gor_12;
    cout << "Введите первое значение по вертикали 1 - 10: ";
    cin >> ver_1;
    cout << "Введите второе значение по вертикали 1 - 10: ";
    cin >> ver_2;
    gor_1 = f_gor (gor_11);
    gor_2 = f_gor (gor_12);
    if ( (gor_1 == 0) || (gor_2 == 0) || (ver_1 > 10) || (ver_1 < 1) || (ver_2 > 10) || (ver_2 < 1)) 
    {cout << "Ошибка ввода данных" << endl; cin.clear(); continue;}
    if ( ( (User [ver_1-1][gor_1-1]) !=1 )  || ( (User [ver_2-1][gor_2-1]) !=1 )  )
      {cout << "Место уже занято" << endl; cin.clear(); continue;}
    if ((gor_1 == gor_2 || ver_1 == ver_2) & ((abs((ver_1)-(ver_2)) ==2) || (abs((gor_1)-(gor_2)) ==2))) break;   
    if (gor_1 == gor_2 || ver_1 == ver_2) cout << endl; else 
    cout << "Ошибка ввода данных - корабль должен распологаться строго по вертикали или горизонтали"<< endl;
    if ((abs((ver_1) - (ver_2)) !=2) || (abs((gor_1) - (gor_2)) !=2))
    cout << "Ошибка ввода данных - корабль должен иметь три палубы"<< endl;
  }
   if (gor_1 < gor_2) 
    {
      User [(ver_1-1)][(gor_1-1)] = 3; User [(ver_1-1)][(gor_1)] = 3;
      User [(ver_1-1)][(gor_2-1)] = 3;
    }
  else if (gor_1 >gor_2)
    {
      User [(ver_1-1)][(gor_2-1)] = 3; User [(ver_1-1)][(gor_2)] = 3;
      User [(ver_1-1)][(gor_1-1)] = 3;
    }
else if (ver_1 < ver_2)
    {
      User [(ver_1-1)][(gor_2-1)] = 3; User [(ver_1)][(gor_2-1)] = 3;
      User [(ver_2-1)][(gor_2-1)] = 3;
    }
else if (ver_1 > ver_2)
    {
      User [(ver_2-1)][(gor_2-1)] = 3; User [(ver_2)][(gor_2-1)] = 3;
      User [(ver_1-1)][(gor_2-1)] = 3;
    }        
  f_zanjat (User);
  f_cout (User);
}
//-------------пользователь распологает 3 2-х палубныx корабля------- 
for (int i = 0; i< 3; i++)
{
 for (;;)
  {
    cout << "Выберите расположение 2-х палубного корабля" << endl;
    cout << "Введите первое значение по горизонтали A - J: ";
    cin >> gor_11;
    cout << "Введите второе значение по горизонтали A - J: ";
    cin >> gor_12;
    cout << "Введите первое значение по вертикали 1 - 10: ";
    cin >> ver_1;
    cout << "Введите второе значение по вертикали 1 - 10: ";
    cin >> ver_2;
    gor_1 = f_gor (gor_11);
    gor_2 = f_gor (gor_12);
    if ( (gor_1 == 0) || (gor_2 == 0) || (ver_1 > 10) || (ver_1 < 1) || (ver_2 > 10) || (ver_2 < 1)) 
    {cout << "Ошибка ввода данных" << endl; cin.clear(); continue;}
    if ( ( (User [ver_1-1][gor_1-1]) !=1 )  || ( (User [ver_2-1][gor_2-1]) !=1 )  )
      {cout << "Место уже занято" << endl; cin.clear(); continue;}
    if ((gor_1 == gor_2 || ver_1 == ver_2) & ((abs((ver_1)-(ver_2)) ==1) || (abs((gor_1)-(gor_2)) ==1))) break;   
    if (gor_1 == gor_2 || ver_1 == ver_2) cout << endl; else 
    cout << "Ошибка ввода данных - корабль должен распологаться строго по вертикали или горизонтали"<< endl;
    if ((abs((ver_1) - (ver_2)) !=1) || (abs((gor_1) - (gor_2)) !=1))
    cout << "Ошибка ввода данных - корабль должен иметь две палубы"<< endl;
  }
   if (gor_1 < gor_2) 
    {
      User [(ver_1-1)][(gor_1-1)] = 3; User [(ver_1-1)][(gor_2-1)] = 3;
    }
  else if (gor_1 >gor_2)
    {
      User [(ver_1-1)][(gor_2-1)] = 3; User [(ver_1-1)][(gor_1-1)] = 3;
    }
else if (ver_1 < ver_2)
    {
      User [(ver_1-1)][(gor_2-1)] = 3; User [(ver_2-1)][(gor_2-1)] = 3;
    }
else if (ver_1 > ver_2)
    {
      User [(ver_2-1)][(gor_2-1)] = 3; User [(ver_1-1)][(gor_2-1)] = 3;
    }        
  f_zanjat (User);
  f_cout (User);
}
//-------------завершение расположения 3 2-х палубныx кораблей-------  
//-------------пользователь распологает 4 1-палубныx корабля------- 
for (int i = 0; i< 4; i++)
{
 for (;;)
  {
    cout << "Выберите расположение 1-палубного корабля" << endl;
    cout << "Введите значение по горизонтали A - J: ";
    cin >> gor_11;
    cout << "Введите значение по вертикали 1 - 10: ";
    cin >> ver_1;
    gor_1 = f_gor (gor_11);
    if ( (gor_1 == 0) || (ver_1 > 10) || (ver_1 < 1)) 
    {cout << "Ошибка ввода данных" << endl; cin.clear(); continue;}
    if ( ( (User [ver_1-1][gor_1-1]) !=1 )  )
      {cout << "Место уже занято" << endl; cin.clear(); continue;}
    break;  
  }    
    User [(ver_1-1)][(gor_1-1)] = 3;   
        
  f_zanjat (User);
  f_cout (User);
}
//-------------завершение расположения 4x 1-палубныx кораблей-------  

for (int i = 0; i< 10; i++)// заменим занятые места кроме кораблей на свободные
{
  for (int j = 0; j < 10; j++)
  if (User [i][j] == 2) User [i][j] = 1;
}

//=============================================================================================================
//=============================================================================================================
// ------------инициализация поля компьютера
int COMP[10][10];
//------заполним пустыми поля компьютера----------------
  for (int i = 0; i< 10; i++)
  {
    for (int j= 0; j< 10; j++)
      { 
         COMP [i] [j] = 1;
      }
  }
//------заполним случайными кораблями поля компьютера----
srand(time(NULL)); 
int v=0, g=0, napravl=0, v1=0, g1=0; 

//-------------установим ч-х палубный-------------------
flag = false;
while (flag == false)
{
  v=rand()%9;
  g=rand()%9;
  napravl=rand()%7;
  COMP[v][g] = 3;
  if (napravl < 4) {if (v<5) { COMP [v+1][g] = 3; COMP [v+2][g] = 3; COMP [v+3][g] = 3;}
                    else {COMP [v-1][g] = 3; COMP [v-2][g] = 3; COMP [v-3][g] = 3;} }
  else {if (g<5) {COMP [v][g+1] = 3; COMP [v][g+2] = 3; COMP [v][g+3] = 3;}
            else {COMP [v][g-1] = 3; COMP [v][g-2] = 3; COMP [v][g-3] = 3;}}

flag = true;  
}
f_zanjat (COMP);

//-------------установим 2  3-х палубный-------------------
for (int i = 0; i<2; i++)
{
flag = false;
while (flag == false)
{
  v=rand()%9;
  g=rand()%9;
  napravl=rand()%7;
  if ((COMP[v][g] == 3) || (COMP[v][g] == 2)) continue;
  if (napravl < 4) {if (v<5) { if ((COMP [v+1][g] == 3) || (COMP [v+1][g] == 2) || (COMP [v+2][g] == 3) || 
                                                                          (COMP [v+2][g] == 2)) continue;} 
                    else { if ((COMP [v-1][g] == 3) || (COMP [v-2][g] == 3) ||
                      (COMP [v-1][g] == 2) || (COMP [v-2][g] == 2)) continue;} 
                   }
  else {if (g<5) {if ((COMP [v][g+1] == 3) || (COMP [v][g+2] == 3) ||
                      (COMP [v][g+1] == 2) || (COMP [v][g+2] == 2) ) continue;}
                  else {if ((COMP [v][g-1] == 3) || (COMP [v][g-2] == 3) ||
                            (COMP [v][g-1] == 2) || (COMP [v][g-2] == 2)) continue;}
       }
  COMP[v][g] = 3;
  if (napravl < 4) {if (v<5) { COMP [v+1][g] = 3; COMP [v+2][g] = 3;}
                    else {COMP [v-1][g] = 3; COMP [v-2][g] = 3;} }
  else {if (g<5) {COMP [v][g+1] = 3; COMP [v][g+2] = 3;}
            else {COMP [v][g-1] = 3; COMP [v][g-2] = 3;}
       }

flag = true;  
}
f_zanjat (COMP);
}
//-------------установим 3  2-х палубный-------------------
for (int i = 0; i<3; i++)
{
flag = false;
while (flag == false)
{
  v=rand()%9;
  g=rand()%9;
  napravl=rand()%7;
  if ((COMP[v][g] == 3) || (COMP[v][g] == 2)) continue;
  if (napravl < 4) {if (v<5) { if ((COMP [v+1][g] == 3) || (COMP [v+1][g] == 2)) continue;} 
                    else { if ((COMP [v-1][g] == 3) || (COMP [v-1][g] == 2)) continue;} 
                   }
  else {if (g<5) {if ((COMP [v][g+1] == 3) || (COMP [v][g+1] == 2) ) continue;}
                  else {if ((COMP [v][g-1] == 3) || (COMP [v][g-1] == 2) ) continue;}
       }
  COMP[v][g] = 3;
  if (napravl < 4) {if (v<5) { COMP [v+1][g] = 3;}
                    else {COMP [v-1][g] = 3;} }
  else {if (g<5) {COMP [v][g+1] = 3; }
            else {COMP [v][g-1] = 3; }
       }

flag = true;  
}
f_zanjat (COMP);
}
//-------------установим 4  1-палубный-------------------
for (int i = 0; i<4; i++)
{
flag = false;
while (flag == false)
{
  v=rand()%9;
  g=rand()%9;
  
  if ((COMP[v][g] == 3) || (COMP[v][g] == 2)) continue;
  COMP[v][g] = 3;

flag = true;  
}
f_zanjat (COMP);
}
// f_cout_COMP (COMP);// Отладка
for (int i = 0; i< 10; i++)// заменим занятые места кроме кораблей на свободные
{
  for (int j = 0; j < 10; j++)
  if (COMP [i][j] == 2) COMP [i][j] = 1;
}
// f_cout_COMP (COMP);// Отладка

// ---------- инициализация полей для боя ---------------
int COMP_boy[10][10];
int USER_boy[10][10];

  for (int i = 0; i< 10; i++)
  {
    for (int j= 0; j< 10; j++)
      { 
         COMP_boy [i] [j] = 1;
         USER_boy [i] [j] = 1;
         
      }
  }
//--------игра выстрелами-----------------------------
bool igra = true;
bool flag_boy;
bool flag_rand = true;
f_cout_COMP (COMP_boy);
while (igra)
{      
    flag_boy = true;
    while (flag_boy)
    { 
      cin.clear();
      cout << "Введите значение выстрела по горизонтали A - J: ";
      cin >> gor_11;
      cout << "Введите значение выстрела по вертикали 1 - 10: ";
      cin >> v;
      g = f_gor (gor_11);    
      if ((g == 0) || (v > 10) || (v < 1)) 
      {cout << "Ошибка ввода данных" << endl; continue;} 
      v=v-1; 
      g=g-1;     
      flag_boy = BOY (COMP, COMP_boy, v, g);
      f_cout_COMP (COMP_boy);
    }

    flag_boy = true;
    while (flag_boy)
    {
      flag_rand = true;
      while (flag_rand)
      {
        v=rand()%9;
        g=rand()%9;
        if (USER_boy [v][g] != 1) continue;
        else flag_rand = false;
      }
      flag_boy = BOY (User, USER_boy, v, g);
      f_cout (USER_boy);
    }

  igra = f_igra (COMP_boy);
  if (igra == false) cout << endl << "Игра завершена с победой";
  else {igra = f_igra (USER_boy);
  if (igra == false) cout <<  endl << "Игра завершена с поражением";}

}

 return 0;
}
