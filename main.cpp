//
//  main.cpp
//  Assignment1
//
//  Created by Colm Murphy on 22/09/2021.
//

#include <iostream>
using namespace std;

struct timet { //definition of structure for time in hr, min, sec format
    int hours;
    int minutes;
    int seconds;
};


timet computeTime(timet t1, timet t2); //fucntion prototypes
int convertToSeconds(timet t);
timet convertToHMS(int totalSeconds, int totalMinutes, int totalHours);


int main() {
    
    timet t1, t2, answer; //declare variables for times entered by user, and the result of the calculation

    cout << "Enter number of hours for time 1: "; //take user input from keyboard for the two times which are to be used in the calculation
    cin >> t1.hours;
    cout << "Enter number of minutes for time 1: ";
    cin >> t1.minutes;
    cout << "Enter number of seconds for time 1: ";
    cin >> t1.seconds;
    
    cout << "\nEnter number of hours for time 2: ";
    cin >> t2.hours;
    cout << "Enter number of minutes for time 2: ";
    cin >> t2.minutes;
    cout << "Enter number of seconds for time 2: ";
    cin >> t2.seconds;
    
    answer = computeTime(t1, t2); //call the function to calculate the answer
    
    cout << "\n\n" << answer.hours << " Hours, " << answer.minutes << " Minutes, and " << answer.seconds << " Seconds.\n"; //print answer as output

    return 0;
}

timet convertToHMS(int totalSeconds, int totalMinutes, int totalHours) { //function to convert time to hr, min, sec format
    timet t1;
    
    t1.hours = totalHours;
    t1.minutes = totalMinutes;
    t1.seconds = totalSeconds;
    
    if (totalSeconds > 60) { //if there are more than 60 seconds, convert to minutes and keep the remainder
        t1.minutes += floor(totalSeconds/60);
        t1.seconds = totalSeconds % 60;
    }
    if (totalMinutes > 60) { //if there are more than 60 minutes, convert to hours and keep the remainder
        t1.hours += floor(totalMinutes/60);
        t1.minutes = totalMinutes % 60;
    }
    return t1; //return in hr, min, sec format
};

int convertToSeconds(timet t) { //function to convert time in hr, min, sec format to seconds
    int totalSeconds = t.seconds; //take number of seconds
    
    totalSeconds += t.minutes * 60; //add minutes * 60 (i.e. minutes in seconds)
    totalSeconds += t.hours * 3600; //add hours *3600 (i.e. hours in seconds)
    
    return totalSeconds;
};

timet computeTime(timet t1, timet t2) { //function to add/subtract the two entered times
    int answerInSeconds, totalSeconds1, totalSeconds2;
    timet answer;
    
    totalSeconds1 = convertToSeconds(t1); //convert both times to seconds
    totalSeconds2 = convertToSeconds(t2);
    
    if (totalSeconds1 > totalSeconds2) { //compare the two totals to see if we need to add them or find the difference
        answerInSeconds = totalSeconds1 + totalSeconds2;
    }
    else {
        answerInSeconds = totalSeconds2 - totalSeconds1;
    }
   
    answer = convertToHMS(answerInSeconds, answer.minutes, answer.hours); //convert the result to the hr, min, sec format
    
    /*these two lines were to correct an error which I couldn't find which caused the time to be converted from seconds to minutes but not to hours*/
    answer.hours = answer.minutes / 60;
    answer.minutes = answer.minutes % 60;
    
    return answer; //return the answer
};
