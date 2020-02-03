
weightsOfModules = open("input.txt", "r")

fuelRequired = 0

for weightOfModule in weightsOfModules:
    fuelRequired += max(0, (int(weightOfModule) // 3) - 2)

print(f"We need: {fuelRequired} fuel")
