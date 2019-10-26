import numbers

def printImage(image):
	for i in image:
		x = ''
		for j in i:
			x += str(j) + " "
		print(x)

def initZoomedImage(image, factor):
	zoomedImage = []
	n = len(image)
	for i in range(n*factor):
		x = []
		for j in range(factor*n):
			if j/factor == int(j/factor) and i/factor == int(i/factor):
				x.append(image[int(i/factor)][int(j/factor)])
			else:
				x.append('-')
		zoomedImage.append(x)
	return zoomedImage

def zoomImage(image, factor):
	zoomedImage = initZoomedImage(image, factor)
	printImage(zoomedImage)

def main():
	n = int(input("enter number of pixels in each row:"))
	image = []
	print("enter pixel values as 0/1 row wise:")
	for i in range(n):
		x = []
		for j in range(n):
			x.append(int(input()))
		image.append(x)
	print("Original Image:")
	printImage(image)
	factor = int(input("enter the factor to which image has to be zoomed in:"))
	zoomedImage = zoomImage(image, factor)

main()
