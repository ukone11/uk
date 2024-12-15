def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def display_top_five(arr):
    print("Top five scores:", arr[-5:][::-1])

def main():
    n = int(input("Enter the number of students: "))
    print("Enter the percentages:")
    percentages = [float(input(f"Percentage of student {i + 1}: ")) for i in range(n)]

    print("\nSorting using Selection Sort:")
    sorted_selection = selection_sort(percentages.copy())
    print("Sorted Percentages:", sorted_selection)
    display_top_five(sorted_selection)

    print("\nSorting using Bubble Sort:")
    sorted_bubble = bubble_sort(percentages.copy())
    print("Sorted Percentages:", sorted_bubble)
    display_top_five(sorted_bubble)

if __name__ == "__main__":
    main()
