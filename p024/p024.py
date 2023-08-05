import itertools

# Generate permutations using itertools
permutations = itertools.permutations(range(10))

# Print the first 10 permutations in lexicographic order
count = 0
for perm in permutations:
    print(''.join(map(str, perm)))
    count += 1
    if count == 10**6:
        break

