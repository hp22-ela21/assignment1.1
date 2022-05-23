/* Inkluderingsdirektiv: */
#include <stdio.h>
#include <stdlib.h>

/* Inline-funktioner: */
static inline int* new_int(const size_t size) { return (int*)malloc(sizeof(int) * size); }
static inline void* get_random(const void* min, const void* max) { const double num = 
   (rand() % (int)(*(int*)max - *(double*)min + 1) + *(double*)min); return &num; }

/************************************************************************************************
* Tilldelar slumpmässiga heltal till array med valbart min- och maxvärde på slumptalen.
*************************************************************************************************/
static void assign(int** data, const size_t size, const int min, const int max)
{
   for (register int* i = *data; i < *data + size; i++)
      *i = get_random(min, max);
   return;
}

/************************************************************************************************
* Skriver signerade heltal till specificerad utenhet, där default är standardutenheten stdout.
*************************************************************************************************/
static void print(FILE* stream, const int* data, const size_t size)
{
   if (!stream) stream = stdout;
   fprintf(stream, "------------------------------------------------------------------------\n");
   for (register const int* i = data; i < data + size; i++)
      fprintf(stream, "%d\n", *i);
   fprintf(stream, "------------------------------------------------------------------------\n\n");
   return;
}

/************************************************************************************************
* Allokerar minne för tio signerade heltal i en int-array, som fylls med slumptal mellan
* -5 och 5. Innehållet skrivs ut i konsolen samt till en textfil döpt data.txt.
*************************************************************************************************/
int main(void)
{
   FILE* fstream = fopen("data.txt", "w");
   int* data = new_int(10);
   assign(&data, 10, -5, 5);
   print(fstream, data, 10);
   print(stdout, data, 10);
   return 0;
}


