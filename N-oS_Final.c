#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <windows.h>
#include <time.h>

void show_menu ();
void show_power_menu ();
void access_directory (int in);
void f_copy (char str2[]);
void f_cut (char str2[]);
void f_paste (char str[]);
void open_dir (char str_dir[]);
void f_access (char str2[]);
void f_delete (char str2[]);
void f_rename (char str2[]);
void f_new (char str2[]);
void power ();
void shut_down();
void restart();
void open_file (char str2[]);
void time_date ();
void design ();
void NoS ();
void login ();
void sign_up();
void start_up();
void my_computer();
void directory_list ();
void browser ();
void web_page();
void web();
void open_bookmark ();
void settings ();
void history ();
void view_history ();
void search_file ();
void admin_menu ();
void user_menu ();
int bookmark(char url[]);
void acc_delete ();
void user_menu();
void change_password();
void clear_bookmarks();

char str[1000][100];
char str_dir [1000];
char str2[1000];
char s_cpy_pst[1000];
char save_cpy_str[1000];
char str_drive[15];
char str_delete[1000];
char str_rename[1000];
char url[100];
char back_dr [25];
char wb_url[100];
int p_menu_size = 120;
int i,h=0,b=1,x=0,entry=-1,l=1;
int cpy_cut = 0;

struct info
{
    char name[30];
    char password[15];
};
struct info member[100];

int main ()
{
    FILE *fp;
    strcpy(member[0].name,"Nafis");
    strcpy(member[1].name,"Rafi");
    strcpy(member[0].password,"124407");
    strcpy(member[1].password,"124422");
    if (fopen("f:\\login.txt","r")==NULL)
    {
        fp = fopen ("f:\\login.txt","w");
        fprintf (fp,"%s %s\n%s %s",member[0].name,member[0].password,member[1].name,member[1].password);
        fclose(fp);
    }
    fflush(stdin);
    //start_up();
    NoS();
    return 0;
}

void start_up()
{
    int in=1,k;
    char ch;
    while (ch!=13)
    {
        system("cls");
        time_date();
        printf ("\n\n\t\t");
        for (k=1; k<=60; k++) printf ("%c",176);
        if(in==1)  printf("\n\t\t%c%c-> LOGIN                                                %c%c",176,176,176,176);
        else printf("\n\t\t%c%c Login                                                  %c%c",176,176,176,176);
        if (in==3) printf ("\n\t\t%c%c-> EXIT                                                 %c%c",176,176,176,176);
        else printf ("\n\t\t%c%c Exit                                                   %c%c",176,176,176,176);
        printf ("\n\t\t");
        for (k=1; k<=60; k++) printf ("%c",176);
        printf ("\n");
        ch=getch();
        if(ch==72) in--;
        else if(ch==80) in++;
        if(in>2) in=1;
        else if(in<1) in=2;
    }
    switch (in)
    {
    case 1:
        login();
        break;
    case 2:
        exit(1);
    }
}

void sign_up()
{
    system("cls");
    int j=0,k,flag=1,t,c=0;
    char ch,nm[30];
    struct info nme;
    FILE *fp;
    fp = fopen("d:\\login.txt","r");
    while (k!=EOF)
    {
        k=fscanf (fp,"%s",nme.name);
        c++;
    }
    x=c;
    fclose(fp);
    fp=fopen("d:\\login.txt","a");
    time_date();
    printf ("\n\t\tEnter Name: ");
    scanf ("%s",&member[x].name);
    printf ("\n\t\tEnter Password: ");
    scanf ("%s",&member[x].password);
    fflush(stdin);
    fprintf (fp,"\n%s %s",member[x].name,member[x].password);
    fclose(fp);
    fflush(stdin);
    system ("cls");
    printf ("\n\n\n\n\n\t\t\t\tSIGNED  UP  SUCCESSFULLY !!");
    getchar();
    admin_menu();
}

