
import matplotlib.pyplot as plt
import time
import numba
import numpy as np

MAX = 100000
numbers = np.zeros(MAX, dtype=np.int32)
maxima = np.zeros(MAX, dtype=np.int32)
cycles = np.zeros(MAX, dtype=np.int32)

n = np.array


@numba.njit
def collatz(number):
    max = number
    init_number = number
    cycle_length = 1
    while number > 1:
        if not number & 1:
            number >>= 1
        else:
            number += (number << 1) + 1
        cycle_length += 1
        if number > max:
            max = number
    return cycle_length, max


collatz(2)

times_start = time.time()
for i in range(2, MAX):
    cycle, max = collatz(i)
    numbers[i] = i  # [i] = cycle
    cycles[i] = cycle   # [i] = cycle
    maxima[i] = max  # [i] = max
times_end = time.time()
print(times_end - times_start)

with open('collatz.txt', 'w') as f:
    for i in range(1, MAX):
        # {numbers[i]:>3},
        f.write(f"{i:>3}, {cycles[i]:>5} {maxima[i]:>7}\n")
plt.figure(figsize=(10, 10))
plt.subplot(2, 1, 1)

plt.plot(numbers, cycles)

plt.title('Number of Cycles')
plt.subplot(2, 1, 2)
plt.plot(numbers, maxima)
plt.title('Maximum value reached')
plt.show()
