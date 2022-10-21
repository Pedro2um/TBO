import os

arquivos = [
    "msbu.c",
    "msbuco.c",
    "msbums.c",
    "msbuo.c",
    "mstd.c",
    "mstdco.c",
    "mstdms.c",
    "mstdo.c"
]

testes = [
    "./input/nearly_sorted/1000000.txt",
    "./input/reverse_sorted/1000000.txt",
    "./input/sorted/1000000.txt",
    "./input/unif_rand/1000000.txt"
]

for arquivo in arquivos:
    os.system("gcc -o main main.c " + arquivo)
    for teste in testes:
        os.system("./main < " + teste + " > "
            + arquivo.split(".")[0]
            + "_" + teste.split("/")[2] + ".txt")

os.system("touch output.csv")
output = open("output.csv", "w")

for teste in testes:
    output.write("," + teste.split("/")[2])
output.write("\n")

for arquivo in arquivos:
    output.write(arquivo.split(".")[0])

    for teste in testes:
        tmp = open(arquivo.split(".")[0]
            + "_" + teste.split("/")[2] + ".txt", "r")        
        output.write("," + tmp.read() + "s")
        tmp.close()
    output.write("\n")

output.close()

os.system("rm *.txt")
os.system("rm main")