void login()
{
    system("cls");
    time_date();
    FILE *fp;
    int t,y,k,flag=1,d;
    char nm [30],ps[15];
    struct info nme;
    fflush(stdin);
    fp = fopen ("d:\\login.txt","r");
    printf ("\n\t\tEnter Name: ");
    scanf ("%s",&nm);
    printf ("\n\t\tEnter Password: ");
    scanf("%s",&ps);
    fflush(stdin);
    while (k!=EOF)
    {
        k=fscanf (fp,"%s",&nme.name);
        t=stricmp(nme.name,nm);
        if (t==0)
        {
            if ((!(stricmp(nm,"Nafis"))) || (!(stricmp(nm,"Rafi"))))
            {
                fscanf (fp,"%s",&nme.password);
                if (!(strcmp(ps,nme.password)))
                {
                    flag=0;
                    strupr(nme.name);
                    system("cls");
                    printf ("\n\n\t\tWELCOME  ADMIN  %s\n",nme.name);
                    printf ("\n\t\tLOGGING  IN !!!  PLEASE  WAIT");
                    for (d=1; d<=3; d++)
                    {
                        printf (".");
                        Sleep(1000);
                    }
                    fflush(stdin);
                    admin_menu();
                    break;
                }
            }
            else
            {
                fscanf (fp,"%s",&nme.password);
                if (!(strcmp(ps,nme.password)))
                {
                    flag=0;
                    strupr(nme.name);
                    system("cls");
                    printf ("\n\t\tWELCOME  USER  %s\n",nme.name);
                    printf ("\n\t\tLOGGING IN !!! PLEASE  WAIT");
                    for (d=1; d<=3; d++)
                    {
                        printf (".");
                        Sleep(1000);
                    }
                    fflush(stdin);
                    NoS();
                    break;
                }
            }
        }
    }
    if (flag==1)
    {
        if (l==3)
        {
            system ("cls");
            printf ("\n\n\n\n\t\t\t\tPROGRAM  SELF  TERMINATING");
            for (d=1; d<=3; d++)
            {
                printf (".");
                Sleep(1000);
            }
            printf ("\n\n");
            fclose(fp);
            fflush(stdin);
            exit(1);
        }
        printf ("\n\t\tACCESS  DENIED...  ");
        printf ("TRY  AGAIN !! ");
        l++;
        getchar();
        fclose(fp);
        login();
    }
}

void admin_menu()
{
    int in=1,k,d;
    char ch;
    while (ch!=13)
    {
        system("cls");
        time_date();
        printf ("\n\t\t");
        for (k=1; k<=60; k++) printf ("%c",176);
        if(in==1) printf("\n\t\t%c%c-> N-oS                                                 %c%c",176,176,176,176);
        else printf("\n\t\t%c%c N-oS                                                   %c%c",176,176,176,176);
        if(in==2) printf("\n\t\t%c%c-> CREATE USER ACCOUNT                                  %c%c",176,176,176,176);
        else printf("\n\t\t%c%c Create User Account                                    %c%c",176,176,176,176);
        if(in==3) printf("\n\t\t%c%c-> DELETE USER ACCOUNT                                  %c%c",176,176,176,176);
        else printf("\n\t\t%c%c Delete User Account                                    %c%c",176,176,176,176);
        if(in==4) printf ("\n\t\t%c%c-> LOG OUT                                              %c%c",176,176,176,176);
        else printf ("\n\t\t%c%c Log Out                                                %c%c",176,176,176,176);
        printf ("\n\t\t");
        for (k=1; k<=60; k++) printf ("%c",176);
        printf ("\n");
        ch=getch();
        if(ch==72) in--;
        else if(ch==80) in++;
        if(in>4) in=1;
        else if(in<1) in=4;
    }
    switch (in)
    {
    case 1:
        NoS();
        break;
    case 2:
        sign_up();
        break;
    case 3:
        acc_delete();
        break;
    case 4:
        printf ("\n\n\t\tLOGGING OFF");
        for (d=1; d<=3; d++)
        {
            printf (".");
            Sleep(1000);
        }
        start_up();
    }
}

void acc_delete()
{
    FILE *fp;
    system("cls");
    time_date();
    char s[100][100],tmp[100];
    int t[100],k=0,j=0,flag=1,x;
    printf ("\n\n\n\t\t\t ENTER NAME: ");
    gets(tmp);
    fflush(stdin);
    fp = fopen("d:\\login.txt","r");
    while(fscanf(fp,"%s %d",&str[k],&t[k])!=EOF)
    {
        if (!(strcmp(tmp,str[k])))
        {
            x=k;
            if (fscanf(fp,"%s %d",&str[k+1],&t[k+1])==EOF)
            {
                fclose(fp);
                fp = fopen("d:\\login.txt","w");
                while (j<=k-1)
                {
                    fprintf(fp,"%s %d\n",str[j],t[j]);
                    j++;
                }
                fclose(fp);
            }
            else
            {
                fclose(fp);
                fp = fopen("d:\\login.txt","w");
                k++;
                flag=0;
                continue;
            }
        }
        k++;
    }
    if (flag==0)
    {
        j=0;
        while (j<k)
        {
            if (j==x) j++;
            fprintf(fp,"%s %d\n",str[j],t[j]);
            j++;
        }
        fclose(fp);
    }
    strupr(tmp);
    printf ("\n\n\n\n\n\n\t\t\t\tUSER  %s'S, ACCOUNT  HAS  BEEN  DELETED !!",tmp);
    getchar();
    fflush(stdin);
    admin_menu();
}

