/* 
1. Ethiopian meteorology agency wants an application that records the 
high and low temperatures for each day of all months of for the year 2010. 
The agency requests you to design the application using three-dimensional weather 
array by which the months. days and daily (low. high. average) temperatures represented. 
The months are labeled by the numbers 1 to 12. 
The date of the months are numbered I through 30 representing the days. and three columns labeled H and L.
representing the day's high. low and average temperatures. Use this information to develop a program that 
records the high and low temperatures far each day of all months and then allow the user to request the following: 

■ Any day's high and low temperature. 
■ Any month high, low and average temperatures for a given month 
■ Month and day with the highest temperature
■ Month and day with the lowest temperature. 
■ All months average temperature to he printed in table format
*/

//include libraries
#include<iomanip>
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
//declaring global user name and PIN variables
string user_Name;
int PIN_num;

//declaring global three-dimensional array to store the values of high and low temperature of the day and month.
float temp_rec[12][30][2];

//Prototyping 
void data();
void admin();
void User_UI();
void Admin_UI();
void welcome();
void low_month_day(float *low);
void high_month_day( float *high);
void high_low_avg_temp_month(int month, float *high, float *low, float *avg );
void high_low_temp_day (int month, int date, float *high, float *low);
void month_name ( int mnum);
void CSV();
void record();
void ui();
void Clear_data();
void random();
void avtable();
void data_table();
void UName_Pin();
void Change_PIN_UserName();
void Thank_u();
int getchoice();
string str_Check();

//int Input Checker
int getchoice(){
    int choice;
    cin>>choice;
    while(!cin.good()){
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        //Dispaly Invalid message
        cout<<"\tInavlid input. Try again: ";
        cin>>choice;
    }
    return choice;
}
//int Input Checker
string str_Check(){
    string choose;
    cin>>choose;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        //Dispaly Invalid message
        cout<<"\tInavlid input. Try again: ";
        cin>>choose;        
    }
    
    return choose;
}
// Read data form Data.csv file in the dir
void data(){
    ifstream myFile;
    float final;
    
    myFile.open("Data.csv");
    
    
        for(int i=0; i<12; i++){
            for(int j=0; j<30; j++){
                for(int k=0; k<2; k++){
                    string ff;
                    getline(myFile, ff, ',');
                    istringstream(ff)>>final;
                    temp_rec[i][j][k] = final;//store the value in the array
                }
            }
        }
}
// Define a function that filter and return the high and low temperature of any days but in c++ we can't return 2 values
// so we use Call By Address or Call By Reference
void high_low_temp_day (int month, int date, float *high, float *low){
    *high  = temp_rec[month-1][date-1][1];
    *low  = temp_rec[month-1][date-1][0];
}

//This function generate month name by taking the number of month
void month_name ( int mnum){
      string mname;
    
     switch (mnum)
    {
    case 0:
        mname="January";
                break;
     case 1:
        mname="February";
                break;
      case 2:
        mname="March";
                break; 
      case 3:
        mname="April";
                break;  
      case 4:
        mname="May";
                break; 
      case 5:
        mname="June";
                break; 
      case 6:
        mname="July";
                break; 
       case 7:
        mname="August";
                break;
      case 8:
        mname="September";
                break;   
       case 9:
        mname="October";
                break; 
       case 10:
        mname="November";
                break;  
      case 11:
        mname="December";
                break;             
    }
    cout<<left<<setw(9)<<mname;
}

//This function generates random number to our array and 
void random(){
    float temp;////temporary value use to sort the values
         for(int i =0; i<12; i++){  
            for(int j=0; j<30; j++){
                for(int k=0; k<2; k++){
                float y = float(150 + rand()%150)/10;//using random value for the daily temperature b/w 15 to 30 °C  
                temp_rec[i][j][k]=y;
                }
                //sort the values by using bubble sort algorithm 
                if(temp_rec[i][j][0]>temp_rec[i][j][1]){
                    temp = temp_rec[i][j][1];
                    temp_rec[i][j][1] = temp_rec[i][j][0];
                    temp_rec[i][j][0] = temp;  
                }
            }
        }
        cout<<"RANDOM DATA HAS BEEN GENERATED AND RECORDED."<<endl;
        CSV();
}
void Clear_data(){
    
    for(int i =0; i<12; i++){
        for(int j=0; j<30; j++){
            for(int k=0; k<2; k++){
                float y = 0;
                temp_rec[i][j][k]=y;
            }
        }

    }
    cout<<"DATA HAS BEEN CLEARED."<<endl;
    CSV();
}
void CSV(){
    ofstream myFile;
    myFile.open("Data.csv");
    for(int i=0; i<12; i++){
        for(int j=0; j<30; j++){
            for(int k=0; k<2; k++){
                myFile<<temp_rec[i][j][k]<<",";
            }
            myFile<<endl;
        }
    }
}

