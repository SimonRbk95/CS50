import requests
import urllib.parse
import csv
import gzip
import shutil
import os

from flask import redirect, render_template, request, session
from os.path import exists


def read_gz(gz_file):
    if not exists('static/cdb.txt'):
        with gzip.open(f'static/{gz_file}', 'rb') as f_in:
            with open('static/cdb.txt', 'wb') as f_out:
                shutil.copyfileobj(f_in, f_out)
            f_out.close()
    contents = []
    with open('static/cdb.txt', newline= "") as file:
        reader = csv.DictReader(file, delimiter="\t")
        for row in reader:
            contents.append(dict(row))
        return contents

def read_csv(csv_file):
    contents = []
    with open(f"static/{csv_file}") as file:
        reader = csv.DictReader(file)
        for row in reader:
            contents.append(row)
        return contents


def lookup(course):
    """Look up quote for symbol."""

    # Contact API
    try:
        api_key = os.environ.get("API_KEY")
        url = f"https://cloud.iexapis.com/stable/stock/{urllib.parse.quote_plus(course)}/quote?token={api_key}"
        response = requests.get(url)
        response.raise_for_status()
    except requests.RequestException:
        return None



read_gz()