#!/usr/bin/env python3

import subprocess

import os

def get_std_flags():
    flags = [
    '-Wall',
    '-Wextra',
    '-Wc++11-compat',
    '-Wno-long-long',
    '-Wno-variadic-macros',
    '-x', 'c++',
    '-fexceptions',
    '-DNDEBUG',
    '-std=c++17',
    '-I','include',
    '-I','~/MyRoot/usr/include',
    ]
    return flags

def get_config_params(config):
    got  = subprocess.run(config.split(),stdout=subprocess.PIPE)
    rvalue = got.stdout.decode('utf-8').strip()
    made = rvalue.replace('-I','-I ').split()
    return made 

def Settings(**kwargs):
    config ="wx-config --cflags"
    flags = get_std_flags() + get_config_params(config)
    rmap =  {
        'flags': flags,
        'do_cache': True
    }
    return rmap;

if __name__ == '__main__':
    print(Settings())

