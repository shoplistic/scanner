import requests
import json
import os.path
import simplejson

authFile = './auth.json'

def confExists():
    return os.path.isfile(authFile)

def getBearer():
    if confExists():
        with open(authFile) as f:
            conf = json.load(f)
            return conf['bearer']
    else:
        return ''

def login(username, password):
    r = requests.post('https://api.shopper.ink/v1/auth', json={ 'username': username, 'password': password })
    if r.status_code == 200:
        f = open(authFile, 'w')
        f.write(simplejson.dumps(r.json(), indent=4))
        f.close()
        return True
    elif r.status_code == 401:
        print('Invalid credentials')
        return False
    else:
        print('Unknown error')
        return False

def get(barcode):
    r = requests.get('https://api.shopper.ink/v1/bcds/' + barcode, headers = { 'Authorization': 'Bearer ' + getBearer() })
    if r.status_code == 200:
        return r.json()
    elif r.status_code == 404:
        print('Item not found')
        return False
    else:
        print('Unknown error')
        return False

def add(item):
    r = requests.post(
        'https://api.shopper.ink/v1/shoppinglist',
        json = { 'barcode': item['barcode'], 'display_name': item['display_name'], 'manufacturer': item['manufacturer'], 'amount': 1 },
        headers = { 'Authorization': 'Bearer ' + getBearer() }
        )
    if r.status_code == 201:
        return True
    else:
        print('Failed to add item to the shopping list')
        return False;
