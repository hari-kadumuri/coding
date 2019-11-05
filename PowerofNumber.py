import math

def getPower(x, y):
	return math.pow(x, y)

def main():
	x = float(input("enter x: "))
	y = int(input("enter y: "))
	print(getPower(x, y))

main()