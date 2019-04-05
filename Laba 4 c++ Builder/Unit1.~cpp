/*===================[Libraries]==================*/
#include <vcl.h>
#include <stdio.h>
#include <io.h>
#include <windows.h>
#include <conio.h>
using namespace std;
/*===================[Variebles]==================*/
struct callStruct {
  char date[12], city[20], incomingNum[14], outcomingNum[14];
  int cityCode;
  double price, time;
} call, TempStorForWriting;

int size = sizeof(callStruct);
FILE *File_Pointer;
char File_Name[] = "MyFileWithData.dat";

int kod, D_f, i = 0, j, kol;
long len;
callStruct st, *ArrayOfAllCall;

bool NeedToUpdate = true;
/*===================[Functions]==================*/
void load();                          //???????? ?? ????? ? ??????
void save();                          //?????????? ? ????
void AddToFile(callStruct OutSt);     //?????????? ? ????
void CraeteNewCall();                 //??????? ????? ??????
void binary_search();                 //???????? ?????
void linely_search();                 //???????? ?????
void QuicSort(int left, int right);   //??????? ??????????
void linely_sort();                   //???????? ??????????
void MyTask();                        //????? ?????? ??????? ?????????? ? ???????

/*===================[Main]=======================*/
void main() {
  while (true) {
    system("cls");
    puts("\n 1 Save      \n 2 Load   \n 3 View all calls    \n 4 Add new  "
         "\n 5 QuicSort  \n 6 linely sort \n 7 Binary search \n 8 Lineary search \n 9 My task");
    scanf("%d", &kod);

    if (NeedToUpdate == true) {
      NeedToUpdate = false;
      load();
    }

    if (kod == 4) {
      save();
    }

    switch (kod) {
      case 1:
        // Save data to file
        save();
        break;

      case 2:
        // Load data from file
        load();
        break;

      case 3:
        // View all students
        system("cls");
        printf("==============================[List of all calls]==============================");
        printf("\n \n");
        for (int i = 0; i < kol; ++i) {
          printf("\n %3d | %11s | %21s | %3d | %14s | %14s | %5lf | %5lf ",
                 i + 1, 
                 ArrayOfAllCall[i].date,
                 ArrayOfAllCall[i].city,
                 ArrayOfAllCall[i].cityCode,
                 ArrayOfAllCall[i].incomingNum,
                 ArrayOfAllCall[i].outcomingNum,
                 ArrayOfAllCall[i].time,
                 ArrayOfAllCall[i].price
                 );
        }
        printf("\n==================================================================================");
        getch();
        break;

      case 4:
        // Create new student
        CraeteNewCall();
        AddToFile(TempStorForWriting);
        NeedToUpdate = true;
        break;

      case 5:
        QuicSort(0, (kol - 1));
        break;

      
      case 6:
        linely_sort();        
        break;

      case 7:
        binary_search();
        break;

      case 8:
        linely_search();
        break;

      case 9:
        MyTask();
        break;

      default:
        break;
    }
  }
}

/*===================[Functions]==================*/
void load() {
  // Load
  File_Pointer = fopen(File_Name, "rb");
  D_f = fileno(File_Pointer);
  len = filelength(D_f);
  kol = len / size;
  ArrayOfAllCall = new callStruct[kol];
  // Geting data from array
  for (i = 0; i < kol; i++)
    fread((ArrayOfAllCall + i), size, 1, File_Pointer);
  fclose(File_Pointer);
}

void save() {
  File_Pointer = fopen(File_Name, "wb");
  for (int i = 0; i < kol; ++i) {
    fwrite(&ArrayOfAllCall[i], size, 1, File_Pointer);
  }
  fclose(File_Pointer);
}

void AddToFile(callStruct OutSt) {
  File_Pointer = fopen(File_Name, "ab");
  fwrite(&OutSt, size, 1, File_Pointer);
  fclose(File_Pointer);
}

void CraeteNewCall() {
  // Add
  system("cls");

  printf("\n date > \n");
  fflush(stdin);
  gets(TempStorForWriting.date);
                
  printf("\n city > \n");
  fflush(stdin);
  gets(TempStorForWriting.city);                 

  printf("\n cityCode > \n");
  scanf("%d", &TempStorForWriting.cityCode);

  printf("\n incomingNum > \n");
  fflush(stdin);
  gets(TempStorForWriting.incomingNum);             

  printf("\n outcomingNum > \n");
  fflush(stdin);
  gets(TempStorForWriting.outcomingNum);                 

  printf("\n time > \n");
  scanf("%lf", &TempStorForWriting.time);

  printf("\n price > \n");
  scanf("%lf", &TempStorForWriting.price);
 }

