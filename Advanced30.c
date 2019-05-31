#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int i;
	int error = 0;
	float perimeter = 0;
	float acreage, s, t=1;
	float x[3] = {0};
	float y[3] = {0};
	float l[3] = {0};
	printf("Enter the Cartesian coordinates of the three vertices of the triangle(x1 y1 x2 y2 x3 y3):");
	scanf("%f %f %f %f %f %f",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]);
	printf("Result:\n");
	for(i=0;i<3;i++){
		l[i] = sqrt(pow(abs(x[i]-x[(i+1)%3]), 2) + pow(abs(y[i]-y[(i+1)%3]), 2));
		perimeter += l[i];
	}
	s = perimeter/2;
	for(i=0;i<3;i++)
	if(l[i]>=abs(l[(i+1)%3]+l[(i+2)%3])) error = 1;
	if(error==1)
	printf("This is a straight line.\n");
	else{
		for(i=0;i<3;i++){
			t *= s-l[i];
			if(l[i]==l[(i+1)%3] && l[i]==l[(i+2)%3]){
				printf("This triangle is an \"Equilateral Triangle\".\n");
				break;
			}
			else if(l[i]==l[(i+1)%3] || l[i]==l[(i+2)%3] || l[(i+1)%3]==l[(i+2)%3]){
				printf("This triangle is an \"Isosceles Triangle\"");
				if(l[(i+2)%3]==sqrt(pow(l[i], 2) * 2))
				printf(" and is also a \"Right Triangle\"");
				printf(".\n");
				break;
			}
			else if(l[(i)%3]==sqrt(pow(l[(i+1)%3], 2) + pow(l[(i+2)%3], 2))){
				printf("This triangle is a \"Right Triangle\".\n");
				break;
			}
		}
		acreage = sqrt(s*t);
		printf("Perimeter = %.3f unit\n",perimeter);
		printf("Acreage = %.3f square unit\n",acreage);
	}
	system("pause");
	return 0;
}
