// My emplamentation
/*===================[Libraries]==================*/
#include <vcl.h>
#include <stdio.h>
#include <io.h>
#include <windows.h>
#include <conio.h>

/*===================[Variebles]==================*/
struct StudentStruct {
  char FIO[30];
  int GroupNumber, DateOfBirth, fiz, mat, chem, inf;
  double GPA;
} Student, TempStorForWriting;

int size = sizeof(StudentStruct);
FILE *File_Pointer;
char File_Name[] = "MyFileWithData.dat";

int kod, D_f, i = 0, j, kol;
long len;
StudentStruct st, *ArrayOfAllStudents;

bool NeedToUpdate = true;
/*===================[Functions]==================*/
void load() {
  // Load
  File_Pointer = fopen(File_Name, "rb");
  D_f = fileno(File_Pointer);
  len = filelength(D_f);
  kol = len / size;
  ArrayOfAllStudents = new StudentStruct[kol];
  // Geting data from array
  for (i = 0; i < kol; i++)
    fread((ArrayOfAllStudents + i), size, 1, File_Pointer);
  fclose(File_Pointer);
}

void save() {
  File_Pointer = fopen(File_Name, "wb");
  for (int i = 0; i < kol; ++i) {
    fwrite(&ArrayOfAllStudents[i], size, 1, File_Pointer);
  }
  fclose(File_Pointer);
}

void AddToFile(StudentStruct OutSt) {
  File_Pointer = fopen(File_Name, "ab");
  fwrite(&OutSt, size, 1, File_Pointer);
  fclose(File_Pointer);
}

void CraeteNewStudent() {
  // Add
  system("cls");
  int val = -1;

  printf("\n F.I.O. > ");
  fflush(stdin);
  gets(TempStorForWriting.FIO);

  printf(" Group Number > ");
  scanf("%d", &TempStorForWriting.GroupNumber);

  printf(" Year Of Birth > ");
  scanf("%d", &TempStorForWriting.DateOfBirth);

  while (!((val <= 10) && (val >= 0))) {
    printf(" Fizika > ");
    scanf("%d", &val);
  }
  TempStorForWriting.fiz = val;
  val = -1;

  while (!((val <= 10) && (val >= 0))) {
    printf(" Matematika > ");
    scanf("%d", &val);
  }
  TempStorForWriting.mat = val;
  val = -1;

  while (!((val <= 10) && (val >= 0))) {
    printf(" Chimija > ");
    scanf("%d", &val);
  }
  TempStorForWriting.chem = val;
  val = -1;

  while (!((val <= 10) && (val >= 0))) {
    printf(" Informatika > ");
    scanf("%d", &val);
  }
  TempStorForWriting.inf = val;

  TempStorForWriting.GPA = (TempStorForWriting.fiz + TempStorForWriting.mat +
                            TempStorForWriting.chem + TempStorForWriting.inf) /
                           4.0;
  printf(" GPA = %lf ", TempStorForWriting.GPA);
}

