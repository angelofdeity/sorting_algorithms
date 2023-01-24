def merge_sort(array):
    middle = len(array) / 2
    left = array[:middle]
    right = array[middle:]
    merge_sort(left)
    merge_sort(right)

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            array[k] = left[i]
            i += 1
        else:
            array[k] = right[j]
            j += 1
        k += 1

    while i < len(left):
        array[k] = left[i]

    while j < len(right):
        array[k] = right[j]
