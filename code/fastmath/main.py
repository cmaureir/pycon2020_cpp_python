import fastmath
import math
import time

l = list(range(50_000_000))

print("# Using math.sqrt")
t_start = time.time()
a = [math.sqrt(i) for i in l]
math_sqrt_time = time.time() - t_start
print(f"math.sqrt: {math_sqrt_time:.2f}s")
print("-" * 10)

print("# Using fastmath.sqrt1: Using only C")
t_start = time.time()
b = fastmath.sqrt1(l)
fastmath_sqrt1 = time.time() - t_start
print(f"fastmath.sqrt1: {fastmath_sqrt1:.2f}s")
print(f"Performance: {math_sqrt_time/fastmath_sqrt1:.2f}")
print("-" * 10)

print("# Using fastmath.sqrt2: Using std::transform")
t_start = time.time()
c = fastmath.sqrt2(l)
fastmath_sqrt2 = time.time() - t_start
print(f"fastmath.sqrt2: {fastmath_sqrt2:.2f}s")
print(f"Performance: {math_sqrt_time/fastmath_sqrt2:.2f}")
print("-" * 10)