void record(){
    int month, date;
    float high, low;
    cout<<"Enter the month number: ";
    month = getchoice();
    cout<<"Enter the date number: ";
    date = getchoice();
    if(date<=30&&date>=1&&month>=1&&month<=12){
        cout<<"High value: ";
        high = getchoice();
        cout<<"Lowest value: ";
        low = getchoice();
        if (high>=low)
        {
        temp_rec[month-1][date-1][0] = low;
        temp_rec[month-1][date-1][1] = high;
         cout<<"THE DATA YOU ENTERED HAS BEEN RECORDED SUCCESSFULLY."<<endl;
        }
       else{
           cout<<"YOUR HIGH VALUE WAS BELOW THE LOW VALUE. PLEASE RETURN AND ENTER CORRECT VALUES !! "<<endl;
       } 
       
    }
    else
    {
        cout<<"Invalid Input";
    }
    
}
void Change_PIN_UserName(){
    UName_Pin();
    string user_name, New_Uname;
    int pin, New_pin;
    cout<<"Enter the Old User Name: ";
    user_name = str_Check();
    cout<<"Enter the Old PIN: ";
    pin = getchoice();
    if(pin==PIN_num && user_name == user_Name){
        cout<<"Enter the new User Name: ";
        New_Uname = str_Check();
        cout<<"Enter the new PIN: ";
        New_pin = getchoice();
        ofstream User_Name, PIN;
        User_Name.open("UserName.csv");
        User_Name<<New_Uname<<",";
        PIN.open("PIN.csv");
        PIN<<New_pin;
    }
    else{
        cout<<"Sorry you entered wrong value!";
    }
}

//this function reads 3D Welcome text form welcome.txt and dispaly it
void welcome()
{
system("color 05");

	ifstream ifs ("welcome.txt");
	string Lines = "";

    if (ifs)
    {
		while (ifs.good ())
		{
	    	string TempLine;
	    	getline (ifs , TempLine);
	    	TempLine += "\n";

	    	Lines += TempLine;
		}

	cout << Lines;


	}

}

// Define a function that filter the high low and average temperature of any month
void high_low_avg_temp_month(int month, float *high, float *low, float *avg ){
    //Declare empty array to store all the high and low values of a month
    float hi[30] = {};
    float lo[30] = {};
    //Declare float variables to store the averages of a daily temperature
    float sum=0, avg_day;

    for(int i=0; i<30; i++){
        // store the high and low temperature values in the empty array 
            hi[i] = temp_rec[month-1][i][1];
            lo[i] = temp_rec[month-1][i][0];
    }
    // finding the lowest and highest values by compering all the high and low temperature of a day
    //assume the first value is the highest and the lowest
    *high = hi[0];
    *low = lo[0];
    for(int i=0; i<30; i++){
        if(hi[i]>*high){
            *high = hi[i];
        }
        if(lo[i]<*low){
            *low = lo[i];
        }
    }
    // finding the average temperatures for a given month by summing up all the temperatures in the month.
    for(int i=0; i<30; i++){
        for(int j=0; j<2; j++){
             sum=sum+temp_rec[month-1][i][j];
           }
    }
    *avg=sum/60;
}

