#!/bin/bash

# python ./scanner/login.py $username $password

echo 'Log in to your shopper account'

read -p 'Username: ' username
read -sp 'Password: ' password
echo

python2 ./scanner/login.py $username $password
mv conf.json scanner/conf.json
