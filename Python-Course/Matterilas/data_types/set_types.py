student_ages = {14, 15, 14, 15, 17, 18, 16}
print(type(student_ages))

people_ages = {14, 15, 22, 26, 28, 39, 40, 11}

print("| ", student_ages | people_ages)
print("& ", student_ages & people_ages)
print("^ ", student_ages ^ people_ages)
print("- ", student_ages - people_ages)
print(student_ages)


student_ages.intersection_update({14, 15}, {16, 17}, {25, 30})  # result in empty set

student_ages &= {14, 15}
student_ages &= {16, 17} # result in empty student_ages
student_ages &= {25, 30}
print(student_ages)


student_ages.difference_update({14, 15}, {16, 17}, {25, 30})
student_ages -= {14, 15}
student_ages -= {16, 17}
student_ages -= {25, 30}
print(student_ages)


# >>> {14, 15, 16, 17, 18}

# add age to student_ages
student_ages.add(23)

print(student_ages)
# >>> {14, 15, 16, 17, 18, 23}

# lookup in set is the same as lookup in dict O(1)
if 15 in student_ages:
    print(True)

# frozenset
cars = frozenset({'Skoda', 'VW', 'BMW', 'Ford'})
cars.add('Dacia')
print("Skoda" in cars)
# >>> raises AttributeError: 'frozenset' object has no attribute 'add'
