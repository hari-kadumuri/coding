import math

def getHypotenuse(a, b):
	return math.pow(a*a+b*b, 0.5)

def main():
	a = float(input('enter a: '))
	b = float(input('enter b: '))
	print(getHypotenuse(a, b))

main()