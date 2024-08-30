#include "matrix_header.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h> 

//Default constructor, sets empty 2x2 matrix
Matrix::Matrix()
{
    //Matrix diminsions set to 2
    m = 2;
    n = 2;
    //Sets each element to 0
    for (int i = 0; i < 4; i++)
    {
        A.push_back(0);
    }
}

//Parameterized constructor. 
//A- values in matrix
//n- columns
Matrix::Matrix(const std::vector<int>& A, unsigned int n)
{
    //Resizes the number of columns on matrix x if n doesnt equal 0
    //and using the modulo operator to see if the remainder of the size divided by n 
    //if equal to 0 meaning the number is an integer.
    if (n != 0 && A.size() % n == 0)
    {
        //reallocates the new diminsions to A and n based on user input
        this->m = A.size() / n;
        this->n = n;
        //puts the users inputs into the matrix
        for (int i = 0; i < A.size(); i++)
        {
            this->A.push_back(A[i]);
        }
    }
    //If the parameters are inconsistent then a 0 by 0 matrix
    else
    {
        this->m = 0;
        this->n = 0;
    }
}

//Second paramaterized constructor
//A- values in matrix
//m- rows
//n- columns
Matrix::Matrix(const vector<int>& A, unsigned int m, unsigned int n)
{
    //Resizes matrix A based on the users input diminsions
    //Check to ensure m * n results in the current size of the matrix
    if (m * n == A.size())
    {
        //reallocates the new diminsions to m and n based on user input
        this->m = m;
        this->n = n;
        //puts content into into matrix
        for (int i = 0; i < A.size(); i++)
        {
            this->A.push_back(A[i]);
        }
    }
    //If the parameters are inconsistent then a 0 by 0 matrix
    else {
        this->m = 0;
        this->n = 0;
    }
}

//Returns value at row and column
//i- row
//j- column
int Matrix::get(unsigned int i, unsigned int j) const
{
    //check to make sure i is in the bounds of the size of the vector
    if (i < m && j < n)
    {
        //returns index of were the element will be
        return A[m * j + i];
    }
    else
    {
        return -2147483648;
    }
}

//Sets value at row and column
//i- row
//j -column
//aij- value
bool Matrix::set(unsigned int i, unsigned int j, int aij)
{
    //Creates an index of were the element will be since this is technically a 1D vector
    int specific_element = m * j + i;

    //check to make sure the index element is in the bounds of the size of the vector
    if (i < m && j < n)
    {
        A[specific_element] = aij;
        return true;
    }
    //If the index is in the bounds of the vector bool true is sent and the element is set
    return false;
}

//returns size of matrix
//dim- dimension wanted
unsigned int Matrix::size(unsigned int dim) const
{
    //if the dim input is 1 the number of rows is returned
    if (dim == 1)
    {
        return m;
    }
    //if the dim input is 2 the number of columns is returned
    if (dim == 2)
    {
        return n;
    }
    //if the diminsion is not valid 0 is returned
    else
    {
        return 0;
    }
}

//Adds two matrix
//rhs- matrix added to A
const Matrix Matrix::add(const Matrix& B) const
{
    //Declaring vector check to be used if the check operate returns a 0 by 0 matrix
    //also used for the sum variable
    vector<int> check;

    // if size of current matrix do not match with that of parameter
    // returns a 0 by 0 matrix
    if (this->A.size() != B.A.size())
    {
        cout << "Error: inconsistent dimensions" << endl;
        Matrix s(check, 0, 0);
        return s;
    }

    //adding matrix values
    for (int i = 0; i < A.size(); i++)
    {
        //sum of two matrix of same index in vector
        int sum = A[i] + B.A[i];
        check.push_back(sum);
    }
    //returns the sum vector
    Matrix s(check, this->m, this->n);
    return s;
}

