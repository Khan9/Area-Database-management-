// student ID: 15201090,15201119,15201095
// project title: Student Database System
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int gcdrec(int ,int);

struct homes_db
{
    char headOffamily[30];
    char occupation[20];
    int income;
    char fam_type;
    int fam_members;
    int male_mem;
    int female_mem;
    int students;
    char other_occup1[20];
    char other_occup2[20];
};
struct institutions_db
{
    char name[50];
    char type[20];
    int i_students;
    char Location[30];
    char contact_no[15];
};
struct religiousplaces
{
    char r_name[50];
    char r_type[15];
    char r_religion[20];
    char r_location[20];
};
struct clubs_db
{
    char c_name[50];
    char c_type[25];
    char c_location[20];
    char c_head[30];
    char c_contact_no[15];
};
struct area_db
{
    struct homes_db frst;
    struct institutions_db sec;
    struct religiousplaces thrd;
    struct clubs_db frth;
};

int main()
{

    struct area_db s[30];
    FILE *fp;
    fp=fopen("area_data.txt","r");
    char str[100];
    int counter=0;

    while(fgets(str,100,fp)!=NULL)
    {
        counter++;
    }
    rewind(fp);

    int i;
    char newline;
    for(i=0; i<10; i++)
    {

        fscanf(fp,"%[^:]:%[^:]:%c:%d:%d:%d:%d:%d:%[^:]:%[^:]%c",s[i].frst.headOffamily,s[i].frst.occupation,&s[i].frst.fam_type,&s[i].frst.income,&s[i].frst.fam_members,&s[i].frst.male_mem,&s[i].frst.female_mem,&s[i].frst.students,s[i].frst.other_occup1,s[i].frst.other_occup2,&newline);

    }

    for(i=0; i<10; i++)
    {
        puts(s[i].frst.headOffamily);
        puts(s[i].frst.occupation);
        printf("%c\n",s[i].frst.fam_type);
        printf("%d\n",s[i].frst.income);
        printf("%d\n",s[i].frst.fam_members);
        printf("%d\n",s[i].frst.male_mem);
        printf("%d\n",s[i].frst.female_mem);
        printf("%d\n",s[i].frst.students);
        puts(s[i].frst.other_occup1);
        puts(s[i].frst.other_occup2);
        puts("\n\n");
    }

    for(i=0; i<7; i++)
    {

        fscanf(fp,"%[^:]:%[^:]:%d:%[^:]:%[^:]%c",s[i].sec.name,s[i].sec.type,&s[i].sec.i_students,s[i].sec.Location,s[i].sec.contact_no,&newline);

    }
    for(i=0; i<7; i++)
    {
        puts(s[i].sec.name);
        puts(s[i].sec.type);
        printf("%d\n",s[i].sec.i_students );
        puts(s[i].sec.Location);
        puts(s[i].sec.contact_no);
    }
    for(i=0; i<6; i++)
    {

        fscanf(fp,"%[^:]:%[^:]:%[^:]:%[^:]%c",s[i].thrd.r_name,s[i].thrd.r_type,s[i].thrd.r_religion,s[i].thrd.r_location,&newline);

    }
    for(i=0; i<6; i++)
    {
        puts(s[i].thrd.r_name);
        puts(s[i].thrd.r_type);
        puts(s[i].thrd.r_religion);
        puts(s[i].thrd.r_location);
    }
    for(i=0; i<10; i++)
    {
        fscanf(fp,"%[^:]:%[^:]:%[^:]:%[^:]:%[^:]%c",s[i].frth.c_name,s[i].frth.c_type,s[i].frth.c_location,s[i].frth.c_head,s[i].frth.c_contact_no,&newline);
    }
    for(i=0; i<10; i++)
    {
        puts(s[i].frth.c_name);
        puts(s[i].frth.c_type);
        puts(s[i].frth.c_location);
        puts(s[i].frth.c_head);
        puts(s[i].frth.c_contact_no);
    }
MainMenu:
    puts("1>Infomation Of Families and Individuals\n");
    puts("2>Infomation Of Educational Institutions\n");
    puts("3>Infomation Of Religious Places\n");
    puts("4>Infomation Of Clubs and Recreational Places\n");
    puts("WHAT ARE YOU LOOKING FOR?\n");

    int n;
    scanf("%d",&n);
    if (n==1)
    {
SubMenu1:

        puts("1.Total Population Of The Area\n");
        puts("2.Number Of Teachers in the Area\n");
        puts("3.Number Of Engineers in the Area\n");
        puts("4.Number Of Doctors in the area\n");
        puts("5.Number of Total Students in the area\n");
        puts("6.Number of Total Govt Employee Living in the area\n");
        puts("7.Number of Businessman in the area\n");
        puts("8.Number Of Retired Persons\n");
        puts("9.Name Of the Richest Person in the area\n");
        puts("10.Name of most needy family\n");
        puts("11.Highest Family Income\n");
        puts("12.Lowest Family Income\n");
        puts("13.Average Family Income\n");
        puts("14.Total members in the largest & smallest Family \n");
        puts("15.Ratio Of Male & Female in the area\n");
        puts("Enter Your Choice: ");
        scanf("%d",&n);
        if (n==1)
        {

            int sum=0;
            for(i=0; i<10; i++)
            {
                sum=sum+s[i].frst.fam_members;
            }
            printf("Total Population: %d\n",sum);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==2)
        {
            int tcount=0;
            char tstr[]="Teacher";
            for(i=0; i<10; i++)
            {
                if (strcmp(s[i].frst.occupation,tstr)==0)
                {
                    if(strcmp(s[i].frst.other_occup1,tstr)==0 && strcmp(s[i].frst.other_occup2,tstr)==0)
                    {
                        tcount=tcount+3;
                    }
                    else if(strcmp(s[i].frst.other_occup1,tstr)==0 || strcmp(s[i].frst.other_occup2,tstr)==0)
                    {
                        tcount=tcount+2;
                    }
                    else
                        tcount++;
                }
                else if (strcmp(s[i].frst.occupation,tstr)!=0)
                {
                    if(strcmp(s[i].frst.other_occup1,tstr)==0 && strcmp(s[i].frst.other_occup2,tstr)==0)
                    {
                        tcount=tcount+2;
                    }
                    else if(strcmp(s[i].frst.other_occup1,tstr)==0 || strcmp(s[i].frst.other_occup2,tstr)==0)
                    {
                        tcount=tcount+1;
                    }
                }
            }
            printf("Total Number of Teachers: %d\n",tcount);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==3)
        {
            int ecount=0;
            char estr[]="Engineer";
            for(i=0; i<10; i++)
            {
                if (strcmp(s[i].frst.occupation,estr)==0)
                {
                    if(strcmp(s[i].frst.other_occup1,estr)==0 && strcmp(s[i].frst.other_occup2,estr)==0)
                    {
                        ecount=ecount+3;
                    }
                    else if(strcmp(s[i].frst.other_occup1,estr)==0 || strcmp(s[i].frst.other_occup2,estr)==0)
                    {
                        ecount=ecount+2;
                    }
                    else
                        ecount++;
                }
                else if (strcmp(s[i].frst.occupation,estr)!=0)
                {
                    if(strcmp(s[i].frst.other_occup1,estr)==0 && strcmp(s[i].frst.other_occup2,estr)==0)
                    {
                        ecount=ecount+2;
                    }
                    else if(strcmp(s[i].frst.other_occup1,estr)==0 || strcmp(s[i].frst.other_occup2,estr)==0)
                    {
                        ecount=ecount+1;
                    }
                }
            }
            printf("Total Number of Engineers: %d\n",ecount);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==4)
        {
            int dcount=0;
            char dstr[]="Doctor";
            for(i=0; i<10; i++)
            {
                if (strcmp(s[i].frst.occupation,dstr)==0)
                {
                    if(strcmp(s[i].frst.other_occup1,dstr)==0 && strcmp(s[i].frst.other_occup2,dstr)==0)
                    {
                        dcount=dcount+3;
                    }
                    else if(strcmp(s[i].frst.other_occup1,dstr)==0 || strcmp(s[i].frst.other_occup2,dstr)==0)
                    {
                        dcount=dcount+2;
                    }
                    else
                        dcount++;
                }
                else if (strcmp(s[i].frst.occupation,dstr)!=0)
                {
                    if(strcmp(s[i].frst.other_occup1,dstr)==0 && strcmp(s[i].frst.other_occup2,dstr)==0)
                    {
                        dcount=dcount+2;
                    }
                    else if(strcmp(s[i].frst.other_occup1,dstr)==0 || strcmp(s[i].frst.other_occup2,dstr)==0)
                    {
                        dcount=dcount+1;
                    }
                }
            }
            printf("Total Number of Doctors: %d\n",dcount);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==5)
        {
            int scount=0;
            for(i=0; i<10; i++)
            {
                scount=scount+s[i].frst.students;
            }
            printf("Total Number of Students: %d\n",scount);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==6)
        {
            int gcount=0;
            char gstr[]="Govt Employee";
            for(i=0; i<10; i++)
            {
                if (strcmp(s[i].frst.occupation,gstr)==0)
                {
                    if(strcmp(s[i].frst.other_occup1,gstr)==0 && strcmp(s[i].frst.other_occup2,gstr)==0)
                    {
                        gcount=gcount+3;
                    }
                    else if(strcmp(s[i].frst.other_occup1,gstr)==0 || strcmp(s[i].frst.other_occup2,gstr)==0)
                    {
                        gcount=gcount+2;
                    }
                    else
                        gcount++;
                }
                else if (strcmp(s[i].frst.occupation,gstr)!=0)
                {
                    if(strcmp(s[i].frst.other_occup1,gstr)==0 && strcmp(s[i].frst.other_occup2,gstr)==0)
                    {
                        gcount=gcount+2;
                    }
                    else if(strcmp(s[i].frst.other_occup1,gstr)==0 || strcmp(s[i].frst.other_occup2,gstr)==0)
                    {
                        gcount=gcount+1;
                    }
                }
            }
            printf("Total Number of Govt Employee: %d\n",gcount);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==7)
        {
            int bcount=0;
            char bstr[]="Businessman";
            for(i=0; i<10; i++)
            {
                if (strcmp(s[i].frst.occupation,bstr)==0)
                {
                    if(strcmp(s[i].frst.other_occup1,bstr)==0 && strcmp(s[i].frst.other_occup2,bstr)==0)
                    {
                        bcount=bcount+3;
                    }
                    else if(strcmp(s[i].frst.other_occup1,bstr)==0 || strcmp(s[i].frst.other_occup2,bstr)==0)
                    {
                        bcount=bcount+2;
                    }
                    else
                        bcount++;
                }
                else if (strcmp(s[i].frst.occupation,bstr)!=0)
                {
                    if(strcmp(s[i].frst.other_occup1,bstr)==0 && strcmp(s[i].frst.other_occup2,bstr)==0)
                    {
                        bcount=bcount+2;
                    }
                    else if(strcmp(s[i].frst.other_occup1,bstr)==0 || strcmp(s[i].frst.other_occup2,bstr)==0)
                    {
                        bcount=bcount+1;
                    }
                }
            }
            printf("Total Number of Bsinessman: %d\n",bcount);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==8)
        {
            int rcount=0;
            char rstr[]="Retired";
            for(i=0; i<10; i++)
            {
                if (strcmp(s[i].frst.occupation,rstr)==0)
                {
                    if(strcmp(s[i].frst.other_occup1,rstr)==0 && strcmp(s[i].frst.other_occup2,rstr)==0)
                    {
                        rcount=rcount+3;
                    }
                    else if(strcmp(s[i].frst.other_occup1,rstr)==0 || strcmp(s[i].frst.other_occup2,rstr)==0)
                    {
                        rcount=rcount+2;
                    }
                    else
                        rcount++;
                }
                else if (strcmp(s[i].frst.occupation,rstr)!=0)
                {
                    if(strcmp(s[i].frst.other_occup1,rstr)==0 && strcmp(s[i].frst.other_occup2,rstr)==0)
                    {
                        rcount=rcount+2;
                    }
                    else if(strcmp(s[i].frst.other_occup1,rstr)==0 || strcmp(s[i].frst.other_occup2,rstr)==0)
                    {
                        rcount=rcount+1;
                    }
                }
            }
            printf("Total Number of Retired Persons: %d\n",rcount);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==9)
        {
            int max,max_index,i;
            max=s[0].frst.income;
            max_index=0;
            for(i=0; i<10; i++)
            {
                if(s[i].frst.income>max)
                {
                    max=s[i].frst.income;
                    max_index=i;
                }
            }
            printf("Name Of the Richest Person in the area: %s\n",s[max_index].frst.headOffamily);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==10)
        {
            int min,min_index,i;
            min=s[0].frst.income;
            min_index=0;
            for(i=0; i<10; i++)
            {
                if(s[i].frst.income<min)
                {
                    min=s[i].frst.income;
                    min_index=i;
                }
            }
            printf("Name Of the most needy Person in the area: %s\n",s[min_index].frst.headOffamily);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==11)
        {
            int max,max_index,i;
            max=s[0].frst.income;
            max_index=0;
            for(i=0; i<10; i++)
            {
                if(s[i].frst.income>max)
                {
                    max=s[i].frst.income;
                    max_index=i;
                }
            }
            printf("Highest Family Income: %d\n",s[max_index].frst.income);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }

        if (n==12)
        {
            int min,min_index,i;
            min=s[0].frst.income;
            min_index=0;
            for(i=0; i<10; i++)
            {
                if(s[i].frst.income<min)
                {
                    min=s[i].frst.income;
                    min_index=i;
                }
            }
            printf("Lowest Family Income: %d\n",s[min_index].frst.income);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==13)
        {
            float sum=0;
            float avg;
            for(i=0; i<10; i++)
            {
                sum=sum+s[i].frst.income;
            }
            avg=sum/10;
            printf("13.Average Family Income: %.2f\n",avg);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==14)
        {
            int max,max_index,i;
            max=s[0].frst.fam_members;
            max_index=0;
            for(i=0; i<10; i++)
            {
                if(s[i].frst.fam_members>max)
                {
                    max=s[i].frst.fam_members;
                    max_index=i;
                }
            }
            printf("Total members in the largest Family: %d \n",s[max_index].frst.fam_members);
            int min,min_index;
            min=s[0].frst.fam_members;
            min_index=0;
            for(i=0; i<10; i++)
            {
                if(s[i].frst.fam_members<min)
                {
                    min=s[i].frst.fam_members;
                    min_index=i;
                }
            }
            printf("Total members in the smallest Family: %d \n",s[min_index].frst.fam_members);

            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }

        }
        if (n==15)
        {
            int msum=0;
            int fsum=0;
            for(i=0; i<10; i++)
            {
                msum=msum+s[i].frst.male_mem;
                fsum=fsum+s[i].frst.female_mem;
            }

            printf("Ratio Of Male and Female is= %d:%d\n",msum/gcdrec(msum,fsum),fsum/gcdrec(msum,fsum));

            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu1;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }

    }
    else if (n==2)
    {
SubMenu2:
        puts("1.Show the name of Educational Institutions and Their Contact No\n");
        puts("2.Show the name of Schools with contact Number\n");
        puts("3.Show the name of Colleges with contact Number\n");
        puts("4.Show the name of Universities with contact Number\n");
        puts("5.Show the name of Madrashas with contact Number\n");
        puts("6.Show total number of Students in all the institutions altogether\n");
        puts("7.Show the Name and address of the institution that has the highest Number of Students\n");
        puts("8.Show the Name and address of the institution that has the lowest Number of Students\n");
        puts("Enter Your Choice: ");

    scanf("%d",&n);
        if(n==1)
        {
            for(i=0; i<7; i++)
            {
                puts(s[i].sec.name);
                puts(s[i].sec.contact_no);
            }
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu2;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if(n==2)
        {
            for(i=0; i<7; i++)
            {
                char sstr[]="School";
                if (strcmp(s[i].sec.type,sstr)==0)
                    {
                        puts(s[i].sec.name);
                        puts(s[i].sec.contact_no);
                    }
            }
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu2;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==3)
        {
            for(i=0; i<7; i++)
            {
                char sstr[]="College";
                if (strcmp(s[i].sec.type,sstr)==0)
                    {
                        puts(s[i].sec.name);
                        puts(s[i].sec.contact_no);
                    }
            }
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu2;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==4)
        {
            for(i=0; i<6; i++)
            {

                if (strcmp(s[i].sec.type,"University")==0)
                    {
                        puts(s[i].sec.name);
                        puts(s[i].sec.contact_no);
                    }
            }
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu2;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==5)
        {
            for(i=0; i<7; i++)
            {
                char sstr[]="Madrasha";
                if (strcmp(s[i].sec.type,sstr)==0)
                    {
                        puts(s[i].sec.name);
                        puts(s[i].sec.contact_no);
                    }
            }
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu2;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==6)
        {
            int sum=0;
            for(i=0;i<7;i++)
            {
                sum=sum+s[i].sec.i_students;
            }
            printf("Total number of Students: %d\n", sum);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu2;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
        if (n==7)
        {
            int max,max_index,i;
            max=s[0].sec.i_students;
            max_index=0;
            for(i=0; i<7; i++)
            {
                if(s[i].sec.i_students>max)
                {
                    max=s[i].sec.i_students;
                    max_index=i;
                }
            }
            puts(s[max_index].sec.name);
            puts(s[max_index].sec.contact_no);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu2;
            }
            if (n==1)
            {
                goto MainMenu;
            }

        }
        if (n==8)
        {

            int min,min_index;
            min=s[0].sec.i_students;
            min_index=0;
            for(i=0; i<7; i++)
            {
                if(s[i].sec.i_students<min)
                {
                    min=s[i].sec.i_students;
                    min_index=i;
                }
            }
            puts(s[min_index].sec.name);
            puts(s[min_index].sec.contact_no);
            printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu2;
            }
            if (n==1)
            {
                goto MainMenu;
            }
        }
    }
    else if (n==3)
    {
SubMenu3:
        puts("1.Show Nearest Religious Place For You\n");
        puts("2.Show Number Of Mosques\n");
        puts("3.Show Number Of Temples\n");
        puts("4.Show Number Of Churches\n");
        puts("Enter Your Choice: ");

            scanf("%d",&n);
             if (n==1)
             {
                 char rlg[15];
                 puts("Enter Your Religion(1st Letter must be uppercase):\n ");
                 scanf("%s",rlg);
                 if (strcmp(rlg,"Muslim")==0)
                 {
                     puts("Enter your Current Location? \n");
                     puts("1.Lalshah Majar\n");
                     puts("2.Rishipara\n");
                     puts("3.Amtola\n");
                     puts("4.Box Nagar\n");
                     puts("5.Safiruddin Market\n");
                     puts("6.Out of this area\n");
                     scanf("%d",&n);
                     if (n==1)
                     {
                         puts("Luckily You won't have to look very far for a mosque\n");
                         printf("Nearest Mosque is in : Lalshah Majar\n");
                     }
                     if(n==2)
                     {
                         puts("Amtala is the nearest place for You");
                     }
                     if(n==3)
                     {
                         puts("Luckily You won't have to look very far for a mosque\n");
                         printf("Nearest Mosque is in : Lalshah Majar");
                     }
                     if(n==4)
                     {
                         puts("Luckily You won't have to look very far for a mosque\n");
                         printf("Nearest Mosque is in : Box Nagar");
                     }
                     if(n==5)
                     {
                         puts("Box Nagar is the nearest place for You");
                     }
                     if(n==6)
                        puts("You'll get Haji Rahmat Ullah Mosjid in Lalshah Majar while Entering this area");
                 }
                 else if (strcmp(rlg,"Hindu")==0)
                 {
                     puts("Only Temple for you is in Rishipara Named Harinath Temple \n");

                 }
                 else if (strcmp(rlg,"Christian")==0)
                    {
                     puts("Only Church for you is in Lalshah Majar Named st john's lutheran church \n");

                    }
                else if (strcmp(rlg,"Buddhist")==0)
                    {
                     puts("Only Temple for you is in Safir Uddin Market Named Buddha Mondir \n");

                    }
                    printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu3;
            }
            if (n==1)
            {
                goto MainMenu;
            }
             }
             if(n==2)
             {
                 int tot=0;
                 for(i=0; i<6; i++)
                 {
                     if (strcmp(s[i].thrd.r_type,"Mosque")==0)
                     {
                         tot++;
                     }

                 }
                 printf("Total Mosques:%d\n",tot);
                 printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu3;
            }
            if (n==1)
            {
                goto MainMenu;
            }

             }
             if(n==3)
             {
                 int tot=0;
                 for(i=0; i<6; i++)
                 {
                     if (strcmp(s[i].thrd.r_type,"Temple")==0)
                     {
                         tot++;
                     }

                 }
                 printf("Total Temples:%d\n",tot);
                 printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu3;
            }
            if (n==1)
            {
                goto MainMenu;
            }
             }
             if(n==4)
             {
                 int tot=0;
                 for(i=0; i<6; i++)
                 {
                     if (strcmp(s[i].thrd.r_type,"Church")==0)
                     {
                         tot++;
                     }
                }
                printf("Total Churches:%d \n",tot);
                printf("Press 0 to go to previous Menu or 1 to Main Menu");
            scanf("%d",&n);
            if (n==0)
            {
                goto SubMenu3;
            }
            if (n==1)
            {
                goto MainMenu;
            }
             }
    }

else if (n==4)
    {
SubMenu4:
puts("1.Show the name of Religious Places\n");//Eikhane kaj baki. Menu nia kichu jhamela baki
    }
    return 0;
}
int gcdrec(int a , int b)
    {
     return(b!=0 ? gcdrec(b,a%b) :a);
    }
