/**
 * stack.h
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: Generic stack using void pointer
 *
 * Date: 2023-05-06
 * Date of last modification: 2023-10-19
 */

#ifndef _STACK_H_
#define _STACK_H_

/******************************************************************************
 *                                                                            *
 *                                 Includes                                   *
 *                                                                            *
 ******************************************************************************/
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "node.h"

/******************************************************************************
 *                                                                            *
 *                             Defines and macros                             *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
 *                                                                            *
 *                  Typedefs, structures, unions and enums                    *
 *                                                                            *
 ******************************************************************************/

/**
 * Structure that represents a
 * generic stack data structure.
 */
typedef struct STRUCT_STACK
{
  PSTRUCT_NODE pstTop;
  int iSize;
} STRUCT_STACK, *PSTRUCT_STACK;

/**
 * Pointer to print stack funciton
 */
typedef int (*PFNSHOW_STACK)(PSTRUCT_STACK);

extern PFNSHOW_STACK gpfnShowStack;

/******************************************************************************
 *                                                                            *
 *                            Prototype functions                             *
 *                                                                            *
 ******************************************************************************/

/**
 * Initialize stack structure
 *
 * Set the initial size and the function used
 * to print the stack elements.
 *
 * Retunr:
 *  true: OK
 *  false: Out memory
 */
bool bInitStack(PSTRUCT_STACK *ppstStack,
                PFNSHOW_STACK pfnShowStack);

/**
 * Verify if the stack is empty
 */
bool bStackIsEmpty(PSTRUCT_STACK pstStack);

/**
 * Insert a element in the top of stack
 *
 * Return
 *  Data: OK
 *  NULL: Memory out
 */
void *vpPushStack(PSTRUCT_STACK *ppstStack, void *vpData);

/**
 * Remove a element of the top of stack
 *
 * Return the popped value or NULL if stack
 * is empty.
 */
void *vpPopStack(PSTRUCT_STACK pstStack);

/**
 * Return the top of stack
 * NULL if stack is empty
 */
void *vpGetStackTop(PSTRUCT_STACK pstStack);

/**
 * Return the size of stack
 */
int iGetStackSize(PSTRUCT_STACK pstStack);

/**
 * Free stack
 */
void vDestroyStack(PSTRUCT_STACK *ppstStack);

#endif /* _STACK_H_ */

