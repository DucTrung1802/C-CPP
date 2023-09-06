#include <stdio.h>

void myFunc1();
void myFunc2();

int main(void) {
	myFunc1();
	myFunc1();
	myFunc1();
	myFunc1();

	myFunc2();
	myFunc2();
	myFunc2();
	myFunc2();

	return 0;
}

void myFunc1() {
	static int count = 0;
	count = count + 1;
	printf("Count func1 = %d\n", count);
}

void myFunc2() {
	static int count = 100;
	count = count + 1;
	printf("Count func2 = %d\n", count);
}
