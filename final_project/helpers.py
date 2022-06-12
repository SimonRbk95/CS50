import requests
import urllib.parse
import csv
import gzip
import shutil

from flask import redirect, render_template, request, session

def read_gz():
    if not exists()
    with gzip.open('static/cdb.txt.gz', 'rb') as f_in:
        with open('static/cdb.txt', 'wb') as f_out:
            shutil.copyfileobj(f_in, f_out)
        contents = []
        with open('static/cdb.txt', newline= "") as file:
            reader = csv.DictReader(file, delimiter="\t")
            for row in reader:
                contents.append(dict(row))
            print(contents[0])

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