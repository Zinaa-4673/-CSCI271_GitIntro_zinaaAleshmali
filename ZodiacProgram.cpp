 #include <iostream>
 #include <string>
 using namespace std;

   int main() {
    string Name;
    int month, day;
    string zodica = "";

    cout << "Enter your name: ";
    getline(cin, Name);

    cout << "Enter Your Birth Month (1-12):";
    cin >> month;

    cout << "Enter Your Birth Day: ";
    cin >> day;

    if ((month == 3 && day >= 21) || (month == 4 && day <= 19)) {
        zodica = "Aries"; 
    } else if ((month == 4 && day >= 20) || (month == 5 && day <= 20)) {
        zodica = "Taurus";
    } else if ((month == 5 && day >= 21) || (month == 6 && day <= 20)) {
        zodica = "Gemini";
    } else if ((month == 6 && day >= 21) || (month == 7 && day <= 22)) {
        zodica = "Cancer";
    } else if ((month == 7 && day >= 23) || (month == 8 && day <= 22)) {
        zodica = "Leo";
    } else if ((month == 8 && day >= 23) || (month == 9 && day <= 22)) {
        zodica = "Virgo";
    } else if ((month == 9 && day >= 23) || (month == 10 && day <= 22)) {
        zodica = "Libra";
    } else if ((month == 10 && day >= 23) || (month == 11 && day <= 21)) {
        zodica = "Scorpio";
    } else if ((month == 11 && day >= 22) || (month == 12 && day <= 21)) {
        zodica = "Sagittarius";
    } else if ((month == 12 && day >= 22) || (month == 1 && day <= 19)) {
        zodica = "Capricorn";
    } else if ((month == 1 && day >= 20) || (month == 2 && day <= 18)) {
        zodica = "Aquarius";
    } else if ((month == 2 && day >= 19) || (month == 3 && day <= 20)) {
        zodica = "Pisces";
    }
    cout << "Hello " << Name << " Your zodiac Sign is: " << zodica << endl;
    return 0;
 }