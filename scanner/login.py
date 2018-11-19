#!/usr/bin/env python2

from lib import api
from sys import argv

if len(argv) == 3:

    if api.login(argv[1], argv[2]):
        print('Logged in')
        exit(0)
    else:
        print('Failed to log in, try again')
        exit(-1)

else:
    print('Expected two arguments. <username> <password>')
    exit(-1)

