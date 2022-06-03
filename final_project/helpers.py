import requests
import urllib.parse
import csv

from flask import redirect, render_template, request, session
from functools import wraps

def read_csv(csv_file):
    contents = []
    with open(csv_file) as file:
        reader = csv.DictReader(file)
        for row in reader:
            contents.append(row)
        return contents

