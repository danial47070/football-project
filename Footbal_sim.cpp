#include <iostream>
#include <string.h>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include <string>
using namespace std;

struct Team {
    string name;
    string coachEmail;
    long long budget;
    int playerCount;
};
struct Player {
    string Id;
    string name;
    int att;
    int def;
    long long value;
};
Player P[50];// array of player structure
struct Table {
    int gf = 0;
    int ga = 0;
    int wins = 0;
    int losses = 0;
    int draws = 0;
    int plays = 0;
    int points = 0;
};
Table table[4];
struct Coach {
    string username;
    string password;
};


void loginMenu() {
    cout << "1. login" << endl;
    cout << "2. forgot password ?" << endl;
}
void forgotMenu() {
    cout << "Coming Soon ..." << endl;
}
void mainMenu() {
    cout << "1. Admin login" << endl;
    cout << "2. Coach login" << endl;
    cout << "3. Exit" << endl;
}
void AdminMenu() {
    cout << "1. Create Teams" << endl;
    cout << "2. create players" << endl;
    cout << "3. Start the league" << endl;
    cout << "4. Start the week" << endl;
    cout << "5. Show the table" << endl;
    cout << "6. Exit" << endl;
}
void CoachMenu() {
    cout << "1. change your Password" << endl;
    cout << "2. Players List" << endl;
    cout << "3. buy players" << endl;
    cout << "4. sell players" << endl;
    cout << "5. Team managment" << endl;
    cout << "6. Exit" << endl;
}
string pathtstt[4] = { // array of files to save every team data in a single file
        "team1stt.txt",
        "team2stt.txt",
        "team3stt.txt",
        "team4stt.txt"
};
string pathtable[4] = {
        "team1t.txt",
        "team2t.txt",
        "team3t.txt",
        "team4t.txt"
};
int findPlayerById(Player P[], int n, string targetId, int index) {
    if (index == n)
        return -1; // player not found
    if (P[index].Id == targetId)
        return index;
    return findPlayerById(P, n, targetId, index + 1);
}
void week1() { // 1 vs 2   // 3 vs 4
    srand(time(0));
    int attsum[4] = {0 , 0 , 0 , 0};
    int defsum[4] = {0 , 0 , 0 , 0};
    int i=0;
    while(i<4){
        ifstream Pstt(pathtstt[i]);
        for(int j=0 ; j<8 ; j++){
            Pstt >> P[j].att;
            Pstt >> P[j].def;
        }
        Pstt.close();
        int c=0;
        int num[5]= {10 , 10 , 10 , 10 , 10};
        while(c<5){
           int numrand = rand()%8; // generate a random number between 0 to 7
           if(num[0] != numrand && num[1] != numrand && num[2] != numrand && num[3] != numrand && num[4] != numrand){
                num[c]= numrand;
                c++;
           }
        }
        for(int k=0 ; k<5 ; k++){
            attsum[i]+= P[num[k]].att;
            defsum[i]+= P[num[k]].def;
        }
        i++;
    }
    ////////////////////////////////////////////////////////////////// match 1
    int gf0 = max(0 , (attsum[0]-defsum[1])/100);
    int gf1 = max(0 , (attsum[1]-defsum[0])/100);
    table[0].gf += max(0 , (attsum[0]-defsum[1])/100);
    table[1].ga += max(0 , (attsum[0]-defsum[1])/100);
    table[1].gf += max(0 , (attsum[1]-defsum[0])/100);
    table[0].ga += max(0 , (attsum[1]-defsum[0])/100);
    table[0].plays += 1;
    table[1].plays += 1;
    if(gf0 > gf1){
        table[0].wins += 1;
        table[1].losses += 1;
        table[0].points += 3;

    }
    else if(gf0 < gf1){
        table[1].wins += 1;
        table[0].losses += 1;
        table[1].points += 3;
    }
    else {
        table[1].draws += 1;
        table[0].draws += 1;
        table[0].points += 1;
        table[1].points += 1;
    }
    ////////////////////////////////////////////////////////////////// match 2
    int gf2 = max(0 , (attsum[2]-defsum[3])/100);
    int gf3 = max(0 , (attsum[3]-defsum[2])/100);
    table[2].gf += max(0 , (attsum[2]-defsum[3])/100);
    table[3].ga += max(0 , (attsum[2]-defsum[3])/100);
    table[3].gf += max(0 , (attsum[3]-defsum[2])/100);
    table[2].ga += max(0 , (attsum[3]-defsum[2])/100);
    table[2].plays += 1;
    table[3].plays += 1;
    if(gf2 > gf3){
        table[2].wins += 1;
        table[3].losses += 1;
        table[2].points += 3;
    }
    else if(gf3 > gf2){
        table[3].wins += 1;
        table[2].losses += 1;
        table[3].points += 3;
    }
    else {
        table[3].draws += 1;
        table[2].draws += 1;
        table[2].points += 1;
        table[3].points += 1;
    }
    for (int i = 0; i < 4; i++) {
        ofstream Table(pathtable[i]);
        Table << table[i].gf << endl;
        Table << table[i].ga << endl;
        Table << table[i].wins << endl;
        Table << table[i].losses << endl;
        Table << table[i].draws << endl;
        Table << table[i].plays << endl;
        Table << table[i].points << endl;
        Table.close();
}
}
void week2() { // 1 vs 3   // 2 vs 4
    srand(time(0));
    int attsum[4] = {0 , 0 , 0 , 0};
    int defsum[4] = {0 , 0 , 0 , 0};
    int i=0;
    while(i<4){
        ifstream Pstt(pathtstt[i]);
        for(int j=0 ; j<8 ; j++){
            Pstt >> P[j].att;
            Pstt >> P[j].def;
        }
        Pstt.close();
        int c=0;
        int num[5]= {10 , 10 , 10 , 10 , 10};
        while(c<5){
           int numrand = rand()%8; // generate a random number between 0 to 7
           if(num[0] != numrand && num[1] != numrand && num[2] != numrand && num[3] != numrand && num[4] != numrand){
                num[c]= numrand;
                c++;
           }
        }
        for(int k=0 ; k<5 ; k++){
            attsum[i]+= P[num[k]].att;
            defsum[i]+= P[num[k]].def;
        }
        i++;
    }
    for (int i = 0; i < 4; i++) {
        ifstream Table(pathtable[i]);
        Table >> table[i].gf;
        Table >> table[i].ga;
        Table >> table[i].wins;
        Table >> table[i].losses;
        Table >> table[i].draws;
        Table >> table[i].plays;
        Table >> table[i].points;
        Table.close();
}
    ////////////////////////////////////////////////////////////////// match 1
    int gf0 = max(0 , (attsum[0]-defsum[2])/100);
    int gf2 = max(0 , (attsum[2]-defsum[0])/100);
    table[0].gf += max(0 , (attsum[0]-defsum[2])/100);
    table[2].ga += max(0 , (attsum[0]-defsum[2])/100);
    table[2].gf += max(0 , (attsum[2]-defsum[0])/100);
    table[0].ga += max(0 , (attsum[2]-defsum[0])/100);
    table[0].plays += 1;
    table[2].plays += 1;
    if(gf0 > gf2){
        table[0].wins += 1;
        table[2].losses += 1;
        table[0].points += 3;

    }
    else if(gf2 > gf0){
        table[2].wins += 1;
        table[0].losses += 1;
        table[2].points += 3;
    }
    else {
        table[2].draws += 1;
        table[0].draws += 1;
        table[0].points += 1;
        table[2].points += 1;
    }
    ////////////////////////////////////////////////////////////////// match 2
    int gf1 = max(0 , (attsum[1]-defsum[3])/100);
    int gf3 = max(0 , (attsum[3]-defsum[1])/100);
    table[1].gf += max(0 , (attsum[1]-defsum[3])/100);
    table[3].ga += max(0 , (attsum[1]-defsum[3])/100);
    table[3].gf += max(0 , (attsum[3]-defsum[1])/100);
    table[1].ga += max(0 , (attsum[3]-defsum[1])/100);
    table[1].plays += 1;
    table[3].plays += 1;
    if(gf1 > gf3){
        table[1].wins += 1;
        table[3].losses += 1;
        table[1].points += 3;
    }
    else if(gf3 > gf1){
        table[3].wins += 1;
        table[1].losses += 1;
        table[3].points += 3;
    }
    else {
        table[3].draws += 1;
        table[1].draws += 1;
        table[1].points += 1;
        table[3].points += 1;
    }
    for (int i = 0; i < 4; i++) {
        ofstream Table(pathtable[i]);
        Table << table[i].gf << endl;
        Table << table[i].ga << endl;
        Table << table[i].wins << endl;
        Table << table[i].losses << endl;
        Table << table[i].draws << endl;
        Table << table[i].plays << endl;
        Table << table[i].points << endl;
        Table.close();
}
}
void week3() { // 1 vs 4   // 3 vs 2
    srand(time(0));
    int attsum[4] = {0 , 0 , 0 , 0};
    int defsum[4] = {0 , 0 , 0 , 0};
    int i=0;
    while(i<4){
        ifstream Pstt(pathtstt[i]);
        for(int j=0 ; j<8 ; j++){
            Pstt >> P[j].att;
            Pstt >> P[j].def;
        }
        Pstt.close();
        int c=0;
        int num[5]= {10 , 10 , 10 , 10 , 10};
        while(c<5){
           int numrand = rand()%8; // generate a random number between 0 to 7
           if(num[0] != numrand && num[1] != numrand && num[2] != numrand && num[3] != numrand && num[4] != numrand){
                num[c]= numrand;
                c++;
           }
        }
        for(int k=0 ; k<5 ; k++){
            attsum[i]+= P[num[k]].att;
            defsum[i]+= P[num[k]].def;
        }
        i++;
    }
    for (int i = 0; i < 4; i++) {
        ifstream Table(pathtable[i]);
        Table >> table[i].gf;
        Table >> table[i].ga;
        Table >> table[i].wins;
        Table >> table[i].losses;
        Table >> table[i].draws;
        Table >> table[i].plays;
        Table >> table[i].points;
        Table.close();
}
    ////////////////////////////////////////////////////////////////// match 1
    int gf0 = max(0 , (attsum[0]-defsum[3])/100);
    int gf3 = max(0 , (attsum[3]-defsum[0])/100);
    table[0].gf += max(0 , (attsum[0]-defsum[3])/100);
    table[3].ga += max(0 , (attsum[0]-defsum[3])/100);
    table[3].gf += max(0 , (attsum[3]-defsum[0])/100);
    table[0].ga += max(0 , (attsum[3]-defsum[0])/100);
    table[0].plays += 1;
    table[3].plays += 1;
    if(gf0 > gf3){
        table[0].wins += 1;
        table[3].losses += 1;
        table[0].points += 3;

    }
    else if(gf3 > gf0){
        table[3].wins += 1;
        table[0].losses += 1;
        table[3].points += 3;
    }
    else {
        table[3].draws += 1;
        table[0].draws += 1;
        table[0].points += 1;
        table[3].points += 1;
    }
    ////////////////////////////////////////////////////////////////// match 2
    int gf2 = max(0 , (attsum[2]-defsum[1])/100);
    int gf1 = max(0 , (attsum[1]-defsum[2])/100);
    table[2].gf += max(0 , (attsum[2]-defsum[1])/100);
    table[1].ga += max(0 , (attsum[2]-defsum[1])/100);
    table[1].gf += max(0 , (attsum[1]-defsum[2])/100);
    table[2].ga += max(0 , (attsum[1]-defsum[2])/100);
    table[2].plays += 1;
    table[1].plays += 1;
    if(gf2 > gf1){
        table[2].wins += 1;
        table[1].losses += 1;
        table[2].points += 3;
    }
    else if(gf1 > gf2){
        table[1].wins += 1;
        table[2].losses += 1;
        table[1].points += 3;
    }
    else {
        table[1].draws += 1;
        table[2].draws += 1;
        table[2].points += 1;
        table[1].points += 1;
    }
    for (int i = 0; i < 4; i++) {
        ofstream Table(pathtable[i]);
        Table << table[i].gf << endl;
        Table << table[i].ga << endl;
        Table << table[i].wins << endl;
        Table << table[i].losses << endl;
        Table << table[i].draws << endl;
        Table << table[i].plays << endl;
        Table << table[i].points << endl;
        Table.close();
}
}
void week4() { // 1 vs 2   // 3 vs 4
    srand(time(0));
    int attsum[4] = {0 , 0 , 0 , 0};
    int defsum[4] = {0 , 0 , 0 , 0};
    int i=0;
    while(i<4){
        ifstream Pstt(pathtstt[i]);
        for(int j=0 ; j<8 ; j++){
            Pstt >> P[j].att;
            Pstt >> P[j].def;
        }
        Pstt.close();
        int c=0;
        int num[5]= {10 , 10 , 10 , 10 , 10};
        while(c<5){
           int numrand = rand()%8; // generate a random number between 0 to 7
           if(num[0] != numrand && num[1] != numrand && num[2] != numrand && num[3] != numrand && num[4] != numrand){
                num[c]= numrand;
                c++;
           }
        }
        for(int k=0 ; k<5 ; k++){
            attsum[i]+= P[num[k]].att;
            defsum[i]+= P[num[k]].def;
        }
        i++;
    }
    ////////////////////////////////////////////////////////////////// match 1
    int gf0 = max(0 , (attsum[0]-defsum[1])/100);
    int gf1 = max(0 , (attsum[1]-defsum[0])/100);
    table[0].gf += max(0 , (attsum[0]-defsum[1])/100);
    table[1].ga += max(0 , (attsum[0]-defsum[1])/100);
    table[1].gf += max(0 , (attsum[1]-defsum[0])/100);
    table[0].ga += max(0 , (attsum[1]-defsum[0])/100);
    table[0].plays += 1;
    table[1].plays += 1;
    if(gf0 > gf1){
        table[0].wins += 1;
        table[1].losses += 1;
        table[0].points += 3;

    }
    else if(gf0 < gf1){
        table[1].wins += 1;
        table[0].losses += 1;
        table[1].points += 3;
    }
    else {
        table[1].draws += 1;
        table[0].draws += 1;
        table[0].points += 1;
        table[1].points += 1;
    }
    ////////////////////////////////////////////////////////////////// match 2
    int gf2 = max(0 , (attsum[2]-defsum[3])/100);
    int gf3 = max(0 , (attsum[3]-defsum[2])/100);
    table[2].gf += max(0 , (attsum[2]-defsum[3])/100);
    table[3].ga += max(0 , (attsum[2]-defsum[3])/100);
    table[3].gf += max(0 , (attsum[3]-defsum[2])/100);
    table[2].ga += max(0 , (attsum[3]-defsum[2])/100);
    table[2].plays += 1;
    table[3].plays += 1;
    if(gf2 > gf3){
        table[2].wins += 1;
        table[3].losses += 1;
        table[2].points += 3;
    }
    else if(gf3 > gf2){
        table[3].wins += 1;
        table[2].losses += 1;
        table[3].points += 3;
    }
    else {
        table[3].draws += 1;
        table[2].draws += 1;
        table[2].points += 1;
        table[3].points += 1;
    }
    for (int i = 0; i < 4; i++) {
        ofstream Table(pathtable[i]);
        Table << table[i].gf << endl;
        Table << table[i].ga << endl;
        Table << table[i].wins << endl;
        Table << table[i].losses << endl;
        Table << table[i].draws << endl;
        Table << table[i].plays << endl;
        Table << table[i].points << endl;
        Table.close();
}
}
void week5() { // 1 vs 3   // 2 vs 4
    srand(time(0));
    int attsum[4] = {0 , 0 , 0 , 0};
    int defsum[4] = {0 , 0 , 0 , 0};
    int i=0;
    while(i<4){
        ifstream Pstt(pathtstt[i]);
        for(int j=0 ; j<8 ; j++){
            Pstt >> P[j].att;
            Pstt >> P[j].def;
        }
        Pstt.close();
        int c=0;
        int num[5]= {10 , 10 , 10 , 10 , 10};
        while(c<5){
           int numrand = rand()%8; // generate a random number between 0 to 7
           if(num[0] != numrand && num[1] != numrand && num[2] != numrand && num[3] != numrand && num[4] != numrand){
                num[c]= numrand;
                c++;
           }
        }
        for(int k=0 ; k<5 ; k++){
            attsum[i]+= P[num[k]].att;
            defsum[i]+= P[num[k]].def;
        }
        i++;
    }
    for (int i = 0; i < 4; i++) {
        ifstream Table(pathtable[i]);
        Table >> table[i].gf;
        Table >> table[i].ga;
        Table >> table[i].wins;
        Table >> table[i].losses;
        Table >> table[i].draws;
        Table >> table[i].plays;
        Table >> table[i].points;
        Table.close();
}
    ////////////////////////////////////////////////////////////////// match 1
    int gf0 = max(0 , (attsum[0]-defsum[2])/100);
    int gf2 = max(0 , (attsum[2]-defsum[0])/100);
    table[0].gf += max(0 , (attsum[0]-defsum[2])/100);
    table[2].ga += max(0 , (attsum[0]-defsum[2])/100);
    table[2].gf += max(0 , (attsum[2]-defsum[0])/100);
    table[0].ga += max(0 , (attsum[2]-defsum[0])/100);
    table[0].plays += 1;
    table[2].plays += 1;
    if(gf0 > gf2){
        table[0].wins += 1;
        table[2].losses += 1;
        table[0].points += 3;

    }
    else if(gf2 > gf0){
        table[2].wins += 1;
        table[0].losses += 1;
        table[2].points += 3;
    }
    else {
        table[2].draws += 1;
        table[0].draws += 1;
        table[0].points += 1;
        table[2].points += 1;
    }
    ////////////////////////////////////////////////////////////////// match 2
    int gf1 = max(0 , (attsum[1]-defsum[3])/100);
    int gf3 = max(0 , (attsum[3]-defsum[1])/100);
    table[1].gf += max(0 , (attsum[1]-defsum[3])/100);
    table[3].ga += max(0 , (attsum[1]-defsum[3])/100);
    table[3].gf += max(0 , (attsum[3]-defsum[1])/100);
    table[1].ga += max(0 , (attsum[3]-defsum[1])/100);
    table[1].plays += 1;
    table[3].plays += 1;
    if(gf1 > gf3){
        table[1].wins += 1;
        table[3].losses += 1;
        table[1].points += 3;
    }
    else if(gf3 > gf1){
        table[3].wins += 1;
        table[1].losses += 1;
        table[3].points += 3;
    }
    else {
        table[3].draws += 1;
        table[1].draws += 1;
        table[1].points += 1;
        table[3].points += 1;
    }
    for (int i = 0; i < 4; i++) {
        ofstream Table(pathtable[i]);
        Table << table[i].gf << endl;
        Table << table[i].ga << endl;
        Table << table[i].wins << endl;
        Table << table[i].losses << endl;
        Table << table[i].draws << endl;
        Table << table[i].plays << endl;
        Table << table[i].points << endl;
        Table.close();
}
}
void week6() { // 1 vs 4   // 3 vs 2
    srand(time(0));
    int attsum[4] = {0 , 0 , 0 , 0};
    int defsum[4] = {0 , 0 , 0 , 0};
    int i=0;
    while(i<4){
        ifstream Pstt(pathtstt[i]);
        for(int j=0 ; j<8 ; j++){
            Pstt >> P[j].att;
            Pstt >> P[j].def;
        }
        Pstt.close();
        int c=0;
        int num[5]= {10 , 10 , 10 , 10 , 10};
        while(c<5){
           int numrand = rand()%8; // generate a random number between 0 to 7
           if(num[0] != numrand && num[1] != numrand && num[2] != numrand && num[3] != numrand && num[4] != numrand){
                num[c]= numrand;
                c++;
           }
        }
        for(int k=0 ; k<5 ; k++){
            attsum[i]+= P[num[k]].att;
            defsum[i]+= P[num[k]].def;
        }
        i++;
    }
    for (int i = 0; i < 4; i++) {
        ifstream Table(pathtable[i]);
        Table >> table[i].gf;
        Table >> table[i].ga;
        Table >> table[i].wins;
        Table >> table[i].losses;
        Table >> table[i].draws;
        Table >> table[i].plays;
        Table >> table[i].points;
        Table.close();
}
    ////////////////////////////////////////////////////////////////// match 1
    int gf0 = max(0 , (attsum[0]-defsum[3])/100);
    int gf3 = max(0 , (attsum[3]-defsum[0])/100);
    table[0].gf += max(0 , (attsum[0]-defsum[3])/100);
    table[3].ga += max(0 , (attsum[0]-defsum[3])/100);
    table[3].gf += max(0 , (attsum[3]-defsum[0])/100);
    table[0].ga += max(0 , (attsum[3]-defsum[0])/100);
    table[0].plays += 1;
    table[3].plays += 1;
    if(gf0 > gf3){
        table[0].wins += 1;
        table[3].losses += 1;
        table[0].points += 3;

    }
    else if(gf3 > gf0){
        table[3].wins += 1;
        table[0].losses += 1;
        table[3].points += 3;
    }
    else {
        table[3].draws += 1;
        table[0].draws += 1;
        table[0].points += 1;
        table[3].points += 1;
    }
    ////////////////////////////////////////////////////////////////// match 2
    int gf2 = max(0 , (attsum[2]-defsum[1])/100);
    int gf1 = max(0 , (attsum[1]-defsum[2])/100);
    table[2].gf += max(0 , (attsum[2]-defsum[1])/100);
    table[1].ga += max(0 , (attsum[2]-defsum[1])/100);
    table[1].gf += max(0 , (attsum[1]-defsum[2])/100);
    table[2].ga += max(0 , (attsum[1]-defsum[2])/100);
    table[2].plays += 1;
    table[1].plays += 1;
    if(gf2 > gf1){
        table[2].wins += 1;
        table[1].losses += 1;
        table[2].points += 3;
    }
    else if(gf1 > gf2){
        table[1].wins += 1;
        table[2].losses += 1;
        table[1].points += 3;
    }
    else {
        table[1].draws += 1;
        table[2].draws += 1;
        table[2].points += 1;
        table[1].points += 1;
    }
    for (int i = 0; i < 4; i++) {
        ofstream Table(pathtable[i]);
        Table << table[i].gf << endl;
        Table << table[i].ga << endl;
        Table << table[i].wins << endl;
        Table << table[i].losses << endl;
        Table << table[i].draws << endl;
        Table << table[i].plays << endl;
        Table << table[i].points << endl;
        Table.close();
}
}

