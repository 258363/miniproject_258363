#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

struct vehicle
{
	int num ;
	int row ;
	int col ;
  int type ;
  struct tm *at;
} ;
int parkinfo[4][10] ; 
int vehcount ;  

void display( ) ;
void changecol ( struct vehicle * ) ;
struct vehicle * add ( int, int, int, int ) ;
void del ( struct vehicle * ) ;
void show() ;
void total_bill(int ,struct tm *ct1,struct tm *ct2);
void get_arrival_time(int);

void changecol ( struct vehicle *v )
{
	v -> col--;
}

struct tm* datetime()
{



           time_t ts;
        struct tm *ct;


        ts = time(NULL);
        ct = localtime(&ts);
        

return ct ;

}
int insertrecord(int veh,int type,int row,int col, struct tm *ct )
{
FILE *fptr;
    fptr = fopen("arival.dat", "a");

    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return 0 ;
    }

    fprintf(fptr,"\n");
    fprintf(fptr,"%d ",veh);
        fprintf(fptr,"%d ",type);
        fprintf(fptr,"%d ",row);
        fprintf(fptr,"%d ",col);

         fprintf(fptr,"%d/%d/%d  ",
                ct->tm_mday, ct->tm_mon + 1, ct->tm_year + 1900);

   fprintf(fptr,"%d:%d:%d  ",
                ct->tm_hour, ct->tm_min, ct->tm_sec);



        fclose(fptr);
}


int insertrecord2(int veh, struct tm *ct )
{
FILE *fptr;
    fptr = fopen("depart.dat", "a");

    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return 0 ;
    }

    fprintf(fptr,"\n");
    fprintf(fptr,"%d ",veh);


         fprintf(fptr,"%d/%d/%d  ",
                ct->tm_mday, ct->tm_mon + 1, ct->tm_year + 1900);

   fprintf(fptr,"%d:%d:%d  ",
                ct->tm_hour, ct->tm_min, ct->tm_sec);



        fclose(fptr);
}
void get_arrival_time(int num)
{


    int veh ,type,row,col ;
    int mon,day,year,hour,min,sec;
    int mon2,day2,year2,hour2,min2,sec2;

    int mon1,day1,year1,hour1,min1,sec1;
    int mon3,day3,year3,hour3,min3,sec3;

    FILE *fptr;
    fptr = fopen("arival.dat", "r");

    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return 0 ;
    }

 while(!feof(fptr))
 {
     fscanf(fptr,"\n");
     fscanf(fptr,"%d ",&veh);
        fscanf(fptr,"%d ",&type);
       fscanf(fptr,"%d ",&row);
        fscanf(fptr,"%d ",&col);
    fscanf(fptr,"%d/%d/%d  ",
                &day, &mon, &year);

   fscanf(fptr,"%d:%d:%d  ",
                &hour, &min, &sec);

   if(veh == num){
     day2 = day;
     mon2 = mon;
     year2 = year;
     hour2 = hour;
     min2 = min;
     sec2 = sec ;
}


 }
 fclose(fptr);



 FILE *fptr1;
    fptr1 = fopen("depart.dat", "r");

    if (fptr1 == NULL)
    {
        printf("File does not exists \n");
        return 0 ;
    }

 while(!feof(fptr1))
 {
     fscanf(fptr1,"\n");
     fscanf(fptr1,"%d ",&veh);

    fscanf(fptr1,"%d/%d/%d  ",
                &day1, &mon1, &year1);

   fscanf(fptr1,"%d:%d:%d  ",
                &hour1, &min1, &sec1);

   if(veh == num){
     day3 = day1;
     mon3 = mon1;
     year3 = year1;
     hour3 = hour1;
     min3 = min1;
     sec3 = sec1 ;
}


 }
 fclose(fptr1);

     int tsec1,tsec2,tsec3;
     tsec1 =  sec3;
      tsec1 += min3*60;
      tsec1 += (hour3*60)*60;
 tsec2 =  sec2;
      tsec2 += min2*60;
      tsec2 += (hour2*60)*60;

   tsec3 = tsec1 - tsec2 ;
   int secnd , minute ,hours;
   int secc , temp1,temp2,temp3,temp4 ;
      secnd = tsec3 % 60 ;
       temp1 = tsec3 - secnd ;
       temp2 = temp1/60 ;
       minute = temp2 % 60 ;
        temp4 = temp2 - minute ;
         hours = temp4 /60 ;

 printf("you have parked your vehicle for %d/%d/%d",hours,minute,secnd);



}


void del ( struct vehicle *v )
{
  int c ;


	parkinfo[v -> row][v -> col] = 0 ;
	vehcount-- ;

}