// Define a function that filter the entire highst temperature of a year and search the day and the month
void high_month_day( float *high){
    *high=temp_rec[0][0][0];
    for(int i=0;i<12; i++)
        for(int j=0; j<30; j++)
            for(int k=0; k<2; k++)
                    if(*high<temp_rec[i][j][k])
                            *high=temp_rec[i][j][k];

}
// Define a function that filter the entire lowest temperature of a year and search the day and the month
void low_month_day(float *low){
    *low =temp_rec[0][0][0];
    for(int i=0;i<12; i++)
        for(int j=0; j<30; j++)
            for(int k=0; k<2; k++)
                    if(*low>temp_rec[i][j][k])
                            *low=temp_rec[i][j][k];


}
// Define a function that Checks the admin user name and PIN is correct;
void admin(){
    UName_Pin();
    int pin;
    string userName;
    for(int i=4; i>0; i--){

    cout<<"Enter the User name: ";
    userName = str_Check();
    if(userName == user_Name){
        cout<<"Enter the PIN: ";
        pin = getchoice();
        
        if(pin==PIN_num){
            Admin_UI();
        }

        else
        {
            if(i==1){
                cout<<"You Loos Your Chances!!";
            }
            else
            {
            cout<<user_Name<<" You Entered Wrong PIN!\n \tTry again you have "<<i-1<<" chance\n\t";
                
            }
            
        }
        

    }
    else{
            if(i==1){
                cout<<"You Loos Your Chances!!";
            }
            else
            {
                cout<<"Wrong User name\n\t Try again you have "<<i-1<<" chance\n\t";
            }
    }

    }
}
// Define a function that displays the entire values of the data in table format
void data_table(){
float sum=0;   

cout<<"--------------------------------------------"<<endl;
cout<<left<<setw(11)<<"DAY"<<" || "<<left<<setw(7)<<"LOW"<<"||"<<" "<<left<<setw(7)<<"HIGH"<<"||"<<" "<<left<<setw(7)<<"AVERAGE"<<"||"<<endl;
cout<<"--------------------------------------------"<<endl;
for(int mnum=0; mnum<12; mnum++){
    for(int j=0; j<30; j++){   
    month_name(mnum);
    cout<<" "<<left<<setw(2)<<j+1;
    cout<<"|| "<<left<<setw(7)<<temp_rec[mnum][j][0]<<"||"<<" "<<left<<setw(7)<<temp_rec[mnum][j][1]<<"||"<<" "<<left<<setw(7)<<(temp_rec[mnum][j][1]+temp_rec[mnum][j][0])/2<<"||"<<endl;
    cout<<"--------------------------------------------"<<endl;                                                            
    }
        }
    
}

//This Function Displays the average temperature of the entire year in table format
void avtable(){

 float sum=0;   
cout<<"-------------------------------"<<endl;
cout<<"||"<<left<<setw(4)<<"NUMBER"<<"|| "<<left<<setw(9)<<"MONTH"<<"|| "<<left<<setw(7)<<"AVERAGE"<<"||"<<endl;
cout<<"-------------------------------"<<endl;
for(int mnum=0; mnum<12; mnum++){
 sum=0; 
    for(int j=0; j<30; j++){
        for(int k=0; k<2; k++){
            sum=sum+temp_rec[mnum][j][k];
            
        }
    }     
            
           
    cout<<"|| "<<left<<setw(4)<< mnum+1<<"|| ";
    month_name(mnum);
    cout<<"|| "<<left<<setw(7)<<sum/60<<"||"<<endl;
    cout<<"-------------------------------"<<endl;                                                            

        }
    
}

// Define a function that displays the menu or UI for User Account only 