void NoS ()
{
    int in=1,k,d;
    char ch;
    while (ch!=13)
    {
        system("cls");
        time_date();
        printf ("\n\t\t");
        for (k=1; k<=60; k++) printf ("%c",176);
        if(in==1) printf("\n\t\t%c%c-> MY COMPUTER                                          %c%c",176,176,176,176);
        else printf("\n\t\t%c%c My Computer                                            %c%c",176,176,176,176);
        if(in==2) printf("\n\t\t%c%c-> N-exT (WEB INTERFACE)                                %c%c",176,176,176,176);
        else printf("\n\t\t%c%c N-exT (Web Interface)                                  %c%c",176,176,176,176);
        if(in==3) printf("\n\t\t%c%c-> POWER                                                %c%c",176,176,176,176);
        else printf("\n\t\t%c%c Power                                                  %c%c",176,176,176,176);
        if (in==4) printf ("\n\t\t%c%c-> LOG OUT                                              %c%c",176,176,176,176);
        else printf ("\n\t\t%c%c Log Out                                                %c%c",176,176,176,176);
        printf ("\n\t\t");
        for (k=1; k<=60; k++) printf ("%c",176);
        printf ("\n");
        ch=getch();
        if(ch==72) in--;
        else if(ch==80) in++;
        if(in>4) in=1;
        else if(in<1) in=4;
    }
    switch (in)
    {
    case 1:
        my_computer();
        break;
    case 2:
        web();
        break;
    case 3:
        power();
        break;
    case 4:
        printf ("\n\n\t\tLOGGING OFF");
        for (d=1; d<=5; d++)
        {
            printf (".");
            Sleep(1000);
        }
        start_up();
    }
}

void my_computer ()
{
    system("cls");
    time_date();
    int i,k;
    DIR *dir;
    fflush(stdin);
    char c[5],ch,s_dir[5]= {"\0"},disp_c[50],dr[5]= {"\0"};
    strcpy(disp_c,"LOCAL DISK (");
    printf ("\n\n\t\t");
    for (k=1; k<=60; k++) printf ("%c",176);
    for (ch='a'; ch<='z'; ch++)
    {
        c[0]=ch;
        strcpy (s_dir,c);
        strcat(s_dir,":\\");
        if ((dir = opendir(s_dir)) != NULL)
        {
            strupr(c);
            strcat(disp_c,c);
            strcat(disp_c,":)");
            printf ("\n\t\t%c%c %s                                        %c%c",176,176,disp_c,176,176);
            strcpy (disp_c,"LOCAL DISK (");
        }
    }
    printf ("\n\t\t");
    for (k=1; k<=60; k++) printf ("%c",176);
    printf ("\n\n\n\t\tWRITE  THE  NAME  OF  THE  DRIVE  YOU  WANT  TO  ACCESS (Small Letter):   ");
    fflush(stdin);
    dr[0]=getchar();
    puts(dr);
    strcpy(str_dir,dr);
    strcat (str_dir,":\\");
    strcpy (back_dr,str_dir);
    strcpy (str_drive,str_dir);
    strupr (str_drive);
    open_dir(str_dir);
    system("cls");
    show_power_menu();
}

void open_dir (char str_dir[])
{
    system("cls");
    time_date();
    printf ("\n\t\t\t\t[ Press 0 to open Power Menu ]");
    int num,t;
    char ch,tmp[300],name[300];
    DIR *dir;
    printf ("\n\n");
    struct dirent *ent;
    int j,k,l,len,space,flag=1;
    i=0;
    if ((dir = opendir(str_dir)) != NULL)
    {
        while ((ent = readdir (dir)) != NULL)
        {
            strcpy (str[i],ent->d_name);
            i++;
        }
        closedir (dir);
        for (k=1; k<=p_menu_size; k++) printf ("%c",176);
        printf ("\n");
        for (j=0; j<i; j++)
        {
            printf ("%c%c   %2d.  %s",176,176,j+1,str[j]);
            len = strlen (str[j]);
            space = p_menu_size -(len+12);
            for (l=1; l<=space; l++) printf (" ");
            printf ("%c%c\n",176,176);
        }
        printf ("%c%c                                                                                                                    %c%c\n",176,176,176,176);
        for (k=1; k<=p_menu_size; k++) printf ("%c",176);
        printf ("\n\n\t\tDIRECTORY: %s\n",str_dir);
        printf ("\n\t\tPlease Write The File/Directory Number You Want To Access: ");
        scanf ("%d",&num);
        getchar();
        if (num==0) show_power_menu();
        else
        {
            fflush(stdin);
            strcpy (str2,str[num-1]);
        }
        strcpy(tmp,str2);
        for (t=0; tmp[t]; t++)
        {
            if (tmp[t]==' ') flag=0, tmp[t] = '_';
        }
        if (flag==0)
        {
            strcpy (name,"rename ");
            strcat (name,"\"");
            strcat (name,str_dir);
            strcat (name,str2);
            strcat (name,"\" ");
            strcat (name,tmp);
            puts(name);
            strcpy(str2,tmp);
            puts(str2);
            strcpy (str[num-1],str2);
            puts(str[num-1]);
            system(name);
        }
    }
}

