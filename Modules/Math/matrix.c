#ifndef BCI_MATRIX_C_INCLUDED
#define BCI_MATRIX_C_INCLUDED

#include "matrix.h"

/**
 * Initializes a matrix
 * @param  mat          matrix to initialze
 * @param  columns      Columns
 * @param  rows         Rows
 * @param  defaultValue Value to initialze the elements to
 * @return              Whether the matrix was initialized successfully
 */
bool matrix_Initialize(matrix *mat, const unsigned int columns, const unsigned int rows, float defaultValue)
{
  mat->columns = columns;
  mat->rows = rows;
  bool result = block_Initialize(&(mat->data), columns * rows, defaultValue);
  if (!result)
  {
    writeDebugStreamLine("init failed");
  }
  return result;
}

void matrix_Set(matrix *mat, const float *data)
{
  for (int i = 0; i < mat->columns * mat->rows; i++)
  {
    block_Set(&(mat->data), i, *(data + i));
  }
}

//--------------------------------------------------------------
//These functions save the result to a separate matrix passed in
//Consequently, they use space O(1)
//--------------------------------------------------------------

/**
* Adds a scalar to every element of this matrix
* @param mat    matrix to read from
* @param scalar Scalar
* @param result matrix to write result to
*/
void matrix_AddScalar(const matrix *mat, const float scalar, matrix *result)
{
  for (int i = 0; i < mat->columns * mat->rows; i++)
  {
    block_Set(&(result->data), i, block_Get(&(mat->data), i) + scalar);
  }
}

/**
* Subtracts a scalar to every element of this matrix
* @param mat    matrix to read from
* @param scalar Scalar
* @param result matrix to write result to
*/
void matrix_SubtractScalar(const matrix *mat, const float scalar, matrix *result)
{
  for (int i = 0; i < mat->columns * mat->rows; i++)
  {
    block_Set(&(result->data), i, block_Get(&(mat->data), i) - scalar);
  }
}

/**
* Multiplies a matrix by a scalar
* @param mat    matrix to read from
* @param scalar Scalar
* @param result matrix to write result to
*/
void matrix_MultiplyByScalar(const matrix *mat, const float scalar, matrix *result)
{
  for (int i = 0; i < mat->columns * mat->rows; i++)
  {
    block_Set(&(result->data), i, block_Get(&(mat->data), i) * scalar);
  }
}

/**
* Divides a matrix by a scalar
* @param mat    matrix to read from
* @param scalar Scalar
* @param result matrix to write result to
*/
void matrix_DivideByScalar(const matrix *mat, const float scalar, matrix *result)
{
  for (int i = 0; i < mat->columns * mat->rows; i++)
  {
    block_Set(&(result->data), i, block_Get(&(mat->data), i) / scalar);
  }
}

/**
* Raises a matrix to a power
* @param mat    matrix to read from
* @param scalar Scalar
* @param result matrix to write result to
*/
void matrix_RaiseToScalar(const matrix *mat, const float scalar, matrix *result)
{
  for (int i = 0; i < mat->columns * mat->rows; i++)
  {
    block_Set(&(result->data), i, pow(block_Get(&(mat->data), i), scalar));
  }
}

/**
* Adds two matricies together
* @param mat1   First matrix
* @param mat2   Second matrix
* @param result matrix to write result to
*/
void matrix_AddMatrix(const matrix *mat1, const matrix *mat2, matrix *result)
{
  for (int i = 0; i < mat1->columns * mat1->rows; i++)
  {
    block_Set(&(result->data), i, block_Get(&(mat1->data), i) + block_Get(&(mat2->data), i));
  }
}

/**
* Subtracts two matricies from each other
* @param mat1   First matrix
* @param mat2   Second matrix
* @param result matrix to write result to
*/
void matrix_SubtractMatrix(const matrix *mat1, const matrix *mat2, matrix *result)
{
  for (int i = 0; i < mat1->columns * mat1->rows; i++)
  {
    block_Set(&(result->data), i, block_Get(&(mat1->data), i) - block_Get(&(mat2->data), i));
  }
}