void User_UI(){
    welcome();
    int choose, month, date,mnum;
    float avg, high, low;
    bool exit= false;
    while(exit==false){
    cout<<"\n\npress \n\n";
    cout<<"\t1. \tto see the entire daily data in table. \n";
    cout<<"\t2. \tFor Any day's high and low temperature. \n";
    cout<<"\t3. \tFor Any month high, low and average temperatures for a given month \n";
    cout<<"\t4. \tFor Month and day with the highest temperature\n";
    cout<<"\t5. \tFor Month and day with the lowest temperature. \n";
    cout<<"\t6. \tFor All months average temperature to he printed in table format\n";
    cout<<"\t7. \tto exit\n";
    choose =getchoice();
    switch (choose)

    {
        case 1:
        data_table();
        break;
        case 2:
            cout<<"enter the month: ";
            month = getchoice();
            if(month>0 && month<=12){
            cout<<"enter the date: ";
            date = getchoice();
            if(date>0 && date<=30){
            // we pass the variables by Reference 
            high_low_temp_day(month, date, &high, &low);
            cout<<date<<"\\"<<month<<"\\"<<"2010 highst temperature is "<<high<<" oC and the lowest is "<<low<<" oC"<<endl;// dispaly the result
            }
            else
            {
                cout<<"invalid input !!"<<endl;    
            }
            
            }
            else{
               cout<<"invalid input !!"<<endl;   
            }
        break;
        case 3: 
            cout<<"Enter the month: ";
            month = getchoice();
            if(month>0 && month<=12){
            high_low_avg_temp_month(month, &high, &low, &avg);
            cout<<"The highest temperature in "<<"month "<< month <<" is "<<high<<" oC"<<endl;
            cout<<"The lowest temperature in "<<"month "<< month <<" is "<<low<<" oC"<<endl;
            cout<<"The average temperature in "<<"month "<< month <<" is "<<avg<<" oC"<<endl;
            }
            else{
                cout<<"invalid input !!"<<endl;
            }
        break;
        case 4: 
            high_month_day(&high);
                cout<<"\nThe highest temperature in entire year is: "<<high<<"\n\n";
                cout<<"this temprature was recorded in:\n\n";
                for(int i=0; i<12; i++){
                    for(int j=0; j<30; j++){
                        for(int k=0; k<2; k++){
                            if(temp_rec[i][j][k]==high){
                            cout<<j+1<<" / "<<i+1<<" / 2010"<<endl;      
                            }
                        }
                    }
                
            }
        break;
        case 5: 
            low_month_day(&low);
            cout<<"\nThe lowest temperature in entire year is: "<<low<<"\n";
             cout<<"this temprature was recorded in:\n\n";
                for(int i=0; i<12; i++){
                    for(int j=0; j<30; j++){
                        for(int k=0; k<2; k++){
                            if(temp_rec[i][j][k]==low){
                            cout<<j+1<<" / "<<i+1<<" / 2010"<<endl;   
                            }
                        }
                    }
                }
        break;
        case 6:
       avtable(); 
        break;
        case 7:
        system ("CLS");
        Thank_u();
        cout<<"version: 1.0.0"<<endl;
        cout<<"build date: june 28 2021"<<endl;
        cout<<"build number: 0718.22/12"<<endl;
        cout<<"built by GROUP 1 plc";
        cout<<"Copyright all rights reserved."<<endl;
        cout<<"credits"<<endl;
        cout<<"YONATAN TESFAYE       ETS 0722/12"<<endl;
        cout<<"YONATAN TEKLESENBET   ETS 0718/12"<<endl;
        cout<<"YOSEF LAKEW           ETS 0729/12"<<endl;
        cout<<"VANILLA GETACHEW      ETS0652/12"<<endl;
        cout<<"EMRAN HAYREDIN        ETS0986/12"<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        exit=true;
        break;
        default:
        cout<<"invalid input. please try again!"<<endl;
        break;
       
    }
    if(choose!=7){
    cout<<"\n\n";
     system ("PAUSE");
     system ("CLS");
    } 
 } 
}
// Define a function that displays the menu or UI for Admin Account only 
void Admin_UI(){
    welcome();
    int choose, month, date,mnum;
    float avg, high, low;
    bool exit= false;
    while(exit==false){
    cout<<"\n\npress \n\n";
    cout<<"\t1. \tRecord Data. \n";
    cout<<"\t2. \tRandom Data. \n";
    cout<<"\t3. \tClear the Data. \n";
    cout<<"\t4. \tTo see the entire daily data in table. \n";
    cout<<"\t5. \tFor Any day's high and low temperature. \n";
    cout<<"\t6. \tFor Any month high, low and average temperatures for a given month \n";
    cout<<"\t7. \tFor Month and day with the highest temperature\n";
    cout<<"\t8. \tFor Month and day with the lowest temperature. \n";
    cout<<"\t9. \tFor All months average temperature to he printed in table format.\n";
    cout<<"\t10. \tTo Change User Name and PIN.\n";
    cout<<"\t11. \tTo exit\n";
    choose = getchoice();
    switch (choose)

    {   case 1:
            record();
            CSV();
        break;
        case 2:
            random();
        break;
        case 3:
            Clear_data();
        break;
        case 4:
        data_table();
        break;
        case 5:
            cout<<"enter the month: ";
            month = getchoice();
            if(month>0 && month<=12){
            cout<<"enter the date: ";
            date = getchoice();
            if(date>0 && date<=30){
            // we pass the variables by Reference 
            high_low_temp_day(month, date, &high, &low);
            cout<<date<<"\\"<<month<<"\\"<<"2010 highst temperature is "<<high<<" oC and the lowest is "<<low<<" oC"<<endl;// dispaly the result
            }
            else{
                cout<<"invalid input !!"<<endl;    
            }
            }
            else{
               cout<<"invalid input !!"<<endl;   
            }
        break;
        case 6: 
            cout<<"Enter the month: ";
            month = getchoice();
            if(month>0 && month<=12){
            high_low_avg_temp_month(month, &high, &low, &avg);
            cout<<"The highest temperature in "<<"month "<< month <<" is "<<high<<" oC"<<endl;
            cout<<"The lowest temperature in "<<"month "<< month <<" is "<<low<<" oC"<<endl;
            cout<<"The average temperature in "<<"month "<< month <<" is "<<avg<<" oC"<<endl;
            }
            else{
                cout<<"invalid input !!"<<endl;
            }
        break;
        case 7: 
            high_month_day(&high);
                cout<<"\nThe highest temperature in entire year is: "<<high<<"\n\n";
                cout<<"this temprature was recorded in:\n\n";
                for(int i=0; i<12; i++){
                    for(int j=0; j<30; j++){
                        for(int k=0; k<2; k++){
                            if(temp_rec[i][j][k]==high){
                            cout<<j+1<<" / "<<i+1<<" / 2010"<<endl;      
                            }
                        }
                    }
                
            }
        break;
        case 8: 
            low_month_day(&low);
            cout<<"\nThe lowest temperature in entire year is: "<<low<<"\n";
             cout<<"this temprature was recorded in:\n\n";
                for(int i=0; i<12; i++){
                    for(int j=0; j<30; j++){
                        for(int k=0; k<2; k++){
                            if(temp_rec[i][j][k]==low){
                            cout<<j+1<<" / "<<i+1<<" / 2010"<<endl;   
                            }
                        }
                    }
                }
        break;
        case 9:
       avtable(); 
        break;
        case 10:
            Change_PIN_UserName();
        break;
        case 11:
        system ("CLS");
        Thank_u();
        cout<<"version: 1.0.0"<<endl;
        cout<<"build date: june 28 2021"<<endl;
        cout<<"build number: 0718.22/12"<<endl;
        cout<<"built by GROUP 1 plc";
        cout<<"© all rights reserved."<<endl;
        cout<<"credits"<<endl;
        cout<<"YONATAN TESFAYE       ETS 0722/12"<<endl;
        cout<<"YONATAN TEKLESENBET   ETS 0718/12"<<endl;
        cout<<"YOSEF LAKEW           ETS 0729/12"<<endl;
        cout<<"VANILLA GETACHEW      ETS0652/12"<<endl;
        cout<<"EMRAN HAYREDIN        ETS0986/12"<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        exit=true;
        break;
        default:
        cout<<"invalid input. please try again!"<<endl;
        break;
       
    }
    if(choose!=11){
    cout<<"\n\n";    
     system ("PAUSE");
     system ("CLS");
    } 
 } 
}

