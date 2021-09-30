import os

if (os.path.isdir("out")):
    os.system("rm ./out/*")
else:
    os.system("mkdir out")

f = open("in_args.csv")

lines = f.readlines()[1:]

f.close()

if (not os.path.isdir("bin")):
    os.system("mkdir bin")

os.system("cd src && make && cd ..")

for line in lines:
    l = "timeout -s 9 5m ./bin/main.out " + " ".join(line.split(",")[:-2])
    a = line.split(",")[-2]

    os.system('echo COMAND : %s' % l)
    os.system('echo -n CORRECT ANSWER IS %s \& YOUR ANSWER IS \ ' % a)
    os.system(l)
    os.system("echo ")
    os.system("echo ")

img_list = os.listdir("./ans_img")

for img in img_list:
    if ("zip" in img):
        continue
    elif (not os.path.isfile("./out/%s" % img)):
        print("%s : NO_FILE" % img)
        continue

    ans_f = open("./ans_img/%s" % img,"r")
    ans = ans_f.read()
    ans_f.close()

    ans = ans.replace("\n", " ").split(" ")
    ans = filter(lambda x: x != "", ans)

    grade_f = open("./out/%s" % img, "r")
    grade = grade_f.read()
    grade_f.close()

    grade = grade.replace("\n", " ").split(" ")
    grade = filter(lambda x: x != "", grade)

    count = 0

    if (len(ans) != len(grade)):
        print("%s : NP" % img)
        continue

    if (ans[0] == grade[0]):
        count += 1

    for i in range(1, len(ans)):
        try:
            if (int(ans[i]) == int(grade[i])):
                count += 1
        except:
            continue

    print("%s : %.4f" % (img, float(count) / float(len(ans))))