void show_power_menu()
{
    int in = 1,j,k,l;
    char ch;
    while (ch!=13)
    {
        system("cls");
        time_date();
        printf ("\n\t\t");
        for (k=1; k<=60; k++) printf ("%c",176);
        if(in==1) printf("\n\t\t%c%c  -> ACCESS DIRECTORY                                   %c%c",176,176,176,176);
        else printf("\n\t\t%c%c  Access Directory                                      %c%c",176,176,176,176);
        if(in==2) printf("\n\t\t%c%c  -> OPEN FILE                                          %c%c",176,176,176,176);
        else printf("\n\t\t%c%c  Open File                                             %c%c",176,176,176,176);
        if(in==3) printf("\n\t\t%c%c  -> COPY                                               %c%c",176,176,176,176);
        else printf("\n\t\t%c%c  Copy                                                  %c%c",176,176,176,176);
        if(in==4) printf("\n\t\t%c%c  -> CUT                                                %c%c",176,176,176,176);
        else printf("\n\t\t%c%c  Cut                                                   %c%c",176,176,176,176);
        if(in==5) printf("\n\t\t%c%c  -> PASTE                                              %c%c",176,176,176,176);
        else printf("\n\t\t%c%c  Paste                                                 %c%c",176,176,176,176);
        if(in==6) printf("\n\t\t%c%c  -> DELETE                                             %c%c",176,176,176,176);
        else printf("\n\t\t%c%c  Delete                                                %c%c",176,176,176,176);
        if(in==7) printf("\n\t\t%c%c  -> RENAME                                             %c%c",176,176,176,176);
        else printf("\n\t\t%c%c  Rename                                                %c%c",176,176,176,176);
        if(in==8) printf("\n\t\t%c%c  -> NEW                                                %c%c",176,176,176,176);
        else printf("\n\t\t%c%c  New                                                   %c%c",176,176,176,176);
        if(in==9) printf("\n\t\t%c%c  -> LIST DIRECTORY                                     %c%c",176,176,176,176);
        else printf("\n\t\t%c%c  List Directory                                        %c%c",176,176,176,176);
        if(in==10) printf("\n\t\t%c%c  -> SEARCH                                             %c%c",176,176,176,176);
        else printf("\n\t\t%c%c  Search                                                %c%c",176,176,176,176);
        if(in==11) printf("\n\t\t%c%c  -> BACK TO MY COMPUTER                                %c%c",176,176,176,176);
        else printf("\n\t\t%c%c  Back to My Computer                                   %c%c",176,176,176,176);
        printf ("\n\t\t");
        for (k=1; k<=60; k++) printf ("%c",176);
        ch=getch();
        if(ch==72) in--;
        else if(ch==80) in++;
        if(in>11) in=1;
        else if(in==0) in=11;
    }
    system("cls");
    switch (in)
    {
    case 1:
        f_access(str2);
        break;
    case 2:
        open_file (str2);
        break;
    case 3:
        f_copy (str2);
        break;
    case 4:
        f_cut (str2);
        break;
    case 5:
        f_paste (str2);
        break;
    case 6:
        f_delete (str2);
        break;
    case 7:
        f_rename(str2);
        break;
    case 8:
        f_new(str2);
        break;
    case 9:
        directory_list();
        break;
    case 10:
        search_file();
        break;
    case 11:
        system ("cls");
        NoS();
        break;
    }
}

void f_access (char str2[])
{
    int j;
    for (j=0; j<=i; j++)
    {
        if (!(stricmp(str[j],str2)))
        {
            strcat (str_dir,str2);
            strcat (str_drive,str2);
            strcat (str_dir,"\\");
            strcat (str_drive,"\\");
            break;
        }
    }
    open_dir(str_dir);
    show_power_menu();
}

void f_copy (char str2[])
{
    int j;
    cpy_cut=1;
    strcpy(save_cpy_str,str2);
    char cp [] = "xcopy \"";
    char str_cpy [1000];
    strcpy(str_cpy,str_dir);
    for (j=0; j<=i; j++)
    {
        if (!(stricmp(str[j],str2)))
        {
            strcat(str_cpy,str2);
            strcat (str_cpy,"\" \"");
            strcat (cp,str_cpy);
            break;
        }
    }
    strcpy(s_cpy_pst,cp);
    printf ("\n\n\t\t\tNow Choose A Directory Where You Want To Paste.");
    getchar ();
    NoS();
}

void f_paste(char str2[])
{
    int k,j;
    system("cls");
    if (cpy_cut==1)
    {
        for (j=1; j<=3; j++)
        {
            printf ("\n\n\n\n\t\t\t\t");
            printf ("COPYING");
            for (k=1; k<=3; k++)
            {
                printf (".");
                Sleep(1000);
            }
            system("cls");
        }
        system("cls");
        time_date();
        printf ("\n\n\n\n\t\t\t\t");
        printf ("COPIED  SUCCESSFULLY !!");
    }
    else if (cpy_cut==2)
    {
        for (j=1; j<=3; j++)
        {
            printf ("\n\n\n\n\t\t\t\t");
            printf ("MOVING");
            for (k=1; k<=3; k++)
            {
                printf (".");
                Sleep(1000);
            }
            system("cls");
        }
        system("cls");
        time_date();
        printf ("\n\n\n\n\t\t\t\t");
        printf ("MOVED  SUCCESSFULLY !!");
    }
    strcat (str_dir,save_cpy_str);
    strcat(s_cpy_pst,str_dir);
    strcat (s_cpy_pst,"\"");
    system (s_cpy_pst);
    cpy_cut=0;
    getchar ();
    system ("cls");
    NoS();
}

