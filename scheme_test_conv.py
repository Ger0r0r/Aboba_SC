from PIL import Image as im
import numpy as np

picture = im.open("Pattern1.bmp")
txt_out = open("output.txt", "w")

raw_colors = picture.getcolors()

pixels = list(picture.getdata())
v, h = picture.size
pixels = [pixels[i * v:(i + 1) * v] for i in range(h)]
pixels = np.array(pixels)
pixels = pixels[5:h-4:10,5:v-4:10]

colors = []

# print(raw_colors[0][1])

for i in range(len(raw_colors)):
	colors.append(raw_colors[i][1])

# colors.remove((255,255,255))
colors.remove((0,0,0))

print(colors)

n = len(colors)

# print(pixels) # very long time
# print(v, h)
# print(len(pixels[0]), len(pixels))
# print(pixels)
v = len(pixels)
h = len(pixels[0])
txt_out.write(str(v) + " " + str(h) + "\n")

for i in range(v):
	for j in range(h):
		for k in range(n):
			if (pixels[i][j][0] == colors[k][0] and pixels[i][j][1] == colors[k][1] and pixels[i][j][2] == colors[k][2] ):
				txt_out.write(str(k) + " ")
				continue
	txt_out.write("\n")

txt_out.write("#\n")

for i in range(v):
	for j in range(h):
		txt_out.write("0 ")
	txt_out.write("\n")

txt_out.close()