//Subtracts two matrix
//B- matrix subtracted from A
const Matrix Matrix::sub(const Matrix& B) const
{
    //Declaring vector check to be used if the check operate returns a 0 by 0 matrix
    //also used for the difference variable
    vector<int> check;

    // if size of current matrix do not match with that of parameter
    // returns a 0 by 0 matrix
    if (this->A.size() != B.A.size())
    {
        cout << "Error: inconsistent dimensions" << endl;
        Matrix d(check, 0, 0);
        return d;
    }

    //subtracting matrix values
    for (int i = 0; i < A.size(); i++)
    {
        //difference of two matrix of same index in vector
        int difference = A[i] - B.A[i];
        check.push_back(difference);
    }

    // returning the difference vector
    Matrix d(check, this->m, this->n);
    return d;
}

//Multiplies matrix
//B- matrix multiplied to A
const Matrix Matrix::mult(const Matrix& B) const
{
    //Declaring vector check to be used if the check operate returns a 0 by 0 matrix
    //also used for the sum variable
    vector<int> check;

    // if size of current matrix do not match with that of parameter
    // returns a 0 by 0 matrix
    if (n != B.m)
    {
        cout << "Error: inconsistent dimensions" << endl;
        Matrix d(check, 0, 0);
        return d;
    }

    //Matrix A
    Matrix r(A, m, n);

    for (int i = 0; i < m * B.n; i++)
    {
        check.push_back(0);
    }

    //result is set to size of multiplication
    Matrix Result(check, this->m, B.n);

    for (int i = 0; i < m; i++)
    {
        // iterates through columns of the matrix
        for (int j = 0; j < B.n; j++)
        {
            // iterates through rows of the matrix
            int sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum += r.get(i, k) * B.get(k, j);
            }
            Result.set(i, j, sum);
        }
    }
    return Result;
}

//Matrix multiplied by a constant
//c- multiplied constant
const Matrix Matrix::mult(int c) const
{
    //creates a matrix to be used to store data
    Matrix result(A, m, n);

    //Multiplies the matrix by a the scalar c
    for (int i = 0; i < A.size(); ++i)
    {
        result.A[i] = c * A[i];
    }
    return result;
}

//Matrix raised to a power
//n- power
const Matrix Matrix::power(unsigned int n) const
{
    //creates a vector to be used to store data or return as a 0 by 0 matrix if
    //the matrix cant be raised to a power
    vector<int> check;

    //Matrix A
    Matrix r(A, m, this->n);
    Matrix power(check, m, this->n);

    //Switches the sign of each variable in the duplicate matrix
    if (this->m == this->n)
    {
        //If power is greater than 1
        if (n > 1)
        {
            //sets power to first exponential of Matrix A
            power = r.mult(r);
            n--;

            //Iterates through remaining exponentials of A
            while (n != 1)
            {
                power = power.mult(r);
                n--;
            }

            //returns the matrix raised to a power
            return power;
        }

        //If power is 1
        else if (n == 1)
        {
            //returns original matrix
            return r;
        }

        //If the power is anything lower than 1
        else
        {
            //If the matrix cant be raised then a 0 by 0 matrix is created
            cout << "Error: power must be greater than 0" << endl;
            Matrix s(check, 0, 0);
            return s;
        }
    }
    //If the diminsions are not the same
    else
    {
        //If the matrix cant be raised then a 0 by 0 matrix is created
        cout << "Error: inconsistent dimensions" << endl;
        Matrix s(check, 0, 0);
        return s;
    }
}

//Creates and returns a new Matrix object that is the transpose of this.
void Matrix::trans(const Matrix& B) const
{
    //creates a vector to be used to transpose the matrix
    vector<int> res(A.size(), 0);
    float a[50][50];

    //Sets the submatrix to input Matrix
    for (int i = 0; i < B.size(1); i++)
    {
        for (int j = 0; j < B.size(2); j++)
        {
            int q = B.get(i, j);
            a[i][j] = q;
        }
    }

    //displays tranpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[j][i] << " ";

            if (j == m - 1)
            {
                cout << endl;
            }
        }
    }
    cout << endl;
}

