/**
 * node.h
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: Node structure
 *
 * Date: 2023-10-19
 */

#ifndef _NODE_H_
#define _NODE_H_

typedef struct STRUCT_NODE
{
  void *vpData;
  struct STRUCT_NODE *pstNext;
} STRUCT_NODE, *PSTRUCT_NODE;

#endif /* _NODE_H_ */

