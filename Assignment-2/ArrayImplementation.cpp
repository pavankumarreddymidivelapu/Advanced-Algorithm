//ArrayImplementation.cpp
#include <iostream> //for input and output operations
#include <vector>   //for creating dynamic arrays to store data
using namespace std; //std is a standard C++ library which is allows you to use objects and functions from std library

int main() 
{
    int Row, Column; //initializing the Row and Column as interger
    cout << "Enter the number of rows in the matrix: ";  //Display the number of row matrix
    cin >> Row;      //user input for the Row
    cout << "Enter the number of columns in the matrix: ";  //Display the number of column matrix
    cin >> Column;   //user input for the column

    vector<vector<int> > sparseMatrix(Row, vector<int>(Column, 0)); //The matix initially is Zeros,2D vector 'sparseMatrix' is created with dimensions taken from the user input

    cout << "Enter the elements of the sparse matrix row by row:" << endl;  //Display the elements of the sparse matrix row by row.

    //Nested loop is used to store the values in the sparseMatrix
    for (int i = 0; i < Row; i++) 
     {   
        for (int j = 0; j < Column; j++) 
        {
            cin >> sparseMatrix[i][j]; //user input for the sparseMatrix
        }
    }

    // Finding the non-zero values in sparseMatrix
    int size = 0;
    for (int row = 0; row < Row; row++) 
    {
        for (int column = 0; column < Column; column++) 
        {
            if (sparseMatrix[row][column] != 0) 
            {
                size++;
            }
        }
    }

    // Defining resultMatrix to store the data 
    vector<vector<int> > resultMatrix(3, vector<int>(size, 0)); 

    // To generate the row,column and value is stored in the resultMatrix
    int k = 0;
    for (int row = 0; row < Row; row++) 
    {
        for (int column = 0; column < Column; column++) 
        {
            if (sparseMatrix[row][column] != 0) 
            {
                resultMatrix[0][k] = row;
                resultMatrix[1][k] = column;
                resultMatrix[2][k] = sparseMatrix[row][column];
                k++;
            }
        }
    }

    // To display resultMatrix
    cout << "sparse matrix Representation:" << endl; //Displaying the 'sparse matrix Representation' 
    cout << "row:   "; //Display row result
    for (int i = 0; i < size; i++) 
    {
        cout << " " << resultMatrix[0][i];
    }
    cout << endl;

    cout << "column:"; //Display column result
    for (int i = 0; i < size; i++) 
    {
        cout << " " << resultMatrix[1][i];
    }
    cout << endl;

    cout << "Value: "; //Display Value result
    for (int i = 0; i < size; i++) 
    {
        cout << " " << resultMatrix[2][i];
    }
    cout << endl;
    return 0;
}