//Recursive function to find determinant of an n by n matrix
int Matrix::determinant(const Matrix& rhs, int n)
{
    if (rhs.size(1) == rhs.size(2))
    {
        int det = 0;
        //Makes an empty vector
        vector<int> check;
        for (int i = 0; i < (n - 1) * (n - 1); i++)
        {
            check.push_back(0);
        }
        //Creates a submatrix that is one column less than the entry
        Matrix submatrix(check, n - 1, n - 1);
        //If the matrix is a 2 by 2 then the matrix can be calculated using a formula
        if (n == 2)
        {
            int v1 = rhs.get(0, 0);
            int v2 = rhs.get(0, 1);
            int v3 = rhs.get(1, 0);
            int v4 = rhs.get(1, 1);
            //formula
            det = (v1 * v4) - (v2 * v3);
        }
        //If the matrix is bigger than a 2 by 2
        else
        {
            //Goes through the intial matrix
            for (int x = 0; x < n; x++)
            {
                int subi = 0;
                for (int i = 1; i < n; i++)
                {
                    int subj = 0;
                    //Puts information into a smaller submatrix
                    for (int j = 0; j < n; j++)
                    {
                        if (j != x)
                        {
                            int q = rhs.get(i, j);
                            submatrix.set(subi, subj, q);
                            subj++;
                        }
                    }
                    subi++;
                }
                //calls the function again with a smaller matrix being the input
                int r = rhs.get(0, x);
                det = det + (pow(-1, x) * r * determinant(submatrix, n - 1));
            }
        }
        //returns the determinate 
        return det;
    }
    //not square matrix
    return -2147483648;
}

//Calculates the inverse
Matrix Matrix::inverse(const Matrix& rhs)
{
    //Checks size of input matrix to make sure its square
    if (rhs.size(1) > 1 && rhs.size(1) == rhs.size(2))
    {
        //Finds the determinent of the matrix using the recurrsive function
        float determ = determinant(rhs, rhs.size(1));
        //If the determinate isnt 0 then the function is invertable
        if (determ != 0)
        {
            //Creates a submatrix with the size of input
            int size = rhs.size(1);
            float a[50][50];

            //Sets the submatrix to input Matrix
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    int q = rhs.get(i, j);
                    a[i][j] = q;
                }
            }

            //Creates identity matrix on the side of the original matrix.
            for (int i = 0; i < size; i++)
            {
                for (int j = size; j < 2 * size; j++)
                {
                    // Add 1 at the diagonal places of
                    // the matrix to create a identity matrix
                    if (i == (j - size))
                    {
                        a[i][j] = 1;
                    }
                    else
                    {
                        a[i][j] = 0;
                    }
                }
            }
            //Applying Gauss Jordan Elimination
            for (int i = 0; i < size; i++)
            {
                //If the first input is 0 then the matrix isnt invertable
                if (a[i][i] == 0.0)
                {
                    cout << "Error: matrix isn't invertable" << endl;
                    cout << endl;
                    vector<int> zero = { 0 };
                    Matrix B(zero, 0, 0);
                    return B;
                }
                //Solves rows
                for (int j = 0; j < size; j++)
                {
                    //1 means the row is already in the simplest form
                    if (i != j)
                    {
                        float d = a[j][i] / a[i][i];

                        //puts division into submatrix on the right side
                        for (int k = 0; k < 2 * size; k++)
                        {
                            a[j][k] -= d * a[i][k];
                        }
                    }
                }
            }
            //Solves diagnols and puts the answers in mod 29 using mod division
            for (int i = 0; i < size; i++)
            {
                float q = a[i][i];
                for (int j = 0; j < 2 * size; j++)
                {
                    a[i][j] = a[i][j] / q;
                }
            }

            //outputs inverse
            for (int i = 0; i < size; i++)
            {
                for (int j = size; j < 2 * size; j++)
                {
                    cout << a[i][j] << "\t";
                }
                cout << endl;
            }
            return rhs;
        }
        //If the determinate is zero the inverse cant be done
        if (determ == 0)
        {
            cout << "Error: matrix isn't invertable" << endl;
            cout << endl;
            vector<int> zero = { 0 };
            Matrix B(zero, 0, 0);
            return B;
        }
    }
    //If the size isnt equal, the inverse cant be done
    else
    {
        cout << "Error: inconsistent dimensions" << endl;
        cout << endl;
        vector<int> zero = { 0 };
        Matrix B(zero, 0, 0);
        return B;
    }
}

//Outputs matrix content
void Matrix::output() const
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[m * j + i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
