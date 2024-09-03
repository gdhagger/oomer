#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  void *ptr;
  size_t chunk_size = 64 * 1024 * 1024; // 64 MB

  while (1)
  {
    ptr = malloc(chunk_size);
    memset(ptr, 0, 1024 * 1024);
  }

  return 0;
}