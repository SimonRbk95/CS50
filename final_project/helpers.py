import requests
import urllib.parse
import csv

from flask import redirect, render_template, request, session
from functools import wraps

def read_file():
    coursera_100 = []
    with open("") as file:
        reader = csv.DictReader(file)
        for row in reader:
            coursera_100.append(row)
        return coursera_100

def read_txt():
    