

def calculateFuelNeeded(mass):
    return max(0, (int(mass) // 3) - 2)

def calculateFuelNeededForUnitWithFuel(mass):
    fuelNeeded = calculateFuelNeeded(mass)

    if fuelNeeded == 0:
        return 0
    else:
        return fuelNeeded + calculateFuelNeededForUnitWithFuel(fuelNeeded)


weightsOfModules = open("input.txt", "r")

fuelRequired = 0

for weightOfModule in weightsOfModules:
    fuelRequired += calculateFuelNeededForUnitWithFuel(weightOfModule)


print(f"We need: {fuelRequired} fuel")


