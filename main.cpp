#include<regex>
#include <iostream>
#include<cstdlib>

using namespace std;


//<< "Click on the play button with a small bug on it on the left and go to the bottom of the screen. click on terminal and answer the question";



void genRandom(int pickNums[], int pickCount)
{
    for(int i = 0; i < pickCount; i++)
    {
        pickNums[i] = rand()%80 + 1;
        for(int j = 0; j < i; j++)
        {
            if(pickNums[j] == pickNums[i])
            {
                i--;
                break;
            }
        }
    }
}

void printPicks(int pickNums[], int pickCount)
{
    cout << endl << "your picks" << endl;
    cout << pickNums[0];
    for(int i=1; i < pickCount; i++)
    {
        cout << ", " <<  pickNums[i];
    }
    cout << endl;
}

int manyNum()
{
    string num;
    int n;
    do
    {
        cout << " enter number of picks:" << endl;
        getline(cin, num);
        try
        {
            n = stoi(num);
        }
        catch(const std::out_of_range & e)
        {
            cout << "Sorry pick another number from 1- 10" << endl;
            continue;
        }
        catch (const std::invalid_argument & e)
        {
            cout << "Sorry pick another number from 1- 10" << endl;
            continue;
        }
        if (n < 1 || n > 10)

        {
            cout << "Sorry pick another number from 1 -10." << endl;
        }
    }
    while (n < 1 || n > 10);
    return n;
}

int numSelect(int pickNums[], int picks)
{
    string num;
    int n;
    for(int i = 0; i< picks; i++)
    {
        do
        {
            cout << " enter a pick:" << endl;
            getline(cin, num);
            try
            {
                n = stoi(num);
            }
            catch(const std::out_of_range & e)
            {
                cout << "Sorry pick another number from 1- 80" << endl;
                continue;
            }
            catch (const std::invalid_argument & e)
            {
                cout << "Sorry pick another number from 1- 80" << endl;
                continue;
            }
            if (n < 1 || n > 80)

            {
                cout << "Sorry pick another number from 1 -80." << endl;
            }
            bool dup = false;
            for(int j = 0; j < i; j++)
            {
                if(pickNums[j] == n)
                {

                    dup = true;
                    break;
                }
            }
            if(dup)
            {
                cout << "dup pick" << endl;
                continue;
            }
        }
        while (n < 1 || n > 80);
        pickNums[i] = n;
    }

    return picks;

}

int main()
{
    int pickNum[10];
    int pickCount;
    string num;

    srand(time(0));

    cout << "KENO!" << endl;


    cout << "1. Pick your own numbers" << endl;
    cout << "2. Quik Pik" << endl;
    cout << " enter a option number: " << endl;
    while(true)
    {
        getline(cin, num);
        if(num == "1")
        {
            pickCount = manyNum();
            numSelect(pickNum, pickCount);
        }
        else if(num == "2")
        {
            pickCount = manyNum();
            genRandom(pickNum, pickCount);
        }
        else
        {
            cout << "invalid option enter 1 or  2" << endl;
            continue;
        }
        printPicks(pickNum, pickCount);
        break;
    }
    return 0;
}
