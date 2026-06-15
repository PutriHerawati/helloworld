# Program to Calculate Volume and Surface Area of a Cuboid
# --------------------------------------------------------

print("--- CUBOID CALCULATOR PROGRAM ---")

# 1. Declaration and Input Values
# Using float to allow users to enter decimal numbers
length = float(input("Enter cuboid length (cm): "))
width = float(input("Enter cuboid width (cm): "))
height = float(input("Enter cuboid height (cm): "))

# 2. Calculations
# Volume Formula: V = l * w * h
volume = length * width * height

# Surface Area Formula: SA = 2 * ((l * w) + (l * h) + (w * h))
surface_area = 2 * ((length * width) + (length * height) + (width * height))

# 3. Output Results
print("\n--- CALCULATION RESULTS ---")
print(f"Cuboid Volume        : {volume} cm³")
print(f"Cuboid Surface Area  : {surface_area} cm²")
print("---------------------------")
