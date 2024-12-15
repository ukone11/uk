def counting_sort(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    for i in range(n):
        index = int(arr[i] / exp) % 10
        count[index] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0:
        index = int(arr[i] / exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1

    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    max_num = max(arr)
    exp = 1
    while max_num / exp > 1:
        counting_sort(arr, exp)
        exp *= 10
    return arr

def display_top_five(arr):
    print("Top five scores:", arr[-5:][::-1])

def main():
    n = int(input("Enter the number of students: "))
    print("Enter the percentages:")
    percentages = [float(input(f"Percentage of student {i + 1}: ")) for i in range(n)]

    print("\nSorting using Radix Sort:")
    sorted_radix = radix_sort(percentages.copy())
    print("Sorted Percentages:", sorted_radix)
    display_top_five(sorted_radix)

if __name__ == "__main__":
    main()
