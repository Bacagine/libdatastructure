/**
 * stack.c
 * 
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *
 * Description: Implementation of stack structure in C using void pointer
 *
 * Date: 2023-05-06
 * Date of last modification: 2023-10-19
 */

#include <stdio.h>
#include "stack.h"

PFNSHOW_STACK gpfnShowStack = NULL;

bool bInitStack(PSTRUCT_STACK *ppstStack,
                PFNSHOW_STACK pfnShowStack)
{
  if((*ppstStack = (PSTRUCT_STACK) malloc(sizeof(STRUCT_STACK))) == NULL)
  {
    return false;
  }

  (*ppstStack)->pstTop = NULL;
  (*ppstStack)->iSize = 0;

  gpfnShowStack = pfnShowStack;

  return true;
}

bool bStackIsEmpty(PSTRUCT_STACK pstStack)
{
  return pstStack->pstTop == NULL;
}

void *vpPushStack(PSTRUCT_STACK *ppstStack, void *vpData)
{
  PSTRUCT_STACK pstStack = *ppstStack;
  PSTRUCT_NODE pstNewNode = (PSTRUCT_NODE) malloc(sizeof(STRUCT_NODE));

  if(pstNewNode == NULL)
  {
    return NULL;
  }
      
  pstNewNode->vpData = vpData;
  pstNewNode->pstNext = pstStack->pstTop;
  pstStack->pstTop = pstNewNode;
  pstStack->iSize++;

  return pstStack->pstTop->vpData;
}

void *vpPopStack(PSTRUCT_STACK pstStack)
{
  PSTRUCT_NODE pstPoppedNode = pstStack->pstTop;
  void *vpPoppedData = pstPoppedNode->vpData;

  if(bStackIsEmpty(pstStack))
  {
    return NULL;
  }

  pstStack->pstTop = pstPoppedNode->pstNext;
  pstStack->iSize--;

  free(pstPoppedNode);

  return vpPoppedData;
}

void *vpGetStackTop(PSTRUCT_STACK pstStack)
{
  if(bStackIsEmpty(pstStack))
  {
    return NULL;
  }

  return pstStack->pstTop->vpData;
}

int iGetStackSize(PSTRUCT_STACK pstStack)
{
  return pstStack->iSize;
}

void vDestroyStack(PSTRUCT_STACK *ppstStack)
{
  PSTRUCT_NODE pstCurrentNode = (*ppstStack)->pstTop;
  PSTRUCT_NODE pstTempNode;
  
  while(pstCurrentNode != NULL)
  {
    pstTempNode = pstCurrentNode;
    pstCurrentNode = pstCurrentNode->pstNext;

    free(pstTempNode->vpData);
    free(pstTempNode);
  }

  free(*ppstStack);
  *ppstStack = NULL;
}