/**
* Multiplies two matricies together
* @param mat1   First matrix
* @param mat2   Second matrix
* @param result matrix to write result to
*/
void matrix_MultiplyByMatrix(const matrix *mat1, const matrix *mat2, matrix *result)
{
  for (int i = 0; i < mat1->rows; i++)
  {
    for (int j = 0; j < mat2->columns; j++)
    {
      block_Set(&(result->data), j + (result->columns * i), 0);
      for (int k = 0; k < mat1->columns; k++)
      {
        block_Set(&(result->data), j + (result->columns * i), block_Get(&(result->data), j + (result->columns * i)) + block_Get(&(mat1->data), k + (mat1->columns * i)) * block_Get(&(mat2->data), j + (mat2->columns * k)));
      }
    }
  }
}

/**
* Inverts a matrix
* @param mat    matrix to read from
* @param result matrix to write to
*/
void matrix_Invert(const matrix *mat, matrix *result)
{
}

/**
* Transposes a matrix
* @param mat    matrix to read from
* @param result matrix to write to
*/
void matrix_Transpose(const matrix *mat, matrix *result)
{
}

//------------------------------------------------------------
//These functions save the result to the same matrix passed in
//Consequently, they use space O(n)
//------------------------------------------------------------

/**
* Adds a scalar to every element of this matrix
* @param mat    matrix for read/write
* @param scalar Scalar
*/
void matrix_AddScalar(matrix *mat, const float scalar)
{
}

/**
* Subtracts a scalar to every element of this matrix
* @param mat    matrix for read/write
* @param scalar Scalar
*/
void matrix_SubtractScalar(matrix *mat, const float scalar)
{
}

/**
* Multiplies a matrix by a scalar
* @param mat    matrix for read/write
* @param scalar Scalar
*/
void matrix_MultiplyByScalar(matrix *mat, const float scalar)
{
}

/**
* Divides a matrix by a scalar
* @param mat    matrix for read/write
* @param scalar Scalar
*/
void matrix_DivideByScalar(matrix *mat, const float scalar)
{
}

/**
* Raises a matrix to a power
* @param mat    matrix for read/write
* @param scalar Scalar
*/
void matrix_RaiseToScalar(matrix *mat, const float scalar)
{
}

/**
* Adds two matricies together
* @param mat1   First matrix
* @param mat2   Second matrix
*/
void matrix_AddMatrix(matrix *mat1, const matrix *mat2)
{
}

/**
* Subtracts two matricies from each other
* @param mat1   First matrix
* @param mat2   Second matrix
*/
void matrix_SubtractMatrix(matrix *mat1, const matrix *mat2)
{
}

/**
* Multiplies two matricies together
* @param mat1   First matrix
* @param mat2   Second matrix
*/
void matrix_MultiplyByMatrix(matrix *mat1, const matrix *mat2)
{
}

/**
* Inverts a matrix
* @param mat    matrix for read/write
*/
void matrix_Invert(matrix *mat)
{
}

/**
* Transposes a matrix
* @param mat    matrix for read/write
*/
void matrix_Transpose(matrix *mat)
{
}

//-----------------------------------------------------------

/**
* Returns the trace of a square matrix
* @param  mat Square matrix to read from
* @return     The trace of the matrix
*/
float matrix_Trace(const matrix *mat)
{
}

/**
* Returns the determinant of a square matrix
* @param  mat Square matrix to read from
* @return     The determinant of that matrix
*/
float matrix_Determinant(const matrix *mat)
{
}

/**
* Clears a matrix
* @param mat      matrix to clear
* @param clearVal Value to clear the elements to
*/
void matrix_Clear(matrix *mat, float clearVal)
{
}

#endif //BCI_MATRIX_C_INCLUDED