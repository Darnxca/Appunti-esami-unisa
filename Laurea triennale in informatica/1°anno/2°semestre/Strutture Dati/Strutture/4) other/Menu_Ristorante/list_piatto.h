// file list.h

typedef struct list_piatto *list_piatto;

// prototipi

list_piatto newListPiatto(void);

piatto getPiatto (list_piatto l, int pos);

list_piatto inputList (int n);

int insertPiatto (list_piatto l, int pos, piatto val);

int stampa_piatti (list_piatto l);
