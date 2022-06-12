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

def lookup(symbol):
    """Look up quote for symbol."""

    # Contact API
    try:
        api_key = os.environ.get("API_KEY")
        url = f"https://cloud.iexapis.com/stable/stock/{urllib.parse.quote_plus(symbol)}/quote?token={api_key}"
        response = requests.get(url)
        response.raise_for_status()
    except requests.RequestException:
        return None
