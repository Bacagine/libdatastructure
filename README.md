# Data Structure

This repository contains my personal Data Structure Library for my C/C++ projects

To better understand my codes, read the README.md at [this link](https://github.com/Bacagine/Bacagine)

OBS: This library is still under development, for now it only has the implementation of a generic stack data structure

# How to use?

## Build and Install
```
# ./mkinstall
```

## Examples of usage

### Stack examples

#### stack_primitive_types.c
```c
/**
 * stack_primitive_types.c: Implementation fo stack structure in C using void pointer
 * 
 * Developed by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *
 * Date: 2023-05-06
 * Date of last modification: 2023-05-09
 */

#include <stdio.h>
#include "stack.h"

#define UNUSED(X) (void) X

typedef enum ENUM_DATA_TYPES
{
  BOOL,
  CHAR,
  INT,
  FLOAT,
  DOUBLE
} ENUM_DATA_TYPES, *PENUM_DATA_TYPES;

ENUM_DATA_TYPES geDataType;

int iShowStack(PSTRUCT_STACK pstStack)
{
  PSTRUCT_NODE pstCurrentNode = pstStack->pstTop;

  if(bStackIsEmpty(pstStack))
  {
    return -1;
  }

  switch(geDataType)
  {
    case BOOL:
      while(pstCurrentNode != NULL)
      {
        printf("%s\n", *((bool *) pstCurrentNode->vpData) == true ? "true" : "false");
        pstCurrentNode = pstCurrentNode->pstNext;
      }

      break;
    case CHAR:
      while(pstCurrentNode != NULL)
      {
        printf("%c\n", *((char *) pstCurrentNode->vpData));
        pstCurrentNode = pstCurrentNode->pstNext;
      }
      
      break;
    case INT:
      while(pstCurrentNode != NULL)
      {
        printf("%d\n", *((int *) pstCurrentNode->vpData));
        pstCurrentNode = pstCurrentNode->pstNext;
      }

      break;
    case FLOAT:
      while(pstCurrentNode != NULL)
      {
        printf("%.2f\n", *((float *) pstCurrentNode->vpData));
        pstCurrentNode = pstCurrentNode->pstNext;
      }

      break;
    case DOUBLE:
      while(pstCurrentNode != NULL)
      {
        printf("%.2lf\n", *((double *) pstCurrentNode->vpData));
        pstCurrentNode = pstCurrentNode->pstNext;
      }

      break;
    default:
      return -2;
  }

  return 0;
}

int main(int argc, char **argv)
{
  PSTRUCT_STACK pstStack;
  int ii;
  float fi;
  int *piData;
  float *pfData = NULL;
  double di;
  double *pdData = NULL;
  char szStr[] = "Gustavo Bacagine";
  char *chData;
  bool *pbData;
  bool bDatas[] = { true, false, false, true, true,
                    false, false, true, true, true };

  UNUSED(argc);
  UNUSED(argv);

  /****************************************************************************
   *                                                                          *
   *                               BOOL TEST                                  *
   *                                                                          *
   ****************************************************************************/
  printf(
      "===============\n"
      "|| BOOL TEST ||\n"
      "===============\n"
  );
  if(bInitStack(&pstStack, iShowStack) == false)
  {
    exit(EXIT_FAILURE);
  }
  
  geDataType = BOOL;
  printf("Initial stack size: %d\n\n", iGetStackSize(pstStack));

  for(ii = 0; ii < 10; ii++)
  {
    pbData = (bool *) malloc(sizeof(bool));

    if(pbData == NULL)
    {
      fprintf(stderr, "E: Out memory!\n");
      exit(EXIT_FAILURE);
    }

    *pbData = bDatas[ii];
    
    printf("Push %s\n", *((bool *) vpPushStack(&pstStack, pbData)) == true ? "true" : "false");
    printf("Stack size: %d\n", iGetStackSize(pstStack));
    
    puts("Show stack after push");
    gpfnShowStack(pstStack);
    putchar('\n');
  }
  
  puts("Show All Stack Elements");
  gpfnShowStack(pstStack);
  putchar('\n');

  for(ii = 0; ii < 10; ii++)
  {
    printf("Pop %s\n", *((bool *) vpPopStack(pstStack)) == true ? "true" : "false");
    printf("Stack size: %d\n", iGetStackSize(pstStack));
    
    puts("Show stack after pop:");
    if(iGetStackSize(pstStack) > 0)
    {
      gpfnShowStack(pstStack);
      putchar('\n');
    }
    else
    {
      puts("Stack is empty\n");
    }

    free(pbData);
    pbData = NULL;
  }
  
  vDestroyStack(&pstStack);

  /****************************************************************************
   *                                                                          *
   *                             INTEGER TEST                                 *
   *                                                                          *
   ****************************************************************************/
  printf(
      "==============\n"
      "|| INT TEST ||\n"
      "==============\n"
  );
  if(bInitStack(&pstStack, iShowStack) == false)
  {
    exit(EXIT_FAILURE);
  }
  
  geDataType = INT;
  printf("Initial stack size: %d\n\n", iGetStackSize(pstStack));
  for(ii = 0; ii < 10; ii++)
  {
    piData = (int *) malloc(sizeof(int));

    if(piData == NULL)
    {
      fprintf(stderr, "E: Out memory!\n");
      exit(EXIT_FAILURE);
    }

    *piData = ii;
    
    printf("Push %d\n", *((int *) vpPushStack(&pstStack, piData)));
    printf("Stack size: %d\n", iGetStackSize(pstStack));
    
    puts("Show stack after push");
    gpfnShowStack(pstStack);
    putchar('\n');
  }
  
  puts("Show All Stack Elements");
  gpfnShowStack(pstStack);
  putchar('\n');

  for(ii = 0; ii < 10; ii++)
  {
    printf("Pop %d\n", *((int *) vpPopStack(pstStack)));
    printf("Stack size: %d\n", iGetStackSize(pstStack));
    
    puts("Show stack after pop:");
    if(iGetStackSize(pstStack) > 0)
    {
      gpfnShowStack(pstStack);
      putchar('\n');
    } 
    else
    {
      puts("Stack is empty\n");
    }

    free(piData);
    piData = NULL;
  }

  vDestroyStack(&pstStack);
 
  /****************************************************************************
   *                                                                          *
   *                               CHAR TEST                                  *
   *                                                                          *
   ****************************************************************************/
  printf(
      "===============\n"
      "|| CHAR TEST ||\n"
      "===============\n"
  );
  if(bInitStack(&pstStack, iShowStack) == false)
  {
    exit(EXIT_FAILURE);
  }
  
  geDataType = CHAR;
  printf("Initial stack size: %d\n\n", iGetStackSize(pstStack));
  for(ii = 0; szStr[ii] != '\0'; ii++)
  {
    chData = (char *) malloc(sizeof(char));

    if(chData == NULL)
    {
      fprintf(stderr, "E: Out memory!\n");
      exit(EXIT_FAILURE);
    }

    chData = &szStr[ii];

    printf("Push %c\n", *((char *) vpPushStack(&pstStack, chData)));
    printf("Stack size: %d\n", iGetStackSize(pstStack));
    
    puts("Show stack after push");
    gpfnShowStack(pstStack);
    putchar('\n');
  }
  
  puts("Show All Stack Elements");
  gpfnShowStack(pstStack);
  putchar('\n');

  for(ii = 0; szStr[ii] != '\0'; ii++)
  {
    printf("Pop %c\n", *((char *) vpPopStack(pstStack)));
    printf("Stack size: %d\n", iGetStackSize(pstStack));
    

    puts("Show stack after pop:");
    if(iGetStackSize(pstStack) > 0)
    {
      gpfnShowStack(pstStack);
      putchar('\n');
    }
    else
    {
      puts("Stack is empty\n");
    }
  }

  vDestroyStack(&pstStack);

  /****************************************************************************
   *                                                                          *
   *                               FLOAT TEST                                 *
   *                                                                          *
   ****************************************************************************/
  printf(
      "================\n"
      "|| FLOAT TEST ||\n"
      "================\n"
  );
  if(bInitStack(&pstStack, iShowStack) == false)
  {
    exit(EXIT_FAILURE);
  }
  
  geDataType = FLOAT;

  printf("Initial stack size: %d\n\n", iGetStackSize(pstStack));
  for(fi = 0; fi < 1.0; fi += 0.1)
  {
    pfData = (float *) malloc(sizeof(float));
    
    if(pfData == NULL)
    {
      fprintf(stderr, "E: Out memory!\n");
      exit(EXIT_FAILURE);
    }

    *pfData = fi;
    printf("Push %.2f\n", *((float *) vpPushStack(&pstStack, pfData)));
    printf("Stack size: %d\n", iGetStackSize(pstStack));
    
    puts("Show stack after push");
    gpfnShowStack(pstStack);
    putchar('\n');
  }

  puts("Show All Stack Elements");
  gpfnShowStack(pstStack);
  putchar('\n');
  
  for(ii = 0; ii < 10; ii++)
  {
    printf("Pop %.2f\n", *((float *) vpPopStack(pstStack)));
    printf("Stack size: %d\n", iGetStackSize(pstStack));
    
    puts("Show stack after pop:");
    if(iGetStackSize(pstStack) > 0)
    {
      gpfnShowStack(pstStack);
      putchar('\n');
    }
    else
    {
      puts("Stack is empty\n");
    }

    free(pfData);
    pfData = NULL;
  }

  vDestroyStack(&pstStack);

  /****************************************************************************
   *                                                                          *
   *                               DOUBLE TEST                                *
   *                                                                          *
   ****************************************************************************/
  puts(
      "=================\n"
      "|| DOUBLE TEST ||\n"
      "=================\n"
  );
  if(bInitStack(&pstStack, iShowStack) == false)
  {
    exit(EXIT_FAILURE);
  }
  
  geDataType = DOUBLE;

  printf("Initial stack size: %d\n\n", iGetStackSize(pstStack));
  for(di = 0; di < 0.9; di += 0.1)
  {
    pdData = (double *) malloc(sizeof(double));
    
    if(pdData == NULL)
    {
      fprintf(stderr, "E: Out memory!\n");
      exit(EXIT_FAILURE);
    }

    *pdData = di;
    printf("Push %.2lf\n", *((double *) vpPushStack(&pstStack, pdData)));
    printf("Stack size: %d\n", iGetStackSize(pstStack));
    
    puts("Show stack after push");
    gpfnShowStack(pstStack);
    putchar('\n');
  }

  puts("Show All Stack Elements");
  gpfnShowStack(pstStack);
  putchar('\n');
  
  for(ii = 0; ii < 10; ii++)
  {
    printf("Pop %.2lf\n", *((double *) vpPopStack(pstStack)));
    printf("Stack size: %d\n", iGetStackSize(pstStack));


    puts("Show stack after pop:");
    if(iGetStackSize(pstStack) > 0)
    {
      gpfnShowStack(pstStack);
      putchar('\n');
    }
    else
    {
      puts("Stack is empty\n");
    }

    free(pdData);
    pdData = NULL;
  }

  vDestroyStack(&pstStack);
  
  return 0;
}

```

#### person.c
```c
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

```