void f_cut (char str2[])
{
    int j;
    cpy_cut=2;
    strcpy(save_cpy_str,str2);
    char cp [] = "move \"";
    char str_cpy [1000];
    strcpy(str_cpy,str_dir);
    for (j=0; j<=i; j++)
    {
        if (!(stricmp(str[j],str2)))
        {
            strcat(str_cpy,str2);
            strcat (str_cpy,"\" \"");
            strcat (cp,str_cpy);
            break;
        }
    }
    strcpy(s_cpy_pst,cp);
    printf ("\n\n\t\t\tNow Choose A Directory Where You Want To Paste.");
    getchar ();
    NoS();
}

void f_delete(char str2[])
{
    int in=1;
    char ch;
    while (ch!=13)
    {
        system("cls");
        time_date();
        if(in==1) printf("\n\t\t-> DELETE A FOLDER");
        else printf("\n\t\t Delete A Folder");
        if(in==2) printf("\n\t\t-> DELETE A FILE");
        else printf("\n\t\t Delete A File");
        printf ("\n");
        ch=getch();
        if(ch==72) in--;
        else if(ch==80) in++;
        if(in>2) in=1;
        else if(in<1) in=2;
    }
    if (in==1)
    {
        strcpy(str_delete,"rmdir/s/q ");
        strcat (str_dir,str2);
        strcat (str_delete,str_dir);
    }
    else if (in==2)
    {
        strcpy(str_delete,"DEL/P/F/S/A ");
        strcat (str_drive,str2);
        strcat (str_delete,str_drive);
    }
    system (str_delete);
    getchar ();
    system ("cls");
    NoS();
}

void f_rename(char str2[])
{
    char str_new_name[1000];
    char ch[1000];
    time_date();
    printf ("\n\nEnter New Name With Extention <No Space Or Invalid Characters>: ");
    gets(ch);
    strcpy (str_rename,"rename ");
    strcat (str_rename,"\"");
    strcat (str_rename,str_dir);
    strcat (str_rename,str2);
    strcat (str_rename,"\"");
    strcat (str_rename," ");
    strcat (str_new_name,ch);
    strcat (str_rename,str_new_name);
    system (str_rename);
    getchar ();
    system ("cls");
    NoS();
}

void f_new(char str2[])
{
    char ch,tmp[200];
    int in=1;
    char name[30];
    char type[10];
    FILE *fp;
    time_date();
    printf ("\n\n\t\tWrite Name: ");
    gets(name);
    while (ch!=13)
    {
        system("cls");
        printf ("\n\n\t\tSpecify Type: ");
        time_date();
        if(in==1) printf("\n\t\t-> DATA FILE (.DAT)");
        else printf("\n\t\t Data File (.dat)");
        if(in==2) printf("\n\t\t-> MICROSOFT EXCEL WORKSHEET (.XLSX)");
        else printf("\n\t\t Microsoft Excel Worksheet (.xlsx)");
        if(in==3) printf("\n\t\t-> CONACT FILE (.CONTACT)");
        else printf("\n\t\t Contact File (.contact)");
        if(in==4) printf("\n\t\t-> TEXT FILE (.TXT)");
        else printf("\n\t\t Text File (.txt)");
        if(in==5) printf("\n\t\t-> MICROSOFT WORD DOCUMENT (.DOC)");
        else printf("\n\t\t Microsoft Word Document(.doc)");
        if (in==6) printf ("\n\t\t-> MICROSOFT POWER POINT PRESENTATION (.PPT)");
        else printf ("\n\t\t Microsoft Power POint Presentation (.ppt)");
        if (in==7) printf ("\n\t\t-> FOLDER");
        else printf ("\n\t\t Folder");
        if(in==8) printf("\n\t\t-> OTHERS (PLEASE SPECIFY)\n");
        else printf("\n\t\t Others (Please Specify)\n");
        ch=getch();
        if(ch==72) in--;
        else if(ch==80) in++;
        if(in>8) in=1;
        else if(in==0) in=8;
    }
    if (in==1) strcpy (type,".dat");
    else if (in==2) strcpy (type,".xlsx");
    else if (in==3) strcpy (type,".contact");
    else if (in==4) strcpy (type,".txt");
    else if (in==5) strcpy (type,".doc");
    else if (in==6) strcpy (type,".ppt");
    else if (in==7)
    {
        strcpy (tmp,"md ");
        strcat(str_drive,name);
        strcat(tmp,str_drive);
        system(tmp);
        system("cls");
        printf ("\n\n\n\t\t\t\t NEW FOLDER CREATED !!");
    }
    else if (in==8)
    {
        printf ("\n\t\t");
        gets (type);
    }
    if (in!=7)
    {
        strcat(str_drive,name);
        strcat (str_drive,type);
        fp = fopen(str_drive,"w");
        getchar ();
        fclose(fp);
        system("cls");
        printf ("\n\n\n\t\t\t\t NEW FILE CREATED !!");
        fflush(stdin);
    }
    system ("cls");
    NoS();
}

