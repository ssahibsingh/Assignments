#include <iostream>
using namespace std;

main()
{
    int count = 0;
    int value;
    int sparsematrix[5][6] =
        {

            {0, 0, 0, 3, 4, 0},
            {0, 7, 0, 1, 4, 1},
            {2, 0, 9, 0, 4, 0},
            {0, 3, 0, 0, 3, 0},
            {0, 1, 0, 9, 0, 0}

        };

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 6; j++)
            if (sparsematrix[i][j] != 0)
                count++;

    int Sparse_representation[3][count];
    int column_position = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 6; j++)
            if (sparsematrix[i][j] != 0)
            {
                Sparse_representation[0][column_position] = i;
                Sparse_representation[1][column_position] = j;
                Sparse_representation[2][column_position] = sparsematrix[i][j];
                column_position++;
            }

    int val;
    for (int i = 0; i < 3; i++)
    {
        val = 0;
        for (int j = 0; j < count; j++)
        {
            if (val == 0 && i == 0)
            {
                cout << "Row:    ";
                val = 1;
            }
            if (val == 0 && i == 1)
            {
                cout << "Column: ";
                val = 1;
            }
            if (val == 0 && i == 2)
            {
                cout << "Value:  ";
                val = 1;
            }

            cout << "  " << Sparse_representation[i][j];
        }
        cout << endl;
    }

    cout << endl;

    cout << "Enter the value to be searched: ";
    cin >> value;

    cout << endl;
    int flag = 0;
    for (int j = 0; j < count; j++)
    {
        if (Sparse_representation[2][j] == value)
        {
            cout << "Element " << value << " found at: " << endl;
            cout << "Row index: " << Sparse_representation[0][j] << endl
                 << "Column index: " << Sparse_representation[1][j] << endl;
            flag = 1;
            cout << endl;
        }
        
    }

    if (flag == 0)
        cout << "Element not Found" << endl;
}