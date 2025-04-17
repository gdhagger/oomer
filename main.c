#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For sleep function

void print_usage()
{
  printf("Usage: oomer [--wait SECONDS]\n");
  printf("  --wait SECONDS  Wait for the specified number of seconds before starting memory allocation\n");
}

int main(int argc, char *argv[])
{
  void *ptr;
  size_t chunk_size = 64 * 1024 * 1024; // 64 MB
  int wait_time = 0;

  // Parse command-line arguments
  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "--wait") == 0)
    {
      if (i + 1 < argc)
      {
        wait_time = atoi(argv[i + 1]);
        i++; // Skip the next argument (the value)
      }
      else
      {
        printf("Error: --wait requires a value\n");
        print_usage();
        return 1;
      }
    }
    else if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
    {
      print_usage();
      return 0;
    }
    else
    {
      printf("Unknown option: %s\n", argv[i]);
      print_usage();
      return 1;
    }
  }

  // Wait if specified
  if (wait_time > 0)
  {
    printf("Waiting for %d seconds before starting memory allocation...\n", wait_time);
    sleep(wait_time);
    printf("Starting memory allocation\n");
  }

  while (1)
  {
    ptr = malloc(chunk_size);
    memset(ptr, 0, 1024 * 1024);
  }

  return 0;
}