void power()
{
    int in=1;
    char ch;
    while (ch!=13)
    {
        system("cls");
        time_date();
        if(in==1) printf("\n\t\t-> SHUTDOWN");
        else printf("\n\t\t Shutdown");
        if(in==2) printf("\n\t\t-> RESTART");
        else printf("\n\t\t Restart");
        if (in==3) printf ("\n\t\t-> LOG OFF");
        else printf ("\n\t\t Log Off");
        if (in==4)printf ("\n\t\t-> ABORT");
        else printf ("\n\t\t Abort");
        if (in==5) printf ("\n\t\t-> BACK TO MY COMPUTER");
        else printf ("\n\t\t Back To My Computer");
        printf ("\n");
        ch=getch();
        if(ch==72) in--;
        else if(ch==80) in++;
        if(in>5) in=1;
        else if(in<1) in=5;
    }
    system ("cls");
    switch (in)
    {
    case 1:
        shut_down ();
    case 2:
        restart ();
    case 3:
        system ("shutdown/f");
        power();
    case 4:
        system ("shutdown/a");
        power();
    case 5:
        system ("cls");
        NoS();
    }
}

void shut_down ()
{
    int in=1;
    char ch,time[10],t[]="shutdown -s -t ";
    while (ch!=13)
    {
        system("cls");
        time_date();
        if(in==1) printf("\n\t\t-> SHUTDOWN NOW");
        else printf("\n\t\t Shutdown Now");
        if(in==2) printf("\n\t\t-> SHUTDOWN AFTER FEW MINUTES");
        else printf("\n\t\t Shutdown After Few Minutes");
        if(in==3) printf("\n\t\t-> BACK");
        else printf("\n\t\t Back");
        printf ("\n\t\t");
        ch=getch();
        if(ch==72) in--;
        else if(ch==80) in++;
        if(in>3) in=1;
        else if(in<1) in=3;
    }
    if (in==1)
    {
        system ("shutdown -s");
        power ();
    }
    else if (in==2)
    {
        printf ("\n\n\t\tEnter Time: ");
        gets (time);
        strcat (t,time);
        system (t);
        power ();
    }
    else if (in==3) power();
}

void restart ()
{
    int in=1;
    char ch,time[10],t[]="shutdown -r -t ";
    while (ch!=13)
    {
        system("cls");
        time_date();
        if(in==1) printf("\n\t\t-> RESTART NOW");
        else printf("\n\t\t Restart Now");
        if(in==2) printf("\n\t\t-> RESTART AFTER FEW MINUTES");
        else printf("\n\t\t Restart After Few Minutes");
        if(in==3) printf("\n\t\t-> BACK");
        else printf("\n\t\t Back");
        printf ("\n\t\t");
        ch=getch();
        if(ch==72) in--;
        else if(ch==80) in++;
        if(in>3) in=1;
        else if(in<1) in=3;
    }
    if (in==1)
    {
        system ("shutdown -r");
        power ();
    }
    else if (in==2)
    {
        printf ("\n\n\t\tEnter Time: ");
        gets (time);
        strcat (t,time);
        system (t);
        power ();
    }
    else if (in==3) power ();
    power ();
}

void open_file (char str2[])
{
    char ch;
    system ("cls");
    time_date();
    printf ("\n\n Sometimes FILE cannot be opened due to non-standard naming of files. In that case, please rename your file and try again.");
    printf ("\n\n\t\t Proceed? Y/N  ");
    ch = getchar ();
    if (ch=='Y'||ch=='y')
    {
        strcat (str_dir,str2);
        system("cls");
        system (str_dir);
        NoS();
    }
    else if (ch=='N'||ch=='n')
    {
        NoS();
    }
}

void search_file()
{
    FILE *fp;
    int ft,c=1;
    char direc [1000] = "dir ";
    char file [100];
    char f[200];
    char tmp[200];
    strcpy(f,str_dir);
    strcat (f,"search_info.txt");
    system ("cls");
    time_date();
    printf ("\n\n\n\t\t\tENTER  FILE  NAME:  ");
    gets (file);
    strcat (direc,str_dir);
    strcat (direc," /s /b | find \"");
    strcat (direc, file);
    strcat (direc,"\"");
    system ("cls");
    printf ("Related Files and Directories:  \n\n\n");
    strcat (direc," > ");
    strcat (direc,str_dir);
    strcat (direc,"search_info.txt");
    system(direc);
    fp = fopen(f,"r");
    while (fgets(tmp,200,fp)!=NULL)
    {
        printf ("%d %s\n",c,tmp);
        c++;
    }
    fclose(fp);
    fflush(stdin);
    getchar ();
    NoS();
}