int main() {
    loginMenu();
    int choice;
    int week = 1;
    int n = 0; // number of players insert by Admin
    string userA;
    string passA;
    Team T[4]; // array of Team structure
    //Player P[50];// array of player structure
    //Playersv Psv[50]; // array of players structure that saves in a file
    Coach C[4]; // array of couch structure
    string pathc[4] = { // array of files to save each coach user/pass in a single file
        "coach1.txt",
        "coach2.txt",
        "coach3.txt",
        "coach4.txt"
    };
    string patht[4] = { // array of files to save each team data in a single file
        "team1.txt",
        "team2.txt",
        "team3.txt",
        "team4.txt"
    };
    string pathbought[4] = { // array of files to save each team players data in a single file **********************************************************************
        "bought1.txt" ,
        "bought2.txt" ,
        "bought3.txt" ,
        "bought4.txt" ,

    };
    cin >> choice; // login menu choice
    if (choice == 1) {
        mainMenu();
    }
    else if (choice == 2) {
        forgotMenu();
    }
    while (true) {
        cin >> choice; // main menu choice
        if (choice == 1) { // Admin login menu
            cout << "user name : ";
            cin >> userA;
            cout << "password : ";
            cin >> passA;
            if (userA == "Admin" && passA == "Admin") {
                cout << endl;
                AdminMenu();
                cin >> choice;
                if (choice == 1) { // Team creation
                    int i = 0;
                    while (i < 4) {
                        //// opening the files
                        ofstream teamdata(patht[i]);
                        ofstream Email(pathc[i]);
                        cout << "enter Team " << i + 1 << " name : ";
                        cin >> T[i].name;
                        cout << "enter Team " << i + 1 << " coach Email : ";
                        cin >> T[i].coachEmail;
                        cout << "enter Team " << i + 1 << " budget : ";
                        cin >> T[i].budget;
                        //// Writing in the files
                        T[i].playerCount = 0;
                        teamdata << T[i].name << endl;
                        teamdata << T[i].budget << endl;
                        teamdata << T[i].playerCount << endl;
                        Email << T[i].coachEmail << endl;
                        Email << T[i].coachEmail << endl; // saving default password in the second line of each coach file
                        //// closing the files
                        teamdata.close();
                        Email.close();
                        // update
                        i++;
                    }
                    cout << endl;
                    cout << ". . . information saved ." << endl;
                    cout << endl;
                    mainMenu();
                }
                if (choice == 2) { // player creation
                    int i = 0;
                    cout << "enter number of players (maximum = 50)" << endl;
                    int num;
                    cin >> num; // number of players admin wants to enter
                    n+=num;
                    //// opening the file
                    ofstream Players("player.txt", ios::app); // opening file in app mode so admin can add players anytime
                    Players << n << endl;
                    while (i < num) {
                        cout << "enter Player " << i + 1 << " name : ";
                        cin >> P[i].name;
                        cout << "enter Player " << i + 1 << " Id : ";
                        cin >> P[i].Id;
                        cout << "enter Player " << i + 1 << " attack : ";
                        cin >> P[i].att;
                        cout << "enter Player " << i + 1 << " defense : ";
                        cin >> P[i].def;
                        cout << "enter Player " << i + 1 << " value : ";
                        cin >> P[i].value;
                        //// writing in the file
                        Players << P[i].Id << "\t";
                        Players << P[i].name << "\t";
                        Players << P[i].att << "\t";
                        Players << P[i].def << "\t";
                        Players << P[i].value << endl;
                        // update
                        i++;
                    }
                    //// closing the file
                    Players.close();
                    cout << endl;
                    cout << ". . . information saved ." << endl;
                    cout << endl;
                    mainMenu();
                }
                if (choice == 3) { //start the league
                    bool ready = true;
                   /* for (int k = 0; k < 4; k++) {
                        ifstream checkT(patht[k]);
                        if (!checkT.is_open()) {
                            cout << "Error: Team " << k + 1 << " file not found! Create all teams first." << endl;
                            ready = false;
                            continue;
                        }
                        checkT >> T[k].name;
                        checkT >> T[k].budget;
                        checkT >> T[k].playerCount;

                        if (T[k].playerCount < 8) {
                            cout << "Team " << T[k].name << " is not ready! Players: " << T[k].playerCount << "/8)" << endl;
                            ready = false;
                        }
                        checkT.close();
                    }*/
                    if (ready) {
                        cout << "All the teams are ready with 8 players each." << endl;
                        cout << "Starting the league simulation..." << endl;
                    }
                    else {
                        cout << "League can't start. All teams must have 8 players." << endl;
                    }
                    mainMenu();
                }
                if (choice == 4) { // starting weeks
                    ifstream Week("week.txt");
                    Week >> week;
                    if (week == 1){
                        week1();
                        week++;
                        cout << "week 1 simulated succesfully" << endl;
                        ofstream Week("week.txt");
                        Week << week << endl;
                    }
                    else if (week == 2){
                        week2();
                        week++;
                        cout << "week 2 simulated succesfully" << endl;
                        ofstream Week("week.txt");
                        Week << week << endl;
                    }
                    else if (week == 3){
                        week3();
                        week++;
                        cout << "week 3 simulated succesfully" << endl;
                        ofstream Week("week.txt");
                        Week << week << endl;
                    }
                    else if (week == 4){
                        week4();
                        week++;
                        cout << "week 4 simulated succesfully" << endl;
                        ofstream Week("week.txt");
                        Week << week << endl;
                    }
                    else if (week == 5){
                        week5();
                        week++;
                        cout << "week 5 simulated succesfully" << endl;
                        ofstream Week("week.txt");
                        Week << week << endl;
                    }
                    else if (week == 6){
                        week6();
                        week++;
                        cout << "week 6 simulated succesfully" << endl;
                        ofstream Week("week.txt");
                        Week << week << endl;
                    }
                    else {
                        cout << "the league ended last week" << endl;
                    }
                    mainMenu();
                }
                if (choice == 5) { // table
                    for (int i = 0; i < 4; i++) {
                        ifstream Table(pathtable[i]);
                        Table >> table[i].gf;
                        Table >> table[i].ga;
                        Table >> table[i].wins;
                        Table >> table[i].losses;
                        Table >> table[i].draws;
                        Table >> table[i].plays;
                        Table >> table[i].points;
                        Table.close();
                    }
                    cout  << "\t" << "pl\t" << "w\t" << "l\t" << "d\t" << "ga\t" << "gf\t" << "p\t" << endl;
                    for (int i = 0; i < 4; i++){
                        cout << "team " << i+1 << "\t" << table[i].plays << "\t" << table[i].wins << "\t" << table[i].losses << "\t" << table[i].draws << "\t" << table[i].ga << "\t" << table[i].gf << "\t" << table[i].points << endl;
                    }
                    mainMenu();
                }
                if (choice == 6) { // exiting the admin menu
                    mainMenu();
                }
            }
            else { // number entered is not between 1 to 6
                cout << "wrong user name or password " << endl;
                mainMenu();
            }
        }
        else if (choice == 2) { // coach login menu
            //// Reading coach email/pass from the file
            for (int i = 0; i < 4; i++) {
                ifstream Email(pathc[i]);
                Email >> C[i].username;
                Email >> C[i].password;
                Email.close();
                ifstream teamdata(patht[i]);
                teamdata >> T[i].name >> T[i].budget >> T[i].playerCount; // reading the last budget from the file
                teamdata.close();
            }
            string userB;
            string passB;
            cout << "username: ";
            cin >> userB;
            cout << "password: ";
            cin >> passB;
            for (int i = 0; i < 4; i++) {
                if (userB == C[i].username && passB == C[i].password) {
                    int num;
                    CoachMenu();
                    cin >> choice;
                    if (choice == 1) { //change password
                        cout << "username: ";
                        cin >> userB;
                        if (userB == C[i].username) {
                            cout << "type your new password: ";
                            cin >> passB;
                            C[i].password = passB;
                            //// saving new pass to file
                            ofstream Email(pathc[i]);
                            Email << C[i].username << endl;
                            Email << C[i].password << endl;
                            Email.close();
                            cout << "password changed." << endl;
                        }
                        cout << endl;
                        mainMenu();
                        break;
                    }
                    else if (choice == 2) { //players' list
                        int num;
                        //// Reading players info from the file
                        ifstream Players("player.txt");
                        Players >> num;
                        for (int i = 0; i < num; i++) {
                            Players >> P[i].Id;
                            Players >> P[i].name;
                            Players >> P[i].att;
                            Players >> P[i].def;
                            Players >> P[i].value;
                        }
                        Players.close();
                        for (int j = 0; j < num; j++) {
                            int min;
                            int temp;
                            min = j;
                            for (int i = j; i < num; i++) {
                                if (P[i].value < P[min].value) {
                                    min = i;
                                }
                            }
                            if (min != j) {
                                Player temp = P[min];
                                P[min] = P[j];
                                P[j] = temp;
                            }
                        }
                        for (int i = 0; i < num; i++) {
                            cout << endl << P[i].Id << " : " << P[i].name << " : " << P[i].att << " : " << P[i].def << " : " << P[i].value << endl;
                        }
                        cout << endl;
                        mainMenu();
                        break; //breaking the loop because the process is complete
                    }
                     else if (choice == 3) {
                    ifstream pfile ("player.txt");
                    int n;
                    pfile >> n;
                    for (int j = 0; j < n; j++)
                        pfile >> P[j].Id >> P[j].name >> P[j].att >> P[j].def >> P[j].value;
                    pfile.close();

                    string targetid;
                    cout << "your budget: " << T[i].budget << endl;
                    cout << "enter your target: ";
                    cin >> targetid;

                    int index = findPlayerById(P, n, targetid, 0);

                    if (index == -1) {
                        cout << "user not found" << endl;
                        mainMenu();
                    } else {
                        if (T[i].budget >= P[index].value) {
                            T[i].budget -= P[index].value;

                            ofstream updateT(patht[i]);
                            updateT << T[i].name << endl << T[i].budget << endl;
                            updateT.close();

                            ofstream myTeam(pathbought[i], ios::app);
                            myTeam << P[index].Id << " " << P[index].name << " " << P[index].value << endl;
                            myTeam.close();

                            ofstream rewrite("player.txt");
                            rewrite << n - 1 << endl;
                            for (int m = 0; m < n; m++) {
                                if (m == index) continue;
                                rewrite << P[m].Id << "\t" << P[m].name << "\t"
                                        << P[m].att << "\t" << P[m].def << "\t"
                                        << P[m].value << endl;
                            }
                            rewrite.close();

                            ofstream Pstt(pathtstt[i], ios::app); // saving att def
                            Pstt << P[index].att << endl;
                            Pstt << P[index].def << endl;
                            Pstt.close();

                            cout << "player bought successfully" << endl;
                        } else {
                            cout << "not enough budget" << endl;
                        }
                    }
                    mainMenu();
                    break;
                }
                    else if (choice == 4) {
                    Player myPlayers[50];
                    int myCount = 0;

                    // reading the players
                    ifstream myTeam(pathbought[i]);
                    while (myTeam >> myPlayers[myCount].Id
                                >> myPlayers[myCount].name
                                >> myPlayers[myCount].value) {
                        myCount++;
                    }
                    myTeam.close();

                    if (myCount == 0) {
                        cout << "your team has no players" << endl;
                        mainMenu();
                        break;
                    }

                    string targetId;
                    cout << "enter player id to sell: ";
                    cin >> targetId;

                    int index = findPlayerById(myPlayers, myCount, targetId, 0);

                    if (index == -1) {
                        cout << "player not found in your team" << endl;
                    } else {
                        // increasing the budget
                        T[i].budget += myPlayers[index].value;

                        // Team file update
                        ofstream updateT(patht[i]);
                        updateT << T[i].name << endl;
                        updateT << T[i].budget << endl;
                        updateT.close();

                        // deleting the sold player
                        ofstream rewriteTeam(pathbought[i]);
                        for (int j = 0; j < myCount; j++) {
                            if (j == index) continue;
                            rewriteTeam << myPlayers[j].Id << " "
                                        << myPlayers[j].name << " "
                                        << myPlayers[j].value << endl;
                        }
                        rewriteTeam.close();

                        // adding the sold player back to the list
                        ifstream pfile("player.txt");
                        int n;
                        pfile >> n;
                        for (int j = 0; j < n; j++)
                            pfile >> P[j].Id >> P[j].name >> P[j].att >> P[j].def >> P[j].value;
                        pfile.close();

                        ofstream pwrite("player.txt");
                        pwrite << n + 1 << endl;
                        for (int j = 0; j < n; j++)
                            pwrite << P[j].Id << "\t" << P[j].name << "\t"
                                << P[j].att << "\t" << P[j].def << "\t"
                                << P[j].value << endl;

                        // deleting the sold player stats
                        pwrite << myPlayers[index].Id << "\t"
                            << myPlayers[index].name << "\t0\t0\t"
                            << myPlayers[index].value << endl;
                        pwrite.close();

                        cout << "player sold successfully" << endl;
                    }
                    mainMenu();
                    break;
                    }
                    else if (choice == 5) { // Team management
                        cout << "/n--- My Team Management ---" << endl;
                        cout << "Team: " << T[i].name << " Budget: " << T[i].budget << endl;
                        ifstream myTeam(pathbought[i]);
                        string playerRow;

                        if (T[i].playerCount == 0) {
                            cout << "No players bought yet!" << endl;
                        }
                        else {
                            cout << "Players in your team:" << endl;
                            while (getline(myTeam, playerRow)) {
                                cout << playerRow << endl;
                            }
                        }
                        myTeam.close();
                        mainMenu();
                        break;
                    }

                    else if (choice == 6) {
                        cout << endl;
                        mainMenu();
                        break;
                    }



                }
                else if (i == 3) {
                    cout << "wrong username or password." << endl;
                    mainMenu();
                }
            }

        }
        else {
            cout << "unvalid";
        }
    }

}



