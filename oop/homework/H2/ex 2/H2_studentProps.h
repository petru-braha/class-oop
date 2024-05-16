#define mathematics 0 
#define english 1
#define history 2
#include <cstring>
class student
{
private:
	char name[100] = { 0 };
	float marks[3] = {-1};
public:
	void setName();
	char* getName();

	void setMTH();
	float getMTH();

	void setENG();
	float getENG();

	void setHST();
	float getHST();

	float average_grade();
};