void time_date ()
{
    time_t rawtime;
    struct tm* timeinfo;
    rawtime = time (NULL);
    timeinfo = localtime (&rawtime);
    if (timeinfo->tm_hour>12) printf ("\t\t\t\t\tLOCAL  TIME :  %d:%d PM\n", timeinfo->tm_hour-12,timeinfo->tm_min);
    else printf ("\t\t\t\t\tLOCAL  TIME :  %d:%d AM\n", timeinfo->tm_hour,timeinfo->tm_min);
    printf ("\t\t\t\t\tLOCAL  DATE : %d/%d/%d",timeinfo->tm_mday,timeinfo->tm_mon+1,timeinfo->tm_year+1900);
}

void directory_list()
{
    int j;
    FILE *fp;
    char str_list[100];
    strcpy(str_list,str_dir);
    strcat(str_list,"List.txt");
    fp = fopen(str_list,"w+");
    for (j=0; j<i; j++)
    {
        fprintf (fp,"%d. %s\n",j+1,str[j]);
    }
    fclose(fp);
    fflush(stdin);
    system("cls");
    printf ("\n\n\n\n\n\t\t\t\tLIST  CREATED  SUCCESSFULLY");
    getchar();
    NoS();
}

void web()
{
    int in=1,k;
    char ch;
    while (ch!=13)
    {
        system("cls");
        time_date();
        printf ("\n\n\t\t");
        for (k=1; k<=60; k++) printf ("%c",176);
        if(in==1) printf("\n\t\t%c%c -> OPEN WEB PAGE                                       %c%c",176,176,176,176);
        else printf("\n\t\t%c%c Open Web Page                                          %c%c",176,176,176,176);
        if(in==2) printf("\n\t\t%c%c -> BOOKMARKS                                           %c%c",176,176,176,176);
        else printf("\n\t\t%c%c Bookmarks                                              %c%c",176,176,176,176);
        if (in==3) printf ("\n\t\t%c%c -> HISTORY                                             %c%c",176,176,176,176);
        else printf ("\n\t\t%c%c History                                                %c%c",176,176,176,176);
        if (in==4) printf ("\n\t\t%c%c -> BACK                                                %c%c",176,176,176,176);
        else printf ("\n\t\t%c%c Back                                                   %c%c",176,176,176,176);
        printf ("\n\t\t");
        for (k=1; k<=60; k++) printf ("%c",176);
        printf ("\n");
        ch=getch();
        if(ch==72) in--;
        else if(ch==80) in++;
        if(in>4) in=1;
        else if(in<1) in=4;
    }
    switch (in)
    {
    case 1:
        web_page(NULL);
        break;
    case 2:
        bookmark(NULL);
        break;
    case 3:
        history ();
        break;
    case 4:
        NoS();
        break;
    }
}

void web_page(char wb_url[])
{
    FILE *fp;
    char ch;
    system ("cls");
    time_date();
    char hstry[100];
    char url[100]= {"\0"};
    char web[100] = "start http://";
    printf ("\n\n\n\n\n\t\t\t\tEnter your URL (Make sure your terminal is connected to Internet):  \n\n\t\t\t\t");
    fflush(stdin);
    if (wb_url==NULL)
    {
        gets(url);
        printf ("\n\n\t\t\t\tDo You Want To BOOKMARK This Page? Y/N   ");
        ch=getchar();
        if(ch=='y'||ch=='Y')
        {
            b=0;
            bookmark(url);
        }
    }
    else strcpy(url,wb_url);
    strcat(web,url);
    if (fopen("d:\\history.txt","r")==NULL)
    {
        fp=fopen ("d:\\history.txt","w");
        fprintf (fp,"%s\n",url);
        fclose(fp);
        fflush(stdin);
    }
    else if (fopen("d:\\history.txt","r")!=NULL)
    {
        fp=fopen("d:\\history.txt","a");
        fprintf (fp,"%s\n",url);
        fclose(fp);
        fflush(stdin);
    }
    system(web);
    system("cls");
    getchar();
    NoS();
}

