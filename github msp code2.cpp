#include <iostream>
using namespace std;

//get 3 tests, get the maxScore and the minScore,
//calculate the averageAll using tests, and the averageBest
//using tests and scores.

void calcAverageAll(int test1, int test2, int test3);
void calcAverageBest(int test1, int test2, int test3, int maxscore, int minScore);

int main()
{
    int test1, test2, test3;
    int maxScore, minScore;


    cout << "Enter test score 1: " << " " << endl;
    cin >> test1;
    cout << "Enter test score 2: " << " " << endl;
    cin >> test2;
    cout << "Enter test score 3: " << " " << endl;
    cin >> test3;

    maxScore = max(test1, max(test2, test3));
    minScore = min(test1, min(test2, test3));

    calcAverageAll(test1, test2, test3);
    calcAverageBest(test1, test2, test3, maxScore, minScore);

    return 0;
}

void calcAverageAll(int test1, int test2, int test3)
{
    int averageAll = (test1 + test2 + test3) / 3;
    cout << "The average of all three tests: " << averageAll << endl;
}
void calcAverageBest(int test1, int test2, int test3, int maxScore, int minScore)
{
    int sumBest = test1 + test2 + test3 - maxScore - minScore;
    int averageBest = sumBest / 1;
    cout << "The average best of the two scores: " << averageBest << endl;
}

