#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jan 15 22:59:02 2018

@author: zhurundong
"""

import time
import requests
import asyncio
import aiohttp
from concurrent.futures import ThreadPoolExecutor

NUMBERS = range(12)
URL = 'http://httpbin.org/get?a={}'

# Get http requests results
def fetch(a):
    r = requests.get(URL.format(a))
    return r.json()['args']['a']

start = time.time()

for num in NUMBERS:
    result = fetch(num)
    print('fetch({}) = {}'.format(num, result))

print('cost time: {}'.format(time.time() - start))

# Get http requests results
def fetch(a):
    r = requests.get(URL.format(a))
    return r.json()['args']['a']

start = time.time()

# Using ThreadPool

with ThreadPoolExecutor(max_workers = 5) as executor:
    for num, result in zip(NUMBERS, executor.map(fetch, NUMBERS)):
        print('fetch({}) = {}'.format(num, result))

print('cost time: {}'.format(time.time() - start))
