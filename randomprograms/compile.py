import os
import sys

if(len(sys.argv) ==1):
    print "No file to compile "
    exit()
arg=sys.argv[1:]
os.system("clang++ "+arg[0]+"-o compiledfile.out")
os.system("compiledfile.out ")

