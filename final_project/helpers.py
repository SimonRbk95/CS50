import requests
import urllib.parse
import csv
import gzip
import shutil
import os

from flask import redirect, render_template, request, session
from os.path import exists

# input txt file name without extension
def read_txt(file):
    if not exists(f'static/{file}.txt'):
        with gzip.open(f'static/{file}.txt.gz', 'rb') as f_in:
            with open(f'static/{file}.txt', 'wb') as f_out:
                shutil.copyfileobj(f_in, f_out)
            f_out.close()
    contents = []
    with open(f'static/{file}.txt', newline= "") as f_out:
        reader = csv.DictReader(f_out, delimiter="\t")
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