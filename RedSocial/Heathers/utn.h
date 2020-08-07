#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#endif // UTN_H_INCLUDED

/** \brief Takes the memory allocation of a int value and asigns it with a value entered by user.
 *
 * \param intNum Memory alocation where the new value will be stored.
 * \param mesage Explains the user the tipe of data that the computer is expecting.
 *
 */

void getInt(int* intNum,char mensage[]);



/** \brief Takes the memory allocation of a float value and asigns it with a value entered by user.
 *
 * If user enters the wrong kind of data, shall be required again after a predetermined error mesage shows.
 *
 * \param floatNum Memory alocation where the new value will be stored.
 * \param mesage Explains the user the tipe of data that the computer is expecting.
 *
 */

void getFloat(float* floatNum,char mensage[]);



/** \brief Takes the memory allocation of a char value and asigns it with a value entered by user.
 *
 * \param character Memory alocation where the new value will be stored.
 * \param mesage Explains the user the tipe of data that the computer is expecting.
 * \param error If user enters the wrong kind of data, shall be required again after a this error mesage shows.
 * \param options char entered by user will be accepted if is within the options in this field
 *
 */

void getChar(char* character,char mensage[],char error[],char options[]);



/**\brief Takes the memory allocation of a char array and asigns it with a value entered by user.
 *
 * \param to Memory alocation where the string will be stored.
 * \param len Expected len of the string entered by user. If overiden the extra data will be ignored
 *
 */

void myFgets(char* to, int len);

void getName(char* to, char* sorter, int len);
