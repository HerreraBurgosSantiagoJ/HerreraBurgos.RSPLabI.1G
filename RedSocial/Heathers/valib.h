#ifndef VALIB_H_INCLUDED
#define VALIB_H_INCLUDED

#endif // VALIB_H_INCLUDED

//Can not be fully translated due to short time at hand

/** \brief Finds out if a given char value is among the aceptable values
 *
 * \param inPut char to be analized
 * \param options char array of aceptable values
 * \return return (1) if acceptable value (0) if not
 *
 */

int validarChar(char ingreso,char opciones[]);



/** \brief Finds out if a given int value is among the aceptable values
 *
 * \param inPut int to be analized
 * \param options int array of aceptable values
 * \return return (1) if acceptable value (0) if not
 *
 */

int validarInt(int ingreso, int opciones[], int len);
