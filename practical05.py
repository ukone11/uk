def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2
    return arr

def display_top_five(arr):
    """Display the top five scores from the sorted array."""
    print("Top five scores:", arr[-5:][::-1])

def main():
    n = int(input("Enter the number of students: "))
    print("Enter the percentages:")
    percentages = [float(input(f"Percentage of student {i + 1}: ")) for i in range(n)]

    print("\nSorting using Insertion Sort:")
    sorted_insertion = insertion_sort(percentages.copy())
    print("Sorted Percentages:", sorted_insertion)
    display_top_five(sorted_insertion)

    print("\nSorting using Shell Sort:")
    sorted_shell = shell_sort(percentages.copy())
    print("Sorted Percentages:", sorted_shell)
    display_top_five(sorted_shell)

if __name__ == "__main__":
    main()
