#include <stdio.h>
#include <stdlib.h> // for using libray function{system("cls")}
#include <string.h> //for using some library function{strcmp()}
 
// declare all function prototype
void interface();
void developers();
void password();
void menu_admin();
void menu_user();

void add_books();
void view_books();
void search_books();

void numberOfBooks();
void search_books_user();
void view_books_user();
void borrow_books();
void deposite_books();
void borrowBooksList();
 
/******structure for books storing****/
struct books_info
{
  int id;
  char name[10];
  char author[10];
  int quantity;
} b;
FILE *booksinfo;
FILE *booksBorrow;
FILE *booksDeposite;
 
/*************main function*************/
int main()
{
 
  interface();
 
  return 0;
}
/***************************************/
 
// function working area
void interface()
{
  /*kollan*/
  int choice1;
  system("cls");
  printf("\n\n\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|          Library Management System          |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
  printf("\n\n\t\t\t\t1.Admin area\n");
  printf("\n\n\t\t\t\t2.User area\n");
  printf("\n\n\t\t\t\t3.Developers\n\n");
  printf("\t\t\t\t-----------------------------------------------\n");
  printf("\t\t\t\tEnter to access:");
  scanf("%d", &choice1);
 
  if (choice1 == 1)
  {
    password();
    // menu_admin();
  }
  else if (choice1 == 2)
  {
    menu_user();
  }
  else if (choice1 == 3)
  {
    developers();
  }
  else
  {
    printf("\n\n\t\t\t\tWrong input\n");
    printf("\n\n\t\t\t\tpress any key to go main menu\n");
    fflush(stdin);
    getchar();
    interface();
  }
}
void developers()
{
  system("cls");
  printf("\n\n\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|          Library Management System          |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
  printf("\n\n\t\t\t\tMd.Emon\n\n");
  printf("\n\n\t\t\t\tpress Enter to get back....");
  fflush(stdin);
  getchar();
  interface();
}
void password()
{
 
  system("cls");
  printf("\n\n\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|          Library Management System          |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
  char store_pass[10] = "123"; // stored password
  char input_pass[10];         // input for password varification
  printf("\n\n\t\t\t\tEnter Password:");
  scanf("%s", input_pass);
  int compare_pass = strcmp(input_pass, store_pass);
  if (compare_pass == 0)
  {
    printf("\n\t\t\t\tCorrect password :)\n");
    // printf("\n\t\t\t\tPress any key...\n");
    menu_admin();
  }
  else
  {
    int n;
    printf("\n\t\t\t\tWrong Password :(\n");
    printf("\n\t\t\t\tPress 1 to get back or write password to access");
    scanf("%d", &n);
    if (n == 1)
    {
      interface();
    }
    else
    {
      password();
    }
    // fflush(stdin);
    // getchar();
  }
}
void menu_admin()
{
  system("cls");
  int choice2;
  printf("\n\n\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|              Menu For Admin                 |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
  printf("\n\n\t\t\t\t1.View Books\n");
  printf("\n\n\t\t\t\t2.Add Books\n");
  printf("\n\n\t\t\t\t3.Search Books\n");
  printf("\n\n\t\t\t\t4.Number of Books\n");
  printf("\n\n\t\t\t\t5.Back\n");
  printf("\n\n\t\t\t\tEnter any number:");
  scanf("%d", &choice2);
  if (choice2 == 1)
  {
    view_books();
  }
  else if (choice2 == 2)
  {
    add_books();
  }
  else if (choice2 == 3)
  {
    search_books();
  }
  else if (choice2 == 4)
  {
 
    numberOfBooks();
  }
  else if (choice2 == 5)
  {
    interface();
  }
  else
  {
    printf("\n\n\t\t\t\tWrong input\n");
    printf("\n\n\t\t\t\tpress any key to go admin menu\n");
    fflush(stdin);
    getchar();
    menu_admin();
  }
}
void menu_user()
{
 
  system("cls");
  int choice2;
  printf("\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|           Menu For User                     |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
  printf("\n\n\t\t\t\t1.Search Books\n");
  printf("\n\n\t\t\t\t2.Books List\n");
  printf("\n\n\t\t\t\t3.Borrow Books\n");
  printf("\n\n\t\t\t\t4.Deposite Books\n");
  printf("\n\n\t\t\t\t5.Back\n");
  printf("\n\n\t\t\t\tEnter any number:");
  scanf("%d", &choice2);
  if (choice2 == 1)
  {
    search_books_user();
  }
  else if (choice2 == 2)
  {
    view_books_user();
  }
  else if (choice2 == 3)
  {
    borrow_books();
  }
  else if (choice2 == 4)
  {
    deposite_books();
  }
  else if (choice2 == 5)
  {
    interface();
  }
}
void add_books()
{
 
  system("cls");
  int id, count;
  printf("\n\n\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|                     Add Books               |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
  booksinfo = fopen("books.dat", "ab+");
  printf("\n\n\t\t\t\t Enter ID:");
  scanf("%d", &id);
  rewind(booksinfo); // indicates starting bytes of file
 
  while (fread(&b, sizeof(b), 1, booksinfo) == 1)
  {
    if (id == b.id)
    {
      printf("\n\n\t\t\t\tThis books already in library...");
      count = 1;
    }
  }
  if (count == 1)
  {
    fflush(stdin);
    getchar();
    menu_admin();
  }
  b.id = id;
  printf("\n\n\t\t\t\t Enter name:");
  scanf("%s", b.name);
  printf("\n\n\t\t\t\t Enter author name:");
  scanf("%s", b.author);
  printf("\n\n\t\t\t\tEnter quantity:");
  scanf("%d", &b.quantity);
 
  fseek(booksinfo, 0, SEEK_END);       //
  fwrite(&b, sizeof(b), 1, booksinfo); // for writting file from taking info of structure
 
  fclose(booksinfo);
  printf("\n\n\t\t\t\tSuccessfully added");
  printf("\n\n\t\t\t\tPress Enter to get back.....");
  fflush(stdin);
  getchar();
  menu_admin();
}
void view_books()
{
  system("cls");
  printf("\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|          View Books                        |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
  printf("\tID\tName\t\tAuthor\tQuantity\n\n");
  booksinfo = fopen("books.dat", "rb");
  while (fread(&b, sizeof(b), 1, booksinfo) == 1)
  {
    printf("\t%d", b.id);
    printf("\t%s", b.name);
    printf("\t%s", b.author);
    printf("\t%d", b.quantity);
    printf("\n");
  }
  printf("\t\t\t\tPress Enter to get back...");
  fflush(stdin);
  getchar();
  menu_admin();
}
void search_books()
{
  system("cls");
  int id, count = 0;
  printf("\n\n\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|          Search Books                       |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
  booksinfo = fopen("books.dat", "rb");
  printf("\t\t\t\tEnter ID:");
  scanf("%d", &id);
  while (fread(&b, sizeof(b), 1, booksinfo) == 1)
 
  {
    if (id == b.id)
    {
      printf("\t\t\t\tBook Found\n");
      printf("\t\t\t\tID:%d\n", b.id);
      printf("\t\t\t\tName:%s\n", b.name);
      printf("\t\t\t\tauthor:%s\n", b.author);
      printf("\t\t\t\tQuantity:%d\n", b.quantity);
      count = 1;
    }
  }
  if (count == 0)
    printf("\t\t\t\tBook Not Found\n");
  printf("\t\t\t\tPress enter to get back....");
  fflush(stdin);
  getchar();
  menu_admin();
}
void numberOfBooks()
{
  system("cls");
  int count = 0;
  printf("\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|           Number Of Books                   |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
 
  booksinfo = fopen("books.dat", "rb");
  while (fread(&b, sizeof(b), 1, booksinfo) == 1)
  {
 
    count = count + b.quantity;
  }
  printf("\t\t\t\t            %d              \n", count);
  printf("\t\t\t\tpress any key to get back....");
 
  fflush(stdin);
  getchar();
  menu_admin();
}
void search_books_user()
{
  system("cls");
  int count = 0;
  char nam[100];
  printf("\n\n\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|          Search Books                       |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
  booksinfo = fopen("books.dat", "rb");
  printf("\t\t\t\tEnter Name:");
  scanf("%s", nam);
  while (fread(&b, sizeof(b), 1, booksinfo) == 1)
 
  {
    if ((strcmp(nam, b.name) == 0))
    {
      printf("\t\t\t\tBook Found\n");
      printf("\t\t\t\tID:%d\n", b.id);
      printf("\t\t\t\tName:%s\n", b.name);
      printf("\t\t\t\tauthor:%s\n", b.author);
      printf("\t\t\t\tQuantity:%d\n", b.quantity);
      printf("\n");
      count = 1;
    }
  }
  if (count == 0)
    printf("\t\t\t\tBook Not Found\n");
  printf("\t\t\t\tpress Enter to get back...");
  fflush(stdin);
  getchar();
  menu_user();
}
void view_books_user()
{
  system("cls");
  printf("\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|           View Books           |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
  printf("\tID\tName\t\tAuthor\tQuantity\n\n");
  booksinfo = fopen("books.dat", "rb");
  while (fread(&b, sizeof(b), 1, booksinfo) == 1)
  {
    printf("\t%d", b.id);
    printf("\t%s", b.name);
    printf("\t%s", b.author);
    printf("\t%d", b.quantity);
    printf("\n");
  }
  printf("\t\t\t\tPress enter to get back.....");
  fflush(stdin);
  getchar();
  menu_user();
}
void borrow_books()
{
  system("cls");
  int count = 0;
  char nam[100];
  printf("\n\n\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|          Enter Books Name For Borrowing     |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
  booksBorrow = fopen("borrow.dat", "rb");
   booksinfo = fopen("books.dat", "rb");
  printf("\t\t\t\tEnter Name:");
  scanf("%s", nam);
  while (fread(&b, sizeof(b), 1, booksinfo) == 1)
 
  {
    if ((strcmp(nam, b.name) == 0))
    {
 
      printf("\n\t\t\t\tID:%d\n", b.id);
      printf("\t\t\t\tName:%s\n", b.name);
      printf("\t\t\t\tauthor:%s\n", b.author);
      printf("\t\t\t\tQuantity:%d\n", b.quantity);
 
      count = 1;
    }
  }
  if (count == 0)
    printf("\t\t\t\tBook Not Found\n");
  else
  {
    int id;
    int count2 = 0;
    printf("\n\t\t\t\tEnter Books Id for Borrow:");
    scanf("%d", &id);
    booksBorrow = fopen("borrow.dat", "a");
    booksinfo = fopen("books.dat", "rb+");
    rewind(booksinfo);
    while (fread(&b, sizeof(b), 1, booksinfo) == 1)
    {
 
      if (id == b.id)
      {
        fwrite(&b, sizeof(b), 1, booksBorrow);
        count2 = 1;
      }
    }
    fclose(booksBorrow);
    if (count2 == 1)
    {
      printf("\t\t\t\tBooks Succeessfully borrowed\n");
      printf("\t\t\t\tYou Have To return your books within 7 Days\n");
      printf("\t\t\t\tEnter Enter to get back....");
    }
  }
 
  fflush(stdin);
  getchar();
  menu_user();
}
void deposite_books()
{
  system("cls");
  int n, id, count = 0;
  printf("\n\n\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|          Enter Books Name For Borrowing     |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
  printf("\n\t\t\t\t1.view Borrowed books\n");
  printf("\n\t\t\t\t2.Deposite Book\n");
  printf("\n\t\t\t\t3.Exit\n\n");
   printf("\n\t\t\t\tEnter number:");
 booksBorrow = fopen("borrow.dat", "rb+");
  scanf("%d", &n);
  if (n == 1)
  {
    borrowBooksList();
  }
  else if(n==2){
  printf("\n\t\t\t\tEnter Books Id for Deposite:");
  scanf("%d", &id);
 
  booksDeposite = fopen("deposite.dat", "wb+");
  rewind(booksBorrow);
 
  while (fread(&b, sizeof(b), 1, booksBorrow) == 1)
  {
    if (id != b.id)
    {
      fseek(booksDeposite, ftell(booksDeposite)-sizeof(b), 0);
      fwrite(&b, sizeof(b), 1, booksDeposite);
      count = 1;
    }
  }
  fclose(booksBorrow);
  fclose(booksDeposite);
  remove("borrow.dat");
  rename("deposite.dat", "borrow.dat");
  booksBorrow = fopen("borrow.dat", "rb+");
  fclose(booksBorrow);
 
    printf("\t\t\t\tBook Deposited\n");
    printf("\t\t\t\tPress Eneter to get back...");
    fflush(stdin);
    getchar();
    menu_user();
 
  }
  else if(n==3) menu_user();
}
void borrowBooksList()
{
 
  system("cls");
  printf("\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|           View Books                        |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
  printf("\tID\tName\tAuthor\tQuantity\n\n");
  booksBorrow = fopen("borrow.dat", "rb");
  while (fread(&b, sizeof(b), 1, booksBorrow) == 1)
  {
    printf("\t%d", b.id);
    printf("\t%s", b.name);
    printf("\t%s", b.author);
    printf("\t%d", b.quantity);
    printf("\n");
  }
  printf("\t\t\t\tPress enter to get back.....");
  fflush(stdin);
  getchar();
  deposite_books();
}