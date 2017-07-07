// Operacoes sobre listas (em ordem alfabetica)

#include "item.h"

// count
// -----
// Return the quantity of items in l;
// or return -1, if l is not found.

int count (void * l);


// create
// ------
// Return a pointer to the created list, whose label is s;
// or return NULL, if the list was not created

void * create (char *s);


// destroy
// -------
// Return NULL if l was destroyed; return l otherwise.
// Destroying l implies in deallocating all nodes of l.

void * destroy (void *l);


// find
// ----
// Return a pointer to the item whose id is m;
// or return NULL, if no item with id m was found.

Item * find (void *l, int m);


// idl
// ---
// Return a pointer to list of items whose label is s;
// or return NULL, if does not exist a list with label s.

void * idl (char *s);


// insert
// ------
// Return l, if m is inserted into l; or return NULL, if
// either l was not found or space for m was not allocated.
// m is inserted into l in ascending order.

void * insert (void *l, Item m);


// label
// -----
// Return the label of l; or return NULL, if l is not found.

char * label (void *l);


// showAll
// -------
// Present all items of l.
// Return l; or return NULL, if l was not found.

void * showAll (void *l);

// showDir
// -------
// Present all lists in the directory and the respective
// number of items in each list.

void showDir();
