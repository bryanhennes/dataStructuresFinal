#include "Assignment.h"

Assignment::Assignment() {
	dueDate = 0;
	courseName = "Class";
	isCompleted = false;
}

Assignment::Assignment(int dD, string courseNm, bool isComp) {
	dueDate = dD;
	courseName = courseNm;
	isCompleted = isComp;
}

void Assignment::setDueDate(int date) {
	dueDate = date;
}

void Assignment::displayAssignment() {
	cout << courseName << " assignment is due in " << dueDate << " days and " << displayCompletedOrNot() << endl;
}

string Assignment::displayCompletedOrNot()
{
	if (isCompleted)
		return "is completed.";
	else
		return "is not completed.";
}
