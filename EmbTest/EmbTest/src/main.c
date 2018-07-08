/*
* Function Ptr: Return Type (* function pointer's variable name)(parameters)
*/
#if 0



#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define NO_OBJECT_ERROR 0
#define INVALID_EMP_NO_ERROR 0
#define NO_ERROR 1

typedef struct EmployeeStr EmployeeStr; //forward declare
typedef EmployeeStr* EmployeePtr;

typedef int(*getEmployeeNumber) (EmployeePtr employee);
typedef int(*setEmployeeNumber) (EmployeePtr employee, int number);

typedef char*(*getEmployeeName) (EmployeePtr employee);
typedef int(*setEmployeeName) (EmployeePtr employee, char* name);

struct EmployeeStr {
	int employee_number;
	char* name;
	getEmployeeNumber _getEmployeeNumber;
	setEmployeeNumber _setEmployeeNumber;
	getEmployeeName _getEmployeeName;
	setEmployeeName _setEmployeeName;
};


int Employee_getEmployeeNumber(EmployeePtr employee) {
	if (employee == NULL) return NO_OBJECT_ERROR;
	else return employee->employee_number;
}

int Employee_setEmployeeNumber(EmployeePtr employee, int number) {
	if (employee == NULL) return NO_OBJECT_ERROR;
	else if (number < 1) return INVALID_EMP_NO_ERROR;
	else {
		employee->employee_number = number;
		return NO_ERROR;
	}
}

char* Employee_getEmployeeName(EmployeePtr employee) {
	if (employee == NULL) return "NO_OBJECT_ERROR";
	else return employee->name;
}

int Employee_setEmployeeName(EmployeePtr employee, char* name) {
	int size = strlen(name);
	char* temp = (char*)malloc(sizeof(char)*size + 1);
	strcpy_s(temp, size+1, name);
	employee->name = temp;
	free(temp);
	return NO_ERROR;
}

int main()
{
	int var;
	char c;

	EmployeePtr employee = (EmployeePtr)malloc(sizeof(EmployeeStr));
	employee->_setEmployeeNumber = Employee_setEmployeeNumber(employee, 5);
	var = employee->_getEmployeeNumber = Employee_getEmployeeNumber(employee);
	printf("Var: %d", var);
	printf("\nEnter character: ");
	c = getc(stdin);
	
	return 0;
}
#endif // DEBUG