int bookmark(char url[])
{
    FILE *fp;
    int c;
    if (url!=NULL)
    {
        if (fopen("d:\\bookmarks.txt","r")==NULL)
        {
            fp=fopen ("d:\\bookmarks.txt","w");
            fprintf (fp,"%s\n",url);
            fclose(fp);
            fflush(stdin);
        }
        else if (fopen("d:\\bookmarks.txt","r")!=NULL)
        {
            fp=fopen("d:\\bookmarks.txt","a");
            fprintf (fp,"%s",url);
            fclose(fp);
            fflush(stdin);
        }
    }
    if (b==0)
    {
        b=1;
        return 0;
    }
    int in=1,k;
    char ch;
    while (ch!=13)
    {
        system("cls");
        time_date();
        printf ("\n\n\t\t");
        for (k=1; k<=60; k++) printf ("%c",176);
        if(in==1) printf("\n\t\t%c%c -> OPEN BOOKMARKS                                      %c%c",176,176,176,176);
        else printf("\n\t\t%c%c Open Bookmarks                                         %c%c",176,176,176,176);
        if (in==2) printf ("\n\t\t%c%c -> CLEAR BOOKMARKS                                     %c%c",176,176,176,176);
        else printf ("\n\t\t%c%c Clear Bookmarks                                        %c%c",176,176,176,176);
        if (in==3) printf ("\n\t\t%c%c -> BACK                                                %c%c",176,176,176,176);
        else printf ("\n\t\t%c%c Back                                                   %c%c",176,176,176,176);
        printf ("\n\t\t");
        for (k=1; k<=60; k++) printf ("%c",176);
        printf ("\n");
        ch=getch();
        if(ch==72) in--;
        else if(ch==80) in++;
        if(in>3) in=1;
        else if(in<1) in=1;
    }
    switch (in)
    {
    case 1:
        open_bookmark();
        break;
    case 2:
        clear_bookmarks();
        break;
    case 3:
        web();
        break;
    }
}

void open_bookmark()
{
    FILE *fp;
    int c=1,s,t,k,flag=0;
    system("cls");
    time_date();
    char bkmrk[100],tmp[100];
    fp = fopen("d:\\bookmarks.txt","r");
    while (fscanf(fp,"%s",&bkmrk)!=EOF)
    {
        printf ("\n\t\t\t[%d]. %s\n",c,bkmrk);
        c++;
    }
    fclose(fp);
    fflush(stdin);
    if (fopen("d:\\bookmarks.txt","r")==NULL)
    {
        printf ("\n\n\t\tNo Bookmarked Website.");
        getchar();
        web();
    }
    else
    {
        fp = fopen("d:\\bookmarks.txt","r");
        printf ("\n\n\t\tEnter Serial Number of the Website You Want To Access:  ");
        scanf ("%d",&s);
        fflush(stdin);
        for (t=1; t<=c; t++)
        {
            fscanf(fp,"%s",&tmp);
            fflush(stdin);
            if (t==s)
            {
                web_page(tmp);
                fclose(fp);
                fflush(stdin);
                flag=0;
                break;
            }
        }
        if (flag==1)
        {
            system("cls");
            printf ("\n\n\t\t\tNo Such Serial Number.");
            web();
        }
    }
}

void clear_bookmarks ()
{
    FILE *fp;
    if (fp = fopen("d:\\bookmarks.txt","r")!=NULL)
    {
        fclose(fp);
        fp = fopen("d:\\bookmarks.txt","w");
        fclose(fp);

    }
    else
    {
        system("cls");
        printf ("\n\n\t\t\tNO  BOOKMARKED  WEBSITE !\n");
    }
}

void history ()
{
    int in=1;
    char ch;
    FILE *fp;
    while (ch!=13)
    {
        system("cls");
        time_date();
        if(in==1) printf("\n\t\t-> VIEW HISTORY");
        else printf("\n\t\t View History");
        if(in==2) printf("\n\t\t-> CLEAR HISTORY");
        else printf("\n\t\t Clear History");
        if (in==3) printf ("\n\t\t-> BACK ");
        else printf ("\n\t\t Back ");
        printf ("\n");
        ch=getch();
        if(ch==72) in--;
        else if(ch==80) in++;
        if(in>3) in=1;
        else if(in<1) in=3;
    }
    switch (in)
    {
    case 1:
        view_history();
        break;
    case 2:
        system ("DEL/F/S/Q/A d:\\history.txt");
        system ("cls");
        if ((fopen("d:\\history.txt","r"))) printf ("\n\n\n\n\t\t\t\tHISTORY  CLEARED !!");
        else printf ("\n\n\n\n\t\t\t\tNO  BROWSING  HISTORY  AVAILABLE !!");
        getchar ();
        web();
        break;
    case 3:
        web();
        break;
    }
}

void view_history()
{
    FILE *fp;
    int c=1;
    char hstry[100];
    system("cls");
    if (fopen("d:\\history.txt","r")!=NULL)
    {
        fp = fopen("d:\\history.txt","r");
        printf ("\n\n");
        while (fscanf (fp,"%s",&hstry)!=EOF)
        {
            printf ("\t\t[%d]. %s\n",c,hstry);
            c++;
        }
        fclose (fp);
        fflush(stdin);
    }
    else printf ("\n\n\n\n\t\tNO  BROWSING  HISTORY  AVAILABLE !!");
    getchar();
    web();
}
