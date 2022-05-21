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

void Assignment::updateDueDate(int date) {
	dueDate = date;
}

void Assignment::displayAssignment() {
	cout << courseName << " assignment is due in " << dueDate << " days and " << displayCompletedOrNot() << endl;
}

bool Assignment::isAssignmentCompleted()
{
	if (isCompleted)
		return true;
	return false;
}

int Assignment::getDueDate() {
	return dueDate;
}

string Assignment::getCourseName() {
	return courseName;
}

string Assignment::displayCompletedOrNot()
{
	if (isCompleted)
		return "is completed.";
	else
		return "is not completed.";
}
