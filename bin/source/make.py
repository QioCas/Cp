import os;

from source import util;
from source.util import Comment;

def Convert(line) -> str:
    for [s, t] in [('$year', util.year), ('$month', util.month)
                   , ('$day', util.day), ('$hour', util.hour)
                   , ('$minute', util.minute), ('$second', util.second)
                   , ('$path', os.getcwd()), ('$name', NameTask)]:
        line = line.replace(str(s), str(t))
    return line


def DFS(template_path, code_path):
    for file in os.listdir(template_path):
        cp_file = Convert(file)
        if os.path.isfile(os.path.join(template_path, file)):
            fo = open('{}'.format(os.path.join(code_path, cp_file)), 'wb')
            with open('{}'.format(os.path.join(template_path, file)), 'r') as fi:
                for line in fi.readlines():
                    fo.write(Convert(line).encode('utf-8'))

            Comment.talk('Prob {} is saved at {}'.format(cp_file, os.path.join(code_path, cp_file)))
            fo.close()

            # Config to open code for editing immediately
            if "cpp" in cp_file:
                os.system('code {}'.format(os.path.join(code_path, cp_file)))
            
        else:
            os.makedirs(os.path.join(code_path, cp_file), exist_ok=True)

            DFS(os.path.join(template_path, file), os.path.join(code_path, cp_file))

def MakeCode(code_path, name, template, cf):
    global NameTask
    NameTask = name

    if code_path == None:
        code_path = Convert(cf['code'])

    os.makedirs(code_path, exist_ok=True)

    os.chdir(code_path)

    DFS(cf['template'] + template, code_path)

def MakeContest(name, numProbs, source, cf):
    os.makedirs(cf['contest'], exist_ok=True)
    os.chdir(cf['contest'])
    
    os.makedirs(name, exist_ok=True)
    os.chdir(name)

    for th in range(int(numProbs)):
        MakeCode(os.getcwd(), str(chr((ord('A') + th))), source, cf)
