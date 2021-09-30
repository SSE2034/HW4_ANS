import os

file_list = os.listdir("./ppm")

for f in file_list:
    if (".zip" in f):
        os.system("unzip ./ppm/%s -d ./ppm" % f)

file_list = os.listdir("./ans_img")

for f in file_list:
    if (".zip" in f):
        os.system("unzip ./ans_img/%s -d ./ans_img" % f)
