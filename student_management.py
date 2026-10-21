
def main():
    students = []
    n = int(input("Enter number of students (1-100): "))

    if not 1 <= n <= 100:
        print("Invalid number of students.")
        return

    for _ in range(n):
        roll = input("Enter roll number: ")
        name = input("Enter student name: ")

        marks = []
        for i in range(3):
            mark = float(input(f"Subject {i + 1} marks (0-100): "))
            if not 0 <= mark <= 100:
                print("Invalid marks.")
                return
            marks.append(mark)

        students.append({
            "roll": roll,
            "name": name,
            "average": sum(marks) / 3
        })

    print("\n--- Student Records ---")
    for s in students:
        print(f"{s['roll']} {s['name']} Average: {s['average']:.2f}")

    topper = max(students, key=lambda s: s["average"])
    print(f"Topper: {topper['name']} ({topper['average']:.2f}%)")


if __name__ == "__main__":
    main()
