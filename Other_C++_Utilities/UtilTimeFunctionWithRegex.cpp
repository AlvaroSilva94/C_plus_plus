#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

uint64_t ValidateTimeFormat(bool match, string time)
{
    //declaration of time variables
    string year,month,day,hour,hour2,minute,minute2,second;

    if (match == true)
    {
        //get individual fields for string format YYYY-MM-DDThh:mm:ss+hh:mm
        year.assign(time.substr(0,4));
        int IntYear = stoi(year);

        month.assign(time.substr(5,2));
        int IntMonth = stoi(month);

        day.assign(time.substr(8,2));
        int IntDay = stoi(day);

        hour.assign(time.substr(11,2));
        int IntHour = stoi(hour);

        minute.assign(time.substr(14,2));
        int IntMinute = stoi(minute);

        second.assign(time.substr(17,2));
        int IntSecond = stoi(second);

        hour2.assign(time.substr(20,2));
        int IntHour2 = stoi(hour2);

        minute2.assign(time.substr(23,2));
        int IntMinute2 = stoi(minute2);

        if ((year.size()==4) && (IntYear <= 2100) && (IntYear > 2000))
        {
            if ((month.size()==2) && (IntMonth <= 12) && (IntMonth > 0))
            {
                if ((day.size()==2) && (IntDay <= 31) && (IntDay > 0))
                {
                   if ((hour.size()==2) && (IntHour <= 24) && (IntHour > 0))
                   {
                       if ((minute.size()==2) && (IntMinute <= 59) && (IntMinute >= 0))
                       {
                           if ((second.size()==2) && (IntSecond <= 59) && (IntSecond >= 0))
                           {
                               if ((hour2.size()==2) && (IntHour2 <= 24) && (IntHour2 >= 0))
                               {
                                 if ((minute2.size()==2) && (IntMinute2 <= 59) && (IntMinute2 >= 0))
                                 {
                                    useroper.ReportCheck<bool>("Attribute time set to set to the notification time in the format \"YYYY-MM-DDThh:mm:ss+hh:mm\"", match, eEqual, true);
                                 }
                                 else
                                 {
                                     useroper.ReportEvent(eRTFault, "Attribute time is not in the format \"YYYY-MM-DDThh:mm:ss+hh:mm\": Minute2 not okay");
                                 }
                               }
                               else
                               {
                                   useroper.ReportEvent(eRTFault, "Attribute time is not in the format \"YYYY-MM-DDThh:mm:ss+hh:mm\": Hour2 not okay");
                               }
                           }
                           else
                           {
                               useroper.ReportEvent(eRTFault, "Attribute time is not in the format \"YYYY-MM-DDThh:mm:ss+hh:mm\": Seconds not okay");
                           }
                       }
                       else
                       {
                           useroper.ReportEvent(eRTFault, "Attribute time is not in the format \"YYYY-MM-DDThh:mm:ss+hh:mm\": Minutes not okay");
                       }
                   }
                   else
                   {
                       useroper.ReportEvent(eRTFault, "Attribute time is not in the format \"YYYY-MM-DDThh:mm:ss+hh:mm\": Hour not okay");
                   }
                }
                else
                {
                    useroper.ReportEvent(eRTFault, "Attribute time is not in the format \"YYYY-MM-DDThh:mm:ss+hh:mm\": Day not okay");
                }
            }
            else
            {
                useroper.ReportEvent(eRTFault, "Attribute time is not in the format \"YYYY-MM-DDThh:mm:ss+hh:mm\": Month not okay");
            }
        }
        else
        {
            useroper.ReportEvent(eRTFault, "Attribute time is not in the format \"YYYY-MM-DDThh:mm:ss+hh:mm\": Year not okay");
        }



    }
    else
    {
        useroper.ReportEvent(eRTFault, "Attribute time is not in the format \"YYYY-MM-DDThh:mm:ss+hh:mm\": match is not true");
    }

    return 0;
}

int main()
{

//Get time from received messsage (code missing due to copywrite)
string strTime;
strTime.assign(""); //Note: Time to assign in format YYYY-MM-DDTHH:MM:SS:SS+MSMS:DD

//regex to limit field interval
regex rtime("[0-9][0-9][0-9][0-9][-][0-1][0-9][-][0-3][0-9][T][0-6][0-9][:][0-6][0-9][:][0-6][0-9][+][0-6][0-9][:][0-6][0-9]");
                                                                                                                                      
//To match regex with the string obtained from the message
bool match1 = regex_match(strTime, rtime);

//function to validate time format
ValidateTimeFormat(match1,strTime);

}


