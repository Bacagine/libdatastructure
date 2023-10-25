/**
 * person.c: Implementation fo stack structure in C using void pointer
 * 
 * Developed by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *
 * Date: 2023-05-06
 * Date of last modification: 2023-05-09
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

#define UNUSED(X) (void) X

typedef struct STRCUT_PERSON
{
  int iID;
  char szName[256];
  int iAge;
} STRUCT_PERSON, *PSTRUCT_PERSON;

int iShowStack(PSTRUCT_STACK pstStack)
{
  PSTRUCT_NODE pstCurrentNode = pstStack->pstTop;

  if(bStackIsEmpty(pstStack))
  {
    return -1;
  }

  while(pstCurrentNode != NULL)
  {
    puts("===============================");
    printf("Person ID: %d", (int) ((PSTRUCT_PERSON) (pstCurrentNode->vpData))->iID);
    printf("\nName: %s\n"
           "Age.: %d\n", (char *) ((PSTRUCT_PERSON) (pstCurrentNode->vpData))->szName,
                         (int) ((PSTRUCT_PERSON) (pstCurrentNode->vpData))->iAge
    );
    puts("===============================\n");
    pstCurrentNode = pstCurrentNode->pstNext;
  }

  return 0;
}

int main(int argc, char **argv)
{
  PSTRUCT_STACK pstStack;
  STRUCT_PERSON stPerson[2];
  PSTRUCT_PERSON pstData;
  int ii;

  stPerson[0].iID = 1;
  strcpy(stPerson[0].szName, "Gustavo Bacagine");
  stPerson[0].iAge = 23;
 
  stPerson[1].iID = 2;
  strcpy(stPerson[1].szName, "Jose da Silva");
  stPerson[1].iAge = 26;

  UNUSED(argc);
  UNUSED(argv);

  /****************************************************************************
   *                                                                          *
   *                              STRUCT TEST                                 *
   *                                                                          *
   ****************************************************************************/
  if(bInitStack(&pstStack, iShowStack) == false)
  {
    exit(EXIT_FAILURE);
  }
  
  for(ii = 0; ii < 2; ii++)
  {
    pstData = (PSTRUCT_PERSON) malloc(sizeof(STRUCT_PERSON));
    *pstData = stPerson[ii];

    printf("PUSH %s\n", stPerson[ii].szName);
    vpPushStack(&pstStack, pstData);
  }
  
  puts("\nSHOW STACK:");
  gpfnShowStack(pstStack);

  for(ii = 0; ii < 2; ii++)
  {
    *pstData = *((PSTRUCT_PERSON) vpPopStack(pstStack));
    printf("POP %s\n", pstData->szName);
  }
  free(pstData);
  pstData = NULL;

  vDestroyStack(&pstStack);
  
  return 0;
}

