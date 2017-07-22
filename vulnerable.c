#include <stdio.h>
#include <string.h>

void foo() {
  char buf[20];
  printf("Enter some text:\n");
  scanf("%s", &buf);
  printf("You entered: %s\n", buf);

}

void malicious() {
  printf("Muahaha. I hacked the computer.\n");
}

int main(int argc, char* argv[]) {
  printf("Address of malicious: %p\n", malicious);
  printf("Address of foo: %p\n", foo);
  printf("Address of main: %p\n", main);

  foo();
  return 0;
}
