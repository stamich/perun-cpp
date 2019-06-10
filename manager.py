import sys, os, getopt

def main(argv):
    cpp_file = ''
    exe_file = ''
    # try:
    #     opts, args = getopt.getopt(argv, "hi:",["help",'ifile='])
    # except getopt.GetoptError as err:
    #     # print help information and exit
    #     print(err)
    #     usage()
    #     sys.exit(2)
    # for o, a in opts:
    #     if o in ("-h", "--help"):
    #         usage()
    #         sys.exit()
    #     elif o in ("-i", "--ifile"):
    #         cpp_file = a + '.cpp'
    #         exe_file = a + '.exe'
    #         run(cpp_file, exe_file)
    fileCreator()


def usage():
    print('run_cpp.py -i <filename> (without .cpp extension)')


def run(cpp_file, exe_file):
    if os.system("g++ foo.c") == 0:
        print ("Worked")
    else:
        print ("Failed")

    os.system("echo Compiling " + cpp_file)
    os.system('g++ ' + cpp_file + ' -o ' + exe_file)
    os.system("echo Running " + exe_file)
    os.system("echo -------------------")
    os.system(exe_file)

# def directories():
#     path = "/csvMaster/"
#     access_rights = 0o755
#     try:
#         os.mkdir(path)
#         os.mkdir(path, access_rights)
#
#         f = open("main.cpp", "w+")
#         for i in range(10):
#             f.write("//This file was created by Python 3.7 %d\r\n" % (i + 1))
#         f.close()
#
#     except OSError:
#         print("Creation of the directory %s failed" % path)
#     else:
#         print("Successfully created the directory %s " % path)


def fileCreator():

    f = open(".gitignore", "w+")
    for i in range(1):
        f.write("cmake-build-debug/**\n")
        f.write(".idea/**\n")
        f.write("\n")
        f.write("*.iml")
    f.close()


if __name__ == '__main__':
    main(sys.argv[1:])
