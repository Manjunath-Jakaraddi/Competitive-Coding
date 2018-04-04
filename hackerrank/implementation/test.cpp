#include <cstdio>
using namespace std;
int N;
char x[110];
int main() {
scanf("%d\n", &N);
while (N--) {
scanf("0.%[0-9]...\n", x);
// ‘&’ is optional when x is a char array
// note: if you are surprised with the trick above,
// please check scanf details in www.cppreference.com
printf("the digits are 0.%s\n", x);
} } // return 0;
