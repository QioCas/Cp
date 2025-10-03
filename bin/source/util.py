
class Colors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

class Comment():
    def error(s = ''):
        print('[' + Colors.FAIL + 'ERROR' + Colors.ENDC + '] ' + Colors.FAIL + s + Colors.ENDC)
        exit(0)
    def talk(s = ''):
        print('[' + Colors.OKBLUE + 'INFO' + Colors.ENDC + '] ' + s)

import time;
local = time.localtime(time.time())
[year, month, day, hour, minute, second] = (
    local.tm_year, local.tm_mon, local.tm_mday,
    local.tm_hour, local.tm_min, local.tm_sec
)

# No Nut Novenber
if month == 11:
    [month, day] = [10, day + 31]

