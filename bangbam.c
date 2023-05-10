#include<hash.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

element_t *D[TABLE_SIZE];

// Hash Code Maps
// Component Sum
static const int transform(const char *key) {
  int number;
  for (number = 0; (*key) != 0; key++)
    number += *key;
  return number;
}

// Compression map
int hash(const char *key) { 
  return (transform(key) % TABLE_SIZE); 
}

// ====================================
//      HASH TABLE OPERATIONS
// ====================================

void init_table(element_t *ht[]) {
  clear(ht);
}

void clear(element_t *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    clearbucket(ht, i);
  }
}

void clearbucket(element_t *ht[], int b) {
  element_t *p = ht[b];
  while (p != NULL) {
    element_t *temp = p;
    p = p->next;
    free(temp);
  }
  ht[b] = NULL;
}

element_t *findElement(element_t *ht[], char key[]) {
  int hash_value = hash(key);
  element_t *p = ht[hash_value];
  while (p != NULL && strcmp(p->key, key) != 0) {
    p = p->next;
  }
  return p;
}

int insertItem(element_t *ht[], element_t o) {
  int hash_value = hash(o.key);
  element_t *pNewElement = (element_t *)malloc(sizeof(element_t) * 1);
  strcpy(pNewElement->key, o.key);
  strcpy(pNewElement->word, o.word);
  pNewElement->next = NULL;

  if (ht[hash_value] == NULL) {
    ht[hash_value] = pNewElement;
    return TRUE;
  } else {
    element_t *p = ht[hash_value];
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = pNewElement;
    return TRUE;
  }
}

int removeElement(element_t *ht[], char key[]) {
  int hash_value = hash(key);
  element_t *p1 = ht[hash_value];

  if (p1 == NULL)
    return -1;  // Not found
  else if (strcmp(p1->key, key) == 0) {
    ht[hash_value] = p1->next;
    free(p1);
    return TRUE;
  } else {
    element_t *p2 = p1->next;
    while (p2 != NULL && strcmp(p2->key, key) != 0) {
      p1 = p2;
      p2 = p2->next;
    }
    if (p2 == NULL) {
      return -1;  // Not found
    } else {
      p1->next = p2->next;
      free(p2);
      return TRUE;
    }
  }
}
