
class Comment():
    def error(self, s = ''):
        print('[{}] {}'.format('ERROR', s))
        exit(0)
    def talk(self, s = ''):
        print('[{}] {}'.format('+', s))

Cmt = Comment()

import time;
local = time.localtime(time.time())
[year, month, day, hour, minute, second] = (
    local.tm_year, local.tm_mon, local.tm_mday,
    local.tm_hour, local.tm_min, local.tm_sec
)
