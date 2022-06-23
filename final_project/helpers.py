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

# input csv file name without extension
def read_csv(file):
    contents = []
    with open(f"static/{file}.csv") as f_out:
        reader = csv.DictReader(f_out)
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

def append_dict(dict, courses):
    courses.append({
    "Course Name": dict["Product Name"],
    "URL": dict["URL"],
    "Partner": dict["Partner"],
    "Certificate": dict["Product Type"],
    })
    return courses

def check_dict(courses, choice, dict, List_q4, max_courses):
    if choice == "Data Analytics/ Science":
        for i in ["Data Analytics", "Data Science"]:
            if i in dict["Product Name"] or i in dict["Primary Domain"] or i in dict["Primary Subdomain"] and len(courses) < max_courses:
                    # only append courses with professional certificates if "get a new job" is the goal
                    if "Get a new job" in List_q4:
                        if dict["Product Type"] == "Professional Certificate" and len(courses) < max_courses:
                            courses = append_dict(dict, courses)
                    elif len(courses) < max_courses:
                        courses = append_dict(dict, courses)
    elif choice in dict["Product Name"] or choice in dict["Primary Domain"] or choice in dict["Primary Subdomain"] and len(courses) < max_courses:
        if "Get a new job" in List_q4:
            if dict["Product Type"] == "Professional Certificate" and len(courses) < max_courses:
                courses = append_dict(dict, courses)
        elif len(courses) < max_courses:
            courses = append_dict(dict, courses)
    return courses
