#include <iostream>
#include <string>

/*
SOAL :
Untuk kasus Champions League pada materi,
modifikasilah sedemikian hingga tiap edge juga memiliki informasi mengenai selisih gol
(selisih gol positif apabila tim menang, kemudian selisih gol negatif apabila tim kalah)
dalam match tersebut. Kemudian tampilkan total perolehan poin dan juga
total selisih gol dari tiap-tiap tim. Tim mendapatkan 3 poin apabila menang, 1 apabila seri,
dan 0 apabila kalah. Kerjakan menggunakan struktur data Graph!
Untuk implementasi bebas, tetapi disarankan menggunakan adjacency matrix.


*/

using namespace std;

enum club_name
{
    REAL_MADRID,
    CHELSEA,
    AC_MILAN,
    VALENCIA,
    TOTAL_CLUB
};

enum match_result
{
    LOSE = 0,
    DRAW,
    NO_MATCH,
    WIN
};

int main()
{

    match_result match[TOTAL_CLUB][TOTAL_CLUB];

    int match_goal[TOTAL_CLUB][TOTAL_CLUB];
    int GF[TOTAL_CLUB][TOTAL_CLUB] = {0};  // Goals scored atau goal yg dicetak
    int GA[TOTAL_CLUB][TOTAL_CLUB] = {0};  // Goals against atau goals yg kebobolan
    int team_points[TOTAL_CLUB] = {0};     // Total point tiap tim
    int goal_difference[TOTAL_CLUB] = {0}; // Selisih antara GA dan GF
    int goals_scored[TOTAL_CLUB] = {0};    // Total goals yg dicetak
    int goals_conceded[TOTAL_CLUB] = {0};  // Total goals yang kebobolan

    // adjacency matrix
    match[REAL_MADRID][VALENCIA] = WIN;  //[0][3] = win;
    match[VALENCIA][REAL_MADRID] = LOSE; //[3][0] = lose;
    // goal dari match
    GF[REAL_MADRID][VALENCIA] = 1;
    GF[VALENCIA][REAL_MADRID] = 0;
    GA[REAL_MADRID][VALENCIA] = 0;
    GA[VALENCIA][REAL_MADRID] = -1;

    // adjacency matrix
    match[REAL_MADRID][AC_MILAN] = WIN;  //[0][2] = win;
    match[AC_MILAN][REAL_MADRID] = LOSE; //[2][0] = lose;
    // goal dari match
    GF[REAL_MADRID][AC_MILAN] = 4;
    GF[AC_MILAN][REAL_MADRID] = 2;
    GA[REAL_MADRID][AC_MILAN] = -2;
    GA[AC_MILAN][REAL_MADRID] = -4;

    // adjacency matrix
    match[REAL_MADRID][CHELSEA] = DRAW; //[0][1] = draw;
    match[CHELSEA][REAL_MADRID] = DRAW; //[1][0] = draw;
    // goal dari match
    GF[REAL_MADRID][CHELSEA] = 1;
    GF[CHELSEA][REAL_MADRID] = 1;
    GA[REAL_MADRID][CHELSEA] = -1;
    GA[CHELSEA][REAL_MADRID] = -1;

    // adjacency matrix
    match[VALENCIA][AC_MILAN] = LOSE; //[3][2] = lose;
    match[AC_MILAN][VALENCIA] = WIN;  //[2][3] = win;
    // goal dari match
    GF[VALENCIA][AC_MILAN] = 1;
    GF[AC_MILAN][VALENCIA] = 3;
    GA[VALENCIA][AC_MILAN] = -3;
    GA[AC_MILAN][VALENCIA] = -1;

    // adjacency matrix
    match[VALENCIA][CHELSEA] = WIN;  //[3][1] = win;
    match[CHELSEA][VALENCIA] = LOSE; //[1][3] - lose;
    // goal dari match
    GF[VALENCIA][CHELSEA] = 2;
    GF[CHELSEA][VALENCIA] = 1;
    GA[VALENCIA][CHELSEA] = -1;
    GA[CHELSEA][VALENCIA] = -2;

    // adjacency matrix
    match[AC_MILAN][CHELSEA] = LOSE; //[2][1] = lose;
    match[CHELSEA][AC_MILAN] = WIN;  //[1][2] = win;
    // goal dari match
    GF[AC_MILAN][CHELSEA] = 4;
    GF[CHELSEA][AC_MILAN] = 5;
    GA[AC_MILAN][CHELSEA] = -5;
    GA[CHELSEA][AC_MILAN] = -4;

    int opponents = 0;
    while (opponents < TOTAL_CLUB)
    {
        if (opponents != REAL_MADRID)
        {
            team_points[REAL_MADRID] += match[REAL_MADRID][opponents];
            goals_scored[REAL_MADRID] += GF[REAL_MADRID][opponents];
            goals_conceded[REAL_MADRID] += GA[REAL_MADRID][opponents];
            match_goal[REAL_MADRID][opponents] = GF[REAL_MADRID][opponents] + GA[REAL_MADRID][opponents];
            goal_difference[REAL_MADRID] += match_goal[REAL_MADRID][opponents];
        }
        if (opponents != CHELSEA)
        {
            team_points[CHELSEA] += match[CHELSEA][opponents];
            goals_scored[CHELSEA] += GF[CHELSEA][opponents];
            goals_conceded[CHELSEA] += GA[CHELSEA][opponents];
            match_goal[CHELSEA][opponents] = GF[CHELSEA][opponents] + GA[CHELSEA][opponents];
            goal_difference[CHELSEA] += match_goal[CHELSEA][opponents];
        }
        if (opponents != AC_MILAN)
        {
            team_points[AC_MILAN] += match[AC_MILAN][opponents];
            goals_scored[AC_MILAN] += GF[AC_MILAN][opponents];
            goals_conceded[AC_MILAN] += GA[AC_MILAN][opponents];
            match_goal[AC_MILAN][opponents] = GF[AC_MILAN][opponents] + GA[AC_MILAN][opponents];
            goal_difference[AC_MILAN] += match_goal[AC_MILAN][opponents];
        }
        if (opponents != VALENCIA)
        {
            team_points[VALENCIA] += match[VALENCIA][opponents];
            goals_scored[VALENCIA] += GF[VALENCIA][opponents];
            goals_conceded[VALENCIA] += GA[VALENCIA][opponents];
            match_goal[VALENCIA][opponents] = GF[VALENCIA][opponents] + GA[VALENCIA][opponents];
            goal_difference[VALENCIA] += match_goal[VALENCIA][opponents];
        }

        opponents++;
    }

    cout << "===========================================================" << endl;
    cout << "=                                                         =" << endl;
    cout << "=              UEFA CHAMPION LEAGUE STANDINGS             =" << endl;
    cout << "=                           GROUP A                       =" << endl;
    cout << "=                                                         =" << endl;
    cout << "===========================================================";
    cout << "\n\nClub Name\tGoals Scored\tGoals Conceded\t  Goals Difference\tTotal Points" << endl;

    for (int i = 0; i < TOTAL_CLUB; i++)
    {
        if (i == REAL_MADRID)
        {
            cout << "REAL MADRID\t\t" << goals_scored[REAL_MADRID] << "\t\t" << goals_conceded[REAL_MADRID] << "\t\t" << goal_difference[REAL_MADRID] << "\t\t\t" << team_points[REAL_MADRID] << endl;
        }

        else if (i == CHELSEA)
        {
            cout << "CHELSEA\t\t\t" << goals_scored[CHELSEA] << "\t\t" << goals_conceded[CHELSEA] << "\t\t" << goal_difference[CHELSEA] << "\t\t\t" << team_points[CHELSEA] << endl;
        }

        else if (i == AC_MILAN)
        {
            cout << "AC MILAN\t\t" << goals_scored[AC_MILAN] << "\t\t" << goals_conceded[AC_MILAN] << "\t\t" << goal_difference[AC_MILAN] << "\t\t\t" << team_points[AC_MILAN] << endl;
        }

        else if (i == VALENCIA)
        {
            cout << "VALENCIA\t\t" << goals_scored[VALENCIA] << "\t\t" << goals_conceded[VALENCIA] << "\t\t" << goal_difference[VALENCIA] << "\t\t\t" << team_points[VALENCIA] << endl;
        }
    }

    cout << "\n\n\n";

    return 0;
}