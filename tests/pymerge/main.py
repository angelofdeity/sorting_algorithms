#!/usr/bin/python3
from merge import merge_sort
array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]
print(*array, sep=", ")
print()
merge_sort(array)
print()
print(*array, sep=", ")