int main(){
    
    system("color 05");
    data();
    ui();
}

//this function takes the main UI that asks if You are Admin or User for this APP
void ui(){
    
    bool back= false;
    int num;
    while(back==false){
    cout <<"\n****************************************************************************\n";
    cout <<"\tWELCOME\n";
    cout <<"\tADDIS ABABA SCIENCE AND TECHNOLOGY UNIVERSITY \n";
    cout <<"\tProject case study \n";
    cout <<"****************************************************************************\n";
    cout<<"1: Admin\n";
    cout<<"2: User\n";
    num = getchoice();

    if(num==1){
        admin();
        back=true;
    }
    else if(num==2)
    {
        User_UI();
        back=true;
    }
    else{
        system("CLS");    
        cout<<"wrong input. please choose from 1 and 2."<<endl;
        }
    }
}   

//This function reads Thank You text form Thank u.txt and display it;
void Thank_u(){

	ifstream ifs ("Thank u.txt");
	string Lines = " ";

    if (ifs)
    {
		while (ifs.good ())
		{
	    	string TempLine;
	    	getline (ifs , TempLine);
	    	TempLine += "\n";

	    	Lines += TempLine;
		}

	cout << Lines;

	}
    cout<<"\n\t  |\t\t\t\t\t\t\t";
    ifs.close ();

}
//define function that read user name and Pin form the CSV file in the dir and store it in Global Variabels
//user_Name and PIN_num.
void UName_Pin(){
    ifstream User_Name;
    ifstream PIN;
    User_Name.open("UserName.csv");
    PIN.open("PIN.csv");
    getline(User_Name, user_Name, ',');
    PIN>>PIN_num;
}