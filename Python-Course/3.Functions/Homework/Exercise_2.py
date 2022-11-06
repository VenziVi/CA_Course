from functools import wraps
import time


def timeit(func):
    @wraps(func)
    def timeit_wrapper(*args, **kwargs):
        start_time = time.perf_counter()
        result = list(func(*args, **kwargs))
        end_time = time.perf_counter()
        total_time = end_time - start_time
        print(f'Function {func.__name__}{args} {kwargs} Took {total_time:.4f} seconds')
        return result
    return timeit_wrapper


"""
Write a function to find all prime numbers from 2 to limit with Sieve of Eratosthenes algorithm.
Extra: create a function with generators
Input: 100
Output: [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
"""


@timeit
def primes_with_sieve(limit):
    primes_list = [True for _ in range(limit + 1)]
    primes_list[0] = primes_list[1] = False
    num = 2
    while num * num <= limit:
        if primes_list[num]:
            index = num * num
            while index <= limit:
                primes_list[index] = False
                index += num
        num += 1
    return [i for i in range(limit + 1) if primes_list[i]]


@timeit
def primes_with_sieve_generator(limit):
    primes_list = [True for _ in range(limit + 1)]
    num = 2
    while num <= limit:
        if primes_list[num]:
            yield num
            for index in range(num * num, limit + 1, num):
                primes_list[index] = False
        num += 1


@timeit
def primes_with_generator(limit):
    primes_list = range(2, limit + 1)
    while len(primes_list) >= 1:
        yield primes_list[0]
        primes_list = [num for num in primes_list if num % primes_list[0] != 0]


print(primes_with_sieve(10000))
print(primes_with_sieve_generator(10000))
print(primes_with_generator(10000))
