#include <stdio.h> 
#define SIZE 100 
int main() { 
int stack[SIZE], top = -1; 
int n, i, num, highest; 
printf("Enter how many numbers: "); 
scanf("%d", &n); 
// push numbers 
for(i = 0; i < n; i++) { 
printf("Enter number %d: ", i+1); 
scanf("%d", &num); 
stack[++top] = num; 
} 
highest = stack[0]; 
printf("\nEven numbers popped from stack:\n"); 
while(top >= 0) { 
int val = stack[top--];   // pop 
if(val % 2 == 0) { 
printf("%d ", val); 
} 
if(val > highest) { 
highest = val;
} 
} 
printf("\n\nHighest marks: %d\n", highest); 
return 0; 
}