void binary_search()
{
	system("cls");
	int  CityCodeSearchingFor;
	int i = 0, j=kol, n;
	printf("Enter the sity code which to search for:\t");
	scanf("%d", &CityCodeSearchingFor);
	printf("\n\n");
	while (i < j) {
		n = (i + j) / 2;
		if (CityCodeSearchingFor > ArrayOfAllCall[n].cityCode)
			i = n + 1;
		else j = n;
	}

	if (ArrayOfAllCall[i].cityCode == CityCodeSearchingFor)
	{
		int f = i;
		while (f <= kol && f >= 0)
		{//left
			if (ArrayOfAllCall[f].cityCode == CityCodeSearchingFor) {
				printf("\n %3d %10s %20s %3d %13s %13s  %5lf %5lf ",
                 f + 1, 
                 ArrayOfAllCall[f].date,
                 ArrayOfAllCall[f].city,
                 ArrayOfAllCall[f].cityCode,
                 ArrayOfAllCall[f].incomingNum,
                 ArrayOfAllCall[f].outcomingNum,
                 ArrayOfAllCall[f].time,
                 ArrayOfAllCall[f].price
                 );
			} 
			f--;
		} 

		f = i + 1;
		while (f <= kol && f >= 0)
		{//right
                if (ArrayOfAllCall[f].cityCode == CityCodeSearchingFor) {
				printf("\n %3d %10s %20s %3d %13s %13s  %5lf %5lf ",
                 f + 1,
                 ArrayOfAllCall[f].date,
                 ArrayOfAllCall[f].city,
                 ArrayOfAllCall[f].cityCode,
                 ArrayOfAllCall[f].incomingNum,
                 ArrayOfAllCall[f].outcomingNum,
                 ArrayOfAllCall[f].time,
                 ArrayOfAllCall[f].price
                 );
			}
			f++;	
		}
	}
	else
	{
		printf("No match!");
	}
	system("pause");
}

void linely_search() {
  system("cls");
  int nu = 0, val;
  printf( "Enter city code:\t");
  scanf("%d",&val);

  for (int i = 0; i < kol; i++)
  {
    if (ArrayOfAllCall[i].cityCode == val) {
      nu++;
      printf("\n %3d %10s %20s %3d %13s %13s  %5lf %5lf ",
                 i + 1, 
                 ArrayOfAllCall[i].date,
                 ArrayOfAllCall[i].city,
                 ArrayOfAllCall[i].cityCode,
                 ArrayOfAllCall[i].incomingNum,
                 ArrayOfAllCall[i].outcomingNum,
                 ArrayOfAllCall[i].time,
                 ArrayOfAllCall[i].price
                 );
    }
  }

  if (nu == 0) printf("No matches");
  printf("\n");
  system("pause");
}

void QuicSort(int left, int right)
{
  int i = left, j = right;
  callStruct t, x;
  x = ArrayOfAllCall[(i + j) / 2];
  do {
    while (ArrayOfAllCall[i].cityCode < x.cityCode && i < right) i++;
    while (ArrayOfAllCall[j].cityCode > x.cityCode && j > left) j--;
    if (i <= j) {
      t = ArrayOfAllCall[i];
      ArrayOfAllCall[i] = ArrayOfAllCall[j];
      ArrayOfAllCall[j] = t;
      i++; j--;
    }
  } while (i <= j);
  if (left < j) QuicSort(left, j);
  if (i < right) QuicSort(i, right);
}

void linely_sort()
{
  callStruct Buff;
  for (int y = 0; y < kol; y++)
  {
    for (int l = kol - 1; l > y; l--)
    {
      if (ArrayOfAllCall[l - 1].cityCode > ArrayOfAllCall[l].cityCode)
      {
        Buff = ArrayOfAllCall[l - 1];
        ArrayOfAllCall[l - 1] = ArrayOfAllCall[l];
        ArrayOfAllCall[l] = Buff;
      }
    }
  }
}

void MyTask(){
  float totalPriceSumm = ArrayOfAllCall[0].price, totalTime = ArrayOfAllCall[0].time;
  bool display = false;
  for (int i = 1; i < kol; ++i) {
   if (kol == (i + 1)){
      totalPriceSumm += ArrayOfAllCall[i].price;
      totalTime += ArrayOfAllCall[i].time;
      display = true;
   	} else {
    	if((ArrayOfAllCall[i].cityCode == ArrayOfAllCall[i - 1].cityCode)) {
      		totalPriceSumm += ArrayOfAllCall[i].price;
      		totalTime += ArrayOfAllCall[i].time;
    	} else {
    		display = true;
    	}
    }
    if(display == true) {
      printf("\n %20s | Toal time: %5lf | Total price summ: %5lf", ArrayOfAllCall[i - 1].city, totalTime, totalPriceSumm);
      totalPriceSumm = ArrayOfAllCall[i].price;
      totalTime = ArrayOfAllCall[i].time;
      display = false;
    }
  }
  printf("\n");
  system("pause");
}
