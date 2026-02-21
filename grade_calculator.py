# Student Grade Calculator
# Added for AI code review demonstration

def calculate_grade(marks):
    # No input validation - potential bug
    total = 0
    for i in range(len(marks)):   # performance issue: should use sum()
        total = total + marks[i]  # style issue: should use +=
    avg = total / len(marks)

    if avg >= 90:
        grade = "A"
    elif avg >= 80:
        grade = "B"
    elif avg >= 70:
        grade = "C"
    elif avg >= 60:
        grade = "D"
    else:
        grade = "F"

    print("Grade: " + grade)      # style: use f-string
    print("Average: " + str(avg)) # style: use f-string
    return grade

# No main guard - runs on import (bug)
marks = [85, 90, 78, 92, 88]
result = calculate_grade(marks)
