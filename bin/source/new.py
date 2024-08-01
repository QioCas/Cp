import os;

from source import util;
from source.util import Cmt;
from sys import platform;

def Convert(line) -> str:
    for [s, t] in [('$year', util.year), ('$month', util.month)
                   , ('$day', util.day), ('$hour', util.hour)
                   , ('$minute', util.minute), ('$second', util.second)
                   , ('$path', os.getcwd()), ('$task', NameTask)]:
        line = line.replace(str(s), str(t))
    return line

def MakeCpp(pwd, task, source = 'basic'):
    global Pcode, NameTask
    os.chdir(pwd)
    if platform == 'linux':
        Pcode = '/home/cas/Cp/Lib/Template/' + source + '.cpp'
    else:
        Pcode = 'D:/Cp/Lib/Template/' + source + '.cpp'
    NameTask = task
    if os.path.exists(task): 
        Cmt.error("Existed probs {}.".format(task))

    os.mkdir(task)
    os.chdir(task)

    fo = open('{}.cpp'.format(task), 'wb')
    with open('{}'.format(Pcode), 'r') as fi:
        for line in fi.readlines():
            fo.write(Convert(line).encode('utf-8'))

    Cmt.talk('Prob {} is saved at {}'.format(task, os.getcwd()))
    fo.close()

# sublime text open file:
    # os.system('sublime-text.subl {}/{}.cpp'.format(os.getcwd(), task))

# visual studio code open file:
    os.system('code {}/{}.cpp'.format(os.getcwd(), task))

    os.chdir(pwd)

def MakeContest(name_contest, num_probs = 6, source = 'basic'):
    if platform == 'linux':
        pwd = '/home/cas/Cp/Contest/'
    else: 
        pwd = 'D:/Cp/Contest/'
    os.chdir(pwd)
    if os.path.exists(name_contest) == 0:
        os.mkdir(name_contest)
    os.chdir(name_contest)
    for th in range(int(num_probs)):
        MakeCpp(os.getcwd(), str(chr((ord('A') + th))), source)
