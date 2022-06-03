import requests
import urllib.parse
import csv

from flask import redirect, render_template, request, session

def read_csv(csv_file):
    contents = []
    with open(csv_file, newline= "") as file:
        reader = csv.DictReader(file, delimiter="\t")
        for row in reader:
            contents.append(dict(row))
        return contents



