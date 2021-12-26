/*Given a time in -hour AM/PM format, convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.*/

#include <bits/stdc++.h>
#include<string>
using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
int hr;
int mm;
int ss;
string r;

hr = ((s[0]-'0')*10)+(s[1]-'0');
mm = ((s[3]-'0')*10)+(s[4]-'0');          
ss = ((s[6]-'0')*10)+(s[7]-'0');

if(hr<12 && s[8]=='P' )
  hr+=12;
  
if(hr==12 && s[8]=='A')
   hr=0;


if(hr<10 && mm<10 && ss<10)
   r = ("0" + to_string(hr) + ":" + "0" + to_string(mm) + ":" + "0" + to_string(ss));
   
else if(hr<10 && mm<10)
   r = ("0" + to_string(hr) + ":" + "0" + to_string(mm) + ":" + to_string(ss));
   
else if(hr<10 && ss<10)
   r = ("0" + to_string(hr) + ":" + to_string(mm) + ":" + "0" + to_string(ss));   
   
else if(mm<10 && ss<10)
   r = (to_string(hr) + ":" + "0" + to_string(mm) + ":" + "0" + to_string(ss));
   
else if(hr<10)
   r = ("0" + to_string(hr) + ":" + to_string(mm) + ":" + to_string(ss)); 
     
else if(mm<10)
   r = (to_string(hr) + ":" + "0" +  to_string(mm) + ":" + to_string(ss));
     
else if(ss<10)
   r = (to_string(hr) + ":" + to_string(mm) + ":" + "0" + to_string(ss));
           
else
   r = (to_string(hr) + ":" + to_string(mm) + ":" + to_string(ss));
     
     
return r;     
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