/*===================[Main]=======================*/
void main() {
  while (true) {
    system("cls");
    puts(
        "\n 1 Save \n 2 Load   \n 3 View all students    \n 4 Add new student  "
        "\n 5 Edit    \n 6 Task ");
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
        printf(
            "==============================[List of allstudents]==============================");
        printf(
            "\n| # |                            FIO| Group #| Year | Fiz|Mat|Chem| Inf|  GPA  |\n");
        for (int i = 0; i < kol; ++i) {
          printf("\n%3d |%30s | %6d | %4d | %2d | %2d | %2d | %2d | %6.3lf|",
                 i + 1, ArrayOfAllStudents[i].FIO,
                 ArrayOfAllStudents[i].GroupNumber,
                 ArrayOfAllStudents[i].DateOfBirth, ArrayOfAllStudents[i].fiz,
                 ArrayOfAllStudents[i].mat, ArrayOfAllStudents[i].chem,
                 ArrayOfAllStudents[i].inf, ArrayOfAllStudents[i].GPA);
        }
        printf(
            "\n==================================================================================");
        getch();
        break;

      case 4:
        // Create new student
        CraeteNewStudent();
        AddToFile(TempStorForWriting);
        NeedToUpdate = true;
        break;

      case 5:
        // Edit Student
        system("cls");
        int StudentToEdit, FieldToEdit;

        printf("Which field change? \n" );
        scanf("%d", &StudentToEdit);

         printf(   "\n 1 FIO \n 2 Group Number    \n 3 Year Of Birth   \n 4 Fizika   "
            "\n 5 Matematika    \n 6 Chimija \n 7  Infarmatika \n 8 ALL \n");
        scanf("%d", &FieldToEdit);
        switch (FieldToEdit) {
          case 1:
            printf("\n F.I.O. > ");
            fflush(stdin);
            gets(ArrayOfAllStudents[StudentToEdit - 1].FIO);
            break;

          case 2:
            printf(" Group Number > ");
            scanf("%d", &ArrayOfAllStudents[StudentToEdit - 1].GroupNumber);
            break;

          case 3:
            printf(" Year Of Birth > ");
            scanf("%d", &ArrayOfAllStudents[StudentToEdit - 1].DateOfBirth);
            break;

          case 4:
            printf(" Fizika > ");
            scanf("%d", &ArrayOfAllStudents[StudentToEdit - 1].fiz);
            ArrayOfAllStudents[StudentToEdit - 1].GPA =
                (ArrayOfAllStudents[StudentToEdit - 1].fiz +
                 ArrayOfAllStudents[StudentToEdit - 1].mat +
                 ArrayOfAllStudents[StudentToEdit - 1].chem +
                 ArrayOfAllStudents[StudentToEdit - 1].inf) /
                4.0;
            break;

          case 5:
            printf(" Matematika > ");
            scanf("%d", &ArrayOfAllStudents[StudentToEdit - 1].mat);
            ArrayOfAllStudents[StudentToEdit - 1].GPA =
                (ArrayOfAllStudents[StudentToEdit - 1].fiz +
                 ArrayOfAllStudents[StudentToEdit - 1].mat +
                 ArrayOfAllStudents[StudentToEdit - 1].chem +
                 ArrayOfAllStudents[StudentToEdit - 1].inf) /
                4.0;
            break;

          case 6:
            printf(" Chimija > ");
            scanf("%d", &ArrayOfAllStudents[StudentToEdit - 1].chem);
            ArrayOfAllStudents[StudentToEdit - 1].GPA =
                (ArrayOfAllStudents[StudentToEdit - 1].fiz +
                 ArrayOfAllStudents[StudentToEdit - 1].mat +
                 ArrayOfAllStudents[StudentToEdit - 1].chem +
                 ArrayOfAllStudents[StudentToEdit - 1].inf) /
                4.0;
            break;

          case 7:
            printf(" Infarmatika > ");
            scanf("%d", &ArrayOfAllStudents[StudentToEdit - 1].inf);
            ArrayOfAllStudents[StudentToEdit - 1].GPA =
                (ArrayOfAllStudents[StudentToEdit - 1].fiz +
                 ArrayOfAllStudents[StudentToEdit - 1].mat +
                 ArrayOfAllStudents[StudentToEdit - 1].chem +
                 ArrayOfAllStudents[StudentToEdit - 1].inf) /
                4.0;
            break;

          case 8:
            CraeteNewStudent();
            ArrayOfAllStudents[StudentToEdit - 1] = TempStorForWriting;
            break;
        }
        break;

      case 6:
        // View all students
        if (kol < 1) {
          printf("Error: No Students in file");
        }
        system("cls");
        printf(
            "======================================[Mytask]======================================");
        printf(
            "\n| # |                            FIO| Group #| Year | Fiz|Mat|Chem| Inf|  GPA  |\n");
        for (int i = 0; i < kol; ++i) {
          if ((ArrayOfAllStudents[i].fiz >= 4) &&
              (ArrayOfAllStudents[i].fiz <= 5) &&
              (ArrayOfAllStudents[i].mat >= 8) &&
              (ArrayOfAllStudents[i].chem >= 8) &&
              (ArrayOfAllStudents[i].inf >= 8)) {
            printf("\n%3d |%30s | %6d | %4d | %2d | %2d | %2d | %2d | %6.3lf|",
                   i + 1, ArrayOfAllStudents[i].FIO,
                   ArrayOfAllStudents[i].GroupNumber,
                   ArrayOfAllStudents[i].DateOfBirth, ArrayOfAllStudents[i].fiz,
                   ArrayOfAllStudents[i].mat, ArrayOfAllStudents[i].chem,
                   ArrayOfAllStudents[i].inf, ArrayOfAllStudents[i].GPA);
          }
        }
        printf("\n==================================================================================");
        getch();
        break;

      default:
        break;
    }
  }
}

