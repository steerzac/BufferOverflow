#include <stdio.h>
#include <string.h>

void foo(char* input) {
  char buf[10];

  printf("Stack looks like");
  printf("\n %p\n %p\n %p\n %p\n %p\n %p\n \n");

  strcpy(buf, input);
  printf("%s\n", buf);

  printf("\n %p\n %p\n %p\n %p\n %p\n %p\n \n");
}

void malicious() {
  printf("Muahaha. I hacked the computer.");
}

int main(int argc, char* argv[]) {
  printf("Address of malicious: %p\n", malicious);
  printf("Address of foo: %p\n", foo);
  printf("Address of main: %p\n", main);

  if(argc != 2) {
    printf("Usage: ./a.out <maliciousString>");
    return -1;
  }

  foo(argv[1]);
  return 0;
}
