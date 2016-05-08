#include <iostream>
#include <sstream>
#include <iomanip>
#include <locale>

using namespace std;
const int INVALID = -1;
void printSquare(int &order, int **p)
{
    int row, col;
    stringstream swidth;
    swidth << order*order; //setw() will be the # of digits that order*order is. For ex: if order*order is 25 then # of digits is 2
    string slength = swidth.str();
    for(row = 0; row < order; row++)
    {
        for(col = 0; col < order; col++)
        {
            cout<<setfill(' ')<<setw(slength.size());
            cout<<p[row][col]<<"  ";
        }
        cout<<endl;
    }
}

void squareAlgorithm(int order)
{
    int row = 0;
    int col = 0;
    int **matrix = new int*[order];

    for(int i = 0; i < order; i++)
    {
        matrix[i] = new int[order]; //allocate new memory
    }

    //fill matrix with INVALID values
    for(row = 0; row < order; row++)
    {
        for(col = 0; col < order; col++)
        {
            matrix[row][col] = INVALID;
        }
    }

    row = 0;
    col = order/2;
    int k = 1;

    for(int a = 0; a < order*order; a++)
    {
        matrix[row][col] = k++;
        row-=1;
        col+=1;

        //the checks for certain exceptions:
        if(row<0)
        {
            if(col<order)
            {

                row = order-1;
            }
            else
            {
                row+=2;
                col-=1;
            }
        }
        else
        {
            if(col>order-1)
            {
                col = 0;
            }
        }

        if(matrix[row][col]!= INVALID)
        {
            row+=2;
            col-=1;
        }
    }

    printSquare(order, matrix);
    for(int i = 0; i < order; i++)
    {
        delete[] matrix[i]; //return memory
    }
    delete[] matrix;
}

int main()
{
    //limit to order of squares is computer memory
    string str_order;
    locale loc;
    cout<<"Odd-Order Magic Square Generator\n------------------\n"<<endl;
    while(1)
    {
        cout<<"Enter the order of the square (must be odd number), or enter any letter to quit"<<endl;
        cin >> str_order;
        if(isdigit(str_order[0],loc))
        {
            int order;
            stringstream(str_order)>>order;
            if(order%2==0)
            {
                cout<<"Please enter an odd number\n"<<endl;
                continue;
            }
            cout<<endl;
            squareAlgorithm(order);
            cout<<endl;
        }
        else
        {
            break;
        }

    }
    return 0;
}
