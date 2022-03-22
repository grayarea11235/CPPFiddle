#!/usr/bin/env python3
# encoding: utf-8

from distutils.core import setup, Extension

spam_module = Extension('spam', sources=['spammodule.cpp'])

setup(name='spam',
      version='0.1.0',
      description='Spammodule written in C++',
      ext_modules=[spam_module])

