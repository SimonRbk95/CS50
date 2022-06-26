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

def append_dict_cdb(dict, courses):
    courses.append({
    "Course Name": dict["Product Name"],
    "URL": dict["Product URL"],
    "Partner": dict["Manufacturer"],
    "Certificate": dict["Product Type"],
    "Image URL" : dict["Image URL"],
    "Current Price" : dict["Current Price"],
    "Product Description" : dict["Product Description"],
    })
    return courses

def append_dict_cdb100(dict, courses):
    courses.append({
    "Course Name": dict["Product Name"],
    "URL": dict["URL"],
    "Partner": dict["Partner"],
    "Certificate": dict["Product Type"],
    })
    return courses

def check_duplicates(courses, dict):
    for course in courses:
        if course["Course Name"] == dict["Product Name"]:
            return True
    return False

def prof_cert_courses(courses, index, dict, keywords_q3, max_courses):
    if any(n in dict["Product Name"] or n in dict["Primary Domain"] or n in dict["Primary Subdomain"] for n in keywords_q3[int(index)]) and len(courses) < max_courses:
        if dict["Product Type"] == "Professional Certificate":
            courses = append_dict_cdb100(dict, courses)
            print(courses)
    return courses

def check_all_courses(courses, index, dict, keywords_q3, max_courses, cdb100=None):
        if len(courses) < max_courses:
            if cdb100 and any(n in dict["Product Name"] or n in dict["Primary Domain"] or n in dict["Primary Subdomain"] for n in keywords_q3[int(index)]):
                        # only append courses with professional certificates if "get a new job" is the goal
                        i = 0
                        while i < len(courses):
                            if not any(course["Course Name"] == dict["Product Name"] for course in courses):
                                courses = append_dict_cdb100(dict, courses)
                            i+=1
            elif any(n in dict["Product Name"] for n in keywords_q3[int(index)]):
                    courses = append_dict_cdb(dict, courses)
        return courses


