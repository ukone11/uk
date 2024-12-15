
def get_average(marks):
    valid_marks = [mark for mark in marks if mark is not None]
    if len(valid_marks) == 0:
        return 0
    return sum(valid_marks) / len(valid_marks)

def get_highest_and_lowest(marks):
    valid_marks = [mark for mark in marks if mark is not None]
    if not valid_marks:
        return None, None
    return max(valid_marks), min(valid_marks)

def count_absent_students(marks):
    return marks.count(None)

def get_highest_frequency_mark(marks):
    valid_marks = [mark for mark in marks if mark is not None]
    if not valid_marks:
        return None
    frequency = {}
    for mark in valid_marks:
        frequency[mark] = frequency.get(mark, 0) + 1
    highest_frequency_mark = max(frequency, key=frequency.get)
    return highest_frequency_mark

def main():
    print("Enter marks for 'Fundamental of Data Structure' (-1 for absent students):")
    n = int(input("Enter the number of students: "))
    marks = []

    for i in range(n):
        mark = input(f"Enter marks for student {i + 1}: ")
        if mark == "-1":
            marks.append(None)  
        else:
            marks.append(int(mark))

   
    average_score = get_average(marks)
    highest_score, lowest_score = get_highest_and_lowest(marks)
    absent_count = count_absent_students(marks)
    most_frequent_mark = get_highest_frequency_mark(marks)

 
    print("\nResults:")
    print(f"Average score of the class: {average_score:.2f}")
    print(f"Highest score: {highest_score}")
    print(f"Lowest score: {lowest_score}")
    print(f"Number of students absent: {absent_count}")
    print(f"Mark with the highest frequency: {most_frequent_mark}")

if __name__ == "__main__":
    main()
